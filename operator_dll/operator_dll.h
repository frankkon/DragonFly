// operator_dll.h : operator_dll DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Coperator_dllApp
// �йش���ʵ�ֵ���Ϣ������� operator_dll.cpp
//

class Coperator_dllApp : public CWinApp
{
public:
	Coperator_dllApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
