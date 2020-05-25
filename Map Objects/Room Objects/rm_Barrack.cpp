/*************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/25/19
 * Purpose:     derived from space class. Represents the barracks
 *              space that is used to store ORC characters
***************************************************************/
#include "rm_Barrack.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

/***************************************************************
 * Function:    rmBarracks()
 * Purpose:     sets default variables for armory space 
****************************************************************/
rmBarrack::rmBarrack()
{
    string type = "Barracks";
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
 * Purpose:     Informs user the room they are in and the special
 *              features within that room
****************************************************************/
void rmBarrack::specialEvent(Hunter* player)
{
    //Prints out the room details and its description
    cout << "[Barracks]" << endl;
    cout << "\r\n" << endl;
    cout << "   You have entered the Baracks." << endl;
    cout << "   It appears this is where the soliders are housed" << endl;       
    cout << "\r\n" << endl;

    //If this is the first time inside the barracks
    if (fightCounter == 1)
    {
        cout << "   A Orc appears!" << endl;
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
                cout << "\r\n";
                fightCounter++;
                return;
            }
            cout << "   You have failed to run away!" << endl;
            cout << "\r\n";
        }

        //Creates a new orc monster
        monster = new Orc;
        gameState = true;
        gameTurn = 0;

        //Finish coding this
        while (gameState == true)
        {
            //User turn
            if (gameTurn % 2 == 0)
            {
                //Prints out the turn stats
                cout << "------------------------------------------" << endl;
                cout << " You are attacking " << monster->getname() << endl;
                cout << "   " << monster->getname() << " [HP]: " << monster->getHp() << endl;
                cout << "\r\n";
                int attRoll = player->attacking();
                int hp = monster->defend(attRoll);

                //If the monster dies
                if (hp == 0)
                {
                    //Gives user exp for defeating the monster
                    gameState = false;
                    player->level(monster->getExp());
                    delete monster;
                    fightCounter++;
                    return;
                }
                
                gameTurn++;
                
            }
            //Enemy turn
            else if (gameTurn % 2 == 1)
            {
                //Prints out the game stats
                cout << "------------------------------------------" << endl;
                cout << monster->getname() << " is attacking you" << endl;

                //Game attack/defend
                int attRoll = monster->attacking();
                int hp = player->defend(attRoll);

                //If user dies
                if (hp == 0)
                {
                    //Returns to the game function and end game.
                    gameState = false;
                    delete monster;
                    fightCounter++;
                    return;
                }
                gameTurn++;
            }
        }
    }

    return;  
}

/***************************************************************
 * Function:    search()
 * Purpose:     Allows user to search the room
****************************************************************/
void rmBarrack::search(Hunter* player)
{
    //Allows user to choose to search to room or not
    choice = searchMenu.searchChoice();
    if (choice == 1)
    {
        //If this is the first time searching the room
        if (entryCounter == 1)
        {
            //Displays hints for user
            cout << "   you search the room...";
            cout << "   There appears to be 2 hallways!" << endl;
            cout << "      [Left] seems to lead to an armory of sorts..." << endl;
            cout << "      [UP] seems to lead to a training hall." << endl;
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