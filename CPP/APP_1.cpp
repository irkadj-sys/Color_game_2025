// APP_1.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"
#include "TGameWin.h"

#define MAX_LOADSTRING 100

//#ifdef _DEBUG
//#define new DEBUG_NEW
//#undef THIS_FILE
//static char THIS_FILE[] = __FILE__;
//#endif

TGameWin     *hGame;
HDC                 MemDC, DC;
HBITMAP             BitmapPole;

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];								// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];								// The title bar text

struct {
	bool Computer, Human;
} Data;

// Foward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	Options(HWND, UINT, WPARAM, LPARAM);
//SIZE                BitmapSize;


int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_APP_1, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow)) 
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_APP_1);

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0)) 
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) 
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage is only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX); 

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= (WNDPROC)WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, (LPCTSTR)IDI_APP_1);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= (LPCSTR)IDC_APP_1;
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, (LPCTSTR)IDI_SMALL);

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HANDLE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPED| WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
      CW_USEDEFAULT,0, WIDTH, HEIGHT, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, unsigned, WORD, LONG)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	TCHAR szHello[MAX_LOADSTRING];
	LoadString(hInst, IDS_HELLO, szHello, MAX_LOADSTRING);

	switch (message) 
	{
		case WM_CREATE:
			Data.Computer = 1;
			BitmapPole = LoadBitmap(hInst,(LPCTSTR)IDB_POLE);
//			GetBitmapDimensionEx(BitmapPole, &BitmapSize);
			DC = GetDC(hWnd);
            hGame = new TGameWin (&DC);
			ReleaseDC (hWnd, DC);
			MemDC = CreateCompatibleDC(DC);
			break;
		case WM_COMMAND:
			wmId    = LOWORD(wParam); 
			wmEvent = HIWORD(wParam); 
			// Parse the menu selections:
			switch (wmId)
			{
				case IDM_ABOUT:
				   DialogBox(hInst, (LPCTSTR)IDD_ABOUTBOX, hWnd, (DLGPROC)About);
				   break;
				case IDM_OPTIONS:
				   DialogBox(hInst, (LPCTSTR)IDD_OPTIONS, hWnd, (DLGPROC)Options);
				   InvalidateRgn(hWnd,NULL,1);
				   break;
				case IDM_NEW:
				   delete hGame;
   			       DC = GetDC(hWnd);
				   hGame = new TGameWin (&DC);
   				   InvalidateRgn(hWnd,NULL,1);
			       ReleaseDC (hWnd, DC);
				   break;
				case IDM_EXIT:
				   delete hGame;
				   DestroyWindow(hWnd);
				   break;
				default:
				   return DefWindowProc(hWnd, message, wParam, lParam);
			}
			break;
		case WM_PAINT:
			hdc = BeginPaint(hWnd, &ps);
			// TODO: Add any drawing code here...
//			RECT rt;
//			DC = GetDC(hWnd);
//			GetClientRect(hWnd, &rt);
						
			SelectObject(MemDC,BitmapPole);
			BitBlt(hdc,0,0,580,390,MemDC,0,0,SRCCOPY);
			
			hGame->DrawField(&hdc);

//			ReleaseDC (hWnd, DC);
			EndPaint(hWnd, &ps);
			break;
		case WM_KEYDOWN:
			DC = GetDC(hWnd);
			hGame->CheckKey(&DC, (int) wParam, Data.Human);
			ReleaseDC (hWnd, DC);
 			break;
		case WM_DESTROY:
			DeleteObject(BitmapPole);
			DeleteDC(MemDC);
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
   }
   return 0;
}

// Mesage handler for about box.
LRESULT CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_INITDIALOG:
				return TRUE;

		case WM_COMMAND:
			if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) 
			{
				EndDialog(hDlg, LOWORD(wParam));
				return TRUE;
			}
			break;
	}
    return FALSE;
}

LRESULT CALLBACK Options(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_INITDIALOG:
		    if (Data.Human)
				CheckRadioButton(hDlg, IDC_HUMAN, IDC_HUMAN,  IDC_HUMAN);
			else
				CheckRadioButton(hDlg, IDC_COMPUTER, IDC_COMPUTER,  IDC_COMPUTER);
			return TRUE;

		case WM_COMMAND:
			if (LOWORD(wParam) == IDOK) 
			{
				if(IsDlgButtonChecked(hDlg,IDC_COMPUTER) == BST_CHECKED )
					{ Data.Computer = true; Data.Human = false; }
				else
					{ Data.Computer = false; Data.Human = true; }

				EndDialog(hDlg, LOWORD(wParam));
				return TRUE;				
			}
			if (LOWORD(wParam) == IDCANCEL) 
			{
				EndDialog(hDlg, LOWORD(wParam));
				return TRUE;
			}
			break;
	}
    return FALSE;
}
