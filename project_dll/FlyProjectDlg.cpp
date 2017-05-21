// FlyProjectDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "project_dll.h"
#include "FlyProjectDlg.h"


// CFlyProjectDlg 对话框

IMPLEMENT_DYNAMIC(CFlyProjectDlg, CDialog)

CFlyProjectDlg::CFlyProjectDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFlyProjectDlg::IDD, pParent)
{

}

CFlyProjectDlg::~CFlyProjectDlg()
{
}

void CFlyProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFlyProjectDlg, CDialog)
    ON_WM_CREATE()
    ON_COMMAND(ID_BUTTON_SAVE,CFlyProjectDlg::ButtonSaveClick)
    ON_COMMAND(ID_BUTTON_NEW,CFlyProjectDlg::ButtonNewClick)
    ON_COMMAND(ID_BUTTON_PREV,CFlyProjectDlg::ButtonPrevClick)
    ON_COMMAND(ID_BUTTON_NEXT,CFlyProjectDlg::ButtonNextClick)
    ON_COMMAND(ID_BUTTON_DEL,CFlyProjectDlg::ButtonDelClick)
    ON_COMMAND(ID_BUTTON_SEARCH,CFlyProjectDlg::ButtonSerchClick)
    ON_COMMAND(ID_BUTTON_EXIT,CFlyProjectDlg::ButtonExitClick)
END_MESSAGE_MAP()


// CFlyProjectDlg 消息处理程序

int CFlyProjectDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CDialog::OnCreate(lpCreateStruct) == -1)
        return -1;

    if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE 
        | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) 
        ||!m_wndToolBar.LoadToolBar(IDR_TOOLBAR))
    {
		TRACE0("未能创建工具栏\n");
		return -1;      // 未能创建
    }

    //m_wndToolBar.SetSizes(CSize(40,40),CSize(32,32));
    RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_LAST,0);

    return 0;
}

void CFlyProjectDlg::OnCancel()
{
    // TODO: 在此添加专用代码和/或调用基类

    //CDialog::OnCancel();
}

void CFlyProjectDlg::OnOK()
{
    // TODO: 在此添加专用代码和/或调用基类

    //CDialog::OnOK();
}

void CFlyProjectDlg::ButtonSaveClick()
{
}

void CFlyProjectDlg::ButtonNewClick()
{
}

void CFlyProjectDlg::ButtonPrevClick()
{
}

void CFlyProjectDlg::ButtonNextClick()
{
}

void CFlyProjectDlg::ButtonDelClick()
{
}

void CFlyProjectDlg::ButtonSerchClick()
{
}

void CFlyProjectDlg::ButtonExitClick()
{
    CDialog::OnCancel();
}