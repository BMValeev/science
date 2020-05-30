//
// Created by eleps on 14.03.19.
//

#ifndef GSTREAMER_VIDEOSNAPSHOT_H
#define GSTREAMER_VIDEOSNAPSHOT_H
#include "VideoApp.h"
#include "VideoInterface.h"
typedef struct _SnapshotVideoStruct : public VideoInterface
{
    GstElement  *queue_sn,      *convert_sn,    *appsink_sn;
    GstPad           *pad_sn;
    GstPad          *sn_pad;
} SnapshotVideoStruct;


class VideoSnapshot : public VideoInterface
{
private:
    SnapshotVideoStruct SnapshotVideo;
    gulong          sn_probe;
    gboolean     sn;
    std::mutex  photo_mx;
    std::string savePath="";
    unsigned int name_model=0;
public:
    bool setPath(std::string path); /*Метод устанавливает путь для записи*/
    VideoSnapshot(VideoApp* object);
    ~VideoSnapshot();
    void addTest(void *user_data);
    void lockPhoto(void);
    void unlockPhoto(void);
    bool makeSnapshot(void);
    bool setName(unsigned int model);
    static GstPadProbeReturn        add_photo (              GstPad          *pad, GstPadProbeInfo *info,gpointer _gstData );
protected:
};
#endif //GSTREAMER_VIDEOSNAPSHOT_H
