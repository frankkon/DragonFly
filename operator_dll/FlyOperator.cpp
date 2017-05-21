// FlyOperator.cpp : 实现文件
//

#include "stdafx.h"
#include "operator_dll.h"
#include "FlyOperator.h"


// CFlyOperator 对话框

IMPLEMENT_DYNAMIC(CFlyOperator, CDialog)

CFlyOperator::CFlyOperator(CWnd* pParent /*=NULL*/)
	: CDialog(CFlyOperator::IDD, pParent)
{

}

CFlyOperator::~CFlyOperator()
{
}

void CFlyOperator::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CFlyOperator, CDialog)
END_MESSAGE_MAP()


// CFlyOperator 消息处理程序
