/*************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/25/19
 * Purpose:     Garden class derives from space class. Represents
 *              a garden room
***************************************************************/
#include "rm_Garden.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::ios;
using std::fstream;
using std::string;

/***************************************************************
 * Function:    rmGarden()
 * Purpose:     Constructor for variables that define the garden
****************************************************************/
rmGarden::rmGarden()
{
    string type = "Garden";
    storedObject = NULL;
    up = NULL;
    down = NULL;
    left = NULL;
    right = NULL;
    entryCounter = 1;
}

/***************************************************************
 * Function:    specialEvent()
 * Purpose:     Displays information about current location
****************************************************************/
void rmGarden::specialEvent(Hunter* player)
{
    //If first time within the room
    if (entryCounter == 1)
    {
        //Displays info and location
        cout << "[Garden]" << endl;
        cout << "\r\n" << endl;
        cout << "   You have entered a garden within the castle. " << endl;
        cout << "   The flowers and trees are scorched in a blue flame..." << endl;       
        cout << "   There are dead bodies everywhere ... Maybe you should look around for clues." << endl;
        cout << "\r\n" << endl;
    }
    else
    {
        cout << "[Garden]" << endl;
        cout << "\r\n" << endl;
        cout << "   You have entered the Garden." << endl;
        cout << "\r\n" << endl;
    }

    return;
}

/***************************************************************
 * Function:    search()
 * Purpose:     Allows user to search the dungeon
****************************************************************/
void rmGarden::search(Hunter* player)
{
    //Allows user choice to search
    choice = searchMenu.searchChoice();
    
    //if users want to search
    if (choice == 1)
    {
        //if  this is the first time within this room
        if (entryCounter == 1)
        {
            //Displays out information for the user
            cout << "   You search the room...";
            cout << "   It seems like the [Left] path is where the " << endl;
            cout << "   trail of bodies lead to..." << endl;
            cout << "   Meanwhile the [UP] path seems to lead into a" << endl;
            cout << "   shabby looking part of the castle..." << endl;
            cout << "\r\n";
            cout << "   While searching around, it also appears that the" << endl;
            cout << "   dead bodies have lingering exp..." << endl;
            
            //Rewards player with exp
            player->level(50);
            cout << "\r\n";
            //Increment counter
            entryCounter++;
            return;
        }
        
        cout << "   You search the room...";
        cout << "   You find nothing of interest." << endl;
    }
    else
    {
        cout << "   You do not search the room." << endl;
        return;
    }
}
