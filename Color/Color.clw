; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMainFrame
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Color.h"
LastPage=0

ClassCount=6
Class1=CColorApp
Class2=CColorDoc
Class3=CColorView
Class4=CMainFrame

ResourceCount=3
Resource1=IDR_MAINFRAME
Resource2=IDD_ABOUTBOX
Class5=CAboutDlg
Class6=COptDlg
Resource3=IDD_OPTDIALOG

[CLS:CColorApp]
Type=0
HeaderFile=Color.h
ImplementationFile=Color.cpp
Filter=N

[CLS:CColorDoc]
Type=0
HeaderFile=ColorDoc.h
ImplementationFile=ColorDoc.cpp
Filter=N

[CLS:CColorView]
Type=0
HeaderFile=ColorView.h
ImplementationFile=ColorView.cpp
Filter=C


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_FILE_OPTIONS




[CLS:CAboutDlg]
Type=0
HeaderFile=Color.cpp
ImplementationFile=Color.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_MYICON,static,1342177283
Control2=IDOK,button,1342373889
Control3=IDC_STATIC,static,1342177408
Control4=IDC_STATIC,static,1342308352

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPTIONS
Command3=ID_APP_EXIT
Command4=ID_APP_ABOUT
CommandCount=4

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
CommandCount=13

[DLG:IDD_OPTDIALOG]
Type=1
Class=COptDlg
ControlCount=5
Control1=IDC_STATIC,button,1342177287
Control2=IDC_HUMAN,button,1342373897
Control3=IDC_COMPUTER,button,1342242825
Control4=IDC_OK,button,1342242817
Control5=IDC_CANCEL,button,1342242816

[CLS:COptDlg]
Type=0
HeaderFile=OptDlg.h
ImplementationFile=OptDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=COptDlg
VirtualFilter=dWC

