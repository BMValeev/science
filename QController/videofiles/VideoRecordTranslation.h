//
// Created by eleps on 14.03.19.
//

#ifndef GSTREAMER_VIDEORECORDTRANSLATION_H
#define GSTREAMER_VIDEORECORDTRANSLATION_H

#include "VideoApp.h"
#include "VideoInterface.h"
typedef struct _RecordTranslationVideoStruct{
    GstElement   *queue, *convert,*capsfilter, *coder, *parser , *tee;
    GstElement  *muxer,*queue_out,   *sink;
    GstElement   *payloader, *udpsink;
} RecordTranslationVideoStruct;


class VideoRecordTranslation : public VideoInterface {
private:
    RecordTranslationVideoStruct RecordVideo;
    std::mutex video_mx;
    bool RecStatus;
    bool TranslateStatus;
    std::string savePath,ip;
    unsigned int name_model,port;
public:
    VideoRecordTranslation(VideoApp* object);
    ~VideoRecordTranslation();
    bool setPath(std::string path); /*Метод устанавливает путь для записи видео*/
    bool setIP(std::string ip); /*Метод устанавливает путь для записи видео*/
    bool setPort(unsigned int port); /*Метод устанавливает путь для записи видео*/
    bool isTranslating(void);/*Метод проверяет осуществляется ли сейчас запись видео этим классом*/
    bool isRecording(void);/*Метод проверяет осуществляется ли сейчас запись видео этим классом*/
    bool startRecord(void);/*Метод начинает запись потока видео*/
    bool startTranslation(void);/*Метод начинает запись потока видео*/
    bool stopRecord(void);/*Метод останавливает запись потока видео*/
    bool stopTranslation(void);/*Метод останавливает запись потока видео*/
    bool setSize(unsigned int kBytes);
    bool setName(unsigned int model);
    bool setQuality(unsigned int quantParam);

protected:
};
#endif //GSTREAMER_VIDEORECORDTRANSLATION_H
