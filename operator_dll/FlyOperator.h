#pragma once


// CFlyOperator �Ի���

class CFlyOperator : public CDialog
{
	DECLARE_DYNAMIC(CFlyOperator)

public:
	CFlyOperator(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CFlyOperator();

// �Ի�������
	enum { IDD = IDD_USER_MANAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
