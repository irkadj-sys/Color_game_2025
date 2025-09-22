// TSide.cpp: implementation of the TSide class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TSide.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

void TSide::PaintField(HDC *hDC)
{
	int i, j, color;
	int H = hGame->GetH();
	int W = hGame->GetW();
	for(i = 0; i < H; i++)
		for(j = 0; j < W; j++)
		{
			color = hGame->GetCell(i,j);
			if( color )
				DrawRomb(hDC,i,j, (color & 63)-1);
		}
}

const COLORREF TSide::Color[5][4] =
						{    {RGB( 0, 65, 246 ),  //4    //blue
								RGB( 0, 98, 255 ),  //5
								RGB( 0, 164, 255 ), //9
								RGB( 0, 0, 255 )}, //    0, 32, 255
   
								{RGB( 0, 164, 0 ),    //7   //green
								RGB( 32, 197, 65 ),   //11
							 	RGB( 32, 255, 65 ),   //
								RGB( 0, 131, 0 )},    //

								{RGB( 197, 0, 0 ),    //  //red
								RGB( 255, 32, 0 ),    //6
								RGB( 255, 131, 131 ), //
								RGB( 197, 0, 0 )},    //

								{RGB( 255, 160, 0 ),  //    //yellow
								RGB( 255, 197, 0 ),   //
								RGB( 255, 255, 102 ), //
								RGB( 197, 131, 0 )},  //

								{RGB( 255, 131, 255 ),      //fiolet
								RGB( 197, 96, 255 ),
								RGB( 255, 131, 255 ),
								RGB( 197, 96, 255 )} 
 };

const int TSide::Romb[100] =   {  0,0,0,0,1,1,0,0,0,0,
										0,0,0,1,3,2,1,0,0,0,
										0,0,1,3,3,2,2,1,0,0,
										0,1,3,3,3,2,2,2,1,0,
										1,3,3,3,3,2,2,2,2,1,
										1,2,2,2,2,4,4,4,4,1,
										0,1,2,2,2,4,4,4,1,0,
										0,0,1,2,2,4,4,1,0,0,
										0,0,0,1,2,4,1,0,0,0,
										0,0,0,0,1,1,0,0,0,0 };


void TSide::DrawRomb(HDC *hDC,int i, int j, int color)
{
	i = 20 + 6 * ( ( j%2 ) + i*2);
	j = 20 + j*6;
	int x, y;
	const int *R = Romb;
	for(x = i; x < (i+10); x++)
		for(y = j; y < (j+10); y++, R++)
			if( *R )
				SetPixel( *hDC, y,x, Color[color][ *R-1 ]);

}

void TSide::Change(HDC *hDC,int delta)
{

	HPEN ForeignPen;
	HBRUSH ForeignBr;
	
	Pen = CreatePen( PS_SOLID, 1, RGB(0,0,0) );
	ForeignPen = (HPEN) SelectObject( *hDC,  Pen );
	Br = CreateSolidBrush( RGB(0,0,0) ) ;
	ForeignBr = (HBRUSH) SelectObject( *hDC,  Br);
	Rectangle( *hDC, rect.left + SColor*16, rect.top, rect.right + SColor*16, rect.bottom);
	
	Pen = CreatePen( PS_SOLID, 1, Color[SColor][1] );
	OldPen = (HPEN) SelectObject( *hDC,  Pen );
	Br = CreateSolidBrush( Color[SColor][1] );
	OldBr = (HBRUSH) SelectObject( *hDC,  Br );
	Rectangle( *hDC, rectCol.left + SColor*16, rectCol.top, rectCol.right + SColor*16, rectCol.bottom );
	SColor += delta;
	if( SColor == NUMBER_COLORS )   SColor = 0;
	else if( SColor == -1 ) SColor = NUMBER_COLORS-1;
	
	DeleteObject (OldPen);
	DeleteObject (OldBr);
	Pen = CreatePen( PS_SOLID, 1, Color[SColor][2] );
	OldPen = (HPEN) SelectObject( *hDC, Pen );
	Br = CreateSolidBrush( Color[SColor][1] ) ;
	OldBr = (HBRUSH) SelectObject( *hDC,  Br );
	Rectangle(*hDC, rect.left + SColor*16, rect.top, rect.right + SColor*16, rect.bottom );

// Clean DC objects
	
	DeleteObject (OldPen);
	DeleteObject (OldBr);

	OldPen = (HPEN) SelectObject( *hDC,  ForeignPen );
	OldBr = (HBRUSH) SelectObject( *hDC,  ForeignBr );
	DeleteObject (OldPen);
	DeleteObject (OldBr);


}


void TSide::Panel(HDC *hDC)
{
for(int i = 0; i < NUMBER_COLORS; i++)
	{
	    Pen = CreatePen( PS_SOLID, 1, Color[i][1] );
		OldPen = (HPEN) SelectObject( *hDC,  Pen );
		Br = CreateSolidBrush(  Color[i][1] );
		OldBr = (HBRUSH) SelectObject( *hDC,  Br );
		Rectangle( *hDC, rectCol.left + i*16, rectCol.top, rectCol.right + i*16, rectCol.bottom );

// Clean DC objects
	
		SelectObject( *hDC,  OldPen );
		SelectObject( *hDC,  OldBr );
		DeleteObject (Pen);
		DeleteObject (Br);

	}

}

void TSide::BigRect(HDC *hDC)
{
	Pen = CreatePen( PS_SOLID, 1, Color[SColor][2] );
	OldPen = (HPEN) SelectObject( *hDC,  Pen );
	Br = CreateSolidBrush(  Color[SColor][1] );
	OldBr = (HBRUSH) SelectObject( *hDC,  Br );
	Rectangle( *hDC, rect.left + SColor*16, rect.top, rect.right + SColor*16, rect.bottom );

// Clean DC objects
	
	SelectObject( *hDC,  OldPen );
	SelectObject( *hDC,  OldBr );
	DeleteObject (Pen);
	DeleteObject (Br);

}

