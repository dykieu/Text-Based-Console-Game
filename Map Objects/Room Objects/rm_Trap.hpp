/*************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/25/19
 * Purpose:     rm_Trap is derived from space class. rm_Trap 
 *              functions to deal damage to a target that enters
 *              the room.
***************************************************************/
#ifndef RM_TRAP_HPP
#define RM_TRAP_HPP

#include "space.hpp"
#include "object.hpp"
#include "character.hpp"
#include "hunter.hpp"

#include "menu.hpp"
#include "dice.hpp"

#include <string>

using std::cout;
using std::cin;
using std::endl;

class rmTrap : public Space
{
    protected:
        int entryCounter;
        int choice;
        int roll;
        Dice die;
        Menu searchMenu;
    public:
        rmTrap();
        void specialEvent(Hunter*);
        void search(Hunter*);
};

#endif