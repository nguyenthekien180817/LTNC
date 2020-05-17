#include "general.h"
#include "keyHandling.h"
#include "replay.h"

int main()
{
    char ask = 'Y';
    greeting();
    while(!replay(ask)){
    input_game_type();
    setup();
    while(!gameOver)
    {
        if(gameType == '1')
        {
            draw_screen();
            key_pressed();
            tail_appearence();
            movement();
            scoring();
            tail_collision_detection();
            wall_collision_detection();
        }

        if(gameType == '2')
        {
            draw_screen();
            key_pressed();
            tail_appearence();
            movement();
            scoring();
            tail_collision_detection();
            through_wall();
        }
    }
    tail_length = 0;
    system ("cls");
    for(int i=0; i<10; i++)
    {
        cout<<endl;
    }
    for(int j=0;j<39;j++)
    {
        cout<<" ";
    }
    TextColor(11);
    cout << "You are dead. Press Y to play again or press any key to quit";
    ask = getch();
    if(ask == 'Y' || ask == 'y')
    {
        gameOver = FALSE;
        system("cls");
    }
}
    return 0;
}



