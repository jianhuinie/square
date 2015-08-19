// square.h : main header file for the SQUARE application
//

#if !defined(AFX_SQUARE_H__5972A1D7_01BB_4112_928F_C260039E2775__INCLUDED_)
#define AFX_SQUARE_H__5972A1D7_01BB_4112_928F_C260039E2775__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSquareApp:
// See square.cpp for the implementation of this class
//

class CSquareApp : public CWinApp
{
public:
	CSquareApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSquareApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSquareApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SQUARE_H__5972A1D7_01BB_4112_928F_C260039E2775__INCLUDED_)
