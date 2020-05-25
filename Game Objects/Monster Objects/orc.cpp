/*************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/25/19
 * Purpose:     Orc class is derived from character class. It
 *              is a monster inside the game.
***************************************************************/
#include "orc.hpp"

/***************************************************************
 * Function:    Orc()
 * Purpose:     constructor for orc character
****************************************************************/
Orc::Orc()
{
    name = "Orc";
    health = 30;
    armor = 2;
    attack = "2D6";
    defense = "1D6";
    experience = 50;
}

/***************************************************************
 * Function:    attacking()
 * Purpose:     attack function for orc, has the chance to use a
 *              skill
****************************************************************/
int Orc::attacking()
{
    //10% to user a skill to attack
    if ((rand() % 100) + 1 >= 90)
    {
        cout << "   Orc uses the skill {OVERHAUL}" << endl;
        return 20;
    }
    //Normal attack
    return die.rollDie(attack);
}

/***************************************************************
 * Function:    defend()
 * Purpose:     Normal defend function that accepts the amount of
 *              damage the attacker is outputting and calculates
 *              the total damage that the orc receives 
****************************************************************/
int Orc::defend(int dmg)
{
    int defRoll = die.rollDie(defense);
    
    //If enemy can't get past your defense
    if (dmg <= (defRoll + armor))
    {
        cout << "   You deal 0 damage"<< endl;
        cout << "   Orc takes no damage" << endl;
        return health; 
    }

    //Calculates total damage
    int totaldmg = dmg - (defRoll + armor);
    cout << "   You deal " << totaldmg << " damage"<< endl;

    //If dmg exceeds hp
    if (totaldmg >= health)
    {
        health = health - health;
        cout << "   ORC [HP]: " << health << endl;
        cout << "   **ORC died..." << endl;
        return health;
    }

    //If your hp can handle the dmg
    health = health - totaldmg;
    cout << "   ORC [HP]: " << health << endl;

    //If attack was just enough to make your hp reach 0
    if (health == 0)
    {
        cout << "   **ORC died..." << endl;
        return health;
    }    
    return health;
}

//Returns defense value
string Orc::getDef()
{
    return defense;
}

//returns health value
int Orc::getHp()
{
    return health;
}

//returns armor value
int Orc::getArmor()
{
    return armor;
}

//returns experience points 
int Orc::getExp()
{
    return experience;
}

//returns character name
string Orc::getname()
{
    return name;
}

//sets the character name
void Orc::setname(string n)
{
    name = n;
} 