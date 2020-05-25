/*************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/25/19
 * Purpose:     rm_MBoss is derived from space class. It is a 
 *              specialized room that allows user to fight with
 *              mBoss object(mini boss)
***************************************************************/
#include "rm_MBoss.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

/***************************************************************
 * Function:    rmMBoss()
 * Purpose:     Defines variables for the mmini-boss room
****************************************************************/
rmMBoss::rmMBoss()
{
    string type = "Cerberus' room";
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
 * Purpose:     Allows user to fight the mini-boss of the dungeon
****************************************************************/
void rmMBoss::specialEvent(Hunter* player)
{
    //Displays info about the room
    cout << "[Cerberus' Room]" << endl;
    cout << "\r\n" << endl;
    cout << "   You have entered Cerberus' Room." << endl;
    cout << "   You feel and intense heat inside the room... one that is almost unbearable." << endl;       
    cout << "\r\n" << endl;

    //If this is the first time entering the room
    if (fightCounter == 1)
    {
        cout << "   <Hell's Gatekeeper> Cerberus appears!" << endl;
        cout << "\r\n" << endl;

        //creates new mini boss
        monster = new mBoss;
        gameState = true;
        gameTurn = 0;

        //facilitates turns during the fight
        while (gameState == true)
        {
            //User turn
            if (gameTurn % 2 == 0)
            {
                //Game stats
                cout << "------------------------------------------" << endl;
                cout << " You are attacking " << monster->getname() << endl;
                cout << "   " << monster->getname() << " [HP]: " << monster->getHp() << endl;
                cout << "   <Your Stats> [HP]: " << player->getHp() << "    [MP]: " << player->getMp() << endl;
                cout << "\r\n";

                //Respective attack and defensive rolls
                int attRoll = player->attacking();
                int hp = monster->defend(attRoll);

                //If monster is dead, reward exp and return to game
                if (hp == 0)
                {
                    gameState = false;
                    player->level(monster->getExp());
                    delete monster;
                    fightCounter++;
                    return;
                }
                //Increments the turn  
                gameTurn++;
            }
            //Monster turn
            else if (gameTurn % 2 == 1)
            {
                //prints out game stats
                cout << "------------------------------------------" << endl;
                cout << monster->getname() << " is attacking you" << endl;

                //Gets respective attack and defend rolls/functions
                int attRoll = monster->attacking();
                int hp = player->defend(attRoll);

                //If user dies return to game and quit
                if (hp == 0)
                {
                    gameState = false;
                    delete monster;
                    fightCounter++;
                    return;
                }
                //Increments the turn
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
void rmMBoss::search(Hunter* player)
{
    //lets user choose to search the room
    choice = searchMenu.searchChoice();
    if (choice == 1)
    {
        //If key not picked up yet
        if (entryCounter == 1)
        {
            //Display info about the key
            cout << "   You search the room..." << endl;
            cout << "   You find: "<< endl;
            cout << "       a <Key>..." << endl;
            cout << "       Item Description: Key to open the door to the boss" << endl;
            cout << "\r\n";

            //IF there is already an item in the misc slot of inventory
            if (player->getMisc() != "empty")
            {
                cout << "   You currently have a item in misc." << endl;
                cout << "   If you pick up a new item, the old one will be lost." << endl;
            }

            //Asks user if they want to pick up the key
            int equip = searchMenu.equipItem();

            //IF user decides to pick up the key/equip it
            if (equip == 1)
            {
                player->setEquipment(player->getWepEQ(), player->getArmEQ(), "key");
                
                //increments counter only if user grabs key(Allows user to come back)
                entryCounter++;
            }

            //Prints out a hint at the end
            cout << "   you look around the room and notice a hallway leading [UP]" << endl;
            cout << "   [UP] seems to lead to a room with a ominous aura." << endl;
            cout << "\r\n";
            return;
        }
        //If already picked up the key
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