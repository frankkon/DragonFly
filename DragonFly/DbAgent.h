#pragma once

#include "mysql.h"
#include "type.h"

class CDbAgent
{
private:

    //MySQL数据库的连接句柄
    MYSQL* m_ptrConn;

public:
    CDbAgent(void);
    ~CDbAgent(void);
    
public:
    int ConnectToDb(const std::string& strHostName, const std::string& strDbName, 
        const std::string& strAccount, const std::string& strPassword);

    int Query(std::string strSQL);
    int getSelectResult(TCOLUMN& col, TRESULT& res );
    int getSelectResultFieldName(TCOLUMN& col);
    unsigned long long getResultCount();
    //int getARow();
    //int getAField();
};

