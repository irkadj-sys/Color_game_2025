// TGameWin.cpp: implementation of the TGameWin class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TGameWin.h"

//#define RAND_MAX 0x0005
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

const int TGameWin::H = 25;
const int TGameWin::W = 89;

TGameWin::TGameWin(HDC *hDC)
{
    Game = new TBoard(H, W);
	Left = new TLeft(hDC, Game);
	Right = new TRight(hDC, Game);
	gameState = gsGameL;
}

TGameWin::~TGameWin()
{
	delete Left;
	delete Right;
	delete Game;
}

void TGameWin::DrawField(HDC *hDC)
{
	Left->Panel(hDC);
	Right->Panel(hDC);
	Left->PaintField(hDC);
	if( gameState != gsGameOver )
	{
		Left->BigRect(hDC);
		Right->BigRect(hDC);
	}
	Left->PrintScore(hDC);
	Right->PrintScore(hDC);

}


void TGameWin::CheckKey(HDC *hDC,int key, bool Human)
{
	int s;
	if( gameState == gsGameR )
		switch (key)
		{ // right player
		case VK_NUMPAD4:
		case VK_LEFT:
			Right->Change(hDC, -1);
			break;
		case VK_NUMPAD6:
		case VK_RIGHT:
			Right->Change(hDC,  1);
			break;
		case 0x0D:
			if ( ( s = Right->Check(hDC, Left->NowColor()) ) == -1) gameState = gsGameOver;
			else if ( s == 0) return;
			else gameState = gsGameL;
			break;
		default: return;
		}
	else if( gameState == gsGameL )
		switch (key)
		{ // left player
		case 0x5A:
			Left->Change(hDC,  -1 );
			break;
		case 0x58:
			Left->Change(hDC,  1);
			break;
		case 0x20:
			if( (s = Left->Check(hDC, Right->NowColor()) ) == -1 )
				gameState = gsGameOver;
			else if ( s == 0)
				return;
			else if( Human )
				gameState = gsGameR;
			else
			{
				int a = 0;
				while( !a )
				{
					Right->SelectColor(hDC, Left->NowColor());
					a = Right->Check(hDC, Left->NowColor() );
				}
			}
		    break;
	}
}
