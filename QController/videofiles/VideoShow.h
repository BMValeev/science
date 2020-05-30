//
// Created by eleps on 14.03.19.
//

#ifndef GSTREAMER_VIDEOSHOW_H
#define GSTREAMER_VIDEOSHOW_H
#include "VideoApp.h"
#include "VideoInterface.h"
typedef struct _ShowVideoStruct
{
    GstElement  *queue_tv,      *sink_tv;
} ShowVideoStruct;


class VideoShow : public VideoInterface
{
private:
    ShowVideoStruct ShowVideo;
public:
    VideoShow(VideoApp* object);
    ~VideoShow();
protected:
};
#endif //GSTREAMER_VIDEOSHOW_H
