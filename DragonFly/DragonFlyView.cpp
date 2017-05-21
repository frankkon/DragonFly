
// DragonFlyView.cpp : CDragonFlyView 类的实现
//

#include "stdafx.h"
#include "vld.h"
#include "DragonFly.h"

#include "DragonFlyDoc.h"
#include "DragonFlyView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDragonFlyView

IMPLEMENT_DYNCREATE(CDragonFlyView, CView)

BEGIN_MESSAGE_MAP(CDragonFlyView, CView)
END_MESSAGE_MAP()

// CDragonFlyView 构造/析构

CDragonFlyView::CDragonFlyView()
{
	// TODO: 在此处添加构造代码

}

CDragonFlyView::~CDragonFlyView()
{
}

BOOL CDragonFlyView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式
	return CView::PreCreateWindow(cs);
}

// CDragonFlyView 绘制

void CDragonFlyView::OnDraw(CDC* pDC)
{
	CDragonFlyDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
    CBitmap mainpic;
    mainpic.LoadBitmap(IDB_MAINPIC);
    CBrush brush(&mainpic);
    RECT clientRect;
    GetClientRect(&clientRect);
    pDC->FillRect(&clientRect, &brush);

}

//void CDragonFlyView::OnRButtonUp(UINT nFlags, CPoint point)
//{
//	ClientToScreen(&point);
//	OnContextMenu(this, point);
//}

//void CDragonFlyView::OnContextMenu(CWnd* pWnd, CPoint point)
//{
//	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
//}


// CDragonFlyView 诊断

#ifdef _DEBUG
void CDragonFlyView::AssertValid() const
{
	CView::AssertValid();
}

void CDragonFlyView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDragonFlyDoc* CDragonFlyView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDragonFlyDoc)));
	return (CDragonFlyDoc*)m_pDocument;
}
#endif //_DEBUG


// CDragonFlyView 消息处理程序
