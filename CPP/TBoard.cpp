// TBoard.cpp: implementation of the TBoard class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TBoard.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

TBoard::TBoard(const int Ht, const int Wt)
{
	int i, j;
//	srand(3);
    bHt = Ht;
    bWt = Wt;
	board = new int* [Ht];

	for(i = 0; i < Ht; i++)
	{
		board[i] = new int [Wt];
		for(j = 0; j < Wt; j++)
		{
			board[i][j] = 5.0 * rand() / RAND_MAX + 1;
			if( i == Ht - 1 && j%2) board[i][j] = 0;
		}
	}
}

TBoard::~TBoard()
{
	for(int i = 0; i < bHt; i++)
		delete[] board[i];
	delete[] board;
}

int TBoard::GetCell(int i, int j)
{
	return board[i][j];
}

int TBoard::SetCell(int i, int j, int playerCD)
{
	board[i][j] += playerCD;
	return board[i][j];
}

int TBoard::ResetCell(int i, int j, int cell)
{
	board[i][j] = cell;
	return board[i][j];
}
