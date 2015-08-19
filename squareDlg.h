// squareDlg.h : header file
//

#if !defined(AFX_SQUAREDLG_H__F8F8627E_100C_4577_84B1_DC315B0C5D78__INCLUDED_)
#define AFX_SQUAREDLG_H__F8F8627E_100C_4577_84B1_DC315B0C5D78__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "GameBox.h"
#include "DlgGameOver.h"	// Added by ClassView
/////////////////////////////////////////////////////////////////////////////
// CSquareDlg dialog
#define WM_TIME_MSG WM_USER+1


class CSquareDlg : public CDialog
{
// Construction
public:
	CSquareDlg(CWnd* pParent = NULL);	// standard constructor
public:
	//DlgGameOver* DGameOver;
	void ReStart();
	void SetScore();
	int gameStatus;
	int status;
	 
	void KeyProc(int iKey);
	 
	 
	GameBox gb;
// Dialog Data
	//{{AFX_DATA(CSquareDlg)
	enum { IDD = IDD_SQUARE_DIALOG };
	int		m_score;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSquareDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSquareDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(WPARAM wParam, LPARAM lParam);
	 
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void ShowNext();
	void DrawLines(RECT rt, int fuck=0);
	void ClearDraw();
	void ReDraw();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SQUAREDLG_H__F8F8627E_100C_4577_84B1_DC315B0C5D78__INCLUDED_)
