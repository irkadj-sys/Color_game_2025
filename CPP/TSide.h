// TSide.h: interface for the TSide class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TSIDE_H__21A5E381_00A5_11D3_BAAA_B8DC600E1F25__INCLUDED_)
#define AFX_TSIDE_H__21A5E381_00A5_11D3_BAAA_B8DC600E1F25__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TBoard.h"

class TSide  
{
protected:
//	TClientDC *dc;
	int 	SColor, FieldColor;
	RECT rect, rectCol;
	int Score;
	TBoard *hGame;
    HPEN Pen, OldPen;
	HBRUSH Br, OldBr;
	int playerCode; 
    static const COLORREF Color[5][4];

    static const int Romb[100];

public:
	void BigRect(HDC *hDC);
	void Panel(HDC *hDC);
	void Change(HDC *hDC, int delta );
	void DrawRomb(HDC *hDC, int i, int j, int color);
	void PaintField(HDC *hDC);
	TSide() { 	  }
	virtual ~TSide()   { }

    int  NowColor() { return FieldColor; }
	virtual int Check(HDC *hDC,int forbid)=0;
	virtual void PrintScore(HDC *hDC)=0;
	virtual void Animation(HDC *hDC)=0;

};

#endif // !defined(AFX_TSIDE_H__21A5E381_00A5_11D3_BAAA_B8DC600E1F25__INCLUDED_)
