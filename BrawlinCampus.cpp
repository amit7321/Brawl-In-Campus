#pragma warning (disable : 4996)
# include "iGraphics.h"
#include"characterKen.h";
#include"OPPIyori.h";
# include "highscore.h"

int CharFlag = 0;  
int CharFlag2 = 0;
int g = 0,p=0,ins=0,ab=0,e=0;    ///< initializes the variables used for entering the pages of menu  

int MM, pl, ex, abo, in, po, Point, Ins, Ins2nd, cap, bac, ground;   /*these  variables are used to load images for main menu page,play button,about button,instruction button,
                                                                      about page,back button,background  */
int c1, c2, c3, c4, c5, c6;    ///< these  variables are used to load the images of the character choice
int health, opphealth, bar, oppbar, OPPhurthigh, OPPhurtlow, hurthigh, hurtlow;     ///< these  variables are used to load the images of the health bars,life length etc.
int charground,charground2;   ///< these  variables are used to load the images of a part of point table
 
int dx = 100;       ///< x coordinate for the kick,punck,powerful kick,powerful images 
int dy = 50;        ///< y coordinate for the kick,punck,powerful kick,powerful images 

int stringindex, numberarray;   ///< 
int st;
int winnerken, winneriyori;
char name; 
int n;
//int winFlag = 0;




// @brief  this function is used to draw 'Back' button
void drawBack()
{
	
	iShowImage(40, 650, 50,50,bac);
	
}
// @brief this function is used to draw 'Play' button
void drawPlayButton()
{
	iSetColor(255, 255, 255);
	iShowImage(100, 500, dx, dy,pl);
	

}
//@brief this function is used to draw 'Point Table' button
void drawPointTableButton()
{
	iSetColor(255, 255, 255);
	iShowImage(100, 400, dx + 140, dy,po);
	

}
//@brief this function is used to draw 'Point Table' button
void drawInsructionButton()
{
	iSetColor(255, 255, 255);
	iShowImage(100, 300, dx + 150, dy,in);
	

}
//@brief this function is used to draw 'About' button
void drawAboutButton()
{
	iSetColor(255, 255, 255);
	iShowImage(100, 200, dx + 20, dy,abo);
	//iSetColor(0, 0, 0);
	//iText(125, 215, "About", GLUT_BITMAP_TIMES_ROMAN_24);
}
//@brief this function is used to draw 'Exit' button
void drawExitButton()
{
	iSetColor(255, 255, 255);
	iShowImage(100, 100, dx , dy,ex);
	
}

void play()
{
	iSetColor(255, 0, 0);
	iText(500, 600, "Game will start here", GLUT_BITMAP_TIMES_ROMAN_24);

}

// Calling the drawing functions of point table of characters
void pointTable()
{

	iShowImage(0, 0, 1280, 720, Point);
	store();
	//ptiori();	
	//ptken();
}



// @brief  This function is used to draw the  'Instruction' page for ken
void drawInstruction()
{
	iShowImage(0, 0, 1280, 720, Ins);
}


// @brief  This function is used to draw the  'Instruction' page for Iyori
void drawInstruction2nd()
{
	iShowImage(0, 0, 1280, 720, Ins2nd);
}


//@brief  This function is used to draw the 'About' page
void about()
{
	iShowImage(0, 0, 1280, 720, cap);
}


// @brief this function is used  to show the images to choose the characters of the game
void showCharacterChoice()
{
	iClear();
	iShowImage(0, 0, 1280, 720, charground);
	iShowImage(20, 10, 400, 230, c1);
	iShowImage(440, 10, 400, 230, c2);
	iShowImage(860, 10, 400, 230, c3);
	iShowImage(20, 250, 400, 230, c4);
	iShowImage(440, 250, 400, 230, c5);
	iShowImage(860, 250, 400, 230, c6);

}
void showCharacterChoice2()
{
	iClear();
	iShowImage(0, 0, 1280, 720, charground2);
	iShowImage(20, 10, 400, 230, c1);
	iShowImage(440, 10, 400, 230, c2);
	iShowImage(860, 10, 400, 230, c3);
	iShowImage(20, 250, 400, 230, c4);
	iShowImage(440, 250, 400, 230, c5);
	iShowImage(860, 250, 400, 230, c6);

}
 // @brief  this function is used to show the images of the health bars
void DrawHealthBar()
{
	iShowImage(25, 625, 560 , 65, bar);
	iShowImage(700, 625, 560, 65, oppbar);
	iShowImage(150, 640, healthlength, 20, health);
	iShowImage(1140, 640,opphealthlength, 20,health);
}

// @brief  This function implements the moves of the characters ken.This function is called through isetTimer
void	a()
{
	PKick();
	Kick();
	punch();
	Ppunch();
}

// @brief  This function implements the moves of the characters Iyori.This function is called through isetTimer
void b()
{
	OPPKick();
	OPPPunch();
	OPPPKick();
	OPPPPunch();
}

/* @brief   This function is used to draw the moves(kick,punch,powerful punch,powerful kick ),the
background of the game , health bars , standing position of the characters
*/
void DrawGame()
{
	iClear();
	iShowImage(0, 0, 1280, 720, ground);
	iSetColor(255, 255, 255);
	iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.s[0]);
	iShowImage(Char2Pos_x, Char2Pos_y, 150, 230, IyoriVariable.s[0]);

	// This block draw the standing position of the characters ken
	if (mflag == 1)
	{
		iClear();
		iShowImage(0, 0, 1280, 720, ground);
		iSetColor(255, 255, 255);
		iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.M[0]);
		if (Oflag==0 && Omflag==0)
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
		else if (Oflag==1)
			iShowImage(Char2Pos_x, Char2Pos_y, 150, 230, IyoriVariable.s[IyoriVariable.i]);
		else if (Oflag == 2)
			iShowImage(Char2Pos_x, Char2Pos_y, 150, 230, IyoriVariable.punch[IyoriVariable.j]);
		else if (Oflag == 3)
			iShowImage(Char2Pos_x, Char2Pos_y, 150, 230, IyoriVariable.pp[IyoriVariable.x]);
		else if (Oflag == 4)
			iShowImage(Char2Pos_x, Char2Pos_y, 150, 230, IyoriVariable.pk[IyoriVariable.y]);
		

	}

	// This block draw the standing position of the characters ken
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

	// This block implements the 'kick' move of the character  ken
	if (flag == 1)
	{

		iClear();
		iShowImage(0, 0, 1280, 720, ground);
		iSetColor(255, 255, 255);
		iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.s[kenVariable.i]);
		if (Oflag == 0 && Omflag == 0&& Ohflag==1)
			iShowImage(Char2Pos_x, Char2Pos_y, 150, 230, OPPhurthigh);
		if (Oflag == 0 && Ohflag ==0)
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

	//  This block implements the 'punch' move of the character ken
	if (flag == 2)
	{


		iClear();
		iShowImage(0, 0, 1280, 720, ground);
		iSetColor(255, 255, 255);
		iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.punch[kenVariable.j]);
		if (Oflag == 0 && Omflag == 0 && Ohflag == 1)
			iShowImage(Char2Pos_x, Char2Pos_y, 150, 230, OPPhurtlow);
		if (Oflag == 0 && Ohflag == 0)
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

	//  This block implements the 'powerful punch' move of the character ken
	if (flag == 3)
	{
		
		iClear();
		iShowImage(0, 0, 1280, 720, ground);
		iSetColor(255, 255, 255);
		iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.pk[kenVariable.x]);
		if (Oflag == 0 && Omflag == 0 && Ohflag == 1)
			iShowImage(Char2Pos_x, Char2Pos_y, 150, 230, OPPhurthigh);
		if (Oflag == 0 && Ohflag == 0)
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

	//  This block implements the 'powerful kick ' move of the character ken
	if (flag == 4)
	{

		iClear();
		iShowImage(0, 0, 1280, 720, ground);
		iSetColor(255, 255, 255);
		iShowImage(CharPos_x, CharPos_y, 316, 272, kenVariable.pp[kenVariable.y]);
		if (Oflag == 0 && Omflag == 0 && Ohflag == 1)
			iShowImage(Char2Pos_x, Char2Pos_y, 150, 230, OPPhurthigh);
		if (Oflag == 0 && Ohflag == 0)
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

	// This block draw the standing position of the characters Iyori
	if (Omflag == 1)
	{

		iClear();
		iShowImage(0, 0, 1280, 720, ground);
		iShowImage(Char2Pos_x, Char2Pos_y, 200, 200, IyoriVariable.M[0]);
		
		if (flag == 0 && hflag==0)
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

	// This block draw the standing position of the characters Iyori
	if (Omflag == 2)
	{
		iClear();
		iShowImage(0, 0, 1280, 720, ground);
		iShowImage(Char2Pos_x, Char2Pos_y, 100, 220, IyoriVariable.M[1]);
		
		if (flag == 0 && hflag == 0)
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

	// This block implements the 'kick' move of the character Iyori
	if (Oflag == 1)
	{
		iClear();
		iShowImage(0, 0, 1280, 720, ground);
		iShowImage(Char2Pos_x, Char2Pos_y, 150, 230, IyoriVariable.s[IyoriVariable.i]);
		if (flag == 0 && mflag == 0 && hflag == 1)
			iShowImage(CharPos_x + 50, CharPos_y, 150, 230, hurthigh);
		if (flag == 0 && mflag == 0 && hflag == 2)
			iShowImage(CharPos_x, CharPos_y, 150, 250, hurtlow);
		if (flag == 0 && hflag == 0)
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

	//  This block implements the 'punch' move of the character Iyori
	if (Oflag == 2)
	{
		iClear();
		iShowImage(0, 0, 1280, 720, ground);
		iShowImage(Char2Pos_x, Char2Pos_y, 150, 230, IyoriVariable.punch[IyoriVariable.j]);
		if (flag == 0 && mflag == 0 && hflag == 1)
			iShowImage(CharPos_x + 50, CharPos_y, 150, 230, hurthigh);
		if (flag == 0 && mflag == 0 && hflag == 2)
			iShowImage(CharPos_x, CharPos_y, 150, 250, hurtlow);
		if (flag == 0 && hflag == 0)
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

	//  This block implements the 'powerful punch' move of the character Iyori
	if (Oflag == 3)
	{
		iClear();
		iShowImage(0, 0, 1280, 720, ground);
		iShowImage(Char2Pos_x, Char2Pos_y, 150, 230, IyoriVariable.pp[IyoriVariable.x]);
		if (flag == 0 && mflag == 0 && hflag == 1)
			iShowImage(CharPos_x + 50, CharPos_y, 150, 230, hurthigh);
		if (flag == 0 && mflag == 0 && hflag == 2)
			iShowImage(CharPos_x, CharPos_y, 150, 250, hurtlow);
		if (flag == 0 && hflag == 0)
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

	//  This block implements the 'powerful kick' move of the character Iyori
	if (Oflag == 4)
	{
		iClear();
		iShowImage(0, 0, 1280, 720, ground);
		iShowImage(Char2Pos_x, Char2Pos_y, 150, 230, IyoriVariable.pk[IyoriVariable.y]);
		if (flag == 0 && mflag == 0 && hflag == 1)
			iShowImage(CharPos_x + 50, CharPos_y, 150, 230, hurthigh);
		if (flag == 0 && mflag == 0 && hflag == 2)
			iShowImage(CharPos_x, CharPos_y, 150, 250, hurtlow);
		if (flag == 0 && hflag == 0)
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

void iDraw()
{

	//place your drawing codes here
	iClear();
	store();
	iSetColor(255, 255, 255);
	iShowImage(0,0, 1280, 720, MM);
	// these functions are the drawing functions of the menu button
	drawPlayButton();
	drawPointTableButton();
	drawInsructionButton();
	drawAboutButton();
	drawExitButton();
	if (g == 2)
	{
		iClear();
		showCharacterChoice2();
		drawBack();
	}
	if (g == 1){
		iClear();
		showCharacterChoice();
		drawBack();
		
	}
	
	if (p == 1){
		iClear();
		win = false;
		pointTable();

		drawBack();
	}
	if (ins == 1){
		iClear();
		drawInstruction();
		drawBack();
	}
	if (ins == 2){
		iClear();
		drawInstruction2nd();
		drawBack();
	}
	if (ab == 1){
		iClear();
		about();
		drawBack();
	}
	if (gameflag==1)
	{
		DrawGame();
		DrawHealthBar();
	}
	if (opphealthlength>=0)
	{
		iClear();
		iShowImage(0, 0, 1280, 720, winnerken);
		gameflag = 2;
		winFlag = 1;
		kenswin = 3;
		win = true;
		store();
		kenswin = 0;
	}
	if (healthlength <=0)
	{
		iClear();
		iShowImage(0, 0, 1280, 720, winneriyori);
           gameflag = 2;
		winFlag = 2;
		win = true;
		ioriwin = 3;
		store();
		ioriwin = 0;
	}


}




	
/*
function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}
/*
function iMouse() is called when the user presses/releases the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		// if mouse is clicked in this particular region then 'character choice' function will activate  
		if (mx >= 100 && mx <= 100 + dx && my >= 500 && my <= 500 + dy)
		{
			g = 1;

		}
		// if mouse is clicked in this particular region then 'point table' function will activate
		else if (mx >= 100 && mx <= 100 + dx + 140 && my >= 400 && my <= 400 + dy)
		{
			p = 1;

		}
		// if mouse is clicked in this particular region then 'instruction' function will activate
		else if (mx >= 100 && mx <= 100 + dx + 150 && my >= 300 && my <= 300 + dy)
		ins = 1;
		// if mouse is clicked in this particular region then "about' function will activate
		else if (mx >= 100 && mx <= 100 + dx + 20 && my >= 200 && my <= 200 + dy)
			ab = 1;
		// if mouse is clicked in this particular region then 'éxit'  function will activate
		else if (mx >= 100 && mx <= 100 + dx && my >= 100 && my <= 100 + dy)
			exit(0);
		// if mouse is clicked in this particular region then back function will activate
		else if (mx >= 40 && mx <= 40 + dx + 25 && my >= 650 && my <= 650 + dy + 10){
			g = 0;
			p = 0;
			ins = 0;
			ab = 0;
		}
	}
	if (g == 1)
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			 if (mx >= 440 && mx <= 840 && my >= 10 && my <= 240)
			{
				CharFlag = 2;
				g = 2;
				p = 0;
				ins = 0;
				ab = 0;
			}
		
				
		}

	}
	if (g == 2)
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			 if (mx >= 860 && mx <= 1260 && my >= 10 && my <= 240)
			{
				CharFlag2 = 3;
				gameflag = 1;
				
				
			}
		

		}
	}
	
	if (gameflag == 1)
	{
		if (Oflag == 0)
		{
			if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
			{
				if (mx > Char2Pos_x && mx < 1280)
				{
					
					Omflag = 2;
					Char2Pos_x += 30;
				}
				else if (mx < Char2Pos_x && mx > 0)
				{
					Omflag = 1;
					if (Char2Pos_x>CharPos_x + 235)
					Char2Pos_x -= 30;
				}
			}



			if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
			{
				if (mx > Char2Pos_x && mx < 1280 && my > 360 && my < 720)
				{
					Oflag = 3;
					IyoriVariable.x = 0;
					iResumeTimer(1);
				}
				else if (mx > Char2Pos_x && mx < 1280 && my < 360 && my > 0)
				{
					Oflag = 4;
					IyoriVariable.y = 0;
					iResumeTimer(1);
				}
				else if (mx < Char2Pos_x && mx > 0 && my < 360 && my > 0)
				{
					Oflag = 1;
					IyoriVariable.j = 0;
					iResumeTimer(1);
				}

				else if (mx < Char2Pos_x && mx > 0 && my > 360 && my < 720)
				{
					Oflag = 2;
					IyoriVariable.i = 0;
					iResumeTimer(1);
				}
			}

		}
	}
	if (gameflag == 2)
	{

		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			if (mx >= 100 && mx <= 350 && my >= 300 && my <= 400)
			{
				g = 0;
				p = 0;
				ins = 0;
				ab = 0;
				gameflag = 0;
				opphealthlength = -400;
				healthlength = 400;
			}
		}
	}

	// This block is used to enter into the 'instruction' page of character Ken  
	if (ins == 1)
	{
			if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			if (mx > 600 && mx < 950 && my > 590 && my < 670)
			{
				ins = 2;
			}
		}
	}

	// This block is used to enter into the 'instruction' page of character Iyori
	if (ins == 2)
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			if (mx > 250 && mx < 625 && my > 580 && my < 670)
			{
				ins = 1;
			}
		}
	}
}
/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if (flag==0) {
		// key for kick
		{
			if (key == 'a')
			{

				flag = 1;
				kenVariable.i = 0;
				iResumeTimer(0);

			}
		}
		// key for punch
		if (key == 's')
		{


			flag = 2;
			kenVariable.j = 0;
			iResumeTimer(0);
		}
		//key for powerful kick
		if (key == 'd')
		{

			flag = 3;
			kenVariable.x = 0;
			iResumeTimer(0);
		}
		//key for powerful punch
		if (key == 'w')
		{

			flag = 4;
			kenVariable.y = 0;
			iResumeTimer(0);
		}
	}
	// key  for esc
	if (key == 27)
	{
		g = 0;
		p = 0;
		ins = 0;
		ab = 0;

	}
	if (key == 13)
		gameflag = 1;
	
	//place your codes for other keys here
}
/*
function iSpecialKeyboard() is called whenver user hits special keys likefunction keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11,
GLUT_KEY_F12, GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN,
GLUT_KEY_PAGE UP, GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END,
GLUT_KEY_INSERT */
void iSpecialKeyboard(unsigned char key)
{ 
	if (flag == 0){
		
		// move the character right side
		if (CharPos_x > 0 && CharPos_x < Char2Pos_x - 220)
		{
			if (key == GLUT_KEY_RIGHT)
			{

				CharPos_x += 20;
				mflag = 1;

			}
		}
		// move the character left side
		 if (CharPos_x > 10 && CharPos_x <Char2Pos_x - 50)
		{
			if (key == GLUT_KEY_LEFT)
			{
			
					CharPos_x -= 20;
					mflag = 2;
				
			}
		}
		
	}
	// exit the code
	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	//place your codes for other keys here
}
int main()
{
	iSetTimer(200, a);   /// ietTimer for function a
	iSetTimer(200, b);   /// ietTimer for function b

	IyoriVariable = characterV(0, 0, 0, 0);       /// initializes the variables of the structures  for  Ken
	kenVariable = characterVariable(0, 0, 0, 0);     /// initializes the variables of the structures for Iyori

	iInitialize(1280, 720, "demooo");  ///Size of the screen
	

	ground = iLoadImage("char\\background.jpg");  /// to load the background image
	MM = iLoadImage("char\\main_menu.png");       /// to load the image of main menu


	showKenImages();    ///  Function used to show to load the images of kick,punch,powerful punch,powerful kick of character ken
	ShowOPPIyoriImages();    ///  Function used to show to load the images of kick,punch,powerful punch,powerful kick of character Iyori

	

	//  load the images of  Health bar for character Ken and Iyori
	health = iLoadImage("char\\health.png");
	bar = iLoadImage("char\\bar.png");
	opphealth = iLoadImage("char\\OPPhealth.png");
	oppbar = iLoadImage("char\\OPPbar.png");

	//load the images of  Hurt for Ken
	hurthigh = iLoadImage("char\\HurtHigh.png");
	hurtlow = iLoadImage("char\\HurtLow.png");

	//load the images of  Hurt for Iyori
	OPPhurthigh = iLoadImage("OPP\\HurtPunch.png");
	OPPhurtlow = iLoadImage("OPP\\HurtKick.png");

	//load the images of  Winner
	winnerken = iLoadImage("char\\WinnerKen.png");
	winneriyori = iLoadImage("char\\WinnerIyori.png");

	//  images for the menu options
	pl = iLoadImage("char\\play.png");
	ex= iLoadImage("char\\exit.png");
	abo= iLoadImage("char\\about.png");
	in = iLoadImage("char\\instructions.png");
	po= iLoadImage("char\\point_table.png");
	Point = iLoadImage("char\\PointTable.png");
	Ins = iLoadImage("char\\instructions1st.png");
	Ins2nd = iLoadImage("char\\instructions2nd.png");
	cap = iLoadImage("char\\capture.png");
	bac = iLoadImage("char\\back.png");
    charground =iLoadImage("char\\charground.png");
    charground2 = iLoadImage("char\\charground2.png");

     // consecutive images for punch
	c1 = iLoadImage("char\\char1.png");
	c2 = iLoadImage("char\\char2.png");
	c3 = iLoadImage("char\\char3.png");
	c4 = iLoadImage("char\\char4.png");
	c5 = iLoadImage("char\\char5.png");
	c6 = iLoadImage("char\\char6.png");
	iStart();
	
	return 0;
}