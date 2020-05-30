//
// Created by eleps on 14.03.19.
//

#ifndef GSTREAMER_VIDEORECORD_H
#define GSTREAMER_VIDEORECORD_H

#include "VideoApp.h"
#include "VideoInterface.h"
typedef struct _RecordVideoStruct
{
    GstElement   *convert_video;
    GstElement  *capsfilter_video;
    GstElement  *coder_video,   *muxer_video,   *sink_video,   *caps_framerate,   *framerate;
    GstElement  *queue_video,    *parser_video, *queue_video_out;
    GstPad      *pad_video;
    GstPad      *video_pad;
} RecordVideoStruct;


class VideoRecord : public VideoInterface
{
private:
    RecordVideoStruct RecordVideo;
    bool getMutex();
    void resetMutex();
    gboolean    video;
    gulong      video_probe;
    std::mutex video_mx;
    bool video_mutex=false;
    bool RecStatus=false;
    std::string savePath="";
    unsigned int name_model=0;
public:

    bool setPath(std::string path); /*Метод устанавливает путь для записи видео*/
    bool isRecording(void);/*Метод проверяет осуществляется ли сейчас запись видео этим классом*/
    bool startRecord(void);/*Метод начинает запись потока видео*/
    bool stopRecord(void);/*Метод останавливает запись потока видео*/
    bool setSize(unsigned int kBytes);
    bool setName(unsigned int model);
    bool setQuality(unsigned int quantParam);
    VideoRecord(VideoApp* object);
    ~VideoRecord();
    //Class handlers to connect
    GstPad*        c_queue_video ();
    GstPad*        c_convert_video ();
    GstPad*        c_capsfilter_video ();
    GstPad*        c_coder_video  ();
    GstPad*         c_videorate_video () ;
    GstPad*         c_rate_capsfilter_video () ;
    GstPad*        c_parser_video ();
    GstPad*        c_muxer_video ();
    GstPad*     c_queue_out_video  ( );
    void           c_sink_video  ();
    //Class handlers to remove
    GstPad*        r_video_block ();
    GstPad*        r_queue_video ();
    GstPad*        r_convert_video();
    GstPad*        r_capsfilter_video ();
    GstPad*        r_coder_video  ();
    void           r_sink_video   ( );


    //Static callbacks independent to the object
    static GstPadProbeReturn        add_sink_video (     GstPad   *pad,GstPadProbeInfo *info,gpointer _gstData);
    static GstPadProbeReturn        add_muxer_video ( GstPad *pad, GstPadProbeInfo *info,gpointer _gstData);
    static GstPadProbeReturn               add_queue_out_video ( GstPad *pad, GstPadProbeInfo *info,gpointer _gstData);
    static GstPadProbeReturn        add_parser_video (     GstPad   *pad,GstPadProbeInfo *info,gpointer _gstData);
    static GstPadProbeReturn        add_coder_video  (      GstPad   *pad,GstPadProbeInfo *info,gpointer _gstData);
    static GstPadProbeReturn add_rate_capsfilter_video (GstPad *pad,GstPadProbeInfo *info,gpointer _gstData);
    static GstPadProbeReturn add_videorate_video (GstPad *pad,GstPadProbeInfo *info,gpointer _gstData);
    static GstPadProbeReturn        add_capsfilter_video (  GstPad  *pad,GstPadProbeInfo *info,gpointer _gstData);
    static GstPadProbeReturn        add_convert_video (    GstPad   *pad,GstPadProbeInfo *info,gpointer _gstData);
    static GstPadProbeReturn        add_queue_video (      GstPad    *pad,GstPadProbeInfo *info,gpointer _gstData);

    static GstPadProbeReturn        remove_parser_video (  GstPad *pad,GstPadProbeInfo *info ,gpointer _gstData);
    static GstPadProbeReturn        remove_capsfilter_video ( GstPad  *pad,GstPadProbeInfo *info,gpointer _gstData);
    static GstPadProbeReturn        remove_coder_video  (   GstPad  *pad,GstPadProbeInfo *info,gpointer _gstData);
    static GstPadProbeReturn        remove_convert_video( GstPad  *pad,GstPadProbeInfo *info  ,gpointer _gstData);
    static GstPadProbeReturn        remove_queue_video (   GstPad *pad,GstPadProbeInfo *info,gpointer _gstData);
    static GstPadProbeReturn        remove_video_block (   GstPad *pad,GstPadProbeInfo *info,gpointer _gstData);
protected:
};
#endif //GSTREAMER_VIDEORECORD_H
