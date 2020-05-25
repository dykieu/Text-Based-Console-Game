/*************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/25/19
 * Purpose:     Character derived class. mBoss class defines a
 *              mini-boss type monster with 3 unique skills and
 *              a different 
***************************************************************/
#include "mBoss.hpp"

/***************************************************************
 * Function:    mBoss()
 * Purpose:     Initializes the variables that make the mini-boss
****************************************************************/
mBoss::mBoss()
{
    name = "Cerberus";
    health = 100;
    armor = 2;
    attack = "2D10";
    defense = "2D6";
    experience = 200;
}

/***************************************************************
 * Function:    attacking()
 * Purpose:     Attack function for the mini-boss. It defines 3
 *              skills that cerberus can use or a normal attack.
****************************************************************/
int mBoss::attacking()
{
    //35% to use a skill
    int roll = (rand() % 100) + 1;
    if (roll >= 85)
    {
        cout << "   Cerberus uses the skill {FEIRY BREATH}" << endl;
        return 30;
    }
    else if (roll >= 75)
    {
        cout << "   Cerberus uses the skill {TRIPLE SMASH}" << endl;
        return 20;
    }
    else if (roll >= 65)
    {
        cout << "   Cerberus uses the skill {BITE}" << endl;
        return 20;
    }

    return die.rollDie(attack);
}

/***************************************************************
 * Function:    defend()
 * Purpose:     normal defense function, cerberus doesn't have any
 *              special defensive functions.
****************************************************************/
int mBoss::defend(int dmg)
{
    //Rolls dice for a defensive roll
    int defRoll = die.rollDie(defense);
    
    //If enemy can't get past your defense
    if (dmg <= (defRoll + armor))
    {
        cout << "   You deal 0 damage"<< endl;
        cout << "   CERBERUS takes no damage" << endl;
        return health; 
    }

    //Total damage dealt to the monster
    int totaldmg = dmg - (defRoll + armor);
    cout << "   You deal " << totaldmg << " damage"<< endl;

    //If dmg exceeds hp
    if (totaldmg >= health)
    {
        health = health - health;
        cout << "   CERBERUS [HP]: " << health << endl;
        cout << "   **CERBERUS died..." << endl;
        return health;
    }

    //If your hp can handle the dmg
    health = health - totaldmg;
    cout << "   CERBERUS [HP]: " << health << endl;

    //If attack was just enough to make your hp reach 0
    if (health == 0)
    {
        cout << "   **CERBERUS died..." << endl;
        return health;
    }    
    return health;
}

//returns def roll
string mBoss::getDef()
{
    return defense;
}

//returns health
int mBoss::getHp()
{
    return health;
}

//returns armor
int mBoss::getArmor()
{
    return armor;
}

//returns exp rewarded
int mBoss::getExp()
{
    return experience;
}

//returns monster name
string mBoss::getname()
{
    return name;
}

//sets monster name
void mBoss::setname(string n)
{
    name = n;
} 