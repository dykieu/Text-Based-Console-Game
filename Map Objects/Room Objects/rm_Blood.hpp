/*************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/25/19
 * Purpose:     Node class contains the general memeber variables
 *              that make up a node object. Will have points to
 *              help link up node objects to create a list.
***************************************************************/
#ifndef RM_BLOOD_HPP
#define RM_BLOOD_HPP

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

class rmBlood : public Space
{
    protected:
        bool gameState;
        int gameTurn;
        int entryCounter;
        int choice;
        int roll;
        Dice die;
        Menu searchMenu;
    public:
        rmBlood();
        void specialEvent(Hunter*);
        void search(Hunter*);
};

#endif