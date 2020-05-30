//
// Created by eleps on 14.03.19.
//
#include <gst/gst.h>
#include <string>
#include <cstring>
#include <cstdio>
#include <stdlib.h>
#include "Names.h"
#include "VideoApp.h"
#include "VideoRecord.h"
#include "VideoInterface.h"



VideoRecord::VideoRecord(VideoApp* object) {
    try{
        parent=object;
        memset(&RecordVideo, 0, sizeof(RecordVideo));
        RecordVideo.queue_video = gst_element_factory_make("queue","queue_r");
        RecordVideo.convert_video = gst_element_factory_make ("imxipuvideotransform", "convert_r");
        RecordVideo.capsfilter_video = gst_element_factory_make("capsfilter","capsfilter_v");
        RecordVideo.coder_video = gst_element_factory_make ("imxvpuenc_h264", "coder_r");
        RecordVideo.parser_video = gst_element_factory_make ("h264parse", "parser_r");
        RecordVideo.muxer_video = gst_element_factory_make ("mpegtsmux", "muxer_r");
        RecordVideo.sink_video = gst_element_factory_make ("multifilesink", "sink_r");
        //RecordVideo.sink_video = gst_element_factory_make ("appsink", "sink_r");
        /*GstCaps *caps_1;
        caps_1 = gst_caps_from_string("video/x-raw , framerate=30/1 ");
        RecordVideo.queue_video_out = gst_element_factory_make("queue","queue_ro");
        RecordVideo.caps_framerate = gst_element_factory_make("capsfilter","capsfilter_r");
        RecordVideo.framerate = gst_element_factory_make("videorate","framerate_r");
        g_object_set (RecordVideo.queue_video_out, "flush-on-eos", 1, nullptr);
        g_object_set (RecordVideo.queue_video_out, "leaky", 2, nullptr);
        g_object_set (RecordVideo.queue_video_out, "silent", TRUE, nullptr);
        g_object_set (RecordVideo.caps_framerate, "caps", caps_1, nullptr);
        gst_object_ref (RecordVideo.queue_video_out);
        gst_object_ref (RecordVideo.caps_framerate);
        gst_object_ref (RecordVideo.framerate);*/
        if ( !RecordVideo.queue_video ||   !RecordVideo.convert_video || !RecordVideo.coder_video ||
             !RecordVideo.muxer_video  ||  !RecordVideo.sink_video  ||   !RecordVideo.parser_video ||
             !RecordVideo.capsfilter_video  ) { //|| !RecordVideo.caps_framerate || !RecordVideo.framerate
            throw std::logic_error(std::string(__func__)+" Elements not created");
        }
        gst_object_ref (RecordVideo.capsfilter_video);
        gst_object_ref (RecordVideo.queue_video);
        gst_object_ref (RecordVideo.convert_video);
        gst_object_ref (RecordVideo.coder_video);
        gst_object_ref (RecordVideo.parser_video);
        gst_object_ref (RecordVideo.muxer_video);
        gst_object_ref (RecordVideo.sink_video);
        gst_object_ref (RecordVideo.capsfilter_video);
        /*Check is everything created or not*/
        video = FALSE;
        video_mx.unlock();
        GstCaps *caps_video;
        caps_video = gst_caps_from_string("video/x-raw , format=I420 ");//,  height=720 , width=1280

        g_object_set (RecordVideo.queue_video, "flush-on-eos", 1, nullptr);
        g_object_set (RecordVideo.queue_video, "leaky", 2, nullptr);
        g_object_set (RecordVideo.queue_video, "silent", 1, nullptr);
        g_object_set (RecordVideo.queue_video, "max-size-buffers", 1, nullptr);

        g_object_set (RecordVideo.capsfilter_video, "caps", caps_video, nullptr);
        g_object_set (RecordVideo.coder_video, "gop-size", 10, nullptr);
        g_object_set (RecordVideo.coder_video, "quant-param", 21, nullptr);
        g_object_set (RecordVideo.coder_video, "drop", 0, nullptr);
        g_object_set (RecordVideo.parser_video, "config-interval", 1, nullptr);

        g_object_set (RecordVideo.sink_video, "async", 0, nullptr);
        g_object_set (RecordVideo.sink_video, "sync", 1, nullptr);
        g_object_set (RecordVideo.sink_video, "max-files", 100, nullptr);
        //g_object_set (RecordVideo.sink_video, "max-file-size", 1114748364, nullptr);
        g_object_set (RecordVideo.sink_video, "next-file", 4, nullptr);


        g_object_set (RecordVideo.muxer_video, "pmt-interval", 18000, nullptr);
        g_object_set (RecordVideo.muxer_video, "pat-interval", 18000, nullptr);
        g_object_set (RecordVideo.muxer_video, "si-interval", 18000, nullptr);
        RecordVideo.video_pad = gst_element_get_static_pad (RecordVideo.queue_video, "sink");
        //RecordVideo.pad_video = parent->getPad();
        //gst_object_ref (RecordVideo.pad_video);
        setPointer(this);
        object->addChild("Record", this);
        cout<<__func__<<" Initialized successfully"<<endl;
    }
    catch (exception& e) { cout << e.what() << endl; }
}
VideoRecord::~VideoRecord() {
    gst_object_unref (RecordVideo.capsfilter_video);
    gst_object_unref (RecordVideo.muxer_video);
    gst_object_unref (RecordVideo.sink_video);
}
// Функционал реализующий Начало видеозаписи
bool VideoRecord::setPath(std::string path){
    if (path.size()==0){return true;}
    if(isRecording()){return true;}
    savePath=path;
    return false;
}
bool VideoRecord::getMutex(){
    if (video_mutex){ return false; }
    video_mutex=true;
    return true;
}
void VideoRecord::resetMutex(){ video_mutex=false; }
bool VideoRecord::startRecord(void){
    cout<<"==========>COME to write video" <<endl;
    unsigned int i=0;
    if(isRecording()){return true;}
    if(savePath==""){ return true;}
    if(!(parent->isEnabled())){ return true;}
    RecordVideo.pad_video = parent->getPad();
    gst_object_ref (RecordVideo.pad_video);
    video_probe=gst_pad_add_probe (RecordVideo.pad_video, (GstPadProbeType) (GST_PAD_PROBE_TYPE_BLOCK |GST_PAD_PROBE_TYPE_BUFFER),
        reinterpret_cast<GstPadProbeCallback> (&VideoRecord::add_queue_video),getPointer(), nullptr);
        while((i++<5)||!isRecording()){
            usleep(100000);
            RecStatus=true;
            cout<<"==========>END to write video good" <<endl;
            return false;
        }
    cout<<"==========>END to write video bad" <<endl;
    return true;
}
bool VideoRecord::stopRecord(void){
    if(!isRecording()){return true;}
    video_probe=gst_pad_add_probe (RecordVideo.video_pad,(GstPadProbeType) (GST_PAD_PROBE_TYPE_BLOCK),
               reinterpret_cast<GstPadProbeCallback>  (&VideoRecord::remove_video_block),getPointer(), nullptr);//
    RecStatus=false;
    return false;
}
bool VideoRecord::isRecording(void){ return RecStatus; }
bool VideoRecord::setSize(unsigned int kBytes){
    if((kBytes<500000)||(kBytes>10000000)){return true;}
    g_object_set (RecordVideo.sink_video, "max-file-size", kBytes*1000, nullptr);
    return false;
}
bool VideoRecord::setName(unsigned int model){
    if((model>5)){return true;}
    name_model=model;
    return false;
}
bool VideoRecord::setQuality(unsigned int quantParam){
    if((quantParam<1)||(quantParam>51)){return true;}
    g_object_set (RecordVideo.coder_video, "quant-param", quantParam, nullptr);
    return false;
}






// Функционал реализующий Начало видеозаписи
GstPad* VideoRecord::c_videorate_video () {
    GstPad *srcpad;
    std::cout <<(std::string) __func__ <<std::endl;
    gst_bin_add ( GST_BIN (parent->getPipeline()), RecordVideo.framerate );
    gst_element_set_state (RecordVideo.framerate, GST_STATE_READY );
    gst_element_set_state (RecordVideo.framerate, GST_STATE_PLAYING );
    gst_element_link (RecordVideo.capsfilter_video, RecordVideo.framerate);
    srcpad=gst_element_get_static_pad (RecordVideo.framerate, "src");
    return srcpad;
}
GstPad* VideoRecord::c_rate_capsfilter_video () {
    std::cout <<(std::string) __func__ <<std::endl;
    GstPad *srcpad;;
    gst_bin_add ( GST_BIN (parent->getPipeline()), RecordVideo.caps_framerate ) ;
    gst_element_set_state (RecordVideo.caps_framerate, GST_STATE_READY );
    gst_element_set_state (RecordVideo.caps_framerate, GST_STATE_PLAYING );
    gst_element_link (RecordVideo.framerate, RecordVideo.caps_framerate);
    srcpad=gst_element_get_static_pad (RecordVideo.caps_framerate, "src");
    return srcpad;
}
GstPad* VideoRecord::c_queue_out_video  ( ){
    GstPad *srcpad;
    std::cout <<(std::string) __func__ <<std::endl;
    gst_bin_add ( GST_BIN (parent->getPipeline()), RecordVideo.queue_video_out );
    gst_element_set_state (RecordVideo.queue_video_out, GST_STATE_READY );
    gst_element_set_state (RecordVideo.queue_video_out, GST_STATE_PLAYING );
    gst_element_link (RecordVideo.parser_video, RecordVideo.queue_video_out);
    srcpad=gst_element_get_static_pad (RecordVideo.queue_video_out, "src");
    return srcpad;
}
GstPadProbeReturn VideoRecord::add_videorate_video (GstPad *pad,GstPadProbeInfo *info,gpointer _gstData){
    VideoRecord* oPipeObject = reinterpret_cast<VideoRecord*> (_gstData);
    GstPad *srcpad;
    if(oPipeObject->getMutex()) {
        std::cout <<(std::string) __func__ <<std::endl;
        gst_pad_remove_probe (pad, GST_PAD_PROBE_INFO_ID (info));
        srcpad =oPipeObject->c_videorate_video();
        gst_pad_add_probe (srcpad, (GstPadProbeType) (GST_PAD_PROBE_TYPE_BLOCK | GST_PAD_PROBE_TYPE_EVENT_DOWNSTREAM | GST_PAD_PROBE_TYPE_BUFFER ) ,
                           reinterpret_cast<GstPadProbeCallback> (&VideoRecord::add_rate_capsfilter_video), oPipeObject, nullptr);
        gst_object_unref (srcpad);
        oPipeObject->resetMutex();
    }
    return GST_PAD_PROBE_DROP;
}
GstPadProbeReturn VideoRecord::add_rate_capsfilter_video (GstPad *pad,GstPadProbeInfo *info,gpointer _gstData){
    VideoRecord* oPipeObject = reinterpret_cast<VideoRecord*> (_gstData);
    GstPad *srcpad;
    if(oPipeObject->getMutex()) {
        std::cout <<(std::string) __func__ <<std::endl;
        gst_pad_remove_probe (pad, GST_PAD_PROBE_INFO_ID (info));
        srcpad =oPipeObject->c_rate_capsfilter_video();
        gst_pad_add_probe (srcpad, (GstPadProbeType) ( GST_PAD_PROBE_TYPE_BLOCK | GST_PAD_PROBE_TYPE_EVENT_DOWNSTREAM | GST_PAD_PROBE_TYPE_BUFFER ) ,
                           reinterpret_cast<GstPadProbeCallback> (&VideoRecord::add_coder_video), oPipeObject, nullptr);
        gst_object_unref (srcpad);
        std::cout <<(std::string) __func__ <<std::endl;
        oPipeObject->resetMutex();
    }
    return GST_PAD_PROBE_DROP;
}
GstPadProbeReturn VideoRecord::add_queue_out_video ( GstPad *pad, GstPadProbeInfo *info,gpointer _gstData){
    VideoRecord* oPipeObject = reinterpret_cast<VideoRecord*> (_gstData);
    GstPad *srcpad;
    if(oPipeObject->getMutex()) {
        std::cout <<(std::string) __func__ <<std::endl;
        gst_pad_remove_probe (pad, GST_PAD_PROBE_INFO_ID (info));
        srcpad =oPipeObject->c_queue_out_video();
        gst_pad_add_probe (srcpad, (GstPadProbeType) (GST_PAD_PROBE_TYPE_BLOCK | GST_PAD_PROBE_TYPE_EVENT_DOWNSTREAM | GST_PAD_PROBE_TYPE_BUFFER)
                , (GstPadProbeCallback) &VideoRecord::add_muxer_video,oPipeObject, nullptr);
        gst_object_unref (srcpad);
        oPipeObject->resetMutex();
    }
    return GST_PAD_PROBE_DROP;
}


GstPad* VideoRecord::c_queue_video () {
    GstPad *srcpad;
    video_mx.lock();
    std::cout <<(std::string) __func__ <<std::endl;
    gst_bin_add ( GST_BIN (parent->getPipeline()), RecordVideo.queue_video );
    gst_element_set_state (RecordVideo.queue_video, GST_STATE_READY );
    gst_element_set_state (RecordVideo.queue_video, GST_STATE_PLAYING );
    //(gst_element_link (parent->getTee(),RecordVideo.queue_video) == TRUE)? g_print("link.\n") : g_print("link failed.\n");
    /*auto status=*/gst_pad_link (RecordVideo.pad_video, RecordVideo.video_pad);
    //gst_element_link(parent->getTee(),RecordVideo.queue_video);
    /*switch(status){
        case GST_PAD_LINK_OK: cout<<"GST_PAD_LINK_OK"<<endl; break;
        case GST_PAD_LINK_WRONG_HIERARCHY: cout<<"GST_PAD_LINK_WRONG_HIERARCHY"<<endl; break;
        case GST_PAD_LINK_WAS_LINKED: cout<<"GST_PAD_LINK_WAS_LINKED"<<endl; break;
        case GST_PAD_LINK_WRONG_DIRECTION: cout<<"GST_PAD_LINK_WRONG_DIRECTION"<<endl; break;
        case GST_PAD_LINK_NOFORMAT: cout<<"GST_PAD_LINK_NOFORMAT"<<endl; break;
        case GST_PAD_LINK_NOSCHED: cout<<"GST_PAD_LINK_NOSCHED"<<endl; break;
        case GST_PAD_LINK_REFUSED: cout<<"GST_PAD_LINK_REFUSED"<<endl; break;
        default: cout<<"wrong"<<endl; break;
    }*/
    srcpad=gst_element_get_static_pad (RecordVideo.queue_video, "src");
    video_mx.unlock();
    return srcpad;
}
GstPad* VideoRecord::c_convert_video () {
    GstPad *srcpad;
    std::cout <<(std::string) __func__ <<std::endl;
    gst_bin_add ( GST_BIN (parent->getPipeline()), RecordVideo.convert_video );
    gst_element_set_state (RecordVideo.convert_video, GST_STATE_READY );
    gst_element_set_state (RecordVideo.convert_video, GST_STATE_PLAYING );
    gst_element_link (RecordVideo.queue_video, RecordVideo.convert_video);
    srcpad=gst_element_get_static_pad (RecordVideo.convert_video, "src");
    return srcpad;
}
GstPad* VideoRecord::c_capsfilter_video () {
    std::cout <<(std::string) __func__ <<std::endl;
    GstPad *srcpad;;
    gst_bin_add ( GST_BIN (parent->getPipeline()), RecordVideo.capsfilter_video ) ;
    gst_element_set_state (RecordVideo.capsfilter_video, GST_STATE_READY );
    gst_element_set_state (RecordVideo.capsfilter_video, GST_STATE_PLAYING );
    gst_element_link (RecordVideo.convert_video, RecordVideo.capsfilter_video);
    srcpad=gst_element_get_static_pad (RecordVideo.capsfilter_video, "src");
    return srcpad;
}
GstPad* VideoRecord::c_coder_video () {
    GstPad *srcpad;
    std::cout <<(std::string) __func__ <<std::endl;
    gst_bin_add ( GST_BIN (parent->getPipeline()), RecordVideo.coder_video );
    gst_element_set_state (RecordVideo.coder_video, GST_STATE_READY );
    gst_element_set_state (RecordVideo.coder_video, GST_STATE_PLAYING );
    gst_element_link (RecordVideo.capsfilter_video, RecordVideo.coder_video);
    srcpad=gst_element_get_static_pad (RecordVideo.coder_video, "src");
    return srcpad;
}
GstPad* VideoRecord::c_parser_video   (){
    GstPad *srcpad;
    std::cout <<(std::string) __func__ <<std::endl;
    gst_bin_add ( GST_BIN (parent->getPipeline()), RecordVideo.parser_video );
    gst_element_set_state (RecordVideo.parser_video, GST_STATE_READY );
    gst_element_set_state (RecordVideo.parser_video, GST_STATE_PLAYING );
    gst_element_link (RecordVideo.coder_video, RecordVideo.parser_video);
    srcpad=gst_element_get_static_pad (RecordVideo.parser_video, "src");
    return srcpad;
}
GstPad* VideoRecord::c_muxer_video  ( ){
    GstPad *srcpad;
    std::cout <<(std::string) __func__ <<std::endl;
    gst_bin_add ( GST_BIN (parent->getPipeline()), RecordVideo.muxer_video );
    gst_element_set_state (RecordVideo.muxer_video, GST_STATE_READY );
    gst_element_set_state (RecordVideo.muxer_video, GST_STATE_PLAYING );
    gst_element_link (RecordVideo.parser_video, RecordVideo.muxer_video);
    srcpad=gst_element_get_static_pad (RecordVideo.muxer_video, "src");
    return srcpad;
}
void VideoRecord::c_sink_video ( ){
    GString *video_filename;
    std::cout <<(std::string) __func__ <<std::endl;
    video_filename=g_string_new(g_build_filename(Names::videoname_multi ().str, nullptr));
    switch(name_model){
        case 0: Names::name_model_0("Video","%03.avi"); break;
        case 1: Names::name_model_1("Video","%03.avi"); break;
        case 2: Names::name_model_2("Video","%03.avi"); break;
        case 3: Names::name_model_3("Video","%03.avi"); break;
        case 4: Names::name_model_4("Video","%03.avi"); break;
        case 5: Names::name_model_5("Video","%03.avi"); break;
        default: Names::name_model_0("Video","%03.avi"); break;
    }
    g_object_set (RecordVideo.sink_video, "location", video_filename->str, nullptr);
    gst_bin_add ( GST_BIN (parent->getPipeline()), RecordVideo.sink_video ) ;
    gst_element_set_state (RecordVideo.sink_video, GST_STATE_READY );
    gst_element_set_state (RecordVideo.sink_video, GST_STATE_PLAYING );
    gst_element_link (RecordVideo.muxer_video, RecordVideo.sink_video);
    video=TRUE;
    return ;
}

GstPadProbeReturn VideoRecord::add_queue_video (GstPad *pad,GstPadProbeInfo *info,gpointer _gstData){
    GstPad *srcpad;
    VideoRecord *oPipeObject = reinterpret_cast<VideoRecord *> (_gstData);
    if(oPipeObject->getMutex()) {
        std::cout <<(std::string) __func__ <<std::endl;
        gst_pad_remove_probe(pad, GST_PAD_PROBE_INFO_ID(info));
        srcpad = oPipeObject->c_queue_video();
        gst_pad_add_probe(srcpad, (GstPadProbeType)
                                  ( GST_PAD_PROBE_TYPE_BLOCK | GST_PAD_PROBE_TYPE_EVENT_DOWNSTREAM | GST_PAD_PROBE_TYPE_BUFFER),
                          reinterpret_cast<GstPadProbeCallback> (&VideoRecord::add_convert_video), oPipeObject, nullptr);
        gst_object_unref(srcpad);
        oPipeObject->resetMutex();
    }
    return GST_PAD_PROBE_DROP;
}
GstPadProbeReturn VideoRecord::add_convert_video (GstPad *pad,GstPadProbeInfo *info,gpointer _gstData){
    VideoRecord* oPipeObject = reinterpret_cast<VideoRecord*> (_gstData);
    GstPad *srcpad;
    if(oPipeObject->getMutex()) {
        std::cout <<(std::string) __func__ <<std::endl;
        gst_pad_remove_probe (pad, GST_PAD_PROBE_INFO_ID (info));
        srcpad =oPipeObject->c_convert_video();
        gst_pad_add_probe (srcpad, (GstPadProbeType) (GST_PAD_PROBE_TYPE_BLOCK | GST_PAD_PROBE_TYPE_EVENT_DOWNSTREAM | GST_PAD_PROBE_TYPE_BUFFER ) ,
                           reinterpret_cast<GstPadProbeCallback> (&VideoRecord::add_capsfilter_video), oPipeObject, nullptr);
        gst_object_unref (srcpad);
        oPipeObject->resetMutex();
    }
    return GST_PAD_PROBE_DROP;
}
GstPadProbeReturn VideoRecord::add_capsfilter_video (GstPad *pad,GstPadProbeInfo *info,gpointer _gstData){
    VideoRecord* oPipeObject = reinterpret_cast<VideoRecord*> (_gstData);
    GstPad *srcpad;
    if(oPipeObject->getMutex()) {
        std::cout <<(std::string) __func__ <<std::endl;
        gst_pad_remove_probe (pad, GST_PAD_PROBE_INFO_ID (info));
        srcpad =oPipeObject->c_capsfilter_video();
        gst_pad_add_probe (srcpad, (GstPadProbeType) ( GST_PAD_PROBE_TYPE_BLOCK | GST_PAD_PROBE_TYPE_EVENT_DOWNSTREAM | GST_PAD_PROBE_TYPE_BUFFER ) ,
                           reinterpret_cast<GstPadProbeCallback> (&VideoRecord::add_coder_video), oPipeObject, nullptr);
        gst_object_unref (srcpad);
        oPipeObject->resetMutex();
    }
    return GST_PAD_PROBE_DROP;
}
GstPadProbeReturn VideoRecord::add_coder_video (  GstPad *pad,GstPadProbeInfo *info,gpointer _gstData) {
    VideoRecord *oPipeObject = (VideoRecord *) _gstData;
    GstPad *srcpad;
    if(oPipeObject->getMutex()) {
        std::cout <<(std::string) __func__ <<std::endl;
        gst_pad_remove_probe(pad, GST_PAD_PROBE_INFO_ID(info));
        srcpad = oPipeObject->c_coder_video();
        gst_pad_add_probe(srcpad,(GstPadProbeType) (GST_PAD_PROBE_TYPE_BLOCK | GST_PAD_PROBE_TYPE_EVENT_DOWNSTREAM | GST_PAD_PROBE_TYPE_BUFFER),
                          reinterpret_cast<GstPadProbeCallback> (&VideoRecord::add_parser_video), oPipeObject, nullptr);
        gst_object_unref(srcpad);
        oPipeObject->resetMutex();
    }
    return GST_PAD_PROBE_DROP;
}
GstPadProbeReturn VideoRecord::add_parser_video ( GstPad *pad, GstPadProbeInfo *info,gpointer _gstData){
    VideoRecord* oPipeObject = reinterpret_cast<VideoRecord*> (_gstData);
    GstPad *srcpad;
    if(oPipeObject->getMutex()) {
        std::cout <<(std::string) __func__ <<std::endl;
        gst_pad_remove_probe (pad, GST_PAD_PROBE_INFO_ID (info));
        srcpad =oPipeObject->c_parser_video();
        gst_pad_add_probe (srcpad, (GstPadProbeType) (GST_PAD_PROBE_TYPE_BLOCK | GST_PAD_PROBE_TYPE_EVENT_DOWNSTREAM | GST_PAD_PROBE_TYPE_BUFFER)
                , reinterpret_cast<GstPadProbeCallback>( &VideoRecord::add_muxer_video),oPipeObject, nullptr);
        gst_object_unref (srcpad);
        oPipeObject->resetMutex();
    }
    return GST_PAD_PROBE_DROP;
}
GstPadProbeReturn VideoRecord::add_muxer_video ( GstPad *pad, GstPadProbeInfo *info,gpointer _gstData){
    VideoRecord* oPipeObject = reinterpret_cast<VideoRecord*> (_gstData);
    GstPad *srcpad;
    if(oPipeObject->getMutex()) {
        std::cout <<(std::string) __func__ <<std::endl;
        gst_pad_remove_probe (pad, GST_PAD_PROBE_INFO_ID (info));
        srcpad =oPipeObject->c_muxer_video();
        gst_pad_add_probe (srcpad, (GstPadProbeType) (GST_PAD_PROBE_TYPE_BLOCK | GST_PAD_PROBE_TYPE_EVENT_DOWNSTREAM | GST_PAD_PROBE_TYPE_BUFFER)
                , (GstPadProbeCallback) &VideoRecord::add_sink_video,oPipeObject, nullptr);
        gst_object_unref (srcpad);
        oPipeObject->resetMutex();
    }
    return GST_PAD_PROBE_DROP;
}
GstPadProbeReturn VideoRecord::add_sink_video ( GstPad *pad, GstPadProbeInfo *info,gpointer _gstData){
    VideoRecord* oPipeObject = reinterpret_cast<VideoRecord*> (_gstData);
    if(oPipeObject->getMutex()) {
        std::cout <<(std::string) __func__ <<std::endl;
        gst_pad_remove_probe (pad, GST_PAD_PROBE_INFO_ID (info));
        oPipeObject->c_sink_video();
        oPipeObject->resetMutex();
    }
    return GST_PAD_PROBE_DROP;
}
// Функционал реализующий конец видеозаписи
void        VideoRecord::r_sink_video (){
    cout<<(__func__)<<endl;
    gst_element_set_state (RecordVideo.parser_video, GST_STATE_NULL);
    gst_bin_remove (GST_BIN (parent->getPipeline()), RecordVideo.parser_video);
    gst_element_set_state (RecordVideo.muxer_video, GST_STATE_NULL);
    gst_bin_remove (GST_BIN (parent->getPipeline()), RecordVideo.muxer_video);
    //gst_element_send_event (RecordVideo.queue_video_out, gst_event_new_eos ());
    //cout<<(gst_bin_remove (GST_BIN (parent->getPipeline()), RecordVideo.queue_video_out)?"removed":"not removed")<<endl;
    gst_element_send_event (RecordVideo.sink_video, gst_event_new_eos ());
    gst_element_set_state (RecordVideo.sink_video, GST_STATE_NULL);
    gst_bin_remove (GST_BIN (parent->getPipeline()), RecordVideo.sink_video);
    //gst_element_set_state (RecordVideo.queue_video, GST_STATE_NULL );
    video=FALSE;
    gst_object_unref (RecordVideo.muxer_video);
    RecordVideo.muxer_video = gst_element_factory_make ("mpegtsmux", "muxer_video");
    gst_object_ref (RecordVideo.muxer_video);
    return;
}
GstPad*        VideoRecord::r_coder_video  (){
    GstPad *srcpad, *sinkpad;
    cout<<(__func__)<<endl;
    gst_element_set_state (RecordVideo.coder_video, GST_STATE_NULL);
    gst_bin_remove (GST_BIN (parent->getPipeline()), RecordVideo.coder_video);
    srcpad=gst_element_get_static_pad (RecordVideo.parser_video, "src");
    gst_pad_add_probe (srcpad, (GstPadProbeType) (GST_PAD_PROBE_TYPE_BLOCK | GST_PAD_PROBE_TYPE_EVENT_DOWNSTREAM),
                       reinterpret_cast<GstPadProbeCallback> (&VideoRecord::remove_parser_video), this, nullptr);
    sinkpad = gst_element_get_static_pad (RecordVideo.parser_video, "sink");
    gst_pad_send_event (sinkpad, gst_event_new_eos ());
    gst_object_unref (sinkpad);
    return srcpad;
}
GstPad*        VideoRecord::r_capsfilter_video  (){
    GstPad *srcpad, *sinkpad;
    cout<<(__func__)<<endl;
    gst_element_set_state (RecordVideo.capsfilter_video, GST_STATE_NULL);
    gst_bin_remove (GST_BIN (parent->getPipeline()), RecordVideo.capsfilter_video);
    srcpad=gst_element_get_static_pad (RecordVideo.coder_video, "src");
    gst_pad_add_probe (srcpad, (GstPadProbeType) (GST_PAD_PROBE_TYPE_BLOCK | GST_PAD_PROBE_TYPE_EVENT_DOWNSTREAM),
                       reinterpret_cast<GstPadProbeCallback> (&VideoRecord::remove_coder_video), this, nullptr);
    sinkpad = gst_element_get_static_pad (RecordVideo.coder_video, "sink");
    gst_pad_send_event (sinkpad, gst_event_new_eos ());
    gst_object_unref (sinkpad);
    return srcpad;
}
GstPad*        VideoRecord::r_convert_video(){
    GstPad *srcpad, *sinkpad;
    cout<<(__func__)<<endl;
    gst_element_set_state (RecordVideo.convert_video, GST_STATE_NULL);
    gst_bin_remove (GST_BIN (parent->getPipeline()), RecordVideo.convert_video);
    srcpad=gst_element_get_static_pad (RecordVideo.capsfilter_video, "src");
    gst_pad_add_probe (srcpad , (GstPadProbeType) (GST_PAD_PROBE_TYPE_BLOCK | GST_PAD_PROBE_TYPE_EVENT_DOWNSTREAM),
                       reinterpret_cast<GstPadProbeCallback> (&VideoRecord::remove_capsfilter_video), this, nullptr);
    sinkpad = gst_element_get_static_pad (RecordVideo.capsfilter_video, "sink");
    gst_pad_send_event (sinkpad, gst_event_new_eos ());
    gst_object_unref (sinkpad);
    return srcpad;
}
GstPad*        VideoRecord::r_queue_video (){
    GstPad  *sinkpad, *srcpad;
    video_mx.lock();
    srcpad =gst_element_get_static_pad (RecordVideo.convert_video, "src");
    cout<<(__func__)<<endl;
    //gst_pad_unlink(RecordVideo.pad_video,RecordVideo.video_pad);
    //gst_element_unlink(RecordVideo.queue_video,RecordVideo.convert_video);
    //gst_element_set_state (RecordVideo.queue_video, GST_STATE_NULL);
    gst_bin_remove (GST_BIN (parent->getPipeline()), RecordVideo.queue_video);
    gst_pad_add_probe (srcpad, (GstPadProbeType) (GST_PAD_PROBE_TYPE_BLOCK | GST_PAD_PROBE_TYPE_EVENT_DOWNSTREAM),
                       reinterpret_cast<GstPadProbeCallback> (&VideoRecord::remove_convert_video), this, nullptr);
    sinkpad = gst_element_get_static_pad (RecordVideo.convert_video, "sink");
    gst_pad_send_event (sinkpad, gst_event_new_eos ());
    gst_object_unref (sinkpad);
    video_mx.unlock();
    return srcpad;
}
GstPad*        VideoRecord::r_video_block (){
    GstPad  *srcpad;
    video_mx.lock();
    srcpad=gst_element_get_static_pad (RecordVideo.queue_video, "src");
    gst_pad_unlink (RecordVideo.pad_video, RecordVideo.video_pad);
    gst_element_release_request_pad (parent->getTee(), RecordVideo.pad_video);
    //gst_object_unref (RecordVideo.pad_video);
    //cout<<gst_element_unlink(parent->getTee(),RecordVideo.queue_video)?"removed":"not removed"<<endl;
    gst_pad_add_probe (srcpad, (GstPadProbeType) (GST_PAD_PROBE_TYPE_BLOCK   | GST_PAD_PROBE_TYPE_EVENT_DOWNSTREAM),
                       reinterpret_cast<GstPadProbeCallback> (&VideoRecord::remove_queue_video), this, nullptr);
    gst_pad_send_event (RecordVideo.video_pad, gst_event_new_eos ());
    cout<<(__func__)<<endl;
    video_mx.unlock();
    return srcpad;
}
GstPadProbeReturn VideoRecord::remove_parser_video ( GstPad *pad, GstPadProbeInfo *info,gpointer _gstData){
    VideoRecord* oPipeObject = reinterpret_cast<VideoRecord*> (_gstData);
    if (GST_EVENT_TYPE (GST_PAD_PROBE_INFO_DATA (info)) != GST_EVENT_EOS){return GST_PAD_PROBE_PASS; }
    std::cout <<(std::string) __func__ <<std::endl;
    gst_pad_remove_probe (pad, GST_PAD_PROBE_INFO_ID (info));
    oPipeObject->r_sink_video();
    return GST_PAD_PROBE_DROP;
}
GstPadProbeReturn VideoRecord::remove_coder_video ( GstPad *pad, GstPadProbeInfo *info,gpointer _gstData){
    VideoRecord* oPipeObject = reinterpret_cast<VideoRecord*> (_gstData);
    if (GST_EVENT_TYPE (GST_PAD_PROBE_INFO_DATA (info)) != GST_EVENT_EOS){return GST_PAD_PROBE_PASS;  }
    std::cout <<(std::string) __func__ <<std::endl;
    gst_pad_remove_probe (pad, GST_PAD_PROBE_INFO_ID (info));
    oPipeObject->r_coder_video();
    return GST_PAD_PROBE_DROP;
}
GstPadProbeReturn VideoRecord::remove_capsfilter_video (GstPad *pad, GstPadProbeInfo *info,gpointer _gstData){
    VideoRecord* oPipeObject = reinterpret_cast<VideoRecord*> (_gstData);
    if (GST_EVENT_TYPE (GST_PAD_PROBE_INFO_DATA (info)) != GST_EVENT_EOS){ return GST_PAD_PROBE_PASS; }
    std::cout <<(std::string) __func__ <<std::endl;
    gst_pad_remove_probe (pad, GST_PAD_PROBE_INFO_ID (info));
    oPipeObject->r_capsfilter_video();
    return GST_PAD_PROBE_DROP;
}
GstPadProbeReturn VideoRecord::remove_convert_video (GstPad  *pad,GstPadProbeInfo *info,gpointer _gstData){
    VideoRecord* oPipeObject = reinterpret_cast<VideoRecord*> (_gstData);
    if (GST_EVENT_TYPE (GST_PAD_PROBE_INFO_DATA (info)) != GST_EVENT_EOS){ return GST_PAD_PROBE_PASS;}
    std::cout <<(std::string) __func__ <<std::endl;
    oPipeObject->r_convert_video();
    gst_pad_remove_probe (pad, GST_PAD_PROBE_INFO_ID (info));
    return GST_PAD_PROBE_DROP;
}
GstPadProbeReturn VideoRecord::remove_queue_video ( GstPad *pad, GstPadProbeInfo *info,gpointer _gstData){
    if (GST_EVENT_TYPE (GST_PAD_PROBE_INFO_DATA (info)) != GST_EVENT_EOS){ return GST_PAD_PROBE_PASS; }
    VideoRecord* oPipeObject = reinterpret_cast<VideoRecord*> (_gstData);
    std::cout <<(std::string) __func__ <<std::endl;
    gst_pad_remove_probe (pad, GST_PAD_PROBE_INFO_ID (info));
    oPipeObject->r_queue_video();
    return GST_PAD_PROBE_DROP;
}
GstPadProbeReturn VideoRecord::remove_video_block( GstPad *pad, GstPadProbeInfo *info,gpointer _gstData) {
    VideoRecord* oPipeObject = reinterpret_cast<VideoRecord*> (_gstData);
    if(oPipeObject->getMutex()) {
        std::cout <<(std::string) __func__ <<std::endl;
        //std::cout <<(std::string) GST_EVENT_TYPE_NAME(GST_PAD_PROBE_INFO_DATA (info)) <<std::endl;
        gst_pad_remove_probe (pad, GST_PAD_PROBE_INFO_ID (info));
        oPipeObject->r_video_block();
        oPipeObject->resetMutex();
        std::cout <<"GST_PAD_PROBE_OK" <<std::endl;
        return GST_PAD_PROBE_HANDLED;
    }
    std::cout <<"GST_PAD_PROBE_DROP" <<std::endl;
    return GST_PAD_PROBE_DROP;
}

