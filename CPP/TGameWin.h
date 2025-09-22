// TGameWin.h: interface for the TGameWin class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TGAMEWIN_H__A08C9361_0974_11D3_BAAA_C77B22941B25__INCLUDED_)
#define AFX_TGAMEWIN_H__A08C9361_0974_11D3_BAAA_C77B22941B25__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TLeft.h"
#include "TRight.h"
#include "TBoard.h"

class TGameWin  
{
enum GameState { gsGameOver,         // game over, wait for newgame command
				  gsGameL,
				  gsGameR};     
	GameState gameState;
	TLeft     *Left;
	TRight    *Right;
    TBoard    *Game;
	static const int H;
	static const int W;

 public:
	void CheckKey(HDC *hDC, int key, bool Human);
    void DrawField(HDC *hDC);
	TGameWin(HDC *hDC);
	virtual ~TGameWin();

};

#endif // !defined(AFX_TGAMEWIN_H__A08C9361_0974_11D3_BAAA_C77B22941B25__INCLUDED_)
