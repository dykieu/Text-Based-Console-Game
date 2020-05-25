/*************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/25/19
 * Purpose:     derived from space class. Represents the barracks
 *              space that is used to store ORC characters
***************************************************************/
#ifndef RM_BARRACK_HPP
#define RM_BARRACK_HPP

#include "space.hpp"
#include "object.hpp"
#include "character.hpp"
#include "hunter.hpp"
#include "orc.hpp"

#include "menu.hpp"
#include "dice.hpp"

#include <string>

using std::cout;
using std::cin;
using std::endl;

class rmBarrack : public Space
{
    protected:
        bool gameState;
        int gameTurn;
        int entryCounter;
        int fightCounter;
        int choice;
        int roll;
        Orc* monster;
        Dice die;
        Menu searchMenu;
    public:
        rmBarrack();
        void specialEvent(Hunter*);
        void search(Hunter*);
};

#endif