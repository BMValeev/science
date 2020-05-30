//
// Created by eleps on 09.07.19.
//

#ifndef MENUCAMERAFHD_CAMERAHEAD_H
#define MENUCAMERAFHD_CAMERAHEAD_H


#include "../Rest/loggable.h"
#include "Serial.h"
typedef std::function<void(uint8_t, std::string)> LogCallback;
class CameraHead: public Loggable {
public:
    enum PressedButtons{ NOT_PRESSED, LEFT_PRESSED, RIGHT_PRESSED, ERROR_PRESSED};
    CameraHead(std::string path);
    ~CameraHead();
    CameraHead::PressedButtons getButtons(); /*0 Not pressed, 1 left pressed, 2 right pressed, 3 error*/

protected:
private:
    Serial *object;
    CameraHead::PressedButtons parse( vector<uint8_t> *data);
};


#endif //MENUCAMERAFHD_CAMERAHEAD_H
