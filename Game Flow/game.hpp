/*************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/25/19
 * Purpose:     Game class will facilitated assigning characters
 *              through the use of menu class. Game class also
 *              facilitates each round of the game, will display
 *              stats relevant to that current game state
***************************************************************/
#ifndef GAME_HPP
#define GAME_HPP

#include "game.hpp"
#include "menu.hpp"
#include "inputVal.hpp"

#include "map.hpp"
#include "space.hpp"
#include "rm_Empty.hpp"

#include "object.hpp"
#include "item.hpp"
#include "character.hpp"
#include "hunter.hpp"

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <fstream>

using std::vector;
using std::string;
using std::fstream;
using std::ios;
using std::cout;
using std::endl;
using std::cin;

class Game
{
    private:
        //Map variables
        Map gameMap;                    //queue
        Space* position;                //node
        Space* temp;
        Space* startAddress;
        vector<Space*> spaceAddress;
        char map[11][9];
        Space* bossRoom;

        //Character Variables
        Hunter test;
        Hunter* tempPlayer;
        string charName;
        vector<Hunter*> delPLayer;

        //Game Variables
        fstream file_I;
        string line;
        int roundCounter;
        bool validDirection;
        Menu gameMenu;
        int direction;
        int xPos;
        int yPos;
        int prevX;
        int prevY;

        //Item variables
        vector<Item*> inventory;
        Item* deleteItem;
        bool foundNew;
    public:
        Game();
        void charFight();
        void playGame();
        void displayMap();
        void newMap();
        void createDung(int, int, int);
        void chooseChar(int);
        void inventoryCheck();
        ~Game();

};

#endif