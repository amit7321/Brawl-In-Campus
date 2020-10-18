

#ifndef DRAWGAME_H_INCLUDED
#define DRAWGAME_H_INCLUDED
#include "iGraphics.h"
#include "stb_image.h"
int CharFlag = 0;
int CharFlag2 = 0;
int g = 0, p = 0, ins = 0, ab = 0, e = 0;
int gameflag = 0;
int MM, pl, ex, abo, in, po, Point, Ins, cap, bac, ground, c1, c2, c3, c4, c5, c6, health, opphealth, bar, oppbar;
int charground, charground2;
int CharPos_x = 50, CharPos_y = 50;
int Char2Pos_x = 960, Char2Pos_y = 55;
int dx = 100;
int dy = 50;
int flag = 0;
int Oflag = 0;
int mflag = 0;
int Omflag = 0;
int healthlength = 400;
int opphealthlength = -400;
int stringindex, numberarray;
int st;
char name;
int n;

typedef struct charv charv;
struct charv{

	int i, j, k, x, y;
	charv()
	{
		;
	}
	charv(int _i, int _j, int _k, int _x, int _y)
	{

		i = _i;
		j = _j;
		k = _k;
		x = _x;
		y = _y;
	}

	int s[5];
	int punch[5];
	int pk[5];
	int pp[5];
	int M[2];

}kenVariable, IyoriVariable;
void DrawGame()
{
	iClear();
	iShowImage(0, 0, 1280, 720, ground);
	iSetColor(255, 255, 255);
	iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.s[0]);
	iShowImage(Char2Pos_x, Char2Pos_y, 150, 230, IyoriVariable.s[0]);
	if (mflag == 1)
	{
		iClear();
		iShowImage(0, 0, 1280, 720, ground);
		iSetColor(255, 255, 255);
		iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.M[0]);
		if (Oflag == 0 && Omflag == 0)
			iShowImage(Char2Pos_x, Char2Pos_y, 150, 230, IyoriVariable.s[0]);
		else if (Omflag == 1)
		{
			iShowImage(Char2Pos_x, Char2Pos_y, 200, 200, IyoriVariable.M[0]);
			Omflag = 0;
		}
		else if (Omflag == 2)
		{
			iShowImage(Char2Pos_x, Char2Pos_y, 100, 210, IyoriVariable.M[1]);
			Omflag = 0;
		}
		else if (Oflag == 1)
			iShowImage(Char2Pos_x, Char2Pos_y, 150, 230, IyoriVariable.s[IyoriVariable.i]);
		else if (Oflag == 2)
			iShowImage(Char2Pos_x, Char2Pos_y, 150, 230, IyoriVariable.punch[IyoriVariable.j]);
		else if (Oflag == 3)
			iShowImage(Char2Pos_x, Char2Pos_y, 150, 230, IyoriVariable.pp[IyoriVariable.x]);
		else if (Oflag == 4)
			iShowImage(Char2Pos_x, Char2Pos_y, 150, 230, IyoriVariable.pk[IyoriVariable.y]);


	}
	if (mflag == 2)
	{
		iClear();
		iShowImage(0, 0, 1280, 720, ground);
		iSetColor(255, 255, 255);
		iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.M[1]);
		if (Oflag == 0 && Omflag == 0)
			iShowImage(Char2Pos_x, Char2Pos_y, 150, 230, IyoriVariable.s[0]);
		else if (Omflag == 1)
		{
			iShowImage(Char2Pos_x, Char2Pos_y, 200, 200, IyoriVariable.M[0]);
			Omflag = 0;
		}
		else if (Omflag == 2)
		{
			iShowImage(Char2Pos_x, Char2Pos_y, 100, 210, IyoriVariable.M[1]);
			Omflag = 0;
		}
		else if (Oflag == 1)
			iShowImage(Char2Pos_x, Char2Pos_y, 150, 230, IyoriVariable.s[IyoriVariable.i]);
		else if (Oflag == 2)
			iShowImage(Char2Pos_x, Char2Pos_y, 150, 230, IyoriVariable.punch[IyoriVariable.j]);
		else if (Oflag == 3)
			iShowImage(Char2Pos_x, Char2Pos_y, 150, 230, IyoriVariable.pp[IyoriVariable.x]);
		else if (Oflag == 4)
			iShowImage(Char2Pos_x, Char2Pos_y, 150, 230, IyoriVariable.pk[IyoriVariable.y]);

	}

	if (flag == 1)
	{

		iClear();
		iShowImage(0, 0, 1280, 720, ground);
		iSetColor(255, 255, 255);
		iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.s[kenVariable.i]);
		if (Oflag == 0 && Omflag == 0)
			iShowImage(Char2Pos_x, Char2Pos_y, 150, 230, IyoriVariable.s[0]);
		else if (Omflag == 1)
		{
			iShowImage(Char2Pos_x, Char2Pos_y, 200, 200, IyoriVariable.M[0]);
			Omflag = 0;
		}
		else if (Omflag == 2)
		{
			iShowImage(Char2Pos_x, Char2Pos_y, 100, 210, IyoriVariable.M[1]);
			Omflag = 0;
		}
		else if (Oflag == 1)
			iShowImage(Char2Pos_x, Char2Pos_y, 150, 230, IyoriVariable.s[IyoriVariable.i]);
		else if (Oflag == 2)
			iShowImage(Char2Pos_x, Char2Pos_y, 150, 230, IyoriVariable.punch[IyoriVariable.j]);
		else if (Oflag == 3)
			iShowImage(Char2Pos_x, Char2Pos_y, 150, 230, IyoriVariable.pp[IyoriVariable.x]);
		else if (Oflag == 4)
			iShowImage(Char2Pos_x, Char2Pos_y, 150, 230, IyoriVariable.pk[IyoriVariable.y]);
	}

	if (flag == 2)
	{


		iClear();
		iShowImage(0, 0, 1280, 720, ground);
		iSetColor(255, 255, 255);
		iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.punch[kenVariable.j]);
		if (Oflag == 0 && Omflag == 0)
			iShowImage(Char2Pos_x, Char2Pos_y, 150, 230, IyoriVariable.s[0]);
		else if (Omflag == 1)
		{
			iShowImage(Char2Pos_x, Char2Pos_y, 200, 200, IyoriVariable.M[0]);
			Omflag = 0;
		}
		else if (Omflag == 2)
		{
			iShowImage(Char2Pos_x, Char2Pos_y, 100, 210, IyoriVariable.M[1]);
			Omflag = 0;
		}
		else if (Oflag == 1)
			iShowImage(Char2Pos_x, Char2Pos_y, 150, 230, IyoriVariable.s[IyoriVariable.i]);
		else if (Oflag == 2)
			iShowImage(Char2Pos_x, Char2Pos_y, 150, 230, IyoriVariable.punch[IyoriVariable.j]);
		else if (Oflag == 3)
			iShowImage(Char2Pos_x, Char2Pos_y, 150, 230, IyoriVariable.pp[IyoriVariable.x]);
		else if (Oflag == 4)
			iShowImage(Char2Pos_x, Char2Pos_y, 150, 230, IyoriVariable.pk[IyoriVariable.y]);

	}
	if (flag == 3)
	{

		iClear();
		iShowImage(0, 0, 1280, 720, ground);
		iSetColor(255, 255, 255);
		iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.pk[kenVariable.x]);
		if (Oflag == 0 && Omflag == 0)
			iShowImage(Char2Pos_x, Char2Pos_y, 150, 230, IyoriVariable.s[0]);
		else if (Omflag == 1)
		{
			iShowImage(Char2Pos_x, Char2Pos_y, 200, 200, IyoriVariable.M[0]);
			Omflag = 0;
		}
		else if (Omflag == 2)
		{
			iShowImage(Char2Pos_x, Char2Pos_y, 100, 210, IyoriVariable.M[1]);
			Omflag = 0;
		}
		else if (Oflag == 1)
			iShowImage(Char2Pos_x, Char2Pos_y, 150, 230, IyoriVariable.s[IyoriVariable.i]);
		else if (Oflag == 2)
			iShowImage(Char2Pos_x, Char2Pos_y, 150, 230, IyoriVariable.punch[IyoriVariable.j]);
		else if (Oflag == 3)
			iShowImage(Char2Pos_x, Char2Pos_y, 150, 230, IyoriVariable.pp[IyoriVariable.x]);
		else if (Oflag == 4)
			iShowImage(Char2Pos_x, Char2Pos_y, 150, 230, IyoriVariable.pk[IyoriVariable.y]);

	}
	if (flag == 4)
	{

		iClear();
		iShowImage(0, 0, 1280, 720, ground);
		iSetColor(255, 255, 255);
		iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.pp[kenVariable.y]);
		if (Oflag == 0 && Omflag == 0)
			iShowImage(Char2Pos_x, Char2Pos_y, 150, 230, IyoriVariable.s[0]);
		else if (Omflag == 1)
		{
			iShowImage(Char2Pos_x, Char2Pos_y, 200, 200, IyoriVariable.M[0]);
			Omflag = 0;
		}
		else if (Omflag == 2)
		{
			iShowImage(Char2Pos_x, Char2Pos_y, 100, 210, IyoriVariable.M[1]);
			Omflag = 0;
		}
		else if (Oflag == 1)
			iShowImage(Char2Pos_x, Char2Pos_y, 150, 230, IyoriVariable.s[IyoriVariable.i]);
		else if (Oflag == 2)
			iShowImage(Char2Pos_x, Char2Pos_y, 150, 230, IyoriVariable.punch[IyoriVariable.j]);
		else if (Oflag == 3)
			iShowImage(Char2Pos_x, Char2Pos_y, 150, 230, IyoriVariable.pp[IyoriVariable.x]);
		else if (Oflag == 4)
			iShowImage(Char2Pos_x, Char2Pos_y, 150, 230, IyoriVariable.pk[IyoriVariable.y]);

	}
	if (Omflag == 1)
	{

		iClear();
		iShowImage(0, 0, 1280, 720, ground);
		iShowImage(Char2Pos_x, Char2Pos_y, 200, 200, IyoriVariable.M[0]);
		if (flag == 0 && mflag == 0)
			iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.s[0]);
		else if (mflag == 1)
		{
			iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.M[0]);
			mflag = 0;
		}
		else if (mflag == 2)
		{
			iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.M[1]);
			mflag = 0;
		}
		else if (flag == 1)
			iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.s[kenVariable.i]);
		else if (flag == 2)
			iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.punch[kenVariable.j]);
		else if (flag == 3)
			iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.pk[kenVariable.x]);
		else if (flag == 4)
			iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.pp[kenVariable.y]);
	}
	if (Omflag == 2)
	{
		iClear();
		iShowImage(0, 0, 1280, 720, ground);
		iShowImage(Char2Pos_x, Char2Pos_y, 100, 220, IyoriVariable.M[1]);
		if (flag == 0 && mflag == 0)
			iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.s[0]);
		else if (mflag == 1)
		{
			iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.M[0]);
			mflag = 0;
		}
		else if (mflag == 2)
		{
			iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.M[1]);
			mflag = 0;
		}
		else if (flag == 1)
			iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.s[kenVariable.i]);
		else if (flag == 2)
			iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.punch[kenVariable.j]);
		else if (flag == 3)
			iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.pk[kenVariable.x]);
		else if (flag == 4)
			iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.pp[kenVariable.y]);
	}
	if (Oflag == 1)
	{
		iClear();
		iShowImage(0, 0, 1280, 720, ground);
		iShowImage(Char2Pos_x, Char2Pos_y, 150, 230, IyoriVariable.s[IyoriVariable.i]);
		if (flag == 0 && mflag == 0)
			iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.s[0]);
		else if (mflag == 1)
		{
			iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.M[0]);
			mflag = 0;
		}
		else if (mflag == 2)
		{
			iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.M[1]);
			mflag = 0;
		}
		else if (flag == 1)
			iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.s[kenVariable.i]);
		else if (flag == 2)
			iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.punch[kenVariable.j]);
		else if (flag == 3)
			iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.pk[kenVariable.x]);
		else if (flag == 4)
			iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.pp[kenVariable.y]);
	}
	if (Oflag == 2)
	{
		iClear();
		iShowImage(0, 0, 1280, 720, ground);
		iShowImage(Char2Pos_x, Char2Pos_y, 150, 230, IyoriVariable.punch[IyoriVariable.j]);
		if (flag == 0 && mflag == 0)
			iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.s[0]);
		else if (mflag == 1)
		{
			iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.M[0]);
			mflag = 0;
		}
		else if (mflag == 2)
		{
			iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.M[1]);
			mflag = 0;
		}
		else if (flag == 1)
			iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.s[kenVariable.i]);
		else if (flag == 2)
			iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.punch[kenVariable.j]);
		else if (flag == 3)
			iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.pk[kenVariable.x]);
		else if (flag == 4)
			iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.pp[kenVariable.y]);
	}
	if (Oflag == 3)
	{
		iClear();
		iShowImage(0, 0, 1280, 720, ground);
		iShowImage(Char2Pos_x, Char2Pos_y, 150, 230, IyoriVariable.pp[IyoriVariable.x]);
		if (flag == 0 && mflag == 0)
			iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.s[0]);
		else if (mflag == 1)
		{
			iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.M[0]);
			mflag = 0;
		}
		else if (mflag == 2)
		{
			iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.M[1]);
			mflag = 0;
		}
		else if (flag == 1)
			iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.s[kenVariable.i]);
		else if (flag == 2)
			iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.punch[kenVariable.j]);
		else if (flag == 3)
			iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.pk[kenVariable.x]);
		else if (flag == 4)
			iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.pp[kenVariable.y]);
	}
	if (Oflag == 4)
	{
		iClear();
		iShowImage(0, 0, 1280, 720, ground);
		iShowImage(Char2Pos_x, Char2Pos_y, 150, 230, IyoriVariable.pk[IyoriVariable.y]);
		if (flag == 0 && mflag == 0)
			iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.s[0]);
		else if (mflag == 1)
		{
			iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.M[0]);
			mflag = 0;
		}
		else if (mflag == 2)
		{
			iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.M[1]);
			mflag = 0;
		}
		else if (flag == 1)
			iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.s[kenVariable.i]);
		else if (flag == 2)
			iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.punch[kenVariable.j]);
		else if (flag == 3)
			iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.pk[kenVariable.x]);
		else if (flag == 4)
			iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.pp[kenVariable.y]);
	}
}


#endif // !MYHEADER_H_INCLUDED
