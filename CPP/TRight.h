// TRight.h: interface for the TRight class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRIGHT_H__17F1DEC2_0276_11D3_BAAA_9351D16FF824__INCLUDED_)
#define AFX_TRIGHT_H__17F1DEC2_0276_11D3_BAAA_9351D16FF824__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TSide.h"

class TRight : public TSide  
{
public:
	TRight(HDC *hDC,TBoard *Game);
	virtual ~TRight();
	virtual int Check(HDC *hDC,int forbid);
	virtual void PrintScore(HDC *hDC);
	void SelectColor(HDC *hDC,int forbid);
	virtual void Animation(HDC *hDC);
};

#endif // !defined(AFX_TRIGHT_H__17F1DEC2_0276_11D3_BAAA_9351D16FF824__INCLUDED_)
