// QQ_LLK_Cheat.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CQQ_LLK_CheatApp:
// �йش����ʵ�֣������ QQ_LLK_Cheat.cpp
//

class CQQ_LLK_CheatApp : public CWinApp
{
public:
	CQQ_LLK_CheatApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CQQ_LLK_CheatApp theApp;