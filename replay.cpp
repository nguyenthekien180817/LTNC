#include "replay.h"


bool replay(char ask)
{
    if(ask == 'Y' || ask == 'y')
    {
        return false;
    }
    else
    {
        if(ask == 'n' || ask == 'n')
        {
            system("cls");

            for(int i=0; i<10; i++)
            {
                cout<<endl;
            }

            for(int j=0;j<39;j++)
            {
                cout<<" ";
            }
            cout << "GOODBYE!!";

            for(int i=0; i<10; i++)
            {
                cout<<endl;
            }
        return true;
        }
    }
}
