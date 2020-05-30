//
// Created by eleps on 12.04.19.
//

#ifndef VIDEOFILES_VIDEOAPPINTERFACE_H
#define VIDEOFILES_VIDEOAPPINTERFACE_H

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
using namespace std;

class VideoAppInterface {
private:
    unsigned int frames_shown=0;
    std::thread *t1,*t2;
    bool living=true;

public:
    unsigned int fps=0;
    virtual ~VideoAppInterface()=0;
    virtual GstElement* getTee(void)=0;
    virtual GstPad* getPad(void)=0;
    virtual GstElement* getPipeline(void)=0;
    virtual void setPointer(VideoAppInterface *object) = 0;
    VideoAppInterface* getPointer(void);
    VideoInterface * getChild(std::string name);
    bool addChild(std::string name, VideoInterface *l_object);
    bool removeChild(std::string name, VideoInterface *l_object);
protected:
    std::map<std::string,VideoInterface*> childs;
    unsigned char stop_status=0x00;
    VideoAppInterface* pointer;
    virtual void cb_message2 (     )= 0;
    virtual bool setState(GstState new_state)=0;
    virtual GstState getState(void)=0;
    void fpsCleanThread(VideoAppInterface *thing);
    void busThread(VideoAppInterface *thing);
    bool getStatus();
    void setStatus(bool value);
    void addFrame();
    unsigned int checkFps(void);
    void cleanFps(void);
    static void cb_message (            GstBus          *bus,GstMessage      *message,gpointer _gstData);
    static void cb_push (gpointer _gstData);
};


#endif //VIDEOFILES_VIDEOAPPINTERFACE_H
