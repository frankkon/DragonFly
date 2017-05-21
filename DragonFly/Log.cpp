//#include "stdafx.h"
#include "vld.h"
#include "Log.h"
#include "global.h"

#include <ctime>
#include <iostream>

CLog::CLog(void)
{
}

CLog::CLog(const char* strFilename):logFile(strFilename)
{
}

CLog::~CLog(void)
{
}

void CLog::openLogFile(const char* strFilename)
{
    logFile.open(strFilename);
}

void CLog::logDebug(const char* strLog)
{
    if(logFile)
    {
        logFile<<"[DEBUG]"<<getLocalNowTime()<<strLog<<std::endl;
    }
}

void CLog::logInfo(const char* strLog)
{
    if(logFile)
    {
       logFile<<"[INFO]"<<getLocalNowTime()<<strLog<<std::endl;
    }
}

void CLog::logWarn(const char* strLog)
{
    if(logFile)
    {
        logFile<<"[WARN]"<<getLocalNowTime()<<strLog<<std::endl;
    }
}

void CLog::logError(const char* strLog)
{
    if(logFile)
    {
        logFile<<"[ERROR]"<<getLocalNowTime()<<strLog<<std::endl;
    }
}

