
// DragonFlyDoc.h : CDragonFlyDoc ��Ľӿ�
//


#pragma once


class CDragonFlyDoc : public CDocument
{
protected: // �������л�����
	CDragonFlyDoc();
	DECLARE_DYNCREATE(CDragonFlyDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CDragonFlyDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


