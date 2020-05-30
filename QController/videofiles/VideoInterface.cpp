//
// Created by eleps on 14.03.19.
//

#include "VideoInterface.h"
#include "VideoApp.h"
VideoInterface::~VideoInterface(){}
void VideoInterface::setPointer(VideoInterface *object){ pointer=object; }
VideoInterface* VideoInterface::getPointer(void){return pointer; }