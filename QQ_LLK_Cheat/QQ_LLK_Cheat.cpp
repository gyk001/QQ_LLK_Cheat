// QQ_LLK_Cheat.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "QQ_LLK_Cheat.h"
#include "QQ_LLK_CheatDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CQQ_LLK_CheatApp

BEGIN_MESSAGE_MAP(CQQ_LLK_CheatApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CQQ_LLK_CheatApp ����

CQQ_LLK_CheatApp::CQQ_LLK_CheatApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CQQ_LLK_CheatApp ����

CQQ_LLK_CheatApp theApp;


// CQQ_LLK_CheatApp ��ʼ��

BOOL CQQ_LLK_CheatApp::InitInstance()
{
	CWinApp::InitInstance();

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	CQQ_LLK_CheatDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˴����ô����ʱ�á�ȷ�������ر�
		//  �Ի���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ�á�ȡ�������ر�
		//  �Ի���Ĵ���
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}
