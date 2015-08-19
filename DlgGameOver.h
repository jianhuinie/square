#if !defined(AFX_DLGGAMEOVER_H__347DED04_2ECA_446B_B67F_A44E8AC296AB__INCLUDED_)
#define AFX_DLGGAMEOVER_H__347DED04_2ECA_446B_B67F_A44E8AC296AB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgGameOver.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DlgGameOver dialog

class DlgGameOver : public CDialog
{
// Construction
public:
	DlgGameOver(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgGameOver)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgGameOver)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DlgGameOver)
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGGAMEOVER_H__347DED04_2ECA_446B_B67F_A44E8AC296AB__INCLUDED_)
