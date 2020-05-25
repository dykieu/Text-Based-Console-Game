/*************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/25/19
 * Purpose:     derived from space class. Represents the basement.
 *              Contains a space where user fight the character
 *              rat
***************************************************************/
#include "rm_Base.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

/***************************************************************
 * Function:    rmBase()
 * Purpose:     sets default variables for basement space 
****************************************************************/
rmBase::rmBase()
{
    string type = "Basement";
    storedObject = NULL;
    up = NULL;
    down = NULL;
    left = NULL;
    right = NULL;
    entryCounter = 1;
    fightCounter = 1;
    gameTurn = 0;
    gameState = true;
}

/***************************************************************
 * Function:    specialEvent()
 * Purpose:     Has user fight a rat character
****************************************************************/
void rmBase::specialEvent(Hunter* player)
{
    //Prints out basement description
    cout << "[Basement]" << endl;
    cout << "\r\n" << endl;
    cout << "   You have entered what appears to be the basement." << endl;
    cout << "   You are greeted with a foul smelling odor..." << endl;       
    cout << "\r\n" << endl;

    //If first time in the dungeon
    if (fightCounter == 1)
    {
        cout << "   A Giant rat appears!" << endl;
        cout << "\r\n" << endl;

        //Asks users if they want to fight or run
        choice = searchMenu.fightRun();

        //If user wants to run
        if (choice == 2)
        {
            //Rolls dice to run
            roll = (rand() % 100) + 1;

            //If roll is high enough, user escapes
            if (roll >= 90)
            {
                cout << "   You have successfully run away!" << endl;
                return;
            }
            cout << "   You have failed to run away!" << endl;
        }

        //Setsup the battle
        monster = new Rat;
        gameState = true;
        gameTurn = 0;

        //Fight till one is dead
        while (gameState == true)
        {
            //user turn
            if (gameTurn % 2 == 0)
            {
                //game states
                cout << "------------------------------------------" << endl;
                cout << " You are attacking " << monster->getname() << endl;
                cout << "   " << monster->getname() << " [HP]: " << monster->getHp() << endl;
                cout << "   <Your Stats> [HP]: " << player->getHp() << "    [MP]: " << player->getMp() << endl;
                cout << "\r\n";

                //Attack and defense rolls
                int attRoll = player->attacking();
                int hp = monster->defend(attRoll);

                //If the monster dies
                if (hp == 0)
                {
                    //rewards exp and returns
                    gameState = false;
                    player->level(monster->getExp());
                    fightCounter++;
                    delete monster;
                    return;
                }
                
                //increment turn
                gameTurn++;
            }
            //Monster turn
            else if (gameTurn % 2 == 1)
            {
                //prints out game stats
                cout << "------------------------------------------" << endl;
                cout << monster->getname() << " is attacking you" << endl;

                //attack and defense functions called
                int attRoll = monster->attacking();
                int hp = player->defend(attRoll);

                //IF user dies returns to the main menu and quit
                if (hp == 0)
                {
                    gameState = false;
                    delete monster;
                    return;
                }

                //increments turn
                gameTurn++;
            }
        }
    }
    return;  
}

void rmBase::search(Hunter* player)
{
    choice = searchMenu.searchChoice();
    if (choice == 1)
    {
        //If user's first time within the dungeon
        if (entryCounter == 1)
        {
            //Provides users with a hint
            cout << "   you search the room...";
            cout << "   There appears to be a hidden door!" << endl;
            cout << "       Maybe you should head [DOWN] past the hallway" << endl;
            cout << "       There might be a room at the end of the hallway" << endl;
            cout << "\r\n";
            entryCounter++;
            return;
        }
        else
        {
            cout << "   you search the room...";
            cout << "   But there is nothing out of the ordinary." << endl;
            return;
        }    
    }
    else
    {
        cout << "   You do not search the room." << endl;
        return;
    }
}
