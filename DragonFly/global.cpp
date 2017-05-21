//全局公共函数实现文件
//#include "stdafx.h"
#include "vld.h"

#include <ctime> 
#include <cstdio> 
#include <cstring>

#include "global.h"
#include "const.h"
#include "sha.h"
#include "hex.h"


std::string getLocalNowTime()
{
    time_t nowtime = time(0);
    struct tm _tm;
    localtime_s(&_tm, &nowtime);
    char szBuf[NORMAL_BUF_SIZE+1] = {0}; 
    strftime(szBuf, NORMAL_BUF_SIZE, "[%Y-%m-%d %X]", &_tm); 
    return szBuf;
}

void encryptoPassword(const char* inPassword, char* outEncodePassword)
{
    byte src[PASSWORD_LENGTH+1];
    memset(src, 0, sizeof(src));
    memcpy(src, inPassword, strlen(inPassword));

    byte buf[SHA512_BUF_SIZE+1];
    memset(buf, 0, sizeof(buf));

    CryptoPP::SHA512 sha;
    sha.CalculateDigest(buf, src, sizeof(src));
    CryptoPP::HexEncoder xEnc;
    xEnc.Put(buf, SHA512_BUF_SIZE);
    memset(buf, 0, sizeof(buf));
    xEnc.Get(buf, SHA512_BUF_SIZE);    
    memcpy(outEncodePassword, buf, SHA512_BUF_SIZE);

}