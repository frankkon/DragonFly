#pragma once


// CLogin �Ի���

class CLogin : public CDialog
{
	DECLARE_DYNAMIC(CLogin)

public:
	CLogin(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CLogin();

// �Ի�������
	enum { IDD = IDD_LOGIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
