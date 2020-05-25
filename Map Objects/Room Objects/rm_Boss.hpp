/*************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/25/19
 * Purpose:     Boss room that contains the boss character object.
 *              The boss fight occurs in this room.
***************************************************************/
#ifndef RM_BOSS_HPP
#define RM_BOSS_HPP

#include "space.hpp"
#include "object.hpp"
#include "character.hpp"
#include "hunter.hpp"
#include "boss.hpp"

#include "menu.hpp"
#include "dice.hpp"

#include <string>

using std::cout;
using std::cin;
using std::endl;

class rmBoss : public Space
{
    protected:
        bool gameState;
        int gameTurn;
        int entryCounter;
        int fightCounter;
        int choice;
        int roll;
        Boss* monster;
        Dice die;
        Menu searchMenu;
    public:
        rmBoss();
        void specialEvent(Hunter*);
        void search(Hunter*);
};

#endif