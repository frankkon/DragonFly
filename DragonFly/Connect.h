#pragma once

#include <string>


class CConnect
{
public:
    static CConnect* getConnect(void);
    static void destory();

    std::string getHostname(void);
    std::string getDatabase(void);
    std::string getAccount(void);
    std::string getPassword(void);


protected:
    CConnect(void);
    ~CConnect(void);
    void loadConnectInfo();

private:
    std::string m_sHostname;
    std::string m_sDatabase;
    std::string m_sAccount;
    std::string m_sPassword;

    static CConnect* conn;
};
