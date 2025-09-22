// TLeft.h: interface for the TLeft class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TLEFT_H__17F1DEC1_0276_11D3_BAAA_9351D16FF824__INCLUDED_)
#define AFX_TLEFT_H__17F1DEC1_0276_11D3_BAAA_9351D16FF824__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TSide.h"

class TLeft : public TSide  
{
public:
	TLeft(HDC *hDC,TBoard *Game);
	virtual ~TLeft();
	virtual int Check(HDC *hDC,int forbid);
	virtual void PrintScore(HDC *hDC);
	virtual void Animation(HDC *hDC);

};

#endif // !defined(AFX_TLEFT_H__17F1DEC1_0276_11D3_BAAA_9351D16FF824__INCLUDED_)
