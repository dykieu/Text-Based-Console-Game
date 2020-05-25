/*************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/25/19
 * Purpose:     Derived from space class. Hidden room has a 
 *              special search function that allows user to
 *              find a hidden item.
***************************************************************/
#ifndef RM_HIDE_HPP
#define RM_HIDE_HPP

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

class rmHide : public Space
{
    protected:
        int entryCounter;
        int choice;
        Menu searchMenu;
    public:
        rmHide();
        void specialEvent(Hunter*);
        void search(Hunter*);
};

#endif