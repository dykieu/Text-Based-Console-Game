/*************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/25/19
 * Purpose:     Derived from space class. Hidden room has a 
 *              special search function that allows user to
 *              find a hidden item.
***************************************************************/
#include "rm_Hide.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::ios;
using std::fstream;
using std::string;

/***************************************************************
 * Function:    rmHide()
 * Purpose:     Defines variables for the hidden room
****************************************************************/
rmHide::rmHide()
{
    string type = "Hidden room";
    storedObject = NULL;
    up = NULL;
    down = NULL;
    left = NULL;
    right = NULL;
    entryCounter = 1;
}

/***************************************************************
 * Function:    specialEvent()
 * Purpose:     Notifies user of the current room and hints at
 *              searching the room
****************************************************************/
void rmHide::specialEvent(Hunter* player)
{
    //If this is the users first time within the room
    if (entryCounter == 1)
    {
        //Displays room information
        cout << "[Hidden Room]" << endl;
        cout << "\r\n" << endl;
        cout << "   You have entered a Hidden Room." << endl;
        cout << "   It is dusty and dark... You should look around" << endl;       
        cout << "\r\n" << endl;
    }
    else
    {
        cout << "[Hidden Room]" << endl;
        cout << "\r\n" << endl;
        cout << "   You have entered a Hidden Room." << endl;
        cout << "\r\n" << endl;
    }

    return;
}

/***************************************************************
 * Function:    search()
 * Purpose:     allows user to search the room
****************************************************************/
void rmHide::search(Hunter* player)
{
    //Gives user the option to search the room
    choice = searchMenu.searchChoice();
    if (choice == 1)
    {
        //If its the user's first time within the room
        if (entryCounter == 1)
        {
            //Displays information and a prompt
            cout << "   You search the room...";
            cout << "   And find an old dusty chest." << endl;
            cout << "   You open the chest and find <Devil King's Daggers>" << endl;
            cout << "   Item Stats: Attack +99" << endl;
            cout << "\r\n";

            //If user already has a weapon
            if (player->getWepEQ() != "empty")
            {
                cout << "   You currently have a weapon equipped." << endl;
                cout << "   If you equip a new weapon, the old one will be lost." << endl;
            }

            //asks user if they want to equip the item
            int equip = searchMenu.equipItem();

            //Equips items
            if (equip == 1)
            {
                player->setEquipment("DKD", player->getArmEQ(), player->getMisc());
            }

            //increments counter
            entryCounter++;
            return;     
        }
        
        cout << "   You search the room...";
        cout << "   But find nothing." << endl;
        cout << "\r\n";
        return;
    }
    else
    {
        cout << "   You do not search the room." << endl;
        return;
    }
}
