/*************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/25/19
 * Purpose:     Boss room that contains the boss character object.
 *              The boss fight occurs in this room.
***************************************************************/
#include "rm_Boss.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

/***************************************************************
 * Function:    rmBoss()
 * Purpose:     Defines variables for the boss room
****************************************************************/
rmBoss::rmBoss()
{
    string type = "Throne room";
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
 * Purpose:     Allows user to fight the boss of the dungeon
****************************************************************/
void rmBoss::specialEvent(Hunter* player)
{
    //Displays prompt about room
    cout << "[Throne Room]" << endl;
    cout << "\r\n" << endl;
    cout << "   You have entered Throne Room." << endl;
    cout << "   You instantly feel suffocated by the presence before you." << endl;       
    cout << "\r\n" << endl;

    //If this is the users first time within the room
    if (fightCounter == 1)
    {
        //Displays a description of the boss and applies a debuff for the room
        cout << "   <Demon Lord> Baran sits on hit throne... coldly staring down at you." << endl;
        cout << "\r\n" << endl;
        cout << "   **The suffocating mana of Baran applies a debuff to you. [Debuff Effect]: -50 mp" << endl;

        //Makes sure that user mp does not go below 0
        if (player->getMp() < 50)
        {
            player->setMp(0);
        }
        else
        {
            player->setMp(player->getMp() - 50);
        }
        
        //Creates the boss object and game
        monster = new Boss;
        gameState = true;
        gameTurn = 0;

        //Allows user to fight and interact with the boss
        while (gameState == true)
        {
            //User turn
            if (gameTurn % 2 == 0)
            {
                //Display stats
                cout << "------------------------------------------" << endl;
                cout << " You are attacking " << monster->getname() << endl;
                cout << "   " << monster->getname() << " [HP]: " << monster->getHp() << endl;
                cout << "   <Your Stats> [HP]: " << player->getHp() << "    [MP]: " << player->getMp() << endl;
                cout << "\r\n";

                //attack and defense functions called respectively
                int attRoll = player->attacking();
                int hp = monster->defend(attRoll);

                //If monster dies
                if (hp == 0)
                {
                    //gives user exp and updates that the boss has been defeated
                    gameState = false;
                    player->setBaran(1);
                    player->level(monster->getExp());
                    delete monster;
                    fightCounter++;
                    return;
                }
                
                //increments game turn
                gameTurn++;
            }
            //Boss turn
            else if (gameTurn % 2 == 1)
            {
                //Displays game stats
                cout << "------------------------------------------" << endl;
                cout << monster->getname() << " is attacking you" << endl;

                //calls the respective attack and defenese functions
                int attRoll = monster->attacking();
                int hp = player->defend(attRoll);

                //If user dies
                if (hp == 0)
                {
                    //Returns back to the game function
                    gameState = false;
                    delete monster;
                    fightCounter++;
                    return;
                }
                //incremements turn
                gameTurn++;
            }
        }
    }
    return;  
}

/***************************************************************
 * Function:    search()
 * Purpose:     allows user to search the room
****************************************************************/
void rmBoss::search(Hunter* player)
{
    //Gives user a choice to search room
    choice = searchMenu.searchChoice();
    if (choice == 1)
    {
        //Prints out information
        cout << "   you search the room...";
        cout << "   But there is nothing out of the ordinary." << endl;
        return;
    }
    else
    {
        cout << "   You do not search the room." << endl;
        return;
    }
}