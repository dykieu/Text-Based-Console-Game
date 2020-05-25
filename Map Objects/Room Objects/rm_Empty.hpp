/*************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/25/19
 * Purpose:     Main room, empty room with no special functions
***************************************************************/
#ifndef RM_EMPTY_HPP
#define RM_EMPTY_HPP

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

class rmEmpty : public Space
{
    protected:
        int entryCounter;
        int choice;
        Menu searchMenu;
    public:
        rmEmpty();
        void specialEvent(Hunter*);
        void search(Hunter*);
};

#endif