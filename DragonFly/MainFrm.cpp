
// MainFrm.cpp : CMainFrame 类的实现
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

    //菜单命令处理
    ON_COMMAND_RANGE(MENU_COMMAND_BEGIN, MENU_COMMAND_END, &CMainFrame::OnMenuClicked)
END_MESSAGE_MAP()

//static UINT indicators[] =
//{
//	ID_SEPARATOR,           // 状态行指示器
//	ID_INDICATOR_CAPS,
//	ID_INDICATOR_NUM,
//	ID_INDICATOR_SCRL,
//};

// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO: 在此添加成员初始化代码
}

CMainFrame::~CMainFrame()
{
    //销毁数据库连接信息单态对象
    CConnect::destory();
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWndEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	//BOOL bNameValid;

	if (!m_wndMenuBar.Create(this))
	{
		TRACE0("未能创建菜单栏\n");
		return -1;      // 未能创建
	}

	m_wndMenuBar.SetPaneStyle(m_wndMenuBar.GetPaneStyle() | CBRS_SIZE_DYNAMIC | CBRS_TOOLTIPS | CBRS_FLYBY);

    //初始化菜单
    InitMenu();

	// 防止菜单栏在激活时获得焦点
	CMFCPopupMenu::SetForceMenuFocus(FALSE);

	//if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
	//	!m_wndToolBar.LoadToolBar(theApp.m_bHiColorIcons ? IDR_MAINFRAME_256 : IDR_MAINFRAME))
	//{
	//	TRACE0("未能创建工具栏\n");
	//	return -1;      // 未能创建
	//}

	//CString strToolBarName;
	//bNameValid = strToolBarName.LoadString(IDS_TOOLBAR_STANDARD);
	//ASSERT(bNameValid);
	//m_wndToolBar.SetWindowText(strToolBarName);

	//CString strCustomize;
	//bNameValid = strCustomize.LoadString(IDS_TOOLBAR_CUSTOMIZE);
	//ASSERT(bNameValid);
	//m_wndToolBar.EnableCustomizeButton(TRUE, ID_VIEW_CUSTOMIZE, strCustomize);

	// 允许用户定义的工具栏操作:
	//InitUserToolbars(NULL, uiFirstUserToolBarId, uiLastUserToolBarId);

	//if (!m_wndStatusBar.Create(this))
	//{
	//	TRACE0("未能创建状态栏\n");
	//	return -1;      // 未能创建
	//}
	//m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: 如果您不希望工具栏和菜单栏可停靠，请删除这五行
	m_wndMenuBar.EnableDocking(CBRS_ALIGN_ANY);
	//m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockPane(&m_wndMenuBar);
	//DockPane(&m_wndToolBar);


	// 启用 Visual Studio 2005 样式停靠窗口行为
	CDockingManager::SetDockingMode(DT_SMART);
	// 启用 Visual Studio 2005 样式停靠窗口自动隐藏行为
	EnableAutoHidePanes(CBRS_ALIGN_ANY);

	// 启用工具栏和停靠窗口菜单替换
	//EnablePaneMenu(TRUE, ID_VIEW_CUSTOMIZE, strCustomize, ID_VIEW_TOOLBAR);

	// 启用快速(按住 Alt 拖动)工具栏自定义
	//CMFCToolBar::EnableQuickCustomization();

	//if (CMFCToolBar::GetUserImages() == NULL)
	//{
	//	// 加载用户定义的工具栏图像
	//	if (m_UserImages.Load(_T(".\\UserImages.bmp")))
	//	{
	//		m_UserImages.SetImageSize(CSize(16, 16), FALSE);
	//		CMFCToolBar::SetUserImages(&m_UserImages);
	//	}
	//}

	// 启用菜单个性化(最近使用的命令)
	// TODO: 定义您自己的基本命令，确保每个下拉菜单至少有一个基本命令。
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
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式
    m_strTitle = _T("蜻蜓-信息管理系统");
    cs.style &= ~FWS_ADDTOTITLE;

	return TRUE;
}

// CMainFrame 诊断

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


// CMainFrame 消息处理程序

void CMainFrame::OnViewCustomize()
{
	//CMFCToolBarsCustomizeDialog* pDlgCust = new CMFCToolBarsCustomizeDialog(this, TRUE /* 扫描菜单*/);
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
	// 基类将执行真正的工作

	if (!CFrameWndEx::LoadFrame(nIDResource, dwDefaultStyle, pParentWnd, pContext))
	{
		return FALSE;
	}


	// 为所有用户工具栏启用自定义按钮
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

    //删除默认菜单栏  
    if (NULL != hMenu)    
    {    
        int Menucount = ::GetMenuItemCount(hMenu);    

        //留下【帮助】菜单不删
        for (int i = 0; i < Menucount-1; ++i)    
        {    
            //每次都删除第一个菜单
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

        //菜单信息表的列
        int iID = 0;
        int iNodeType = 0;
        int iParentPos = 0;
        std::string sCaption;

        std::string sBuf;
        UINT iPos = 0; //菜单插入位置
        for(unsigned int i = 0; i < m_vMenu.size(); i++)
        {
            sBuf = m_vMenu[i][COLUMN_MENU_NODE_TYPE];
            iNodeType = atoi(sBuf.c_str());

            sBuf = m_vMenu[i][COLUMN_MENU_ID];
            iID = atoi(sBuf.c_str());

            sBuf = m_vMenu[i][COLUMN_MENU_PARENT_POS];
            iParentPos = atoi(sBuf.c_str());

            sCaption = m_vMenu[i][COLUMN_MENU_CAPTION];
            
            if(MENU_TYPE_POPUP == iNodeType) //弹出菜单
            {
                //AppendMenu( HMENU hMenu,   UINT uFlags,   UINT uIDNewItem,  LPCTSTR lpNewItem ); 
                //BOOL InsertMenu( HMENU hMenu, UINT uPosition, UINT uFlags, PTR uIDNewItem, LPCTSTR lpNewItem );
                CMenu menu;
                menu.CreateMenu();
                //::AppendMenu(hMenu, MF_POPUP, (UINT)menu.m_hMenu, sCaption.c_str()); 
                ::InsertMenu(hMenu, iPos++, MF_POPUP|MF_BYPOSITION, (UINT)menu.m_hMenu, sCaption.c_str());
                menu.Detach();
            }
            else if(MENU_TYPE_ITEM == iNodeType)//菜单项
            {
                //AppendMenu(  HMENU hMenu,   UINT uFlags,   UINT uIDNewItem,  LPCTSTR lpNewItem ); 
                //GetSubMenu(  HMENU hMenu,   int nPos ); 
                HMENU hSubMenu = ::GetSubMenu(hMenu, iParentPos);
                ::AppendMenu(hSubMenu, MF_STRING, iID, sCaption.c_str()); 
            }
            else if(MENU_TYPE_SEPERATOR == iNodeType) //分隔符
            {
                //ToDo
            }
            else
            {
                //错误处理
            }
        }
    }
    else
    {
        //错误处理
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
            //获取查询结果
            TCOLUMN col;
            m_vMenu.clear();
            agt.getSelectResult(col, m_vMenu);
        }
        else
        {
            //错误处理
        }
    }
    else
    {
        //错误处理
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
            //std::string sDllName = "加载dll:" + m_vMenu[i][COLUMN_MENU_MODULE];
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
                    AfxMessageBox("模块加载失败！");
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
                //错误处理
                AfxMessageBox("模块加载失败！");
                return false;
            }

            FreeLibrary(hDLL);
            return true;
        }
    }

    AfxMessageBox("模块加载失败！");
    return false;
}

