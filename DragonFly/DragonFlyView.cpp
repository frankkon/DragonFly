
// DragonFlyView.cpp : CDragonFlyView ���ʵ��
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

// CDragonFlyView ����/����

CDragonFlyView::CDragonFlyView()
{
	// TODO: �ڴ˴���ӹ������

}

CDragonFlyView::~CDragonFlyView()
{
}

BOOL CDragonFlyView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ
	return CView::PreCreateWindow(cs);
}

// CDragonFlyView ����

void CDragonFlyView::OnDraw(CDC* pDC)
{
	CDragonFlyDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
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


// CDragonFlyView ���

#ifdef _DEBUG
void CDragonFlyView::AssertValid() const
{
	CView::AssertValid();
}

void CDragonFlyView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDragonFlyDoc* CDragonFlyView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDragonFlyDoc)));
	return (CDragonFlyDoc*)m_pDocument;
}
#endif //_DEBUG


// CDragonFlyView ��Ϣ�������
