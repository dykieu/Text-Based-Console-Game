/*************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/25/19
 * Purpose:     derived from space class. Represents the basement.
 *              Contains a space where user fight the character
 *              rat
***************************************************************/
#ifndef RM_BASE_HPP
#define RM_BASE_HPP

#include "space.hpp"
#include "object.hpp"
#include "character.hpp"
#include "hunter.hpp"
#include "rat.hpp"

#include "menu.hpp"
#include "dice.hpp"

#include <string>

using std::cout;
using std::cin;
using std::endl;

class rmBase : public Space
{
    protected:
        bool gameState;
        int gameTurn;
        int entryCounter;
        int fightCounter;
        int choice;
        int roll;
        Rat* monster;
        Dice die;
        Menu searchMenu;
    public:
        rmBase();
        void specialEvent(Hunter*);
        void search(Hunter*);
};

#endif