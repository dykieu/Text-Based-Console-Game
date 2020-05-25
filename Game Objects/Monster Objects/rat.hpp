/*************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/25/19
 * Purpose:     Rat class is derived from character class. It
 *              is a monster inside the game.
***************************************************************/
#ifndef RAT_HPP
#define RAT_HPP

#include "object.hpp"
#include "character.hpp"
#include "dice.hpp"

#include <iostream>
#include <string>

using std::string;
using std::ostream;
using std::cout;
using std::cin;
using std::endl;

class Rat : public Character
{
    protected:
        Dice die;
        int experience;
    public:
        Rat();
        int attacking();
        int defend(int);
        string getDef();
        int getHp();
        int getArmor();
        int getExp();
        string getname();
        void setname(string); 
};

#endif