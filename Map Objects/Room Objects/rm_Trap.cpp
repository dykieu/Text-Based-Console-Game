/*************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/25/19
 * Purpose:     rm_Trap is derived from space class. rm_Trap 
 *              functions to deal damage to a target that enters
 *              the room.
***************************************************************/
#include "rm_Trap.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

/***************************************************************
 * Function:    rmTrap()
 * Purpose:     Defines variables for the trap room
****************************************************************/
rmTrap::rmTrap()
{
    string type = "Trap Room";
    storedObject = NULL;
    up = NULL;
    down = NULL;
    left = NULL;
    right = NULL;
    entryCounter = 1;
}

/***************************************************************
 * Function:    specialEvent()
 * Purpose:     Users who enter the room trigger the trap
****************************************************************/
void rmTrap::specialEvent(Hunter* player)
{
    //Displays room information
    cout << "[Trap Room]" << endl;
    cout << "\r\n" << endl;
    cout << "   You have entered a trap!" << endl;
    cout << "\r\n";
    cout << "   Arrows are shot from the wall and straight at you" << endl;       
    cout << "   You attempt to dodge but you are unsuccessful..." << endl;
    cout << "\r\n" << endl;

    //Inflicts damage onto the user
    player->inflictDmg(15);
    
    return;  
}

/***************************************************************
 * Function:    search()
 * Purpose:     allows user to search the room
****************************************************************/
void rmTrap::search(Hunter* player)
{
    //Lets user choose to search the room or not
    choice = searchMenu.searchChoice();
    if (choice == 1)
    {
        //Triggers another trap if user looks inside the room
        cout << "   You search the room...";
        cout << "   and you accidently activate another trap" << endl;
        cout << "   Poisonous gas seaps through the wall damaging you further." << endl;
        player->inflictDmg(10);
        cout << "\r\n";
        return;
    }
    else
    {
        cout << "   You do not search the room." << endl;
        return;
    }
}
