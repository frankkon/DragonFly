
// MainFrm.h : CMainFrame ��Ľӿ�
//

#pragma once

#include "type.h"


class CMainFrame : public CFrameWndEx
{
	
protected: // �������л�����
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL LoadFrame(UINT nIDResource, DWORD dwDefaultStyle = WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, CWnd* pParentWnd = NULL, CCreateContext* pContext = NULL);

// ʵ��
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // �ؼ���Ƕ���Ա
	CMFCMenuBar       m_wndMenuBar;
	//CMFCToolBar       m_wndToolBar;
	//CMFCStatusBar     m_wndStatusBar;
	//CMFCToolBarImages m_UserImages;

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnViewCustomize();
	//afx_msg LRESULT OnToolbarCreateNew(WPARAM wp, LPARAM lp);
    afx_msg LRESULT OnResetMenu(WPARAM,LPARAM); 
    afx_msg void OnMenuClicked(UINT nID);
	DECLARE_MESSAGE_MAP()

private:
    void InitMenu(void);
    void ClearMenu(void);
    void LoadMenuInfo(void);
    void LoadMenuInfoFromDB(void);
    bool LoadModule(int iMenuCmd);

private:
    TRESULT m_vMenu;

};


