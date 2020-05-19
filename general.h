#ifndef general_h
#define general_h

#include <windows.h>
#include <ctime>
#include <iostream>
#include "keyHandling.h"


using namespace std;

bool gameOver;
int screenWidth = 40;
int screenHeight =10;
int gameType;
char greet1[11]="Snake game";
char greet2[22]="Welcome to my project";
int head_x, head_y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int tail_length;

void TextColor (int color) // hàm đổi màu text tham khảo của https://www.youtube.com/watch?v=Lif3FD6Bqqg
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , color);
}

char greeting() // ịn ra màn hình chào mừng
{
    TextColor(11);
    for(int i=0; i<10; i++)
    {
        cout<<endl;
    }
    for(int j=0;j<35;j++)
    {
        cout<<" ";
    }

    for(int i=0;i< strlen(greet1);i++)
    {
        cout<<greet1[i];
        Sleep(60);
    }

    cout << endl;

    for(int k=0;k<35;k++)
    {
        cout<<" ";
    }
    for(int i=0;i<strlen(greet2);i++)
    {
        cout<<greet2[i];
        Sleep(60);
    }
    cout << endl << endl << endl;
    for(int k=0;k<35;k++)
    {
        cout<<" ";
    }
    Sleep(1000);
    cout  << "Press any key to continue";
    getch();
    system("cls");
}


void setup() // setup những hàm cơ bản
{
	gameOver = false;
	dir = NONE;
	head_x = screenWidth / 2;
	head_y = screenHeight / 2;
	srand(time(NULL));
	fruitX = rand() % screenWidth;
	fruitY = rand() % screenHeight;
	score = 0;
}


void draw_screen() // vẽ ra màn hình chơi game
{
	system("cls");
	TextColor(6);
	for (int i = 0; i < screenWidth+2; i++)
		cout << "_";
	cout << endl;

	for (int i = 0; i < screenHeight; i++)
	{
		for (int j = 0; j < screenWidth; j++)
		{
			if (j == 0)
				cout << "|";
			if (i == head_y && j == head_x)
            {
				cout << "O";
            }
			else if (i == fruitY && j == fruitX)
            {
				cout << "*";
            }
			else
			{
				bool print = false;
				for (int k = 0; k < tail_length; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						cout << "x";
						print = true;
					}
				}
				if (!print)
					cout << " ";
			}


			if (j == screenWidth - 1)
				cout << "|";
		}
		cout << endl;
	}

	for (int i = 0; i < screenWidth+2; i++)
		cout << "#";
	cout << endl;
	cout << "Score:" << score << endl;
}


void movement() // logic di chuyển
{
    switch (dir)
	{
        case LEFT:
            head_x--;
            Sleep(100);
            break;
        case RIGHT:
            head_x++;
            Sleep(100);
            break;
        case UP:
            head_y--;
            Sleep(160);
            break;
        case DOWN:
            head_y++;
            Sleep(160);
            break;
        default:
            break;
    }
}


void tail_appearence() // hàm hiện đuôi
{
    int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = head_x;
	tailY[0] = head_y;
	for (int i = 1; i < tail_length; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
}


void scoring() // nhận biết ăn quả và ghi điểm
{
    if (head_x == fruitX && head_y == fruitY)
    {
        score += 10;
        fruitX = rand() % screenWidth;
        fruitY = rand() % screenHeight;
        tail_length++;
    }
}


void tail_collision_detection() // nhận biết va chạm với đuôi
{
    for (int i = 0; i < tail_length; i++)
        if (tailX[i] == head_x && tailY[i] == head_y)
        {
            gameOver = true;
        }


}


void wall_collision_detection() // nhận biết va chạm với tường
{
    if (head_x >= screenWidth || head_x < 0 || head_y >= screenHeight || head_y < 0)
    {
        gameOver = true;
    }
}


void through_wall() // hàm giúp rắn đi xuất hiện sau khi đi qua tường
{
    if (head_x >= screenWidth)
    {
        head_x = 0;
    }
    else if (head_x < 0)
    {
        head_x = screenWidth - 1;
    }

    if (head_y >= screenHeight)
    {
        head_y = 0;
    }
    else if (head_y < 0)
    {
        head_y = screenHeight - 1;
    }
}


char input_game_type() // chọn chế độ chơi
{
    TextColor(11);
    for(int i=0; i<10; i++)
    {
        cout<<endl;
    }
    for(int j=0;j<39;j++)
    {
        cout<<" ";
    }
    cout << "Choose your game type" << endl;
    for(int j=0;j<39;j++)
    {
        cout<<" ";
    }
    cout << "1. Classic" << endl;
    for(int j=0;j<39;j++)
    {
        cout<<" ";
    }
    cout << "2. Modern go through wall";
    gameType = getch();
}
#endif // general_h


