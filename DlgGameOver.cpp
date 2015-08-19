// DlgGameOver.cpp : implementation file
//

#include "stdafx.h"
#include "square.h"
#include "DlgGameOver.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgGameOver dialog


DlgGameOver::DlgGameOver(CWnd* pParent /*=NULL*/)
	: CDialog(DlgGameOver::IDD, pParent)
{
	//{{AFX_DATA_INIT(DlgGameOver)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DlgGameOver::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgGameOver)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgGameOver, CDialog)
	//{{AFX_MSG_MAP(DlgGameOver)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgGameOver message handlers

void DlgGameOver::OnButton1(){
   EndDialog(0);
} 
