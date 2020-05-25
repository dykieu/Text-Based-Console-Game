/*************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/25/19
 * Purpose:     rm_MBoss is derived from space class. It is a 
 *              specialized room that allows user to fight with
 *              mBoss object(mini boss)
***************************************************************/
#ifndef RM_MBOSS_HPP
#define RM_MBOSS_HPP

#include "space.hpp"
#include "object.hpp"
#include "character.hpp"
#include "hunter.hpp"
#include "mBoss.hpp"

#include "menu.hpp"
#include "dice.hpp"

#include <string>

using std::cout;
using std::cin;
using std::endl;

class rmMBoss : public Space
{
    protected:
        bool gameState;
        int gameTurn;
        int entryCounter;
        int fightCounter;
        int choice;
        int roll;
        mBoss* monster;
        Dice die;
        Menu searchMenu;
    public:
        rmMBoss();
        void specialEvent(Hunter*);
        void search(Hunter*);
};

#endif