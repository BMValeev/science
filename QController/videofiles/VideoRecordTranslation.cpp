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
#include "VideoRecordTranslation.h"
#include "VideoInterface.h"



VideoRecordTranslation::VideoRecordTranslation(VideoApp* object)
        :RecStatus(false),TranslateStatus(false),savePath(""),name_model(0),port(400),ip("192.168.0.100") {
    try{
        parent=object;
        memset(&RecordVideo, 0, sizeof(RecordVideo));
        RecordVideo.queue = gst_element_factory_make("queue","queue_r");
        RecordVideo.convert = gst_element_factory_make ("imxipuvideotransform", "convert_r");
        RecordVideo.capsfilter = gst_element_factory_make("capsfilter","capsfilter_v");
        RecordVideo.coder = gst_element_factory_make ("imxvpuenc_h264", "coder_r");
        RecordVideo.parser = gst_element_factory_make ("h264parse", "parser_r");
        RecordVideo.tee = gst_element_factory_make ("multifilesink", "sink_r");

        RecordVideo.muxer = gst_element_factory_make ("mpegtsmux", "muxer_r");
        RecordVideo.sink = gst_element_factory_make ("multifilesink", "sink_r");

        RecordVideo.payloader = gst_element_factory_make ("multifilesink", "sink_r");
        RecordVideo.udpsink = gst_element_factory_make ("multifilesink", "sink_r");
        if ( !RecordVideo.queue ||   !RecordVideo.convert || !RecordVideo.capsfilter ||
             !RecordVideo.coder  ||  !RecordVideo.parser  ||   !RecordVideo.tee ||
             !RecordVideo.muxer || !RecordVideo.sink || !RecordVideo.payloader || !RecordVideo.udpsink ) {
            throw std::logic_error(std::string(__func__)+" Elements not created");
        }
        gst_object_ref (RecordVideo.queue);
        gst_object_ref (RecordVideo.convert);
        gst_object_ref (RecordVideo.capsfilter);
        gst_object_ref (RecordVideo.coder);
        gst_object_ref (RecordVideo.parser);
        gst_object_ref (RecordVideo.tee);
        gst_object_ref (RecordVideo.muxer);
        gst_object_ref (RecordVideo.sink);
        gst_object_ref (RecordVideo.payloader);
        gst_object_ref (RecordVideo.udpsink);
        /*Check is everything created or not*/
        video_mx.unlock();
        GstCaps *caps_video;
        caps_video = gst_caps_from_string("video/x-raw , format=I420 ");//,  height=720 , width=1280

        g_object_set (RecordVideo.queue, "flush-on-eos", 1, nullptr);
        g_object_set (RecordVideo.queue, "leaky", 2, nullptr);
        g_object_set (RecordVideo.queue, "silent", 1, nullptr);
        g_object_set (RecordVideo.queue, "max-size-buffers", 1, nullptr);

        g_object_set (RecordVideo.capsfilter, "caps", caps_video, nullptr);
        g_object_set (RecordVideo.coder, "gop-size", 10, nullptr);
        g_object_set (RecordVideo.coder, "quant-param", 21, nullptr);
        g_object_set (RecordVideo.coder, "drop", 0, nullptr);
        g_object_set (RecordVideo.parser, "config-interval", 1, nullptr);

        g_object_set (RecordVideo.sink, "async", 0, nullptr);
        g_object_set (RecordVideo.sink, "sync", 1, nullptr);
        g_object_set (RecordVideo.sink, "max-files", 100, nullptr);
        //g_object_set (RecordVideo.sink, "max-file-size", 1114748364, nullptr);
        g_object_set (RecordVideo.sink, "next-file", 4, nullptr);

        g_object_set (RecordVideo.muxer, "pmt-interval", 18000, nullptr);
        g_object_set (RecordVideo.muxer, "pat-interval", 18000, nullptr);
        g_object_set (RecordVideo.muxer, "si-interval", 18000, nullptr);

        gst_bin_add_many (GST_BIN (parent->getPipeline()), RecordVideo.queue,  RecordVideo.convert
                ,RecordVideo.capsfilter, RecordVideo.coder,  RecordVideo.parser,  RecordVideo.tee
                ,RecordVideo.muxer, RecordVideo.sink, RecordVideo.payloader,  RecordVideo.udpsink,  nullptr);
        if (gst_element_link_many (parent->getTee(), RecordVideo.queue, RecordVideo.convert
                ,RecordVideo.capsfilter, RecordVideo.coder,  RecordVideo.parser,  RecordVideo.tee
                , nullptr) != TRUE) {
            throw std::logic_error(std::string(__func__)+" Elements not linked");
        }
        setPointer(this);
        object->addChild("RecordTranslation", this);
    }
    catch (exception& e) { cout << e.what() << endl; }
}
VideoRecordTranslation::~VideoRecordTranslation() {
    gst_object_unref (RecordVideo.queue);
    gst_object_unref (RecordVideo.convert);
    gst_object_unref (RecordVideo.capsfilter);
    gst_object_unref (RecordVideo.coder);
    gst_object_unref (RecordVideo.parser);
    gst_object_unref (RecordVideo.tee);
    gst_object_unref (RecordVideo.muxer);
    gst_object_unref (RecordVideo.sink);
    gst_object_unref (RecordVideo.payloader);
    gst_object_unref (RecordVideo.udpsink);
}

bool VideoRecordTranslation::startRecord(void){
    if(isRecording()){return true;}
    if(savePath==""){ return true;}
    if(!(parent->isEnabled())){ return true;}
    if(gst_element_link_many (RecordVideo.tee,RecordVideo.muxer,RecordVideo.sink, nullptr)!= TRUE){return false;}
    return true;
}
bool VideoRecordTranslation::stopRecord(void){
    if(!isRecording()){return true;}
   gst_element_unlink_many (RecordVideo.tee,RecordVideo.muxer,RecordVideo.sink, nullptr);
    RecStatus=false;
    return false;
}
bool VideoRecordTranslation::startTranslation(void){
    if(isTranslating()){return true;}
    if(ip==""){ return true;}
    if(!(parent->isEnabled())){ return true;}
    if(gst_element_link_many (RecordVideo.tee,RecordVideo.payloader,RecordVideo.udpsink, nullptr)!= TRUE){return true;}
    return false;
}
bool VideoRecordTranslation::stopTranslation(void){
    if(!isTranslating()){return true;}
    gst_element_link_many (RecordVideo.tee,RecordVideo.payloader,RecordVideo.udpsink, nullptr);
    return false;
}

bool VideoRecordTranslation::isRecording(void){ return RecStatus; }
bool VideoRecordTranslation::isTranslating(void){return TranslateStatus;}


bool VideoRecordTranslation::setSize(unsigned int kBytes){
    if((kBytes<500000)||(kBytes>10000000)){return true;}
    g_object_set (RecordVideo.sink, "max-file-size", kBytes*1000, nullptr);
    return false;
}
bool VideoRecordTranslation::setName(unsigned int model){
    if((model>5)){return true;}
    name_model=model;
    return false;
}
bool VideoRecordTranslation::setQuality(unsigned int quantParam){
    if((quantParam<1)||(quantParam>51)){return true;}
    g_object_set (RecordVideo.coder, "quant-param", quantParam, nullptr);
    return false;
}
bool VideoRecordTranslation::setIP(std::string lip){
    ip=lip;
    g_object_set (RecordVideo.udpsink, "host", ip, nullptr);
    return false;
}
bool VideoRecordTranslation::setPort(unsigned int lport){
    port=lport;
    g_object_set (RecordVideo.udpsink, "port", port, nullptr);
    return false;
}
bool VideoRecordTranslation::setPath(std::string path){
    if (path.size()==0){return true;}
    if(isRecording()){return true;}
    savePath=path;
    return false;
}





