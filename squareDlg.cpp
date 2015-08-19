// squareDlg.cpp : implementation file
//

#include "stdafx.h"
#include "square.h"
#include "squareDlg.h"
#define sleepTime 300
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();
	 

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()



DWORD WINAPI threadProc(void *p) {
	CSquareDlg* pp = (CSquareDlg*)p;

	while (1) {
		if(pp->status==1){
		Sleep((1-(pp->m_score/3000.0))*sleepTime);//随着分数的增加下落速度也加快
		PostMessage(pp->m_hWnd, WM_TIME_MSG, 0, 0);
		}
	}
	return 0;
}
/////////////////////////////////////////////////////////////////////////////
// CSquareDlg dialog

CSquareDlg::CSquareDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSquareDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSquareDlg)
	m_score = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	gb.pf = this;
	status=0;
	gameStatus=0;
	//DGameOver=new DlgGameOver();
	CreateThread(NULL, 0, threadProc, this, 0, 0);
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSquareDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSquareDlg)
	DDX_Text(pDX, IDC_EDIT1, m_score);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSquareDlg, CDialog)
	//{{AFX_MSG_MAP(CSquareDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(WM_TIME_MSG, OnTimer) 
 
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CSquareDlg message handlers

BOOL CSquareDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSquareDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}
 


// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.
afx_msg void CSquareDlg:: OnTimer(WPARAM wParam, LPARAM lParam){
	if (gb.idNext) {
		if (gb.idNow && gb.CanDown()) {
			ClearDraw();
			gb.px++;
			ReDraw();
// 			ClearDraw();
// 			Down();
// 			ReDraw();
// 			 
			 //Invalidate(false);
			 
		}
		else
		{
			if(!gb.CanDown()&&gb.px<0){
              status=0;
			  DlgGameOver DGameOver;
			  DGameOver.DoModal();
// 			  if(!DGameOver->GetSafeHwnd()){
//                 DGameOver->Create(IDD_DIALOG1,this);
//                 DGameOver->ShowWindow(SW_SHOW);
// 			  }
			}
				else{
					gb.ClearRow();
					gb.px = -4;
					gb.py=3;
					gb.idNow = gb.idNext;
					memcpy(gb.bNow, gb.bNext, sizeof(Block) * 16);
					gb.CreateNext();
					// memcpy(gb.bNext, gb.bNow, sizeof(Block) * 16);
					ShowNext();	 
					}
		}	 
		
	} else {
		 
		gb.CreateNext();
		ShowNext();
		//Invalidate(TRUE);
	}
}
 
void CSquareDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);

	}
	else
	{
// 		   CRect rect; 
//         CPaintDC dc(this); 
//         GetClientRect(rect); 
//         dc.FillSolidRect(rect,RGB(255,255,255));  //设置背景色
		CDialog::OnPaint();
	}
 
////////////////////////////////填充小方块
// 	for(int pi=0;pi<4;pi++){
// 		for(int qi=0;qi<4;qi++){
// 			if(gb.bNext[pi][qi].isFill == 1){
//               int x1=370+30*qi ;
// 			  int y1=5+30*pi ;
// 			  int x2=x1+30 ;
// 			  int y2=y1+30 ;
// 			  CBrush brush(COL[gb.bNext[pi][qi].color]);   
//               CRect rect(x1,y1,x2,y2);  
//               dc1.FillRect(&rect,&brush); 
// 			}
// 		}
// 	}

////////////////////////////////////绘制游戏区域
      
        SetScore();
    	CClientDC dc1(this);
		for (int ii = 0; ii < 20; ii++) {
			for (int jj = 0; jj < 10; jj++) {
				if (gb.bGame[ii][jj].isFill) {
					CBrush hbr(COL[gb.bGame[ii][jj].color]);
					CRect rectij(5 + 30 * jj, 5 + 30 * ii, 35 + 30 * jj, 35 + 30 * ii);
					dc1.FillRect( &rectij, &hbr);
				}
			}
		}
			DrawLines(CRect(5, 5, 10 * 30 + 5, 605), 1);
			ShowNext();
        	DrawLines(CRect(370, 5, 490, 125), 1);
			
 //      CPen pen(PS_SOLID,1,RGB(189,200,200));
//      CPen *pOldPen=dc1.SelectObject(&pen);
//      CBrush *pBrush=CBrush::FromHandle((HBRUSH)
//      GetStockObject(NULL_BRUSH));
//      CBrush *pOldBrush=dc1.SelectObject(pBrush);
//      dc1.Rectangle(CRect(5,5,305,605));
// 	 for(int i=35;i<=600;i+=30){
//         dc1.MoveTo(5,i);
// 	    dc1.LineTo(305,i);
// 	 }
// 	 for(int j=35;j<=300;j+=30){
//         dc1.MoveTo(j,5);
// 	    dc1.LineTo(j,605);
// 	 }
// 	 dc1.Rectangle(CRect(370,5,490,125));
//      for(int m=35;m<=120;m+=30){
//         dc1.MoveTo(370,m);
// 	    dc1.LineTo(490,m);
// 	 }
// 	 for(int n=400;n<=480;n+=30){
//         dc1.MoveTo(n,5);
// 	    dc1.LineTo(n,125);
// 	 }
//      dc1.SelectObject(pOldPen);
//      dc1.SelectObject(pOldBrush);
// ////////////////////////////////
    
//     CBrush brush(COL[2]);   //填充小方块
//     CRect rect(370,5,400,35);  
//     dc1.FillRect(&rect,&brush); 
//
///////////////////重绘游戏区域的小方块	
 }

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSquareDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

template<class T>
T imax(T a, T b) {
	return a > b ? a : b;
}
template<class T>
T imin(T a, T b) {
	return a < b ? a : b;
}

void CSquareDlg::ClearDraw()
{
	CClientDC dc1(this);
	for (int ii = 0; ii < 4; ii++) {
		for (int jj = 0; jj < 4; jj++) {
			int a = gb.px + ii, b = gb.py + jj;
			if (a < 0) continue;
			if (gb.bNow[ii][jj].isFill) {
				gb.bGame[a][b].isFill = 0; 
				gb.bGame[a][b].color = 0;
				CBrush hbr(COL[gb.bGame[a][b].color]);
				CRect brickij(5 + 30 * b, 5 + 30 * a, 35 + 30 * b, 35 + 30 * a);
				FillRect(dc1, &brickij, hbr);
			}
		}
	}
	DrawLines(CRect(5 + gb.py * 30, 5 + gb.px * 30, 125 + gb.py * 30, 125 + gb.px * 30));
}


void CSquareDlg::ReDraw()
{	
	CClientDC dc1(this);
	for (int ii = 0; ii < 4; ii++) {
		for (int jj = 0; jj < 4; jj++) {
			int a = gb.px + ii, b = gb.py + jj;
			if (a < 0 || a >= 20 || b < 0 || b >= 10) continue;
			if (gb.bNow[ii][jj].isFill) {
				gb.bGame[a][b] = gb.bNow[ii][jj];
				CBrush hbr(COL[gb.bGame[a][b].color]);
				CRect rectij(5 + 30 * b, 5 + 30 * a, 35 + 30 * b, 35 + 30 * a);
				FillRect(dc1, &rectij, hbr);
			}
		}
	}
	DrawLines(CRect(5 + gb.py * 30, 5 + gb.px * 30, 125 + gb.py * 30, 125 + gb.px * 30));
	//ShowNext();
}

void CSquareDlg::DrawLines(RECT rt, int fuck)
{
	if (fuck == 0) {
		rt.left = imax<INT32>(5, rt.left);
		rt.top = imax<INT32>(5, rt.top);
		rt.right = imin<INT32>(10 * 30 + 5, rt.right);
		rt.bottom = imin<INT32>(20 * 30 + 5, rt.bottom);
	}

	CClientDC dc1(this); 
	CPen pen(PS_SOLID,1,RGB(189,200,200));
	CPen *pOldPen=dc1.SelectObject(&pen);
	CBrush *pBrush=CBrush::FromHandle((HBRUSH)
	GetStockObject(NULL_BRUSH));
	CBrush *pOldBrush=dc1.SelectObject(pBrush);
 
 	for(int i=rt.left;i<=rt.right;i+=30){
 		dc1.MoveTo(i, rt.top);
 		dc1.LineTo(i, rt.bottom);
	}
	for(int j=rt.top;j<=rt.bottom;j+=30){
		dc1.MoveTo(rt.left ,j);
		dc1.LineTo(rt.right ,j);
	}
	dc1.SelectObject(pOldPen);
	dc1.SelectObject(pOldBrush);
}

void CSquareDlg::ShowNext()
{

	CClientDC dc1(this);
	int pi, qi;
	CBrush brush(0xFFFFFF);
    CRect rect(370, 5, 490, 125);  
    dc1.FillRect(&rect, &brush); 

	for( pi=0;pi<4;pi++){
		for( qi=0;qi<4;qi++){
			if(gb.bNext[pi][qi].isFill == 1){
              int x1=370+30*qi ;
			  int y1=5+30*pi ;
			  int x2=x1+30 ;
			  int y2=y1+30 ;
			  CBrush brush(COL[gb.bNext[pi][qi].color]);   
              CRect rect(x1,y1,x2,y2);  
              dc1.FillRect(&rect,&brush); 
			}
		}
	}
	DrawLines(CRect(370, 5, 490, 125), 1);
}

 BOOL CSquareDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	switch (pMsg->message) 
	{
	case WM_KEYDOWN:
		KeyProc(pMsg->wParam);
	}
	return CDialog::PreTranslateMessage(pMsg);
}



void CSquareDlg::KeyProc(int iKey)
{
if(gameStatus==1){
	 switch(iKey){
		 case 37:
			 ClearDraw();
			 gb.MoveLeft();
			 ReDraw();
			 break;
		 case 39:
			 ClearDraw();
			 gb.MoveRight();
			 ReDraw();
			 break;
		 case 38:
			 ClearDraw();
			 gb.Rotate();
			 ReDraw();
			 break;
		 case 40:
			 	PostMessage(WM_TIME_MSG, 0, 0);
				break;
		 case 83:
			 status=1;
				 break;
		 case 80:
			 status=0;
			 break;
		 case 82:
			 ReStart();
			 break;
	 }
}
else {
	switch(iKey){
		 case ' ':
			 status=1;
			 gameStatus=1; 
			 break; 
    }
}
}

 

void CSquareDlg::SetScore()
{
  UpdateData(TRUE);
  m_score=gb.score;
  UpdateData(FALSE);
}

void CSquareDlg::ReStart()
{
 for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 10; j++) {
			gb.bGame[i][j].isFill = false;
			gb.bGame[i][j].color = 0;
		}
	}
	gb.idNow = 0;
	gb.idNext = 0;
	gb.score=0;
	status = 1;
	gameStatus=1;
	Invalidate(TRUE);
}
