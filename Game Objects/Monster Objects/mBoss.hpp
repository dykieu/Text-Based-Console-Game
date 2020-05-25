/*************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/25/19
 * Purpose:     Character derived class. mBoss class defines a
 *              mini-boss type monster with 3 unique skills and
 *              a different 
***************************************************************/
#ifndef MBOSS_HPP
#define MBOSS_HPP

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

class mBoss : public Character
{
    protected:
        Dice die;
        int experience;
    public:
        mBoss();
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