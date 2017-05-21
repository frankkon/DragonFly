//#include "stdafx.h"
#include "vld.h"
#include "DbAgent.h"

#include "errno.h"
#include "const.h"

CDbAgent::CDbAgent(void):m_ptrConn(NULL)
{
    mysql_library_init(0, NULL, NULL);
}

CDbAgent::~CDbAgent(void)
{
    if(NULL != m_ptrConn)
    {
        mysql_close(m_ptrConn);
        m_ptrConn = NULL;
    }
    mysql_library_end();
}

int CDbAgent::ConnectToDb(const std::string& strHostName, const std::string& strDbName, 
        const std::string& strAccount, const std::string& strPassword)
{
    m_ptrConn = mysql_init(NULL);

    if(!m_ptrConn)
    {
        return INIT_FAILURE;
    }

    //Unicode转换为ASCII
    //size_t count;
    //char szHostName[NORMAL_BUF_SIZE+1] = {0};
    //char szDbName[NORMAL_BUF_SIZE+1] = {0};
    //char szAccount[NORMAL_BUF_SIZE+1] = {0};
    //char szPassword[NORMAL_BUF_SIZE+1] = {0};
    //wcstombs_s(&count, szHostName, NORMAL_BUF_SIZE, strHostName, NORMAL_BUF_SIZE);
    //wcstombs_s(&count, szDbName, NORMAL_BUF_SIZE, strDbName, NORMAL_BUF_SIZE);
    //wcstombs_s(&count, szAccount, NORMAL_BUF_SIZE, strAccount, NORMAL_BUF_SIZE);
    //wcstombs_s(&count, szPassword, NORMAL_BUF_SIZE, strPassword, NORMAL_BUF_SIZE);

    m_ptrConn = mysql_real_connect(m_ptrConn, strHostName.c_str(), strAccount.c_str(), 
        strPassword.c_str(), strDbName.c_str(), 0, NULL, 0);

    if(!m_ptrConn)
    {
        mysql_close(m_ptrConn);
        return CONNECT_FAILURE;
    }

    if(SUCCESS != mysql_set_character_set(m_ptrConn, "gbk"))
    {
        mysql_close(m_ptrConn);
        return CONNECT_FAILURE;
    }

    return CONNECT_SUCCESS;

}

int CDbAgent::Query(std::string strSQL)
{
    //Unicode转换为ASCII
    //size_t count;
    //char szSQL[MAX_BUF_SIZE+1] = {0};
    //wcstombs_s(&count, szSQL, MAX_BUF_SIZE, strSQL, MAX_BUF_SIZE);

    return mysql_real_query(m_ptrConn, strSQL.c_str(), strSQL.length());
}

int CDbAgent::getSelectResult(TCOLUMN& col, TRESULT& res)
{

    MYSQL_RES* ptrResult;
    MYSQL_ROW  row; 

    ptrResult = mysql_use_result(m_ptrConn);

    unsigned int iFieldsNum = mysql_num_fields(ptrResult);

    TROW v;
    while (row = mysql_fetch_row(ptrResult))
    {
        for(unsigned int i = 0; i < iFieldsNum; i++)
        {
            v.push_back(row[i] ? row[i] : "NULL");
        }
        res.push_back(v);
        v.clear();
    }

    MYSQL_FIELD *field;
    while((field = mysql_fetch_field(ptrResult)))
    {
        col.push_back(field->name);
    }

    mysql_free_result(ptrResult);

    return 0;
}

int CDbAgent::getSelectResultFieldName(TCOLUMN& col)
{
    MYSQL_RES* ptrResult = mysql_use_result(m_ptrConn);

    MYSQL_FIELD *field;
    while((field = mysql_fetch_field(ptrResult)))
    {
        col.push_back(field->name);
    }

    mysql_free_result(ptrResult);

    return 0;
}

unsigned long long CDbAgent::getResultCount()
{
    MYSQL_RES* ptrResult = mysql_store_result(m_ptrConn);
    unsigned long long rslt = mysql_num_rows(ptrResult);
    mysql_free_result(ptrResult);

    return rslt;
}
