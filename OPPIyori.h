#ifndef OPPIyori_H_INCLUDED
#define OPPIyori_H_INCLUDED


int hflag = 0;
int mflag = 0;


typedef struct characterV characterV;
struct characterV {

	int i;   ///<  used to change the consecutive images for 'kick' move 
	int j;   ///<  used to change the consecutive images for 'punch' move 
	int x;   ///<  used to change the consecutive images for 'powerful kick' move
	int y;   ///<  used to change the consecutive images for 'poewrful punch' move

	// empty constructor
	characterV()
	{
		;
	}

	// constructor initializes the variables  of the structure 
	characterV(int _i, int _j, int _x, int _y)
	{

		i = _i;
		j = _j;
		x = _x;
		y = _y;
	}

	int s[5];         ///< Array used for the kick images
	int punch[5];    ///< Array used for the punch images
	int pk[5];       ///< Array used for the powerful kick images
	int pp[5];      ///< Array used for the powerful  images
	int M[2];      ///< Array used for the main menu images 

}IyoriVariable;

void ShowOPPIyoriImages()
{
	// consecutive images for kick
	IyoriVariable.s[0] = iLoadImage("OPP\\K1.png");
	IyoriVariable.s[1] = iLoadImage("OPP\\K2.png");
	IyoriVariable.s[2] = iLoadImage("OPP\\K3.png");
	IyoriVariable.s[3] = iLoadImage("OPP\\K4.png");
	IyoriVariable.s[4] = iLoadImage("OPP\\S1.png");

	// consecutive images for punch
	IyoriVariable.punch[0] = iLoadImage("OPP\\P1.png");
	IyoriVariable.punch[1] = iLoadImage("OPP\\P2.png");
	IyoriVariable.punch[2] = iLoadImage("OPP\\P3.png");
	IyoriVariable.punch[3] = iLoadImage("OPP\\P4.png");
	IyoriVariable.punch[4] = iLoadImage("OPP\\S1.png");

	// consecutive images for kick
	IyoriVariable.pp[0] = iLoadImage("OPP\\PK1.png");
	IyoriVariable.pp[1] = iLoadImage("OPP\\PK2.png");
	IyoriVariable.pp[2] = iLoadImage("OPP\\PK3.png");
	IyoriVariable.pp[3] = iLoadImage("OPP\\PK4.png");
	IyoriVariable.pp[4] = iLoadImage("OPP\\S1.png");

	// consecutive images for kick
	IyoriVariable.pk[0] = iLoadImage("OPP\\PP1.png");
	IyoriVariable.pk[1] = iLoadImage("OPP\\PP2.png");
	IyoriVariable.pk[2] = iLoadImage("OPP\\PP3.png");
	IyoriVariable.pk[3] = iLoadImage("OPP\\PP4.png");
	IyoriVariable.pk[4] = iLoadImage("OPP\\S1.png");

	//Opponent Move 
	IyoriVariable.M[0] = iLoadImage("OPP\\F1.png");
	IyoriVariable.M[1] = iLoadImage("OPP\\B1.png");
}
// This function is used for changing the consecutive images of 'kick' move Iyori

void OPPKick()
{
	IyoriVariable.i++;
	if (IyoriVariable.i == 3 && CharPos_x <= Char2Pos_x && CharPos_x >= Char2Pos_x - 230)
	{
		healthlength = healthlength - 12;
		hflag = 2;
		flag = 0;
		mflag = 0;
	}
	if (IyoriVariable.i >4)
	{
		IyoriVariable.i = 0;
		Oflag = 0;
		hflag = 0;
		iPauseTimer(1);
	}
}

// This function is used for changing the consecutive images of 'punch' move for Iyori
void OPPPunch()
{
	IyoriVariable.j++;
	if (IyoriVariable.j == 3 && CharPos_x <= Char2Pos_x && CharPos_x >= Char2Pos_x - 200)
	{
		healthlength = healthlength - 12;
		hflag = 2;
		flag = 0;
		mflag = 0;
	}
	if (IyoriVariable.j > 4)
	{
		IyoriVariable.j = 0;
		Oflag = 0;
		hflag = 0;
		iPauseTimer(1);
	}
}

// This function is used for changing the consecutive images of 'power kick' move for Iyori
void OPPPKick()
{
	IyoriVariable.x++;
	if (IyoriVariable.x == 3 && CharPos_x <= Char2Pos_x && CharPos_x >= Char2Pos_x - 230)
	{
		healthlength = healthlength - 25;
		hflag = 1;
		flag = 0;
		mflag = 0;
	}
	if (IyoriVariable.x > 4)
	{
		IyoriVariable.x = 0;
		Oflag = 0;
		hflag = 0;
		iPauseTimer(1);
	}

}
// This function is used for changing the consecutive images of 'powerul kick' move for Iyori
void OPPPPunch()
{
	IyoriVariable.y++;
	if (IyoriVariable.y == 3 && CharPos_x <= Char2Pos_x && CharPos_x >= Char2Pos_x - 200)
	{
		healthlength = healthlength - 25;
		hflag = 1;
		flag = 0;
		mflag = 0;
	}
	if (IyoriVariable.y > 4)
	{
		IyoriVariable.y = 0;
		Oflag = 0;
		hflag = 0;
		iPauseTimer(1);
	}
}
#endif //