//
// Created by eleps on 14.03.19.
//

#ifndef GSTREAMER_VIDEOAPP_H
#define GSTREAMER_VIDEOAPP_H
#include <map>
#include <vector>
#include <mutex>
#include <thread>
#include <functional>
#include <iostream>
#include <gst/gst.h>
#include <gst/app/app.h>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <gtk/gtk.h>
#include <fcntl.h>
#include <sys/signal.h>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include "Names.h"
#include "VideoInterface.h"
#include "VideoAppInterface.h"
#define DEFAULT_HDMIRX	 "/sys/bus/i2c/devices/0-000f/hdmirx"
using namespace std;
typedef struct _BaseVideoStruct {
    GstElement  *pipeline,  *source,   *queue,           *tee,  *capsfilter;
    GstBus      *bus;
} BaseVideoStruct;

class VideoApp : public VideoAppInterface
{
private:
    BaseVideoStruct BaseVideo;

    bool setState(GstState new_state) override;
    GstState getState(void) override;
public:
    VideoApp();
    ~VideoApp();
    bool seeVideo(void);
    bool isEnabled(void);
    bool enableCamera(void);
    bool disableCamera(void);
    bool restartDevice(void);
    GstElement* getTee(void) override;
    GstPad* getPad(void) override;
    GstElement* getPipeline(void) override;
    void setPointer(VideoAppInterface *object) override;
    void cb_message2 (     ) override ;
protected:
};


#endif //GSTREAMER_VIDEOAPP_H
