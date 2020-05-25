/*************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/25/19
 * Purpose:     derived from space class. Represents and armory
 *              space where users can pick up items
***************************************************************/
#ifndef RM_ARMORY_HPP
#define RM_ARMORY_HPP

#include "space.hpp"
#include "object.hpp"
#include "character.hpp"
#include "hunter.hpp"
#include "menu.hpp"

#include <string>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;

class rmArmory : public Space
{
    protected:
        int entryCounter;
        int choice;
        Menu searchMenu;
    public:
        rmArmory();
        void specialEvent(Hunter*);
        void search(Hunter*);
};

#endif