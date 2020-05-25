/*************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/25/19
 * Purpose:     Boss class defines the final boss of the dungeon
 *              <Demon Lord> Baran. Baran has special attack skills
 *              that deal damage with random rolls. Does not have
 *              any unique defensive skills
***************************************************************/
#ifndef BOSS_HPP
#define BOSS_HPP

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

class Boss : public Character
{
    protected:
        Dice die;
        int experience;
    public:
        Boss();
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