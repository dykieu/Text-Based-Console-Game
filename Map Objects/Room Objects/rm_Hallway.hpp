/*************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/25/19
 * Purpose:     Derived from space class. Hallway class is 
 *              essentially a empty room that just acts to 
 *              transition users between rooms.
***************************************************************/
#ifndef RM_HALLWAY_HPP
#define RM_HALLWAY_HPP

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

class rmHall : public Space
{
    protected:
        int entryCounter;
        int choice;
        int roll;
        Dice die;
        Menu searchMenu;
    public:
        rmHall();
        void specialEvent(Hunter*);
        void search(Hunter*);
};

#endif