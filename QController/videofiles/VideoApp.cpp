//
// Created by eleps on 14.03.19.
//

#include "VideoApp.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


VideoApp::VideoApp(){
    memset(&BaseVideo, 0, sizeof(BaseVideo));
    GstCaps *caps_video;
    try{
        caps_video = gst_caps_from_string("video/x-raw,framerate=50/1");
        BaseVideo.pipeline = gst_pipeline_new ("test-pipeline");
        BaseVideo.source = gst_element_factory_make ("imxv4l2videosrc", "source");
        BaseVideo.queue = gst_element_factory_make("queue","queue");
        BaseVideo.capsfilter = gst_element_factory_make ("capsfilter", "caps_framerate");
        BaseVideo.tee = gst_element_factory_make ("tee", "tee");

        BaseVideo.bus = gst_element_get_bus (BaseVideo.pipeline);
        if (!BaseVideo.pipeline ||      !BaseVideo.source ||        !BaseVideo.tee || !BaseVideo.capsfilter
            ||        !BaseVideo.queue     ) {
            gst_object_unref (BaseVideo.pipeline);
            throw std::logic_error(std::string(__func__)+" Elements not created");
        }
        gst_object_ref (BaseVideo.pipeline);
        gst_object_ref (BaseVideo.capsfilter);
        gst_object_ref (BaseVideo.source);
        gst_object_ref (BaseVideo.tee);
        gst_object_ref (BaseVideo.queue);
        g_object_set (BaseVideo.tee, "allow-not-linked", 1, nullptr);
        g_object_set (BaseVideo.source, "queue-size", 6, nullptr);
        //g_object_set (BaseVideo.source, "num-additional-buffers", 0, nullptr);
        g_object_set (BaseVideo.source, "fps",  50,1, nullptr);
        g_object_set (BaseVideo.source, "fps-n", 50, nullptr);
        g_object_set (BaseVideo.capsfilter, "caps", caps_video, nullptr);

        g_object_set (BaseVideo.queue, "flush-on-eos",  0, nullptr);
        g_object_set (BaseVideo.queue, "leaky", 2, nullptr);
        g_object_set (BaseVideo.queue, "silent", FALSE, nullptr);
        g_object_set (BaseVideo.queue, "max-size-buffers", 1, nullptr);

        gst_bin_add_many (GST_BIN (BaseVideo.pipeline),BaseVideo.source,
                          BaseVideo.tee,BaseVideo.capsfilter, BaseVideo.queue,    nullptr);
        if (    (gst_element_link_many (BaseVideo.source,BaseVideo.capsfilter,
                                        BaseVideo.queue,  BaseVideo.tee, nullptr) != TRUE)  ) {
            throw std::logic_error(std::string(__func__)+" Elements not linked");
        }
        setPointer(this);
        std::thread t1(&VideoApp::fpsCleanThread, this, this);
        std::thread t2(&VideoApp::busThread, this, this);
        t1.detach();
        t2.detach();
        cout<<__func__<<" Initialized successfully"<<endl;
    }
    catch (exception& e) { cout << e.what() << endl; }
}
VideoApp::~VideoApp() {
    setStatus(false);
    disableCamera();
    if (childs.size()!=0){
        //remove all childs here
    }
    gst_element_set_state (BaseVideo.pipeline, GST_STATE_NULL);
    gst_object_unref (BaseVideo.pipeline);
    gst_object_unref (BaseVideo.source);
    gst_object_unref (BaseVideo.tee);
    gst_object_unref (BaseVideo.queue);
}

bool VideoApp::isEnabled(void){
    static int error=0;
    //cout<<"State is:"<<((getState()==GST_STATE_PLAYING)?"Playing ":"Stopped")<<endl;
    if((getState()==GST_STATE_PLAYING)&&(fps==0)){
        if (error>2){disableCamera();  error=0; cout<<"Clean"<<endl; }
        error++;
    }
    return (getState()==GST_STATE_PLAYING)?true:false;
}
bool VideoApp::enableCamera(void){
    if((getState()!=GST_STATE_PLAYING)&& seeVideo()){
        usleep(500000);
        setState(GST_STATE_READY);
        setState(GST_STATE_PLAYING);
        return false;
    }
    return true;
}
bool VideoApp::disableCamera(void){
    if(getState()==GST_STATE_PLAYING){
        usleep(500000);
        this->stop_status=0x01;
        setState(GST_STATE_NULL);
        usleep(500000);
        setState(GST_STATE_READY);
        sleep(1);
        this->stop_status=0x00;
        return false;
    }
    return false;
}
bool VideoApp::restartDevice(void){
    usleep(500000);
    stop_status=0x01;
    setState(GST_STATE_NULL);
    usleep(500000);
    setState(GST_STATE_READY);
    stop_status=0x00;
    usleep(500000);
    setState(GST_STATE_READY);
    setState(GST_STATE_PLAYING);
    return false;
}
bool VideoApp::seeVideo(void){
    char * value = new char [2];
    string hd="12";
    string fhd="15";
    string data;
    ifstream interface(DEFAULT_HDMIRX);
    interface.read(value,2);
    data.push_back(value[0]);
    data.push_back(value[1]);
    interface.close();
    if ((data.compare(hd)==0)||(data.compare(fhd)==0)){
        return true;
    }
    return false;
}//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!11
GstElement* VideoApp::getTee(void){return BaseVideo.tee;}
GstPad* VideoApp::getPad(void){
    GstPadTemplate *tee_src_pad_template = gst_element_class_get_pad_template (GST_ELEMENT_GET_CLASS (BaseVideo.tee), "src_%u");
    GstPad* pad=gst_element_request_pad (BaseVideo.tee, tee_src_pad_template, nullptr, nullptr);
    //gst_object_ref (pad);
    return pad;
}
GstElement* VideoApp::getPipeline(void){return BaseVideo.pipeline;}
GstState VideoApp::getState(void){return GST_STATE(BaseVideo.pipeline);}
bool VideoApp::setState(GstState new_state){
    gst_element_set_state (BaseVideo.pipeline, new_state );
    return false;
}
void     VideoApp::setPointer(VideoAppInterface *object){
    pointer=object;
    //std::cout<<reinterpret_cast<gpointer> (pointer)<<std::endl;
    gst_bus_add_watch (BaseVideo.bus,(GstBusFunc) (&VideoApp::cb_message), nullptr);
    g_signal_connect_swapped (BaseVideo.queue, "pushing", G_CALLBACK (&VideoApp::cb_push),reinterpret_cast<gpointer> (pointer));
}
//Логгирование
void    VideoApp::cb_message2 ( ){
    GstMessage      *message;
    GError *err = nullptr;
    gchar *debug_info = nullptr;
    GstState old_state, new_state;
    message = gst_bus_pop(BaseVideo.bus);
    if(message == nullptr)
        return;
    switch (GST_MESSAGE_TYPE (message)) {
        case GST_MESSAGE_ERROR:
            gst_message_parse_error (message, &err, &debug_info);
            g_printerr ("Error received from element %s: %s\n", GST_OBJECT_NAME (message->src), err->message);
            g_printerr ("Debugging information: %s\n", debug_info ? debug_info : "none");
            break;
        case GST_MESSAGE_EOS:
            g_print ("we reached EOS\n");
            //g_main_loop_quit (loop);
            break;
        case GST_MESSAGE_WARNING:
            gst_message_parse_warning(message, &err, &debug_info);
            g_printerr ("Warning received from element %s: %s\n", GST_OBJECT_NAME (message->src), err->message);
            g_printerr ("Debugging information: %s\n", debug_info ? debug_info : "none");
            break;
        case GST_MESSAGE_INFO:
            gst_message_parse_info(message, &err, &debug_info);
            g_printerr ("Info received from element %s: %s\n", GST_OBJECT_NAME (message->src), err->message);
            g_printerr ("Debugging information: %s\n", debug_info ? debug_info : "none");
            break;
        case GST_MESSAGE_STATE_CHANGED:

            gst_message_parse_state_changed (message, &old_state, &new_state, nullptr);
            /*g_print ("Element %s changed state from %s to %s.\n",
                     GST_OBJECT_NAME (message->src),
                     gst_element_state_get_name (old_state),
                     gst_element_state_get_name (new_state));*/
            break;
        case GST_MESSAGE_STATE_DIRTY:
            g_print ("dirty\n");
            break;
        default:
            break;
            g_error_free (err);
            g_free (debug_info);
            gst_message_unref (message);
    }
}
