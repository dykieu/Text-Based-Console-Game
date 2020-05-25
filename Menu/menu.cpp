/**********************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/25/19
 * Purpose:     Menu Class contains functions that prompt users
 *              with an interface and allows user to choose to
 *              play the game or quit. Also contains all user inferface
 *              questions.
**********************************************************************/
#include <iostream>
#include "menu.hpp"
#include "inputVal.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::ios;
using std::fstream;
using std::string;

/***************************************************************
 *                  Menu::selection()
 * prompts user to either play the game or quit
****************************************************************/
int Menu::selection()
{
    //Menu selection and validation.
    cout << "Welcome to the program menu." << endl;
    cout << "Please choose from the following options:" << endl;
    cout << "   1. Enter '1' to start the Solo-Leveling game." << endl;
    cout << "   2. Enter '2' to exit the program" << endl;

    input = introCheck(1, 2);
    return input;
}

/***************************************************************
 * Function:    searchChoice()
 * Purpose:     prompts user to search the room
****************************************************************/
int Menu::searchChoice()
{
    cout << "Would you like to search the room?" << endl;
    cout << "   <1> Enter '1' to search." << endl;
    cout << "   <2> Enter '2' to not search" << endl;

    return introCheck(1, 2);
}

/***************************************************************
 *                  Menu::exitProg()
 * Displays an exit message for users
****************************************************************/
int Menu::exitProg()
{
    cout << "Thank you for using the program." << endl;
    cout << "Program exitting now." << endl;

    return 2;
}

/***************************************************************
 * Function:    directionChoice()
 * Purpose:     prints out options for user to move their char
****************************************************************/
int Menu::directionChoice()
{
    cout << "Which direction would you to head in?" << endl;
    cout << "   <1> Enter '1' [UP]" << endl;
    cout << "   <2> Enter '2' [DOWN]" << endl;
    cout << "   <3> Enter '3' [LEFT]" << endl;
    cout << "   <4> Enter '4' [RIGHT]" << endl;
    return introCheck(1, 4);
}

/***************************************************************
 * Function:    gameDescription()
 * Purpose:     Prints out the task and description of the game
****************************************************************/
void Menu::gameDescription()
{
    file_I.open("gameDescription.txt", ios::in);

    while (getline(file_I, line))
    {
        cout << line << endl;
    }
    file_I.close();
    cout << "[Enter '1'] to continue...";
    introCheck(1, 1);

    file_I.open("task.txt", ios::in);
    while (getline(file_I, line))
    {
        cout << line << endl;
    }
    file_I.close();
    cout << "[Enter '1'] to continue...";
    introCheck(1, 1);
    return;
}

/***************************************************************
 * Function:    gameEnd()
 * Purpose:     Prints out the game ending message
****************************************************************/
void Menu::gameEnd()
{
    file_I.open("gameOver.txt", ios::in);

    while (getline(file_I, line))
    {
        cout << line << endl;
    }
    file_I.close();
    cout << "[Enter '1'] to continue...";
    introCheck(1, 1);
    return;    
}

/***************************************************************
 * Function:    gameWon()
 * Purpose:     prints out the game winning message
****************************************************************/
void Menu::gameWon()
{
    file_I.open("gameWon.txt", ios::in);

    while (getline(file_I, line))
    {
        cout << line << endl;
    }
    file_I.close();
    cout << "[Enter '1'] to continue...";
    introCheck(1, 1);
    return;    
}

/***************************************************************
 * Function:    fightRun()
 * Purpose:     asks user if they want to attempt to run or fight
****************************************************************/
int Menu::fightRun()
{
    cout << "What would you like to do" << endl;
    cout << "   <1> Enter '1' to [FIGHT]" << endl;
    cout << "   <2> Enter '2' to [RUN]" << endl;

    return introCheck(1, 2);
}

/***************************************************************
 * Function:    drink()
 * Purpose:     prompts user if they want to drink the substance
****************************************************************/
int Menu::drink()
{
    cout << "   <1> Enter '1' to drink blood" << endl;
    cout << "   <2> Enter '2' to not drink blood" << endl;

    return introCheck(1, 2);
}

/***************************************************************
 * Function:    gameDescription()
 * Purpose:     prompts user and asks them if they want to train
****************************************************************/
int Menu::train()
{
    cout << "   <1> Enter '1' to hit dummies" << endl;
    cout << "   <2> Enter '2' to not hit dummies" << endl;

    return introCheck(1, 2);
}

/***************************************************************
 * Function:    equipItem()
 * Purpose:     prompts user if they want to pickup an item
****************************************************************/
int Menu::equipItem()
{
    cout << "   <1> Enter '1' to pick up item" << endl;
    cout << "   <2> Enter '2' to not pick up item" << endl;

    return introCheck(1, 2);
}

/***************************************************************
 * Function:    AttOrSpell()
 * Purpose:     prompts user for attack or spell 
****************************************************************/
int Menu::AttOrSpell()
{
    cout << "What would you like to do" << endl;
    cout << "   <1> Enter '1' to Attack Normally" << endl;
    cout << "   <2> Enter '2' to Use a Spell [Cost: 10 mp]" << endl;

    return introCheck(1, 2);
}

/***************************************************************
 *                  Menu::playAgain()
 * Prompts user to play again or not.
****************************************************************/
int Menu::playAgain()
{
    cout << "Welcome to the program menu." << endl;
    cout << "Please choose from the following options:" << endl;
    cout << "   1. Enter '1' to Play again." << endl;
    cout << "   2. Enter '2' to exit the program" << endl;
    return introCheck(1, 2);
}
