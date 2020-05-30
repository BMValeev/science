//
// Created by eleps on 12.04.19.
//

#include "VideoAppInterface.h"
VideoAppInterface::~VideoAppInterface() {}
VideoAppInterface* VideoAppInterface::getPointer(void){ return pointer;}
VideoInterface * VideoAppInterface::getChild(std::string name){
    return (childs.find(name) != childs.end())?childs.find(name)->second:nullptr;
}
bool VideoAppInterface::addChild(std::string name, VideoInterface *l_object){
    return (childs.insert(std::make_pair(name, l_object)).second == false) ?false:true;
}
bool VideoAppInterface::removeChild(std::string name,VideoInterface* l_object){
    return (childs.insert(std::make_pair(name, l_object)).second == false) ?false:true;
}
void VideoAppInterface::setStatus(bool value){living=value;}
bool VideoAppInterface::getStatus(){return living;}
//функционал для реализации подсчета кадров в секунду

void    VideoAppInterface::cb_push (gpointer _gstData){
    VideoAppInterface* oPipeObject = reinterpret_cast<VideoAppInterface*> (_gstData);
    oPipeObject->addFrame();
}
void    VideoAppInterface::addFrame(){frames_shown++; }
unsigned int VideoAppInterface::checkFps(void){return fps;}
void    VideoAppInterface::cleanFps(void){
    std::cout << checkFps() <<": FPS" << std::endl;
    fps=frames_shown;
    frames_shown=0;
}
void VideoAppInterface::fpsCleanThread(VideoAppInterface *thing) {
    while(thing->getStatus()){
        std::this_thread::sleep_for(1s);
        thing->cleanFps();
        //cout <<"stop status= "<<to_string(stop_status)<<endl;
        if(stop_status==0x00){continue;}
        if(stop_status++>0x04){popen("echo '1' > /sys/bus/i2c/devices/0-000f/hpd", "r");stop_status=0x01;}
    }
    return;
}
//Логгирование
void    VideoAppInterface::cb_message ( GstBus *bus,GstMessage *message,gpointer _gstData){
    GError *err = nullptr;
    gchar *debug_info = nullptr;
    GstState old_state, new_state;
    switch (GST_MESSAGE_TYPE (message)) {
        case GST_MESSAGE_ERROR:
            gst_message_parse_error (message, &err, &debug_info);
            g_printerr ("Error received from element %s: %s\n", GST_OBJECT_NAME (message->src), err->message);
            g_printerr ("Debugging information: %s\n", debug_info ? debug_info : "none");
            break;
        case GST_MESSAGE_EOS:
            cout<<"GST_MESSAGE_EOS"<<endl;
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
            cout<<"GST_MESSAGE_STATE_DIRTY"<<endl;
            break;
        case GST_MESSAGE_STRUCTURE_CHANGE:
            cout<<"GST_MESSAGE_STRUCTURE_CHANGE"<<endl;
            break;
        case GST_MESSAGE_APPLICATION:
            cout<<"GST_MESSAGE_APPLICATION"<<endl;
            break;
        case GST_MESSAGE_SEGMENT_START:
            cout<<"GST_MESSAGE_SEGMENT_START"<<endl;
            break;
        case GST_MESSAGE_SEGMENT_DONE:
            cout<<"GST_MESSAGE_SEGMENT_DONE"<<endl;
            break;
        case GST_MESSAGE_ASYNC_START:
            cout<<"GST_MESSAGE_ASYNC_START"<<endl;
            break;
        case GST_MESSAGE_ASYNC_DONE:
            cout<<"GST_MESSAGE_ASYNC_DONE"<<endl;
            break;
        case GST_MESSAGE_ANY:
            cout<<"GST_MESSAGE_ANY"<<endl;
            break;
        default:
            break;
            g_error_free (err);
            g_free (debug_info);
            gst_message_unref (message);
    }
}
void VideoAppInterface::busThread(VideoAppInterface *thing) {
    std::cout << thing->getPointer() << std::endl;
    while(thing->getStatus()){
        //thing->cb_message2();
        std::this_thread::sleep_for(1s);
    }
    return;
}