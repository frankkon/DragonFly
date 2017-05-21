#pragma once


// CLogin 对话框

class CLogin : public CDialog
{
	DECLARE_DYNAMIC(CLogin)

public:
	CLogin(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CLogin();

// 对话框数据
	enum { IDD = IDD_LOGIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
    CString m_sAccount;
    CString m_sPassword;
protected:
    virtual void OnCancel();
    virtual void OnOK();
public:
    afx_msg void OnBnClickedOk();
    afx_msg void OnBnClickedCancel();
};
