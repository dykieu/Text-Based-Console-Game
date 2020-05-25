/*************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/25/19
 * Purpose:     Item class is derived from object class. 
 *              Functions to be a template for item creation
 *              during the game.
***************************************************************/
#include "item.hpp"

/***************************************************************
 * Function:    Item()
 * Purpose:     initializes variables for a starting item
****************************************************************/
Item::Item()
{
    name = "none";
    type = "none";
    attackPower = 0;
    defensePower = 0;
}

//Sets the attack power of the item
void Item::setAttPwr(int value)
{
    attackPower = value;
}

//Sets the def power of the item
void Item::setDefPwr(int value)
{
    defensePower = value;
}

//returns the attack power of the item
int Item::getAttPwr()
{
    return attackPower;
}

//returns the def power of the item
int Item::getDefPwr()
{
    return defensePower;
}

//Sets what the item type is
void Item::setType(string value)
{
    type = value;
}

//returns item type
string Item::getType()
{
    return type;
}