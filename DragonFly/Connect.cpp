#include "stdafx.h"
#include "vld.h"
#include "Connect.h"
#include "tinyxml.h"

CConnect* CConnect::conn = NULL;

CConnect::CConnect(void) : m_sHostname(""),
                           m_sDatabase(""),
                           m_sAccount(""),
                           m_sPassword("")
{
}

CConnect::~CConnect(void)
{
}

CConnect* CConnect::getConnect(void)
{
    if(NULL == conn)
    {
        conn = new CConnect();
        if(NULL != conn)
        {
            conn->loadConnectInfo();
        }
    }

    return conn;
}

void CConnect::destory()
{
    if(NULL != conn)
    {
        delete conn;
        conn = NULL;
    }
}

void CConnect::loadConnectInfo()
{
    TiXmlDocument doc("connect.xml");
    if(doc.LoadFile())
    {
        TiXmlElement* root = doc.RootElement();
        TiXmlNode* child = root->FirstChild();
        m_sHostname = child->ToElement()->GetText(); 


        child = root->IterateChildren(child); 
        m_sDatabase = child->ToElement()->GetText(); 

        child = root->IterateChildren(child); 
        m_sAccount = child->ToElement()->GetText(); 

        child = root->IterateChildren(child); 
        m_sPassword = child->ToElement()->GetText(); 
    }
    else
    {
    }
}

std::string CConnect::getHostname(void)
{
    return m_sHostname;
}

std::string CConnect::getDatabase(void)
{
    return m_sDatabase;
}

std::string CConnect::getAccount(void)
{
    return m_sAccount;
}

std::string CConnect::getPassword(void)
{
    return m_sPassword;
}

