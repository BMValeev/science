//
// Created by eleps on 14.03.19.
//

#ifndef GSTREAMER_VIDEOINTERFACE_H
#define GSTREAMER_VIDEOINTERFACE_H
#include <gst/gst.h>
#include <gst/app/app.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <mutex>
#include <thread>
#include <functional>
#include <iostream>
#define Log(x) cout<<__func__<<" "<<x<<endl;

class VideoApp;
class VideoInterface
{
private:
public:
    virtual ~VideoInterface() = 0;
    void setPointer(VideoInterface *object);
    VideoInterface* getPointer(void);
    VideoApp* parent;
    VideoInterface* pointer;
protected:

};
#endif //GSTREAMER_VIDEOINTERFACE_H
