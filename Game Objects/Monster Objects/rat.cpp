/*************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/25/19
 * Purpose:     Rat class is derived from character class. It
 *              is a monster inside the game.
***************************************************************/
#include "rat.hpp"

/***************************************************************
 * Function:    Rat()
 * Purpose:     constructor for character Rat. 
****************************************************************/
Rat::Rat()
{
    name = "Giant Rat";
    health = 10;
    armor = 0;
    attack = "1D6";
    defense = "1D6";
    experience = 50;
}

/***************************************************************
 * Function:    attacking()
 * Purpose:     normal attack function, rolls a dice and returns
 *              the value.
****************************************************************/
int Rat::attacking()
{
    return die.rollDie(attack);
}

/***************************************************************
 * Function:    defend()
 * Purpose:     defense function that takes a dmg input and then
 *              calculates how much damage the rat takes
****************************************************************/
int Rat::defend(int dmg)
{
    //defense roll
    int defRoll = die.rollDie(defense);
    
    //If enemy can't get past your defense
    if (dmg <= (defRoll + armor))
    {
        cout << "   You deal 0 damage"<< endl;
        cout << "   Rat takes no damage" << endl;
        return health; 
    }

    //calculates the total damage inflicted 
    int totaldmg = dmg - (defRoll + armor);
    cout << "   You deal " << totaldmg << " damage"<< endl;

    //If dmg exceeds hp
    if (totaldmg >= health)
    {
        health = health - health;
        cout << "   Rat [HP]: " << health << endl;
        cout << "   **Rat died..." << endl;
        return health;
    }

    //If your hp can handle the dmg
    health = health - totaldmg;
    cout << "   Rat [HP]: " << health << endl;

    //If attack was just enough to make your hp reach 0
    if (health == 0)
    {
        cout << "   **Rat died..." << endl;
        return health;
    }    
    return health;
}

//returns defense value
string Rat::getDef()
{
    return defense;
}

//returns health value
int Rat::getHp()
{
    return health;
}

//returns the armor value
int Rat::getArmor()
{
    return armor;
}

//returns the experience
int Rat::getExp()
{
    return experience;
}

//returns character name
string Rat::getname()
{
    return name;
}

//sets the name of the character
void Rat::setname(string n)
{
    name = n;
} 