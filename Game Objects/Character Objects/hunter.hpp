/*************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/25/19
 * Purpose:     Hunter class defines the player character 'Hunter'
 *              Introduces special skills and a level up system
 *              that improves character stats throughout the game.
***************************************************************/
#ifndef HUNTER_HPP
#define HUNTER_HPP
#include "object.hpp"
#include "character.hpp"
#include "dice.hpp"
#include "menu.hpp"

#include <iostream>
#include <string>

using std::string;
using std::ostream;
using std::cout;
using std::cin;
using std::endl;

class Hunter : public Character
{
    protected:
        //Character Variables
        int killedBaran;
        int wepDmg;
        int armDef;
        int hpMax;
        int mana;
        Dice die;
        int exp;
        char rank;

        //Equipment variables(Inventory)
        string wepEq;
        string armEq;
        string misc;
        
        //Special Skill Variables
        int spellMultiplier;
        string spellName;
    public:
        Hunter();
        string getname();
        void setname(string);  
        int attacking();
        int defend(int);
        void inflictDmg(int);
        void recovery(int);
        void level(int);
        void setEquipment(string, string, string);
        string getWepEQ();
        string getArmEQ();
        string getMisc();
        char getRank();
        string getDef();
        int getHp();
        int getMp();
        int getArmor();
        void setMp(int);
        void changeWep(int);
        void changeArmor(int);
        int getBaran();
        void setBaran(int);
};       

#endif