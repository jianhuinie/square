; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=DlgGameOver
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "square.h"

ClassCount=4
Class1=CSquareApp
Class2=CSquareDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_SQUARE_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Class4=DlgGameOver
Resource4=IDD_DIALOG1

[CLS:CSquareApp]
Type=0
HeaderFile=square.h
ImplementationFile=square.cpp
Filter=N

[CLS:CSquareDlg]
Type=0
HeaderFile=squareDlg.h
ImplementationFile=squareDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_EDIT1

[CLS:CAboutDlg]
Type=0
HeaderFile=squareDlg.h
ImplementationFile=squareDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SQUARE_DIALOG]
Type=1
Class=CSquareDlg
ControlCount=7
Control1=IDC_STATIC,static,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT1,edit,1484849280
Control5=IDC_EDIT2,edit,1484849280
Control6=IDC_STATIC,static,1342177287
Control7=IDC_STATIC,static,1342308352

[DLG:IDD_DIALOG1]
Type=1
Class=DlgGameOver
ControlCount=2
Control1=IDC_STATIC,static,1342308352
Control2=IDC_BUTTON1,button,1342242816

[CLS:DlgGameOver]
Type=0
HeaderFile=DlgGameOver.h
ImplementationFile=DlgGameOver.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_BUTTON1

