#pragma once

// CFlyProjectDlg �Ի���

class CFlyProjectDlg : public CDialog
{
	DECLARE_DYNAMIC(CFlyProjectDlg)

public:
	CFlyProjectDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CFlyProjectDlg();

// �Ի�������
	enum { IDD = IDD_PROJECT_MANAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

    CToolBar m_wndToolBar;

	DECLARE_MESSAGE_MAP()
public:
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void ButtonSaveClick();
    afx_msg void ButtonNewClick();
    afx_msg void ButtonPrevClick();
    afx_msg void ButtonNextClick();
    afx_msg void ButtonDelClick();
    afx_msg void ButtonSerchClick();
    afx_msg void ButtonExitClick();

protected:
    virtual void OnCancel();
    virtual void OnOK();
};
