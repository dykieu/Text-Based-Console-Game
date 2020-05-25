/*************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/25/19
 * Purpose:     derived from space class. Represents and armory
 *              space where users can pick up items
***************************************************************/
#include "rm_Armory.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::ios;
using std::fstream;
using std::string;

/***************************************************************
 * Function:    rmArmory()
 * Purpose:     sets default variables for armory space 
****************************************************************/
rmArmory::rmArmory()
{
    string type = "Armory";
    storedObject = NULL;
    up = NULL;
    down = NULL;
    left = NULL;
    right = NULL;
    entryCounter = 1;
}

/***************************************************************
 * Function:    specialEvent()
 * Purpose:     Informs user of which room they are in.
****************************************************************/
void rmArmory::specialEvent(Hunter* player)
{
    //Prints out current room and a short description
    cout << "[Armory]" << endl;
    cout << "\r\n" << endl;
    cout << "   You have entered the armory." << endl;
    cout << "   Maybe you should look around and see if you can find equipment." << endl;       
    cout << "\r\n" << endl;

    return;
}

/***************************************************************
 * Function:    search()
 * Purpose:     Allows user to search the room and possibly 
 *              discover things.
****************************************************************/
void rmArmory::search(Hunter* player)
{
    //Allows user to choose if they want to search to room or not
    choice = searchMenu.searchChoice();
    if (choice == 1)
    {
        //If this is the user's first time in the room
        if (entryCounter == 1)
        {
            //User finds a "blade" item
            cout << "   You search the room...";
            cout << "   You find: "<< endl;
            cout << "       a rusty blade..." << endl;
            cout << "           Item Stats: Attack +10" << endl;
            cout << "\r\n";

            //If the player already has an item equipped
            if (player->getWepEQ() != "empty")
            {
                cout << "   You currently have a weapon equipped." << endl;
                cout << "   If you equip a new weapon, the old one will be lost." << endl;
            }

            //Asks user if they want to equip the item
            int equip = searchMenu.equipItem();

            //If user wants to equip item, equip it
            if (equip == 1)
            {
                player->setEquipment("rusted blade", player->getArmEQ(), player->getMisc());
            }

            //User finds another item, chainmail
            cout << "   You also find: "<< endl;
            cout << "       Chainmail..." << endl;
            cout << "           Item Stats: defense +10" << endl;

            //If user already has a armor equipped
            if (player->getArmEQ() != "empty")
            {
                cout << "   You currently have a armor equipped." << endl;
                cout << "   If you equip a new armor, the old one will be lost." << endl;
            }

            //Asks user if they want to equip the item
            int equip2 = searchMenu.equipItem();

            //If user wants to equip the item
            if (equip2 == 1)
            {
                player->setEquipment(player->getWepEQ(), "chainmail", player->getMisc());
            }

            //Incremement entry counter
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
