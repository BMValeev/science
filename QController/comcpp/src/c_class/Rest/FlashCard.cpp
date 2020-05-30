//
// Created by User on 14.01.2019.
//
#include <string.h>
#include <stdio.h>
#include <sys/mount.h>
#include <sys/stat.h>
#include <sys/statvfs.h>
#include <sys/statfs.h>
#include <linux/magic.h>
#include <mutex>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include "FlashCard.h"
using namespace std;
std::map<std::string,FlashCard*> FlashCard::Devices{};
vector<std::string> FlashCard::mountPoints{};




/*public and used by higher classh things*/
FlashCard& FlashCard::getInstance(std::string device) {
    auto it=FlashCard::Devices.find(device);
    if(it==Devices.end()){
        Devices[device]=new FlashCard(device);
        FlashCard &Device = *FlashCard::Devices.find(device)->second;
        Device.setPartition(device);
        return *FlashCard::Devices.find(device)->second;
    }
    return *FlashCard::Devices.find(device)->second;
}
bool FlashCard::isMounted(){
    //printLog(DebugLog, static_cast<std::string>(__func__) + " is " +((flash_mounted)?"Mounted":"not Mounted"));
    if(!fileExist()){
        unmountFlash();
        flash_mounted=false;
    }
    return flash_mounted;
}
bool FlashCard::checkFlashSize(float value){
    float free;
    free= getAvailableSpace(SaveFolder.c_str())/ (float) (1024*1024);
    std::cout<<" free space " <<free <<std::endl;
    return (free>value) ? true : false ;
}
bool FlashCard::mountFlash() {
    if (mountPoint==""){return true;}
    if(isMounted()){return false;}
    if(mountNtfs()==false){return false;}
    if(mountFat()==false){return false;}
    printLog(DebugLog, static_cast<std::string>(__func__) +  " error");
    return true;
}
bool FlashCard::isMountable(){
    if (mountPoint==""){return false; }
    if(flash_mounted){
        //printLog(DebugLog, static_cast<std::string>(__func__) + " is mounted");
        return true;
    }
    if(!fileExist()){
        printLog(DebugLog, static_cast<std::string>(__func__) + " no device");
        unmountFlash();
        return false;
    }
    setFS(getFS());
    if(!mountFlash()){
        printLog(DebugLog, static_cast<std::string>(__func__) + " is Mountable");
        unmountFlash();
        return true;
    }
    if(!fixFlash()){
        printLog(DebugLog, static_cast<std::string>(__func__) + " is Mountable");
        unmountFlash();
        return true;
    }
    if(!deepFixFlash()){
        printLog(DebugLog, static_cast<std::string>(__func__) + " is Mountable");
        unmountFlash();
        return true;
    }
    printLog(DebugLog, static_cast<std::string>(__func__) + " is notMountable");
    unmountFlash();
    return false;
}
bool FlashCard::begin(LogCallback cb) {
    std::lock_guard<std::mutex> lock(mBmutex); // automatically unlocks when function is leaved, no need to call unlock
    if(mInit){        return false; }
    setLogCallback(cb);
    if (!folderExist()) { createFolder();  }
    unmountFlash();
    removeFolderFiles();
    if (!fileExist()) {isMountable();  }
    status=true;
    std::thread x(&FlashCard::mountThread, this, this);
    x.detach();
    printLog(DebugLog, static_cast<std::string>(__func__) + " Initialized");
    return false;
}



bool FlashCard::setMountPoint(std::string name) {
    if (mountPoint == name){
        printLog(DebugLog, static_cast<std::string>(__func__) + "Device name is same: " + name);
        return false;
    }
    mPmutex.lock();
    if(find(FlashCard::mountPoints.begin(),FlashCard::mountPoints.end(),name)!=FlashCard::mountPoints.end()){
        printLog(DebugLog, static_cast<std::string>(__func__) + "Device name is already used by someone: " + name);
        mPmutex.unlock();
        return true;
    }
    printLog(DebugLog, static_cast<std::string>(__func__) + "Device name is set: " + name);
    FlashCard::mountPoints.push_back(mountPoint);
    mountPoint = name;
    if (!folderExist()) {
        printLog(DebugLog, static_cast<std::string>(__func__) + "Create folder: ");
        createFolder();
    }
    mPmutex.unlock();
    return false;
}
bool FlashCard::setPartition(std::string name) {
    mPmutex.lock();
    printLog(DebugLog, static_cast<std::string>(__func__) + "Device partition is set: " + name);
    Patrition = name;
    mPmutex.unlock();
    return false;
}
float FlashCard::checkFlashSize(){
    float free;
    free= getAvailableSpace(SaveFolder.c_str())/ (float) (1024*1024);
    return free ;
}



bool FlashCard::unmountFlash(){
    std::lock_guard<std::mutex> lock(flash_mx);
    printLog(DebugLog, static_cast<std::string>(__func__) );
    try{
        umount(mountPoint.c_str());
        flash_mounted=false;
        return false;
    }
    catch (const std::exception&) {return true; }
}

/*public but used for service functions*/
bool FlashCard::getStatus(){return status; }
/*Service functions*/

std::string FlashCard::getFS(){
    struct statfs stat;
    if (statfs(patrition.c_str(), &stat) != 0){ return "fat32"; }
    if ((stat.f_type==NSFS_MAGIC  ) || (stat.f_type==MSDOS_SUPER_MAGIC) )//NTFS_SB_MAGIC
    return "ntfs";
}
bool FlashCard::fileExist(){
    struct stat   buffer;
    return (stat (Patrition.c_str(), &buffer) == 0);
}
bool FlashCard::folderExist(){
    struct stat   buffer;
    return (stat (mountPoint.c_str(), &buffer) == 0);
}
float FlashCard::getAvailableSpace(const char *path){
    struct statvfs stat;
    if (statvfs(mountPoint.c_str(), &stat) != 0){ return 1000.0;}
    return ((float)  stat.f_bsize * (float) stat.f_bavail);
}
void FlashCard::createFolder(){
    if (mountPoint.size()==0){return;}
    printLog(InfoLog, static_cast<std::string>(__func__) +std::string(" ") +std::string("mkdir ")+mountPoint);
    popen((std::string("mkdir ")+mountPoint).c_str() , "r");
    return;
}
void FlashCard::removeFolderFiles(){
    FILE *fp;
    //fp = popen((std::string("rm -rf ")+mountPoint+std::string("/* 2>&1")).c_str(), "r");
    //fclose(fp);
}
bool FlashCard::setFS(std::string name) {
    if (name == "fat32"){
        fileSystem = FAT32;
        return false;
    }
    if (name == "ntfs"){
        fileSystem = NTFS;
        return false;
    }

    return true;
}
bool FlashCard::fixFlash(){
    std::lock_guard<std::mutex> lock(flash_mx);
    if (fileSystem != NTFS){  return false;}
    FILE *fp;
    char command[1000];
    memset(command, 0x00, sizeof(command));
    fp =popen(FixCommand.c_str(), "r");
    sleep(2);
    fgets(command, 1000, fp);
    //printLog(DebugLog, static_cast<std::string>(__func__) +  command);
    fclose(fp);
    return false;
}
bool FlashCard::deepFixFlash(){
    std::lock_guard<std::mutex> lock(flash_mx);
    if (fileSystem != NTFS){return false; }
    FILE *fp;
    char command[1000];
    memset(command, 0x00, sizeof(command));
    fp =popen(FixCommand.c_str(), "r");
    sleep(2);
    fgets(command, 1000, fp);
    //printLog(DebugLog, static_cast<std::string>(__func__) +  command);
    fclose(fp);
    return false;
}
bool FlashCard::mountNtfs() {
    std::lock_guard<std::mutex> lock(flash_mx);
    FILE *fp;
    printLog(DebugLog, static_cast<std::string>(__func__) +  "mounting");
    char command[1000];
    memset(command, 0x00, sizeof(command));
    fp = popen((std::string("ntfs-3g ")+Patrition+std::string(" ")+mountPoint+std::string(" ")+ConsoleOut).c_str(), "r");
    fgets(command, 1000, fp);
    fclose(fp);
    printLog(DebugLog, static_cast<std::string>(__func__) +  command);
    if (strlen(command) > 9) { return true; }
    flash_mounted=true;
    printLog(DebugLog, static_cast<std::string>(__func__) +  "mounted");
    return false;
}
bool FlashCard::mountFat() {
    std::lock_guard<std::mutex> lock(flash_mx);
    /*int fp;
    printLog(DebugLog, static_cast<std::string>(__func__) +  "mounting");
    char command[1000];
    memset(command, 0x00, sizeof(command));
    fp =mount(patrition.c_str(),mountPoint.c_str(), "vfat",0x00,nullptr);
    if (fp) {return true; }
    flash_mounted=true;
    printLog(DebugLog, static_cast<std::string>(__func__) +  "mounted");
    */
    FILE *fp;
    printLog(DebugLog, static_cast<std::string>(__func__) +  "mounting");
    char command[1000];
    memset(command, 0x00, sizeof(command));
    fp = popen((std::string("mount ")+Patrition+std::string(" ")+mountPoint+std::string(" ")+ConsoleOut).c_str(), "r");
    fgets(command, 1000, fp);
    fclose(fp);
    printLog(DebugLog, static_cast<std::string>(__func__) +  command);
    if (strlen(command) > 30) { return true; }
    flash_mounted=true;
    printLog(DebugLog, static_cast<std::string>(__func__) +  "mounted");

    return false;
}
/*Constructors//Destructors*/
FlashCard::FlashCard(std::string device)
        : Loggable () {
    printLog(DebugLog, static_cast<std::string>(__func__) + " FlashCard constructor called");
    if (FlashCard::Devices.find(device)!=Devices.end()) throw std::logic_error("Instance already exists");
    Devices[device]=this;
    setPartition(device);
    begin();
}
FlashCard::~FlashCard(){
    auto it=FlashCard::Devices.find(patrition);
    if(it!=Devices.end()){
        unmountFlash();
        Devices.erase(it);
    }
}
/*Inside threads*/
void FlashCard::mountThread(FlashCard *thing) {
    printLog(DebugLog, static_cast<std::string>(__func__) + " FlashCard thread started");
    while(thing->getStatus()){
        try{
            if(!thing->isMounted()){ thing->isMountable();}
            std::this_thread::sleep_for(5s);
        }
        catch (exception& e) {cout << e.what() << endl;}
    }
    return;
}


