/*************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/25/19
 * Purpose:     Blood room allows user the ability to heal for
 *              full hp if they dare to drink the blood
***************************************************************/
#include "rm_Blood.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::ios;
using std::fstream;
using std::string;

/***************************************************************
 * Function:    rmBlood()
 * Purpose:     Constructor for variables that blood room space
****************************************************************/
rmBlood::rmBlood()
{
    string type = "Blood pool";
    storedObject = NULL;
    up = NULL;
    down = NULL;
    left = NULL;
    right = NULL;
    entryCounter = 1;
}

/***************************************************************
 * Function:    specialEvent()
 * Purpose:     Offers the user a chance to recover their hp and
 *              also gain exp
****************************************************************/
void rmBlood::specialEvent(Hunter* player)
{
    //If first time inside the rool
    if (entryCounter == 1)
    {
        //DIsplay description
        cout << "[Blood Pool]" << endl;
        cout << "\r\n" << endl;
        cout << "   You have entered a room with a pool of blood in the middle " << endl;
        cout << "   There are bodies of monsters littered all around the pool..." << endl;       
        cout << "   The pool of blood looks quite suspicious..." << endl;
        cout << "\r\n" << endl;

        //Prompts user if they want to drink the blood or not
        int drink = searchMenu.drink();

        //If user chooses to drink the blood
        if (drink == 1)
        {
            //Display information for user
            cout << "You lean down and take a sip from the blood pool..." << endl;
            cout << "   Suddenly you feel the demonic blood start to flow violently through your body" << endl;
            cout << "   You scream out in agony and faint." << endl;
            cout << "\r\n";
            cout << "   You wake up hours later..." << endl;
            cout << "   Your body feels strangely refreshed and coursing with power..." << endl;
            cout << "   What an odd feeling." << endl;
            cout << "\r\n";
            cout << "**[Hp] FULLY recovered..." << endl;
            
            //Recovers hp and receives exp
            player->recovery(100);
            player->level(150);
        }
        //If user does not want to drink blood
        else
        {
            cout << "   You do not drink the blood" << endl;
        }
        
        entryCounter++;
    }
    else
    {
        cout << "[Blood Pool]" << endl;
        cout << "\r\n" << endl;
        cout << "   You have entered the Blood Pool." << endl;
        cout << "\r\n" << endl;
    }

    return;
}

/***************************************************************
 * Function:    search()
 * Purpose:     allows user to search the room
****************************************************************/
void rmBlood::search(Hunter* player)
{
    //Presents option to search room
    choice = searchMenu.searchChoice();
    
    //If user wants to search
    if (choice == 1)
    {
        //Display hints
        cout << "   you search the room...";
        cout << "   There appears to be a hallway to the [RIGHT]" << endl;
        cout << "      [Right] Seems to lead somewhere dangerous. The hallway is charred black" << endl; 
        cout << "              and bones are littered everywhere" << endl;
        cout << "\r\n";
        return;
    }
    else
    {
        cout << "   You do not search the room." << endl;
        cout << "\r\n";
        return;
    }
}
