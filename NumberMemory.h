
// NumberMemory.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CNumberMemoryApp:
// �йش����ʵ�֣������ NumberMemory.cpp
//

class CNumberMemoryApp : public CWinApp
{
public:
	CNumberMemoryApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CNumberMemoryApp theApp;