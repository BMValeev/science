#ifndef CRC_H
#define CRC_H

class CRC
{
public:
    static unsigned char crc8(unsigned char *buffer, unsigned long len);
    static unsigned short crc16(unsigned char *buffer, unsigned long len);
    static bool crcBool(unsigned char *buffer, unsigned int len);
    static unsigned char checkSum(unsigned char *buffer, unsigned long len);
};

#endif // CRC_H
