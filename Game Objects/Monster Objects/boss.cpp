/*************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/25/19
 * Purpose:     Boss class defines the final boss of the dungeon
 *              <Demon Lord> Baran. Baran has special attack skills
 *              that deal damage with random rolls. Does not have
 *              any unique defensive skills
***************************************************************/
#include "boss.hpp"

/***************************************************************
 * Function:    Boss()
 * Purpose:     Constructor for variables that define Baran
****************************************************************/
Boss::Boss()
{
    name = "<Demon Lord> Baran";
    health = 200;
    armor = 2;
    attack = "2D12";
    defense = "2D12";
    experience = 600;
}

/***************************************************************
 * Function:    Attacking()
 * Purpose:     Function defines 3 of barans skills, rolls and
 *              returns an attack value
****************************************************************/
int Boss::attacking()
{
    //30% to user a skill to attack
    //10% each skill
    int roll = (rand() % 10) + 1;
    if (roll == 1)
    {
        cout << name << " uses the skill {Moonlight Slash}" << endl;
        return ((rand() % 70) + 30);
    }
    else if (roll == 2 || roll == 3)
    {
        cout << name << " uses the skill {Vortex Blade}" << endl;
        return ((rand() % 20) + 20);
    }
    else if (roll == 4 || roll == 5)
    {
        cout << name << " uses the skill {Monarch's Roar}" << endl;
        return ((rand() % 20) + 20);
    }

    //Basic attack
    return die.rollDie(attack);
}

/***************************************************************
 * Function:    Defend(0)
 * Purpose:     Basic defensive function that accepts attack from
 *              opponent and calculates dmg taken based on the
 *              characters defensive values
****************************************************************/
int Boss::defend(int dmg)
{
    //Defense roll
    int defRoll = die.rollDie(defense);
    
    //If enemy can't get past your defense
    if (dmg <= (defRoll + armor))
    {
        cout << "   You deal 0 damage"<< endl;
        cout << "   " << name << " takes no damage" << endl;
        return health; 
    }

    //Calculates total damage dealt
    int totaldmg = dmg - (defRoll + armor);
    cout << "   You deal " << totaldmg << " damage"<< endl;

    //If dmg exceeds hp
    if (totaldmg >= health)
    {
        health = health - health;
        cout << "   " << name << " [HP]: " << health << endl;
        cout << "   **" << name << " died..." << endl;
        return health;
    }

    //If your hp can handle the dmg
    health = health - totaldmg;
    cout << "   " << name << " [HP]: " << health << endl;

    //If attack was just enough to make your hp reach 0
    if (health == 0)
    {
        cout << "   **" << name << " died..." << endl;
        return health;
    }    
    return health;
}

//Returns defense value
string Boss::getDef()
{
    return defense;
}

//returns health value
int Boss::getHp()
{
    return health;
}

//Returns armor value
int Boss::getArmor()
{
    return armor;
}

//Returns exp rewarded
int Boss::getExp()
{
    return experience;
}

//Returns monster name
string Boss::getname()
{
    return name;
}

//Allows user to set name
void Boss::setname(string n)
{
    name = n;
} 