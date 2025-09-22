// TBoard.h: interface for the TBoard class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TBOARD_H__3919D7A1_0A51_11D3_BAAA_444553540000__INCLUDED_)
#define AFX_TBOARD_H__3919D7A1_0A51_11D3_BAAA_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class TBoard  
{
    int **board;
	int bHt;
	int bWt;

public:
	int SetCell(int i, int j, int playerCD);
	int ResetCell(int i, int j, int cell);
	int GetCell(int i, int j);
	TBoard(const int Ht, const int Wt);
	virtual ~TBoard();
	int GetH() { return bHt;}
    int GetW() { return bWt;}
};

#endif // !defined(AFX_TBOARD_H__3919D7A1_0A51_11D3_BAAA_444553540000__INCLUDED_)
