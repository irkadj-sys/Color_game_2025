// TLeft.cpp: implementation of the TLeft class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TLeft.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

TLeft::TLeft(HDC *hDC,TBoard *Game)
{
	hGame = Game;
	playerCode = 64;

	rectCol.left= WIDTH/4 - RECT_S*2;
	rectCol.top = HEIGHT-93;
	rectCol.right = rectCol.left + RECT_S/2;
	rectCol.bottom = rectCol.top + RECT_S/2 ;

	rect.left = rectCol.left - RECT_S/4;
	rect.top = rectCol.top - RECT_S/4;
	rect.right = rectCol.right + RECT_S/4;
	rect.bottom = rectCol.bottom + RECT_S/4 ;

	SColor = hGame->GetCell(hGame->GetH()-1,0) - 1;
	hGame->SetCell(hGame->GetH()-1,0,playerCode);
	Score = 1;
	Check(hDC, 0);
	SColor = 0;
	Change(hDC,0);
}

TLeft::~TLeft()
{

}

int TLeft::Check(HDC *hDC,int forbid)
{
	int i, j, ii;
	bool backi, backj;
	if( SColor != FieldColor-1 && SColor != forbid-1)
		FieldColor = SColor + 1;
	else return 0;
	i = hGame->GetH() - 1;
	while( i >= 0)
	{  backi = false;
		j = 0;
		while( j < hGame->GetW() )
		{  backj = false;
			ii = i-1+(2*(j%2));
			if( hGame->GetCell(i,j) & playerCode )
			{  DrawRomb(hDC,i,j, FieldColor - 1);
				if( ii >= 0 &&  ii < hGame->GetH())
				{	if( j+1 < hGame->GetW() )
						if( hGame->GetCell(ii,j+1) == FieldColor )
						{	hGame->SetCell(ii, j+1, playerCode);
							Score++;
							if( ii > i ) backi = true;}
					if( j-1 >=0 )
						if( hGame->GetCell(ii,j-1) == FieldColor )
						{	hGame->SetCell(ii,j-1, playerCode);
							Score++;
							backj = true;
							if( ii > i ) backi = true; }
				}
				if( j + 1 < hGame->GetW() )
					if( hGame->GetCell(i,j+1) == FieldColor )
					{	hGame->SetCell(i,j+1, playerCode);
						Score++; }
						if( j - 1 >=0 )
				if( hGame->GetCell(i, j-1) == FieldColor )
					{	hGame->SetCell(i, j-1, playerCode);
						Score++;
						backj = true; }
				hGame->ResetCell(i,j, playerCode + FieldColor);
			}
			if( !backj ) j++;
			else if( j ) j--;
		}
		if( !backi ) i--;
		else if ( i < hGame->GetH()-1 ) i++;
	}
	PrintScore(hDC);
	if (Score > (hGame->GetW() * hGame->GetH() - hGame->GetW()/2)/2 )
	{ 	Animation(hDC);
		return  -1;	}
	else return  1;
}

void TLeft::PrintScore(HDC *hDC)
{
	char temp[10];
	SetTextColor( *hDC, RGB (255,255,255) );
	SetBkColor( *hDC, RGB (0,0,0) );
	wsprintf(temp, "%d%s", Score, "    ");
	TextOut( *hDC, WIDTH/4 - RECT_S, HEIGHT-70, temp, strlen(temp));

}

void  TLeft::Animation(HDC *hDC)
{
	int i,j;
	for(j = 0; j < hGame->GetW(); j++)
		for(i = hGame->GetH()-1; i >=0; i--)
			if( hGame->GetCell(i, j) )
			{	DrawRomb(hDC,i,j, FieldColor-1);
				hGame->ResetCell(i, j, FieldColor);
			}
}

