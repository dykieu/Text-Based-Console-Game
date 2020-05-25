/*************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/25/19
 * Purpose:     Orc class is derived from character class. It
 *              is a monster inside the game.
***************************************************************/
#ifndef ORC_HPP
#define ORC_HPP

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

class Orc : public Character
{
    protected:
        Dice die;
        int experience;
    public:
        Orc();
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