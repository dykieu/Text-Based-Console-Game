/*************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/25/19
 * Purpose:     Hunter class defines the player character 'Hunter'
 *              Introduces special skills and a level up system
 *              that improves character stats throughout the game.
***************************************************************/
#include "hunter.hpp"

/***************************************************************
 * Function:    Hunter()
 * Purpose:     initializes variables for the Hunter Character
****************************************************************/
Hunter::Hunter()
{
    //Character Stats
    attack = "1D6";
    defense = "1D6";
    rank = 'E';
    armor = 0;
    health = 100;
    mana = 100;
    hpMax = health;
    exp = 0;

    //Spell variables
    spellMultiplier = 1;
    spellName = "Deadly Strike<I>";

    //Item bonuses
    wepDmg = 0;
    armDef = 0;

    //Items
    wepEq = "empty";
    armEq = "empty";
    misc = "empty";

    //Achievements:
    killedBaran = 0;
}

/***************************************************************
 * Function:    inflictDmg()
 * Purpose:     Deals TRUE dmg to the Hunter(Traps within game).
****************************************************************/
void Hunter::inflictDmg(int dmg)
{
    //IF damage exceeds the amount of health, prevents health from going negative
    if (dmg >= health)
    {
        health = health - health;
        cout << "   due to the impact you take " << dmg << " damage." << endl;
        cout << "   [HP]: " << health << endl;
    }
    else if (health > dmg)
    {
        health = health - dmg;
        cout << "   due to the impact you take " << dmg << " damage." << endl;
        cout << "   [HP]: " << health << endl;
    }
    
}

/***************************************************************
 * Function:    attacking()
 * Purpose:     Function for when hunter attacks. Allows the
 *              hunter to choose to use a normal attack or spell.
 *              Rolls for a normal attack or use a spell which
 *              does a flat damage + multiplier
****************************************************************/
int Hunter::attacking()
{
    int choice;
    Menu attMenu;
    choice = attMenu.AttOrSpell();

    //If user chooses to use a spell
    if (choice == 2)
    {
        //If user has enough mana for the spell
        if (mana >= 10)
        {
            //Uses spell and returns the dmg inflicted by the spell
            cout << "   You use " << spellName << endl;
            mana = mana - 10;
            return (25 * 1) + wepDmg;
        }

        cout << "   No enought mana!" << endl;
        cout << "   **You use normal attacks instead" << endl;
    }
    
    //Attack damage + wep bonus
    return die.rollDie(attack) + wepDmg;
}

/***************************************************************
 * Function:    defend()
 * Purpose:     Basic defense function that takes into account of
 *              def dice roll, armor, and any other reductions
 *              It prints out updated stats.
****************************************************************/
int Hunter::defend(int dmg)
{
    //Rolls a dice for the def roll
    int defRoll = die.rollDie(defense);
    
    //If enemy can't get past your defense
    if (dmg <= (defRoll + armor + armDef))
    {
        cout << "   You block the attack" << endl;
        return health; 
    }

    //Calculates the total damage dealt by the enemy
    int totaldmg = dmg - (defRoll + armor + armDef);
    cout << "   You take " << totaldmg << " damage"<< endl;

    //If dmg exceeds hp
    if (totaldmg >= health)
    {
        health = health - health;
        cout << "   [HP]: " << health << endl;
        cout << "   **You have died..." << endl;
        return health;
    }

    //If your hp can handle the dmg
    health = health - totaldmg;
    cout << "   [HP]: " << health << endl;

    //If attack was just enough to make your hp reach 0
    if (health == 0)
    {
        cout << "   **You have died..." << endl;
        return health;
    }
    
    return health;
}

/***************************************************************
 * Function:    recovery()
 * Purpose:     Allows user to recover hp (This is for the blood
 *              room). 
****************************************************************/
void Hunter::recovery(int restore)
{
    //If health is restored max the max, set it to max
    if ((health + restore) > hpMax)
    {
        health = hpMax;
    }
    else
    {
        health = health + restore;
    }
    return;
}

/***************************************************************
 * Function:    level()
 * Purpose:     Function that updates the hunter's experience 
 *              points. If the hunter is a certain rank and meets
 *              a exp threshold, they will level up. The function 
 *              is ran 5 times in the case that exp exceeds multiple
 *              level thresholds.
****************************************************************/
void Hunter::level(int experience)
{
    //Prints out how much exp was gained
    cout << "       gained " << experience << " exp" << endl;
    exp = exp + experience;

    //Loops through 5 times to make sure that all level ups are accounted for
    int i = 5;
    while (i > 0)
    {
        switch (rank)
        {
        //Rank up to D
        case 'E':
            //User levels up to rank D
            if (exp >= 50)
            {
                //Updates stats
                rank = 'D';
                attack = "1D12";
                defense = "1D12";
                cout << "Congrats, you have ranked up!" << endl;
                cout << "   Rank: " << rank << endl;
                i--;
            }
            i--;
            break;
        //Rank up to C
        case 'D':
            //User levels up to rank C
            if (exp >= 100)
            {
                //Update stats
                rank = 'C';
                attack = "2D6";
                defense = "2D6";
                cout << "Congrats, you have ranked up!" << endl;
                cout << "   Rank: " << rank << endl;
                i--;
            }
            i--;
            break;
        //Rank up to B
        case 'C':
            //User levels up to rank B
            if (exp >= 200)
            {
                //Update Stats
                rank = 'B';
                attack = "2D10";
                defense = "2D10";
                spellMultiplier = 2;
                cout << "Congrats, you have ranked up!" << endl;
                cout << "   Rank: " << rank << endl;
                cout << "   " << spellName << " has evolved into Deadly Strike<II>" << endl;
                cout << "       It will now deal more damage." << endl;

                //Upgrades spell
                spellName = "Deadly Strike[II]";
                i--;
            }
            i--;
            break;
        //Rank up to A
        case 'B':
            //User levels up to rank A
            if (exp >= 250)
            {
                //Update Stats
                rank = 'A';
                attack = "2D12";
                defense = "2D12";
                cout << "Congrats, you have ranked up!" << endl;
                cout << "   Rank: " << rank << endl;
                i--;
            }
            i--;
            break;
        //Rank up to S
        case 'A':
            //User levels up to rank S
            if (exp >= 400)
            {
                //Update Stats
                rank = 'S';
                attack = "3D99";
                cout << "Congrats, you have ranked up!" << endl;
                cout << "   Rank: " << rank << endl;
                cout << "   " << spellName << " has evolved into Deadly Strike<III>" << endl;
                cout << "       It will now deal more damage." << endl;
                //Upgrades spell
                spellMultiplier = 5;
                spellName = "Deadly Strike<III>";
                i--;
            }
            i--;
            break;          
        default:
            i--;
            break;
        }
    }
    return;
}

//Returns hunter rank
char Hunter::getRank()
{
    return rank;
}

//Returns hunter def dice
string Hunter::getDef()
{
    return defense;
}

//Returns hunter health
int Hunter::getHp()
{
    return health;
}

//Returns hunter mana
int Hunter::getMp()
{
    return mana;
}

//Returns hunter armor
int Hunter::getArmor()
{
    return armor;
}

//Returns hunter name
string Hunter::getname()
{
    return name;
}

//sets hunter name
void Hunter::setname(string n)
{
    name = n;
}

//Sets hunter mp
void Hunter::setMp(int value)
{
    mana = value;
}

//Allows hunter to equip certain items
void Hunter::setEquipment(string wep, string armor, string miscItem)
{
    //Sets the items
    wepEq = wep;
    armEq = armor;
    misc = miscItem;
    return;
}

//returns what weapon hunter is wearing
string Hunter::getWepEQ()
{
    return wepEq;
}

//returns what armor hunter is  wearing
string Hunter::getArmEQ()
{
    return armEq;
}

//Returns any misc items the hunter is holding
string Hunter::getMisc()
{
    return misc;
}

//If a weapon is equiped, change the bonus to match it
void Hunter::changeWep(int value)
{
    wepDmg = value;
}

//if a armor is equipped, change the bonus to match
void Hunter::changeArmor(int value)
{
    armDef = value;
}

//Trophy if hunter kills the finall boss
int Hunter::getBaran()
{
    return killedBaran;
}

//Sets variable that indicates that user has killed baran
void Hunter::setBaran(int value)
{
    killedBaran = value;
}