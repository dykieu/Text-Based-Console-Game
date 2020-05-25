/*************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/25/19
 * Purpose:     rm_Empty is just a standard room, no special 
 *              features.
***************************************************************/
#include "rm_Empty.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::ios;
using std::fstream;
using std::string;

/***************************************************************
 * Function:    rmEmpty()
 * Purpose:     initializes the space variables for this room
****************************************************************/
rmEmpty::rmEmpty()
{
    string type = "Empty room";
    storedObject = NULL;
    up = NULL;
    down = NULL;
    left = NULL;
    right = NULL;
    entryCounter = 1;
}

/***************************************************************
 * Function:    specialevent()
 * Purpose:     Room just contains a prompt that displays the room
 *              info
****************************************************************/
void rmEmpty::specialEvent(Hunter* player)
{
    //If the first time in the room
    if (entryCounter == 1)
    {
        //Displays room and description
        cout << "[Main Courtyard]" << endl;
        cout << "\r\n" << endl;
        cout << "   You have entered the main courtyard of what appears to" << endl;
        cout << "   be a castle. There are no enemies in sight but you feel" << endl;       
        cout << "   an ominous and suffocating presence within the castle." << endl;
        cout << "\r\n" << endl;
        entryCounter++;
    }
    else
    {
        cout << "[Main Courtyard]" << endl;
        cout << "\r\n" << endl;
        cout << "   You have entered the main courtyard." << endl;
        cout << "\r\n" << endl;
    }

    return;
}

/***************************************************************
 * Function:    search()
 * Purpose:     allows user to search the room
****************************************************************/
void rmEmpty::search(Hunter* player)
{
    //gives user a choice to search or not
    choice = searchMenu.searchChoice();

    //IF user searchs
    if (choice == 1)
    {
        //prints out hints
        cout << "you search the room...";
        cout << "here appears to be 3 hallways!" << endl;
        cout << "   [Left] seems to lead to the basement." << endl;
        cout << "   [Right] seems to lead to some room." << endl;
        cout << "   [UP] seems to lead to an outdoor area." << endl;
        cout << "\r\n";
        return;
    }
    else
    {
        cout << "   You do not search the room." << endl;
        return;
    }
}
