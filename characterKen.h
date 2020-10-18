#ifndef characterKen_H_INCLUDED
#define characterKen_H_INCLUDED


int flag = 0;
int Ohflag = 0;
int Oflag = 0;
int  Omflag = 0;
int CharPos_x = 50, CharPos_y = 50;   ///<  Initializing the position of  character Ken
int Char2Pos_x = 960, Char2Pos_y = 55;  ///<  Initializing the position of  character Iyori 
int healthlength = 400;   ///< Initializing the lenth of the healthbar for character ken
int opphealthlength = -400;    ///<  Initializing the lenth of the healthbar for character Iyori

typedef struct characterVariable characterVariable;
struct characterVariable {

	int i;   ///<  used to change the consecutive images for 'kick' move 
	int j;   ///<  used to change the consecutive images for 'punch' move 
	int x;   ///<  used to change the consecutive images for 'powerful kick' move
	int y;   ///<  used to change the consecutive images for 'poewrful punch' move

	// empty constructor
	characterVariable()
	{
		;
	}

	// constructor initializes the variables  of the structure 
	characterVariable(int _i, int _j, int _x, int _y)
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

}kenVariable;

void showKenImages() {

	// consecutive images for kick
	kenVariable.s[0] = iLoadImage("char\\s1.png");
	kenVariable.s[1] = iLoadImage("char\\k1.png");
	kenVariable.s[2] = iLoadImage("char\\k2.png");
	kenVariable.s[3] = iLoadImage("char\\k3.png");
	kenVariable.s[4] = iLoadImage("char\\k4.png");

	// consecutive images for punch
	kenVariable.punch[0] = iLoadImage("char\\s1.png");
	kenVariable.punch[1] = iLoadImage("char\\p2.png");
	kenVariable.punch[2] = iLoadImage("char\\p3.png");
	kenVariable.punch[3] = iLoadImage("char\\p4.png");
	kenVariable.punch[4] = iLoadImage("char\\p6.png");

	// consecutive images for powerful kick
	kenVariable.pk[0] = iLoadImage("char\\pk2.png");
	kenVariable.pk[1] = iLoadImage("char\\pk3.png");
	kenVariable.pk[2] = iLoadImage("char\\pk4.png");
	kenVariable.pk[3] = iLoadImage("char\\pk5.png");
	kenVariable.pk[4] = iLoadImage("char\\pk7.png");

	// consecutive images for powerful punch
	kenVariable.pp[0] = iLoadImage("char\\pp1.png");
	kenVariable.pp[1] = iLoadImage("char\\pp2.png");
	kenVariable.pp[2] = iLoadImage("char\\pp4.png");
	kenVariable.pp[3] = iLoadImage("char\\pp5.png");
	kenVariable.pp[4] = iLoadImage("char\\pp6.png");

	kenVariable.M[0] = iLoadImage("char\\b1.png");
	kenVariable.M[1] = iLoadImage("char\\f1.png");



}
// This function is used for changing the consecutive images of 'kick' move for Ken
void Kick()
{



	kenVariable.i++;
	if (kenVariable.i == 3 && Char2Pos_x <= CharPos_x + 230 && Char2Pos_x > CharPos_x)
	{
		opphealthlength = opphealthlength + 12.5;
		Ohflag = 1;
		Oflag = 0;
		Omflag = 0;
	}

	if (kenVariable.i >4)
	{
		kenVariable.i = 0;
		flag = 0;
		Ohflag = 0;
		iPauseTimer(0);
	}

}
// This function is used for changing the consecutive images of 'kick' move for Ken
void punch()
{
	kenVariable.j++;

	if (kenVariable.j == 3 && Char2Pos_x <= CharPos_x + 160 && Char2Pos_x > CharPos_x)
	{
		opphealthlength = opphealthlength + 12.5;
		Ohflag = 1;
		Oflag = 0;
		Omflag = 0;
	}
	if (kenVariable.j > 4){
		kenVariable.j = 0;
		flag = 0;
		Ohflag = 0;
		iPauseTimer(0);

	}

}

// This function is used for changing the consecutive images of 'powerful kick' move for Ken
void PKick()
{



	kenVariable.x++;
	if (kenVariable.x == 3 && Char2Pos_x <= CharPos_x + 230 && Char2Pos_x > CharPos_x)
	{
		opphealthlength = opphealthlength + 25;
		Ohflag = 1;
		Oflag = 0;
		Omflag = 0;
	}
	if (kenVariable.x > 4)
	{
		kenVariable.x = 0;
		flag = 0;
		Ohflag = 0;
		iPauseTimer(0);
	}


}
// This function is used for changing the consecutive images of 'powerful kick' move foe ken
void Ppunch()
{
	kenVariable.y++;
	if (kenVariable.y == 3 && Char2Pos_x <= CharPos_x + 200 && Char2Pos_x > CharPos_x)
	{
		opphealthlength = opphealthlength + 25;
		Ohflag = 2;
		Oflag = 0;
		Omflag = 0;
	}
	if (kenVariable.y > 4)
	{
		kenVariable.y = 0;
		flag = 0;
		Ohflag = 0;
		iPauseTimer(0);
	}

}






#endif //Header file included