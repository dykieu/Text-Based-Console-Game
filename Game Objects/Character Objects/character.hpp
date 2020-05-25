/*************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/25/19
 * Purpose:     Pure virtual class that will served as the base
 *              class for each character in the combat game
***************************************************************/
#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "object.hpp"
#include "dice.hpp"

#include <iostream>
#include <string>

using std::string;
using std::ostream;

class Character
{
    protected:
        string name;
        string attack;
        string defense;
        int armor;
        int health;
    public:
        Character();
        virtual string getname() = 0;
        virtual void setname(string) = 0;
        virtual int attacking() = 0;
        virtual int defend(int) = 0;
        virtual string getDef() = 0;
        virtual int getHp() = 0;
        virtual int getArmor() = 0;
};


#endif