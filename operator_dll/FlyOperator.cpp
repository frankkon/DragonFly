// FlyOperator.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "operator_dll.h"
#include "FlyOperator.h"


// CFlyOperator �Ի���

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


// CFlyOperator ��Ϣ�������
