
// 8puzzle.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMy8puzzleApp:
// See 8puzzle.cpp for the implementation of this class
//

class CMy8puzzleApp : public CWinApp
{
public:
	CMy8puzzleApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMy8puzzleApp theApp;