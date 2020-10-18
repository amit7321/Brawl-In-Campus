#define highscore_H_INCLUDED
#define highscore_H_INCLUDED
# include <stdlib.h>
int gameflag =0;
char s[10];
int winFlag = 0;
char str1[10] = "Ken";
char str2[10] = "Iori";
int kenswin;
int ioriwin;
bool win = true;




struct Highscore{
	char name[10];
	int scores;
} v[4];


void store(){
	FILE *fp;



	fp = fopen("highScore.txt", "r");

	int j = 0;
	while (fscanf(fp, "%s\t%d\n", v[j].name, &v[j].scores) != EOF)
	{
		j++;
	}


	fclose(fp);


	
	
	//if (winFlag == 1){
		

	for (int i = 0; i < 4; i++)
	{
		if (v[i].name == str1)
		{
			v[i].scores += kenswin;
			kenswin = 0;
			printf("%d", v[i].scores);

		}
		if (v[i].name == str2)
		{
			v[i].scores += ioriwin;
			ioriwin = 0;
			
		}
			
	}
//}
/* if(winFlag == 2)
{
	
	for (int i = 0; i < 4; i++){
		if (v[i].name == str2)
		{
			v[i].scores += 3;
		}
			
	}
}*/

	Highscore temp[2];
	for (int i = 0; i<2; i++){
		for (j = 0; j<2 - 1; j++)
		{

			if (v[j].scores<v[j + 1].scores)
			{
				temp[0].scores = v[j].scores;
				v[j].scores = v[j + 1].scores;
				v[j + 1].scores = temp[0].scores;

				strcpy(temp[0].name, v[j].name);
				strcpy(v[j].name, v[j + 1].name);
				strcpy(v[j + 1].name, temp[0].name);
			}

		}
	}
	fp = fopen("highScore.txt", "w");

	int x = 0;
	for (j = 0; j<2; j++)
	{
		/*iText(150, 400- x, v[j].name, GLUT_BITMAP_TIMES_ROMAN_24);
		itoa(v[j].scores, s, 10);
		iText(950, 400- x, s, GLUT_BITMAP_TIMES_ROMAN_24);*/
		fprintf(fp, "%s\t%d\n", v[j].name, v[j].scores);
		printf("%s\t%d\n", v[j].name, v[j].scores);
		//x = x + 50;

	}
	if (!win)
	{
		for (j = 0; j < 2; j++)
		{
			iText(150, 400 - x, v[j].name, GLUT_BITMAP_TIMES_ROMAN_24);
			itoa(v[j].scores, s, 10);
			iText(950, 400 - x, s, GLUT_BITMAP_TIMES_ROMAN_24);

			x = x + 50;
		}
		win = true;
	}

	fclose(fp);

}
