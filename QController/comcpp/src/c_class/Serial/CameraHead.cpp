//
// Created by eleps on 09.07.19.
//

#include "CameraHead.h"
#include <iostream>
CameraHead::CameraHead(std::string path){
    try{
        object=new Serial(path.c_str());
        if (object==nullptr){
            throw std::logic_error(std::string(__func__)+"Serial is not initalized");
        }
    }
    catch (exception& e) { cout << e.what() << endl; }
}
CameraHead::~CameraHead(){

}
CameraHead::PressedButtons CameraHead::getButtons(){
    vector<uint8_t> data;
    object->ReceiveArray(&data);
    return parse(&data);
}
CameraHead::PressedButtons CameraHead::parse(vector<uint8_t> *data){
    CameraHead::PressedButtons response;
    if(data->size()==0){return ERROR_PRESSED;}
    switch(data->at(0)){
        case 0:response=NOT_PRESSED; break;
        case 1:response=LEFT_PRESSED; break;
        case 2:response=RIGHT_PRESSED; break;
        default:response=ERROR_PRESSED; break;
    }
    return response;
}