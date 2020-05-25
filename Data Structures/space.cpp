/*************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/25/19
 * Purpose:     Space class functions as "rooms" for characters
 *              to interact with.
***************************************************************/
#include "space.hpp"

Space::Space()
{
}

//returns type
string Space::getType()
{
    return type;
}

//sets hunter object
void Space::setObject(Hunter* character)
{
    storedObject = character;
}

//sets the room up
void Space::setUp(Space* nextRoom)
{
    up = nextRoom;
}

//set the room down
void Space::setDown(Space* nextRoom)
{
    down = nextRoom;
}

//sets the room left
void Space::setLeft(Space* nextRoom)
{
    left = nextRoom;
}

//sets the room right
void Space::setRight(Space* nextRoom)
{
    right = nextRoom;
}

//returns the hunter object
Hunter* Space::getData()
{
    return storedObject;
}

//returns room up
Space* Space::getUp()
{
    return up;
}

//returns room down
Space* Space::getDown()
{
    return down;
}

//returns room right
Space* Space::getRight()
{
    return right;
}

//returns room left
Space* Space::getLeft()
{
    return left;
}