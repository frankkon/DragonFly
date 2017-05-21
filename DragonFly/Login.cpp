// Login.cpp : 实现文件
//

#include "stdafx.h"
#include "vld.h"
#include "DragonFly.h"
#include "Login.h"
#include "Connect.h"
#include "DbAgent.h"
#include "errno.h"
#include "const.h"
#include "global.h"

#include <string>

// CLogin 对话框

IMPLEMENT_DYNAMIC(CLogin, CDialog)

CLogin::CLogin(CWnd* pParent /*=NULL*/)
	: CDialog(CLogin::IDD, pParent)
    , m_sAccount(_T(""))
    , m_sPassword(_T(""))
{

}

CLogin::~CLogin()
{
}

void CLogin::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_ACCOUNT, m_sAccount);
    DDV_MaxChars(pDX, m_sAccount, 16);
    DDX_Text(pDX, IDC_PASSWORD, m_sPassword);
	DDV_MaxChars(pDX, m_sPassword, 16);
}


BEGIN_MESSAGE_MAP(CLogin, CDialog)
    ON_BN_CLICKED(IDOK, &CLogin::OnBnClickedOk)
    ON_BN_CLICKED(IDCANCEL, &CLogin::OnBnClickedCancel)
END_MESSAGE_MAP()


// CLogin 消息处理程序

void CLogin::OnCancel()
{
    // TODO: 在此添加专用代码和/或调用基类

    //CDialog::OnCancel();
}

void CLogin::OnOK()
{
    // TODO: 在此添加专用代码和/或调用基类

    //CDialog::OnOK();
}

void CLogin::OnBnClickedOk()
{
    // TODO: 在此添加控件通知处理程序代码
    UpdateData(TRUE);
    std::string sHostname = CConnect::getConnect()->getHostname();
    std::string sDatabase = CConnect::getConnect()->getDatabase();
    std::string sAccount = CConnect::getConnect()->getAccount();
    std::string sPassword = CConnect::getConnect()->getPassword();
    CDbAgent agt;
    
    if(CONNECT_SUCCESS == agt.ConnectToDb(sHostname, sDatabase, sAccount, sPassword))
    {
        //密码转换
        char szEncodePassword[SHA512_BUF_SIZE+1] = {0};
        encryptoPassword(m_sPassword, szEncodePassword);

        std::string sSQL = "select account from tbl_account_info where account = \"" + m_sAccount
            + "\" and password = \"" + szEncodePassword + "\"";
        if(SUCCESS == agt.Query(sSQL))
        {
            if( HAVE_FOUND == agt.getResultCount())
            {
                CDialog::OnOK();
            }
            else
            {
                AfxMessageBox(_T("账号和或密码错误，请重新输入！"));
                m_sPassword = "";
                UpdateData(FALSE);
            }
        }
        else
        {
                AfxMessageBox(_T("查询账号信息失败！"));
                CDialog::OnCancel();
        }
    }
}

void CLogin::OnBnClickedCancel()
{
    // TODO: 在此添加控件通知处理程序代码
    CDialog::OnCancel();
}
