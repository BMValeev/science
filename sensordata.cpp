//
// Created by eleps on 16.01.20.
//

#include "sensordata.h"
#include <iostream>
#include <unistd.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <unistd.h>
#include <fcntl.h>
#include <cstring>
#include <chrono>
#include <sys/ioctl.h>
sensordata::sensordata() :
        size(1024),m_index(0)        {
    values.reserve(size);
    for (unsigned int j(0); j < size; j++) {        values.append(10000000);    }
    //configure(0x20,0x10);
}
void sensordata::reconfigure(){configure(0xff,0x10);}
void sensordata::configure(unsigned int val,unsigned int CHFIN) {
    std::vector<uint8_t> data,received;
    //gst_init (&argc, &argv);
    I2C &i2c = I2C::getInstance();
    i2c.begin("/dev/i2c-2");
    data.push_back(0x1c);
    data.push_back(0x80);
    data.push_back(0x00);
    i2c.transaction(0x2B<<1,data,0);
    data.clear();
    data.push_back(0x1a); //FDC2214_CONFIG
    data.push_back(0x1c);//should be right
    data.push_back(0x81);//should be right
    //data.push_back(0xC1);//should be right
    i2c.transaction(0x2B<<1,data,0);
    data.clear();
    data.push_back(0x08);
    data.push_back((uint8_t) val);////////FDC2214_RCOUNT_CH0//0x02
   // data.push_back(0x20);////////FDC2214_RCOUNT_CH0//0x02
    //data.push_back(0x10);////////FDC2214_RCOUNT_CH0//0x02
    data.push_back(0xff);
    i2c.transaction(0x2B<<1,data,0);
    data.clear();
    data.push_back(0x0c);
    data.push_back(0x00);////////F//DC2214_OFFSET_CH0=0
    data.push_back(0x00);
    i2c.transaction(0x2B<<1,data,0);
    data.clear();
    data.push_back(0x10);
    data.push_back(0x00);//////////FDC2214_SETTLECOUNT_CH0
    data.push_back(0x20);
    i2c.transaction(0x2B<<1,data,0);
    data.clear();
    data.push_back(0x14);
    data.push_back(CHFIN);///////////////FDC2214_CLOCK_DIVIDERS_CH0
    data.push_back(0x01);
    i2c.transaction(0x2B<<1,data,0);
    data.clear();
    data.push_back(0x1e);
    data.push_back(0xf8);//FDC2214_DRIVE_CH0
    data.push_back(0x00);
    i2c.transaction(0x2B<<1,data,0);
    data.clear();
    data.push_back(0x19);
    data.push_back(0x08);//errors should be right
    data.push_back(0x00);
    i2c.transaction(0x2B<<1,data,0);
    data.clear();
    data.push_back(0x1b);
    data.push_back(0x02);//should work only on channel0
    data.push_back(0x0d);//FDC2214_MUX_CONFIG
    i2c.transaction(0x2B<<1,data,0);
    data.clear();
    data.push_back(0x1c);
    //data.push_back(0x06); //gain=16
    data.push_back(0x04); //gain=16
    data.push_back(0x00);
    i2c.transaction(0x2B<<1,data,0);
    data.clear();
}
void sensordata::renewData(){
    //std::cout<<__func__<<std::endl;
    return;
    unsigned int temp=0,temp_msb=0;
    float d_old=0.0;
    auto t1=std::chrono::system_clock::now();
    double dur;
    std::vector<uint8_t> data,received2,received,data1;
    I2C &i2c = I2C::getInstance();
    i2c.begin("/dev/i2c-2");
    data.push_back(0x00);
    data1.push_back(0x01);
    i2c.transaction(0x2B<<1,data,2);
    received=i2c.recData();
    i2c.transaction(0x2B<<1,data1,2);
    received2=i2c.recData();
    //received.push_back(0x00);
    //received.push_back(0x00);
    //received2.push_back(0x00);
    //received2.push_back(0x00);
    i2c_rdwr_ioctl_data message_1,message_0,message_2;
    memset(&message_1, 0, sizeof(message_1));
    memset(&message_0, 0, sizeof(message_0));
    memset(&message_2, 0, sizeof(message_2));
    i2c_msg message_packet_2[1];
    i2c_msg message_packet_1[2];
    i2c_msg message_packet_0[2];
    memset(&message_packet_2, 0, sizeof(i2c_msg)*1);
    memset(&message_packet_1, 0, sizeof(i2c_msg)*2);
    memset(&message_packet_0, 0, sizeof(i2c_msg)*2);
    message_2.msgs = message_packet_2;
    message_1.msgs = message_packet_1;
    message_0.msgs = message_packet_0;
    message_2.nmsgs = 1;
    message_1.nmsgs = 2;
    message_0.nmsgs = 2;
    message_packet_2[0].addr = 0x2B;
    message_packet_2[0].flags = I2C_M_RD; // I2C_M_RD|I2C_M_RECV_LEN;I2C_M_NOSTART
    message_packet_2[0].buf = received2.data();
    message_packet_2[0].len = static_cast<uint16_t>(2);

    message_packet_1[0].addr = 0x2B;
    message_packet_1[0].flags = 0; // I2C_M_RD|I2C_M_RECV_LEN;I2C_M_NOSTART
    message_packet_1[0].buf = data1.data();
    message_packet_1[0].len = static_cast<uint16_t>(data1.size());
    message_packet_1[1].addr = 0x2B;
    message_packet_1[1].flags = I2C_M_RD; // I2C_M_RD|I2C_M_RECV_LEN;I2C_M_NOSTART
    message_packet_1[1].buf = received2.data();
    message_packet_1[1].len = static_cast<uint16_t>(2);

    message_packet_0[0].addr = 0x2B;
    message_packet_0[0].flags = 0; // I2C_M_RD|I2C_M_RECV_LEN;I2C_M_NOSTART
    message_packet_0[0].buf = data.data();
    message_packet_0[0].len = static_cast<uint16_t>(data.size());
    message_packet_0[1].addr = 0x2B;
    message_packet_0[1].flags = I2C_M_RD; // I2C_M_RD|I2C_M_RECV_LEN;I2C_M_NOSTART
    message_packet_0[1].buf = received.data();
    message_packet_0[1].len = static_cast<uint16_t>(2);

    int file = open("/dev/i2c-2", O_RDWR);
    if (file == -1) {
        std::cout<<"ERROR"<< std::endl;
        close(file);
    }
    if (ioctl(file, I2C_SLAVE, 0x2B) < 0) {
        std::cout<<"ERROR"<< std::endl;
        close(file);
    }
    if(ioctl(file, I2C_RDWR, &message_0)<=0){std::cout<<"error0"<< std::endl;}
    if(ioctl(file, I2C_RDWR, &message_1)<=0){std::cout<<"error1"<< std::endl;}
    temp_msb=(received.at(0)*256+received.at(1))*256*256;
    temp=received2.at(0)*256  + received2.at(1);
    d_old=temp;
    while(true){
        for(m_index=0;m_index<size;m_index++){
            t1=std::chrono::system_clock::now();
            if(ioctl(file, I2C_RDWR, &message_2)<=0){values[m_index] = 300;continue;}
            temp=received2.at(0)*256  + received2.at(1);
            if((std::abs(d_old-static_cast<float>(temp))/static_cast<float>(temp))>0.4){
                if(ioctl(file, I2C_RDWR, &message_0)<=0){values[m_index] = 300;continue;}
                if(ioctl(file, I2C_RDWR, &message_1)<=0){values[m_index] = 300;continue;}
                temp_msb=(received.at(0)*256+received.at(1))*256*256;
                //std::cout<<"loop2: "<<temp_msb<< std::endl;
                d_old=temp;
                values[m_index] =  temp_msb+temp;
            }
            else{
                d_old=temp;
                values[m_index] =  temp_msb+temp;
            }
            time*=eps1;
            dur=std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now()-t1).count()/1000;
            if (dur>=2000){QThread::usleep(2000);}
            else{QThread::usleep(2000-static_cast<unsigned int>(dur));}
            dur=eps*std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now()-t1).count();
            time+=dur;
        }
    }
}
/*i2c_rdwr_ioctl_data message;
memset(&message, 0, sizeof(message));
i2c_msg message_packet[1];
memset(&message_packet, 0, sizeof(i2c_msg));
message.msgs = message_packet;
message.nmsgs = 1;
message_packet[0].addr = 0x2B;
message_packet[0].flags = I2C_M_RD; // I2C_M_RD|I2C_M_RECV_LEN;I2C_M_NOSTART
message_packet[0].buf = received.data();
message_packet[0].len = static_cast<uint16_t>(4);
int file = open("/dev/i2c-2", O_RDWR);
if (file == -1) {
    close(file);
}
if (ioctl(file, I2C_SLAVE, 0x2B) < 0) {
    close(file);
}
while(true) {
   /// if (false){
    if (ioctl(file, I2C_RDWR, &message)>0){
        unsigned int d = (received.at(0) * 256 + received.at(1));
        std::cout<<received.size()<< std::endl;
        std::cout<<received.at(1)<< std::endl;
        //std::cout<<received.at(2)<< std::endl;
        //std::cout<<received.at(3)<< std::endl;
        values[m_index] = 4096 - d;
    }
    else{
        values[m_index] = 300;
        //usleep(100);
    }
    QThread::usleep(5000ata );
    m_index=(m_index+1)%size;
    //
}
close(file);*/
/*if(OK_I2C==i2c.transaction_add(0x2B<<1,2)) {
    received=i2c.recData();
    unsigned int d=(received.at(0)*256+received.at(1));
    values[m_index]=4096-d;
}*/
//else{            values.append(0);        }