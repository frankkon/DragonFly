
// DragonFlyView.h : CDragonFlyView ��Ľӿ�
//


#pragma once


class CDragonFlyView : public CView
{
protected: // �������л�����
	CDragonFlyView();
	DECLARE_DYNCREATE(CDragonFlyView)

// ����
public:
	CDragonFlyDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CDragonFlyView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	//afx_msg void OnFilePrintPreview();
	//afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	//afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // DragonFlyView.cpp �еĵ��԰汾
inline CDragonFlyDoc* CDragonFlyView::GetDocument() const
   { return reinterpret_cast<CDragonFlyDoc*>(m_pDocument); }
#endif

