// project_dll.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "project_dll.h"
#include "FlyProjectDlg.h"

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

// Cproject_dllApp

BEGIN_MESSAGE_MAP(Cproject_dllApp, CWinApp)
END_MESSAGE_MAP()


// Cproject_dllApp ����

Cproject_dllApp::Cproject_dllApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� Cproject_dllApp ����

Cproject_dllApp theApp;


// Cproject_dllApp ��ʼ��

BOOL Cproject_dllApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

extern "C" __declspec(dllexport) void do_project()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	
    CFlyProjectDlg dlgProject;
    dlgProject.DoModal();
}