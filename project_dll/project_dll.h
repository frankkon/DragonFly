// project_dll.h : project_dll DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Cproject_dllApp
// �йش���ʵ�ֵ���Ϣ������� project_dll.cpp
//

class Cproject_dllApp : public CWinApp
{
public:
	Cproject_dllApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
