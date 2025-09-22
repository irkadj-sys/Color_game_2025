// TGameWin.cpp: implementation of the TGameWindow class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TGameWindow.h"

//#define RAND_MAX 0x0005

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

TGameWindow::TGameWindow(HDC *hDC)
{
	int i, j;
	for(i = 0; i < H; i++)
		for(j = 0; j < W; j++)
		{
//			board[i][j] = rand() + 1;
			if( i == H - 1 && j%2) board[i][j] = 0;
		}
	Left = new TLeft(hDC);
	Right = new TRight(hDC);
	gameState = gsGameL;
}

TGameWindow::~TGameWindow()
{
	delete Left;
	delete Right;
}

void TGameWindow::DrawField(HDC *hDC)
{
	Left->Panel(hDC);
	Right->Panel(hDC);
	Left->PaintField(hDC);
	if( gameState != gsGameOver )
	{
		Left->BigRect(hDC);
		Right->BigRect(hDC);
		Left->PrintScore(hDC);
		Right->PrintScore(hDC);
	}

}

