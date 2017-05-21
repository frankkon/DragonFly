
// MainFrm.cpp : CMainFrame ���ʵ��
//

#include "stdafx.h"
#include "vld.h"
#include "DragonFly.h"

#include "MainFrm.h"
#include "Connect.h"
#include "DbAgent.h"
#include "errno.h"
#include "const.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWndEx)

//const int  iMaxUserToolbars = 10;
//const UINT uiFirstUserToolBarId = AFX_IDW_CONTROLBAR_FIRST + 40;
//const UINT uiLastUserToolBarId = uiFirstUserToolBarId + iMaxUserToolbars - 1;

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWndEx)
	ON_WM_CREATE()
	ON_COMMAND(ID_VIEW_CUSTOMIZE, &CMainFrame::OnViewCustomize)
	//ON_REGISTERED_MESSAGE(AFX_WM_CREATETOOLBAR, &CMainFrame::OnToolbarCreateNew)
    ON_REGISTERED_MESSAGE(AFX_WM_RESETMENU,&CMainFrame::OnResetMenu)

    //�˵������
    ON_COMMAND_RANGE(MENU_COMMAND_BEGIN, MENU_COMMAND_END, &CMainFrame::OnMenuClicked)
END_MESSAGE_MAP()

//static UINT indicators[] =
//{
//	ID_SEPARATOR,           // ״̬��ָʾ��
//	ID_INDICATOR_CAPS,
//	ID_INDICATOR_NUM,
//	ID_INDICATOR_SCRL,
//};

// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	// TODO: �ڴ���ӳ�Ա��ʼ������
}

CMainFrame::~CMainFrame()
{
    //�������ݿ�������Ϣ��̬����
    CConnect::destory();
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWndEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	//BOOL bNameValid;

	if (!m_wndMenuBar.Create(this))
	{
		TRACE0("δ�ܴ����˵���\n");
		return -1;      // δ�ܴ���
	}

	m_wndMenuBar.SetPaneStyle(m_wndMenuBar.GetPaneStyle() | CBRS_SIZE_DYNAMIC | CBRS_TOOLTIPS | CBRS_FLYBY);

    //��ʼ���˵�
    InitMenu();

	// ��ֹ�˵����ڼ���ʱ��ý���
	CMFCPopupMenu::SetForceMenuFocus(FALSE);

	//if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
	//	!m_wndToolBar.LoadToolBar(theApp.m_bHiColorIcons ? IDR_MAINFRAME_256 : IDR_MAINFRAME))
	//{
	//	TRACE0("δ�ܴ���������\n");
	//	return -1;      // δ�ܴ���
	//}

	//CString strToolBarName;
	//bNameValid = strToolBarName.LoadString(IDS_TOOLBAR_STANDARD);
	//ASSERT(bNameValid);
	//m_wndToolBar.SetWindowText(strToolBarName);

	//CString strCustomize;
	//bNameValid = strCustomize.LoadString(IDS_TOOLBAR_CUSTOMIZE);
	//ASSERT(bNameValid);
	//m_wndToolBar.EnableCustomizeButton(TRUE, ID_VIEW_CUSTOMIZE, strCustomize);

	// �����û�����Ĺ���������:
	//InitUserToolbars(NULL, uiFirstUserToolBarId, uiLastUserToolBarId);

	//if (!m_wndStatusBar.Create(this))
	//{
	//	TRACE0("δ�ܴ���״̬��\n");
	//	return -1;      // δ�ܴ���
	//}
	//m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: �������ϣ���������Ͳ˵�����ͣ������ɾ��������
	m_wndMenuBar.EnableDocking(CBRS_ALIGN_ANY);
	//m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockPane(&m_wndMenuBar);
	//DockPane(&m_wndToolBar);


	// ���� Visual Studio 2005 ��ʽͣ��������Ϊ
	CDockingManager::SetDockingMode(DT_SMART);
	// ���� Visual Studio 2005 ��ʽͣ�������Զ�������Ϊ
	EnableAutoHidePanes(CBRS_ALIGN_ANY);

	// ���ù�������ͣ�����ڲ˵��滻
	//EnablePaneMenu(TRUE, ID_VIEW_CUSTOMIZE, strCustomize, ID_VIEW_TOOLBAR);

	// ���ÿ���(��ס Alt �϶�)�������Զ���
	//CMFCToolBar::EnableQuickCustomization();

	//if (CMFCToolBar::GetUserImages() == NULL)
	//{
	//	// �����û�����Ĺ�����ͼ��
	//	if (m_UserImages.Load(_T(".\\UserImages.bmp")))
	//	{
	//		m_UserImages.SetImageSize(CSize(16, 16), FALSE);
	//		CMFCToolBar::SetUserImages(&m_UserImages);
	//	}
	//}

	// ���ò˵����Ի�(���ʹ�õ�����)
	// TODO: �������Լ��Ļ������ȷ��ÿ�������˵�������һ���������
	//CList<UINT, UINT> lstBasicCommands;

	//lstBasicCommands.AddTail(ID_FILE_NEW);
	//lstBasicCommands.AddTail(ID_FILE_OPEN);
	//lstBasicCommands.AddTail(ID_FILE_SAVE);
	//lstBasicCommands.AddTail(ID_FILE_PRINT);
	//lstBasicCommands.AddTail(ID_APP_EXIT);
	//lstBasicCommands.AddTail(ID_EDIT_CUT);
	//lstBasicCommands.AddTail(ID_EDIT_PASTE);
	//lstBasicCommands.AddTail(ID_EDIT_UNDO);
	//lstBasicCommands.AddTail(ID_APP_ABOUT);
	//lstBasicCommands.AddTail(ID_VIEW_STATUS_BAR);
	//lstBasicCommands.AddTail(ID_VIEW_TOOLBAR);

	//CMFCToolBar::SetBasicCommands(lstBasicCommands);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWndEx::PreCreateWindow(cs) )
		return FALSE;
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ
    m_strTitle = _T("����-��Ϣ����ϵͳ");
    cs.style &= ~FWS_ADDTOTITLE;

	return TRUE;
}

// CMainFrame ���

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWndEx::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWndEx::Dump(dc);
}
#endif //_DEBUG


// CMainFrame ��Ϣ�������

void CMainFrame::OnViewCustomize()
{
	//CMFCToolBarsCustomizeDialog* pDlgCust = new CMFCToolBarsCustomizeDialog(this, TRUE /* ɨ��˵�*/);
	//pDlgCust->EnableUserDefinedToolbars();
	//pDlgCust->Create();
}

//LRESULT CMainFrame::OnToolbarCreateNew(WPARAM wp,LPARAM lp)
//{
//	LRESULT lres = CFrameWndEx::OnToolbarCreateNew(wp,lp);
//	if (lres == 0)
//	{
//		return 0;
//	}
//
//	CMFCToolBar* pUserToolbar = (CMFCToolBar*)lres;
//	ASSERT_VALID(pUserToolbar);
//
//	BOOL bNameValid;
//	CString strCustomize;
//	bNameValid = strCustomize.LoadString(IDS_TOOLBAR_CUSTOMIZE);
//	ASSERT(bNameValid);
//
//	pUserToolbar->EnableCustomizeButton(TRUE, ID_VIEW_CUSTOMIZE, strCustomize);
//	return lres;
//}

BOOL CMainFrame::LoadFrame(UINT nIDResource, DWORD dwDefaultStyle, CWnd* pParentWnd, CCreateContext* pContext) 
{
	// ���ཫִ�������Ĺ���

	if (!CFrameWndEx::LoadFrame(nIDResource, dwDefaultStyle, pParentWnd, pContext))
	{
		return FALSE;
	}


	// Ϊ�����û������������Զ��尴ť
	//BOOL bNameValid;
	//CString strCustomize;
	//bNameValid = strCustomize.LoadString(IDS_TOOLBAR_CUSTOMIZE);
	//ASSERT(bNameValid);

	//for (int i = 0; i < iMaxUserToolbars; i ++)
	//{
	//	CMFCToolBar* pUserToolbar = GetUserToolBarByIndex(i);
	//	if (pUserToolbar != NULL)
	//	{
	//		pUserToolbar->EnableCustomizeButton(TRUE, ID_VIEW_CUSTOMIZE, strCustomize);
	//	}
	//}

	return TRUE;
}

LRESULT CMainFrame::OnResetMenu(WPARAM,LPARAM)  
{  
    InitMenu();  
    return 0;  
}

void CMainFrame::InitMenu(void)
{
    ClearMenu();
    LoadMenuInfo();
}

void CMainFrame::ClearMenu(void)
{
    HMENU hMenu = m_wndMenuBar.GetDefaultMenu();  

    //ɾ��Ĭ�ϲ˵���  
    if (NULL != hMenu)    
    {    
        int Menucount = ::GetMenuItemCount(hMenu);    

        //���¡��������˵���ɾ
        for (int i = 0; i < Menucount-1; ++i)    
        {    
            //ÿ�ζ�ɾ����һ���˵�
            ::DeleteMenu(hMenu, 0, MF_BYPOSITION);    
        }          
    }  
}

void CMainFrame::LoadMenuInfo(void)
{
    LoadMenuInfoFromDB();
    if(!m_vMenu.empty())
    {
        HMENU hMenu = m_wndMenuBar.GetDefaultMenu(); 

        //�˵���Ϣ�����
        int iID = 0;
        int iNodeType = 0;
        int iParentPos = 0;
        std::string sCaption;

        std::string sBuf;
        UINT iPos = 0; //�˵�����λ��
        for(unsigned int i = 0; i < m_vMenu.size(); i++)
        {
            sBuf = m_vMenu[i][COLUMN_MENU_NODE_TYPE];
            iNodeType = atoi(sBuf.c_str());

            sBuf = m_vMenu[i][COLUMN_MENU_ID];
            iID = atoi(sBuf.c_str());

            sBuf = m_vMenu[i][COLUMN_MENU_PARENT_POS];
            iParentPos = atoi(sBuf.c_str());

            sCaption = m_vMenu[i][COLUMN_MENU_CAPTION];
            
            if(MENU_TYPE_POPUP == iNodeType) //�����˵�
            {
                //AppendMenu( HMENU hMenu,   UINT uFlags,   UINT uIDNewItem,  LPCTSTR lpNewItem ); 
                //BOOL InsertMenu( HMENU hMenu, UINT uPosition, UINT uFlags, PTR uIDNewItem, LPCTSTR lpNewItem );
                CMenu menu;
                menu.CreateMenu();
                //::AppendMenu(hMenu, MF_POPUP, (UINT)menu.m_hMenu, sCaption.c_str()); 
                ::InsertMenu(hMenu, iPos++, MF_POPUP|MF_BYPOSITION, (UINT)menu.m_hMenu, sCaption.c_str());
                menu.Detach();
            }
            else if(MENU_TYPE_ITEM == iNodeType)//�˵���
            {
                //AppendMenu(  HMENU hMenu,   UINT uFlags,   UINT uIDNewItem,  LPCTSTR lpNewItem ); 
                //GetSubMenu(  HMENU hMenu,   int nPos ); 
                HMENU hSubMenu = ::GetSubMenu(hMenu, iParentPos);
                ::AppendMenu(hSubMenu, MF_STRING, iID, sCaption.c_str()); 
            }
            else if(MENU_TYPE_SEPERATOR == iNodeType) //�ָ���
            {
                //ToDo
            }
            else
            {
                //������
            }
        }
    }
    else
    {
        //������
    }
}

void CMainFrame::LoadMenuInfoFromDB(void)
{
    CDbAgent agt;
    
    if(CONNECT_SUCCESS == agt.ConnectToDb(CConnect::getConnect()->getHostname(),
                                          CConnect::getConnect()->getDatabase(), 
                                          CConnect::getConnect()->getAccount(), 
                                          CConnect::getConnect()->getPassword()))
    {
        std::string sSQL = "select * from tbl_sys_menu order by menu_id;";
        if(QUERY_SUCCESS == agt.Query(sSQL))
        {
            //��ȡ��ѯ���
            TCOLUMN col;
            m_vMenu.clear();
            agt.getSelectResult(col, m_vMenu);
        }
        else
        {
            //������
        }
    }
    else
    {
        //������
    }
}

void CMainFrame::OnMenuClicked(UINT nID)
{
    LoadModule(nID);
}

bool CMainFrame::LoadModule(int iMenuCmd)
{
    int iID = 0;
    std::string sBuf;

    for(unsigned int i = 0; i < m_vMenu.size(); i++)
    {
        sBuf = m_vMenu[i][COLUMN_MENU_ID];
        iID = atoi(sBuf.c_str());

        if( iID == iMenuCmd)
        {
            //std::string sDllName = "����dll:" + m_vMenu[i][COLUMN_MENU_MODULE];
            //AfxMessageBox(sDllName.c_str());

            HINSTANCE hDLL;            
            typedef void (CALLBACK * LPFNDLLFUNC) ();
            LPFNDLLFUNC lpfnDllFunc;    

            std::string sDll = m_vMenu[i][COLUMN_MENU_MODULE] + ".dll";
            std::string sDllFun = "do_" + m_vMenu[i][COLUMN_MENU_MODULE];
            hDLL = LoadLibrary( sDll.c_str());
            if (hDLL != NULL)
            {
                lpfnDllFunc = (LPFNDLLFUNC)GetProcAddress(hDLL, sDllFun.c_str());
                if (!lpfnDllFunc)
                {
                    // handle the error
                    AfxMessageBox("ģ�����ʧ�ܣ�");
                    FreeLibrary(hDLL);
                    return false;
                }
                else
                {
                    // call the function
                    lpfnDllFunc();
                }
            }
            else
            {
                //������
                AfxMessageBox("ģ�����ʧ�ܣ�");
                return false;
            }

            FreeLibrary(hDLL);
            return true;
        }
    }

    AfxMessageBox("ģ�����ʧ�ܣ�");
    return false;
}

