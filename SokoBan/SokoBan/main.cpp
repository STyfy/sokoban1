#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<conio.h>


#define  X  10
#define  Y  10

int   x1 = 7, y1 = 1;
int   x2 = 6, y2 = 2;

char  map[X][Y] = { '*', '*', '*', '*', '*', '*', '*', '*', '*', '*',
'*', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*',
'*', ' ', ' ', ' ', ' ', ' ', '*', ' ', '*', '*',
'*', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*', '*',
'*', '*', ' ', '*', ' ', ' ', ' ', '*', '*', '*',
'*', ' ', ' ', '*', '*', ' ', ' ', ' ', '*', '*',
'*', ' ', '@', '*', '*', ' ', ' ', ' ', '*', '*',
'*', 'p', ' ', ' ', '*', ' ', ' ', ' ', '*', '*',
'*', '*', ' ', ' ', ' ', ' ', ' ', ' ', 'O', '*',
'*', '*', '*', '*', '*', '*', '*', '*', '*', '*' };



void   drawmap()
{
	system("cls");
	int m ,n;
	for (m = 0; m < 10; m++)
	{
		for (n = 0; n < 10; n++)
			printf("%c", map[m][n]);
		printf("\n"); 
	}
	
}

int   movebox(int a,int b)
{
	char  destination;

	
	destination = map[x2 + a][y2 + b];
	switch (destination)
	{
	case ' ':map[x2 + a][y2 + b] = '@'; map[x2][y2] = ' ';  return 1;
	case 'O':MessageBox(0, TEXT("You win!"), "Game over", 0); exit(0);
	case '*':
	default:return 0;
	}
	

}


void  movepeople(int A,int B)
{
	char aim;
	aim = map[x1 + A][y1 + B];
	switch (aim)
	{
	case '@':if (movebox(A, B)){ map[x1 + A][y1 + B] = 'P'; map[x1][y1] = ' '; x1+= A; y1 += B; x2 += A; y2 += B; }break;
	case ' ':{map[x1 + A][y1 + B] = 'P'; map[x1][y1] = ' '; x1 += A; y1 += B; } break;
	case '*':break;
	default:break;
	}
	drawmap();
}
int  main()
{
	char control;
	drawmap();

	while (control=_getch())
	{
		switch (control)
		{
		case 'w':
		case 'W':movepeople(-1, 0); break;
		case 's':
		case 'S':movepeople(1, 0); break;
		case 'A':
		case 'a':movepeople(0, -1); break;
		case 'd':
		case 'D':movepeople(0, 1); break;
		default: break;
		}
	}
	return 0;
}