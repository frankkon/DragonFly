// operator_dll.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "operator_dll.h"
#include "FlyOperator.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: ����� DLL ����� MFC DLL �Ƕ�̬���ӵģ�
//		��Ӵ� DLL �������κε���
//		MFC �ĺ������뽫 AFX_MANAGE_STATE ����ӵ�
//		�ú�������ǰ�档
//
//		����:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// �˴�Ϊ��ͨ������
//		}
//
//		�˺������κ� MFC ����
//		������ÿ��������ʮ����Ҫ������ζ��
//		��������Ϊ�����еĵ�һ�����
//		���֣������������ж������������
//		������Ϊ���ǵĹ��캯���������� MFC
//		DLL ���á�
//
//		�й�������ϸ��Ϣ��
//		����� MFC ����˵�� 33 �� 58��
//

// Coperator_dllApp

BEGIN_MESSAGE_MAP(Coperator_dllApp, CWinApp)
END_MESSAGE_MAP()


// Coperator_dllApp ����

Coperator_dllApp::Coperator_dllApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� Coperator_dllApp ����

Coperator_dllApp theApp;


// Coperator_dllApp ��ʼ��

BOOL Coperator_dllApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

extern "C" __declspec(dllexport) void do_operator()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	
    CFlyOperator dlgOperator;
    dlgOperator.DoModal();
}