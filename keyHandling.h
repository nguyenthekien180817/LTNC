#ifndef key_handling
#define key_handling

#include <conio.h>

enum Direction { NONE, LEFT, RIGHT, UP, DOWN };
Direction dir;

void key_pressed()
{
	if (kbhit())
	{
		switch (getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'A':
			dir = LEFT;
			break;		
		case 'd':
			dir = RIGHT;
			break;
		case 'D':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 'W':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'S':
			dir = DOWN;
			break;
		}
	}
}

#endif // key_handling
