
// DragonFlyDoc.cpp : CDragonFlyDoc 类的实现
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


// CDragonFlyDoc 构造/析构

CDragonFlyDoc::CDragonFlyDoc()
{
	// TODO: 在此添加一次性构造代码

}

CDragonFlyDoc::~CDragonFlyDoc()
{
}

BOOL CDragonFlyDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CDragonFlyDoc 序列化

void CDragonFlyDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}


// CDragonFlyDoc 诊断

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


// CDragonFlyDoc 命令
