#pragma once


// CFlyOperator 对话框

class CFlyOperator : public CDialog
{
	DECLARE_DYNAMIC(CFlyOperator)

public:
	CFlyOperator(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CFlyOperator();

// 对话框数据
	enum { IDD = IDD_USER_MANAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
