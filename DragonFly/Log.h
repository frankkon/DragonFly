#pragma once

#include <string>
#include <fstream>

class CLog
{
private:
    std::ofstream logFile;

public:
    CLog(void);
    CLog(const char* strFilename);
    ~CLog(void);

    void openLogFile(const char* strFilename);
    void logDebug(const char* strLog);
    void logInfo(const char* strLog);
    void logWarn(const char* strLog);
    void logError(const char* strLog);

};
