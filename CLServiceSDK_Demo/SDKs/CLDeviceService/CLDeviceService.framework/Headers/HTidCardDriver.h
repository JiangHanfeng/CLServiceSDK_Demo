//
// Created by 马昀 on 16/6/16.
//

#ifndef ANDROID_IDCARDDRIVER_H

unsigned short ReadIDCardData(const char * uid,const char* upwd,const char *deviceid,const char *extstr,const char *serverAddr,int port, int *outlen,unsigned char outdata[]);
unsigned short Wlt2Bmp(const char * uid,const char* upwd,const char *deviceid,const char *serverAddr,int port, unsigned char wltbuf[],int *outlen,unsigned char outdata[]);

#define ANDROID_IDCARDDRIVER_H

#endif //ANDROID_IDCARDDRIVER_H
