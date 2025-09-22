// TGameWindow.h: interface for the TGameWindow class.
//
//////////////////////////////////////////////////////////////////////
#include "TLeft.h"
#include "TRight.h"

#if !defined(AFX_TGAMEWINDOW_H__F0D07EE1_019F_11D3_BAAA_444553540000__INCLUDED_)
#define AFX_TGAMEWINDOW_H__F0D07EE1_019F_11D3_BAAA_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class TGameWindow  
{
 enum GameState { gsGameOver,         // game over, wait for newgame command
				  gsGameL,
				  gsGameR};     
	GameState gameState;
	TLeft     *Left;
	TRight    *Right;

 public:
    void DrawField(HDC *hDC);
	TGameWindow(HDC *hDC);
	virtual ~TGameWindow();

};

#endif // !defined(AFX_TGAMEWINDOW_H__F0D07EE1_019F_11D3_BAAA_444553540000__INCLUDED_)

