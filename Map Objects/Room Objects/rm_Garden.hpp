/*************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/25/19
 * Purpose:     Garden class derives from space class. Represents
 *              a garden room
***************************************************************/
#ifndef RM_GARDEN_HPP
#define RM_GARDEN_HPP

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

class rmGarden : public Space
{
    protected:
        int entryCounter;
        int choice;
        Menu searchMenu;
    public:
        rmGarden();
        void specialEvent(Hunter*);
        void search(Hunter*);
};

#endif