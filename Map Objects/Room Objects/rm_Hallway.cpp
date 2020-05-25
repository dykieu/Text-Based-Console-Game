/*************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/25/19
 * Purpose:     Derived from space class. Hallway class is 
 *              essentially a empty room that just acts to 
 *              transition users between rooms.
***************************************************************/
#include "rm_Hallway.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

/***************************************************************
 * Function:    rmHall()
 * Purpose:     Defines variables for the boss room
****************************************************************/
rmHall::rmHall()
{
    string type = "Hallway";
    storedObject = NULL;
    up = NULL;
    down = NULL;
    left = NULL;
    right = NULL;
    entryCounter = 1;
}

/***************************************************************
 * Function:    specialEvent()
 * Purpose:     Informs user of room info and special event
****************************************************************/
void rmHall::specialEvent(Hunter* player)
{
    //Displays room information
    cout << "[Hallway]" << endl;
    cout << "\r\n" << endl;
    cout << "   You have entered a hallway within the castle." << endl;
    cout << "   The air is chilly and you are surrounded by an" << endl;       
    cout << "   eerie darkness..." << endl;
    cout << "\r\n" << endl;
  
    return;  
}


/***************************************************************
 * Function:    search()
 * Purpose:     allows user to search the room
****************************************************************/
void rmHall::search(Hunter* player)
{
    choice = searchMenu.searchChoice();
    if (choice == 1)
    {
        //Rolls too see if user triggers a trap
        roll = (rand() % 100) + 1;
        if (roll >= 85)
        {
            //DIsplays information about the trap
            cout << "   You search the room...";
            cout << "   and you find a skull!" << endl;
            cout << "   It bites your finger before rolling off into the darkness." << endl;
            player->inflictDmg(2);
            cout << "\r\n";
            return;
        }
        else
        {
            cout << "   You search the room...";
            cout << "   But find nothing." << endl;
            cout << "\r\n";
             return;
        }
    }
    else
    {
        cout << "   You do not search the room." << endl;
        return;
    }
}
