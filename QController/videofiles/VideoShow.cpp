//
// Created by eleps on 14.03.19.
//
#include <gst/gst.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/statvfs.h>
#include <sys/signal.h>
#include "VideoApp.h"
#include "VideoShow.h"


VideoShow::VideoShow(VideoApp* object){
    try{
        parent=object;
        memset(&ShowVideo, 0, sizeof(ShowVideo));
        ShowVideo.queue_tv = gst_element_factory_make("queue","queue_tv");
        ShowVideo.sink_tv = gst_element_factory_make ("imxg2dvideosink", "sink_tv");
        gst_object_ref (ShowVideo.queue_tv);
        gst_object_ref (ShowVideo.sink_tv);
        if (  !ShowVideo.queue_tv  ||  !ShowVideo.sink_tv ) {throw std::logic_error(std::string(__func__)+" Elements not created"); }

        g_object_set (ShowVideo.queue_tv, "flush-on-eos", 0, nullptr);
        g_object_set (ShowVideo.queue_tv, "leaky", 2, nullptr);
        g_object_set (ShowVideo.queue_tv, "max-size-buffers", 1, nullptr);
        g_object_set (ShowVideo.sink_tv, "sync", 1, nullptr); //orig TRUE
        g_object_set (ShowVideo.sink_tv, "async", 0, nullptr);
        g_object_set (ShowVideo.sink_tv, "use-vsync", 1, nullptr);
        g_object_set (ShowVideo.sink_tv, "clear-at-null", 1, nullptr); //orig TRUE
        gst_bin_add_many (GST_BIN (parent->getPipeline()), ShowVideo.queue_tv,  ShowVideo.sink_tv,nullptr);
        if (    (gst_element_link_many (parent->getTee(), ShowVideo.queue_tv, ShowVideo.sink_tv, nullptr) != TRUE)) {
            throw std::logic_error(std::string(__func__)+" Elements not added");
        }
        setPointer(this);
        object->addChild("Show", this);
        cout<<__func__<<" Initialized successfully"<<endl;
    }
    catch (exception& e) { cout << e.what() << endl; }
}
VideoShow::~VideoShow(){

    gst_object_unref (ShowVideo.queue_tv);
    gst_object_unref (ShowVideo.sink_tv);
}
