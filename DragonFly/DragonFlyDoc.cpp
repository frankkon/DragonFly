
// DragonFlyDoc.cpp : CDragonFlyDoc ���ʵ��
//

#include "stdafx.h"
#include "vld.h"
#include "DragonFly.h"

#include "DragonFlyDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDragonFlyDoc

IMPLEMENT_DYNCREATE(CDragonFlyDoc, CDocument)

BEGIN_MESSAGE_MAP(CDragonFlyDoc, CDocument)
END_MESSAGE_MAP()


// CDragonFlyDoc ����/����

CDragonFlyDoc::CDragonFlyDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CDragonFlyDoc::~CDragonFlyDoc()
{
}

BOOL CDragonFlyDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CDragonFlyDoc ���л�

void CDragonFlyDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// CDragonFlyDoc ���

#ifdef _DEBUG
void CDragonFlyDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDragonFlyDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDragonFlyDoc ����
