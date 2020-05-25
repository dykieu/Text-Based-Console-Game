/*************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/25/19
 * Purpose:     Main will serve to facilitate the transition 
 *              between menu options while also initializing
 *              the game. 
***************************************************************/
#include "inputVal.hpp"
#include "menu.hpp"
#include "game.hpp"                                                                                                                       

#include <iostream>
#include <string>

using std::string;
using std::endl;
using std::cout;
using std::cin;

/***************************************************************
 * Function:    Main()
 * Purpose:     facilitates the start of the game and a exit msg
 *              at the end of the game.
****************************************************************/
int main()
{
    //Declarations
    Menu startGame;
    Game newGame;
    int userChoice;
    bool gameState = true;

    //Asks user if they want to play or exit
    userChoice = startGame.selection(); 

    //If user chooses to play the game
    if (userChoice == 1)
    {
        cout << "###################################################################" << endl;
        startGame.gameDescription();
        newGame.playGame();
        startGame.exitProg();
    }
    //User chooses to not play the game
    else if (userChoice == 2)
    {
        //Exit message and closes program
        startGame.exitProg();
        
    }
    
    return 0;

}