/*************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/25/19
 * Purpose:     rm_TH is derived from space class. Acts as a 
 *              training hall room that users can use to train
 *              their character
***************************************************************/
#ifndef RM_TH_HPP
#define RM_TH_HPP

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

class rmTH : public Space
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
        rmTH();
        void specialEvent(Hunter*);
        void search(Hunter*);
};

#endif