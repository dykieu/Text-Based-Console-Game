/*************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/25/19
 * Purpose:     rm_TH is derived from space class. Acts as a 
 *              training hall room that users can use to train
 *              their character
***************************************************************/
#include "rm_TH.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::ios;
using std::fstream;
using std::string;

/***************************************************************
 * Function:    rmTH()
 * Purpose:     Defines variables for the training hall room
****************************************************************/
rmTH::rmTH()
{
    string type = "Training hall";
    storedObject = NULL;
    up = NULL;
    down = NULL;
    left = NULL;
    right = NULL;
    entryCounter = 1;
}

/***************************************************************
 * Function:    specialEvent()
 * Purpose:     Allows user the ability to "train" and get exp
****************************************************************/
void rmTH::specialEvent(Hunter* player)
{
    //If this is the user's first time in the room
    if (entryCounter == 1)
    {
        //Displays the room information
        cout << "[Training Hall]" << endl;
        cout << "\r\n" << endl;
        cout << "   You have entered the Training Hall " << endl;
        cout << "   There are training dummies everywhere..." << endl;       
        cout << "   Maybe hitting them will help you get stronger." << endl;
        cout << "\r\n" << endl;

        //Prompts user if they want to train or not
        int train = searchMenu.train();
        if (train == 1)
        {
            //Reward user for hitting dummies
            cout << "   You hit the dummies until exhaustion..." << endl;
            player->level(50);
        }
        else
        {
            cout << "   You do not hit the dummies" << endl;
        }
        
        entryCounter++;
    }
    //If not first time in the room
    else
    {
        cout << "[Training Hall]" << endl;
        cout << "\r\n" << endl;
        cout << "   You have entered the Training Hall." << endl;
        cout << "\r\n" << endl;
    }

    return;
}

/***************************************************************
 * Function:    search()
 * Purpose:     allows user to search the room
****************************************************************/
void rmTH::search(Hunter* player)
{
    //Prompts user if they want to search the room
    choice = searchMenu.searchChoice();
    if (choice == 1)
    {
        cout << "   You search the room...";
        cout << "   You find nothing of interest." << endl;
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
