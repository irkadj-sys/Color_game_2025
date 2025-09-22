// TRight.cpp: implementation of the TRight class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TRight.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

TRight::TRight(HDC *hDC,TBoard *Game)
{
	hGame = Game;
	playerCode = 128;

	rectCol.left= 3*WIDTH/4 - RECT_S*2;
	rectCol.top = HEIGHT-93;
	rectCol.right = rectCol.left + RECT_S/2;
	rectCol.bottom = rectCol.top + RECT_S/2 ;

	rect.left = rectCol.left - RECT_S/4;
	rect.top = rectCol.top - RECT_S/4;
	rect.right = rectCol.right + RECT_S/4;
	rect.bottom = rectCol.bottom + RECT_S/4 ;

	SColor = hGame->GetCell(0,hGame->GetW()-1)-1;
	hGame->SetCell(0, hGame->GetW()-1, playerCode);
	Score = 1;
	Check(hDC, 0);
	SColor = 0;
	Change(hDC,0);
}

TRight::~TRight()
{

}
int TRight::Check(HDC *hDC,int forbid)
{
	int i, j, ii;
	bool backi, backj;
	if( SColor != FieldColor-1 && SColor != forbid-1 )
		FieldColor = SColor + 1;
	else return 0;
	i = 0;
	while( i < hGame->GetH())
	{  backi = false;
		j = hGame->GetW() - 1;
		while( j >=0 )
		{  backj = false;
			ii = i-1+(2*(j%2));
			if( hGame->GetCell(i,j) & playerCode )
			{  DrawRomb(hDC, i, j, FieldColor - 1);
				if( ii >= 0 &&  ii < hGame->GetH())
				{	if( j+1 < hGame->GetW() )
						if( hGame->GetCell(ii,j+1) == FieldColor )
						{	hGame->SetCell(ii,j+1, playerCode);
							Score++;
							if( ii < i ) backi = true;
							backj = true; }
					if( j-1 >=0 )
						if( hGame->GetCell(ii,j-1) == FieldColor )
						{  hGame->SetCell(ii,j-1, playerCode);
							Score++;
							if( ii < i ) backi = true;}
				}
				if( j + 1 < hGame->GetW() )
					if( hGame->GetCell(i,j+1) == FieldColor )
					{	hGame->SetCell(i,j+1, playerCode);
						Score++;
						backj = true; }
				if( j - 1 >=0 )
					if( hGame->GetCell(i,j-1) == FieldColor )
					{	hGame->SetCell(i,j-1, playerCode);
						Score++; }
				hGame->ResetCell(i,j, playerCode + FieldColor);
			}
			if( !backj ) j--;
			else if( j < hGame->GetW()-2 ) j++;
		}
		if( !backi ) i++;
		else if ( i ) i--;
	}
	PrintScore(hDC);
	if (Score > (hGame->GetW() * hGame->GetH() - hGame->GetW()/2)/2 )
	{	Animation(hDC);
		return  -1;}
	else  return 1;
}

void TRight::PrintScore(HDC *hDC)
{
	char temp[10];
	SetTextColor( *hDC, RGB(255,255,255 ));
	SetBkColor( *hDC, RGB(0,0,0) );
	wsprintf(temp, "%d%s", Score, "    ");
	TextOut(*hDC,  3*WIDTH/4 - RECT_S, HEIGHT-70, temp, strlen(temp));
}

void TRight::SelectColor(HDC *hDC,int forbid)
{
	int j = hGame->GetW()-1;
	int i = 0;
	while( hGame->GetCell(i, j) & playerCode )
	{ 	i = i + (j%2);
		j--;	}
	if ( i<hGame->GetH()-1 && (!(hGame->GetCell(i, j) & playerCode/2 )) && hGame->GetCell(i, j) != forbid )
	{
	Change(hDC,(SColor>hGame->GetCell(i, j))?(SColor-hGame->GetCell(i, j)-1):(hGame->GetCell(i, j)-SColor-1));
		SColor = hGame->GetCell(i, j) - 1;
	}
	else Change(hDC,1);
}

void TRight::Animation(HDC *hDC)
{
	int i,j;
	for(j = hGame->GetW()-1; j >=0; j--)
		for(i = 0; i < hGame->GetH(); i++)
			if( hGame->GetCell(i, j) )
				DrawRomb(hDC,i, j, FieldColor-1);
}