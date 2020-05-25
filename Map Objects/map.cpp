/*************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/25/19
 * Purpose:     Map class functions as a queue class that 
 *              facilitates the linkage and adding of space objects
 *              to each other. User to create a virtual map the the
 *              character can use to move around in. 
***************************************************************/
#include "map.hpp"

//Constructor
Map::Map()
{
}

/***************************************************************
 * Function:    isEmpty()
 * Purpose:     checks if a space is empty
****************************************************************/
bool Map::isEmpty(Space** area)
{
    //If there is already a single room 
    if ((*area) != NULL)
    {
        return false;
    }
    
    return true;
}


/***************************************************************
 * Function:    addUp()
 * Purpose:     Adds space class in the upwards position
****************************************************************/
void Map::addUp(Space** currentArea, Hunter* hunter, char type, Space** storeAddress)
{
    //Key:
    //A - Empty      B - Basement       C - Hallway
    //D - Baracks    E - Armory         F - Training Hall
    //G - Blood      H - mini-boss      I - Boss
    //J - Garden     K - Trap           L - Hidden Room  

    //Creates a newSpace based on the key
    switch (type)
    {
    case 'A':
        newSpace = new rmEmpty;
        break;
    case 'B':
        newSpace = new rmBase;
        break;
    case 'C':
        newSpace = new rmHall;
        break;
    case 'D':
        newSpace = new rmBarrack;
        break;
    case 'E':
        newSpace = new rmArmory;
        break;
    case 'F':
        newSpace = new rmTH;
        break;
    case 'G':
        newSpace = new rmBlood;
        break;
    case 'H':
        newSpace = new rmMBoss;
        break;
    case 'I':
        newSpace = new rmBoss;
        break;
    case 'J':
        newSpace = new rmGarden;
        break;
    case 'K':
        newSpace = new rmTrap;
        break;
    case 'L':
        newSpace = new rmHide;
        break;
    }

    //Sets other direction pointers of the new space to null
    //Sets a transversing pointer equal to start position
    pointer = (*currentArea);
    newSpace->setObject(hunter);
    newSpace->setLeft(NULL);
    newSpace->setRight(NULL);
    newSpace->setDown(NULL);

    //If there is not area setup yet, set the first area equal to this.
    if ((*currentArea) == NULL)
    {
        (*currentArea) = newSpace;
        (*currentArea)->setUp(NULL);
        (*storeAddress) = (*currentArea);
        return;
    }
    
    //Transverse in a single direction till null is hit.
    while (pointer->getUp() != NULL)
    {
        pointer = pointer->getUp();
    }
    
    //Sets the prev's next space to the new space
    pointer->setUp(newSpace);

    //Sets the new space's last space to the prev space
    newSpace->setDown(pointer);
    (*storeAddress) = newSpace;
    return;
}

/***************************************************************
 * Function:    addDown()
 * Purpose:     Adds space class in the downwards position
****************************************************************/
void Map::addDown(Space** currentArea, Hunter* hunter, char type, Space** storeAddress)
{
    //Key:
    //A - Empty      B - Basement       C - Hallway
    //D - Baracks    E - Armory         F - Training Hall
    //G - Blood      H - mini-boss      I - Boss
    //J - Garden     K - Trap           L - Hidden Room      

    //Creates a newSpace based on the key  
    switch (type)
    {
    case 'A':
        newSpace = new rmEmpty;
        break;
    case 'B':
        newSpace = new rmBase;
        break;
    case 'C':
        newSpace = new rmHall;
        break;
    case 'D':
        newSpace = new rmBarrack;
        break;
    case 'E':
        newSpace = new rmArmory;
        break;
    case 'F':
        newSpace = new rmTH;
        break;
    case 'G':
        newSpace = new rmBlood;
        break;
    case 'H':
        newSpace = new rmMBoss;
        break;
    case 'I':
        newSpace = new rmBoss;
        break;
    case 'J':
        newSpace = new rmGarden;
        break;
    case 'K':
        newSpace = new rmTrap;
        break;
    case 'L':
        newSpace = new rmHide;
        break;
    }

    //Sets other direction pointers of the new space to null
    //Sets a transversing pointer equal to start position
    pointer = (*currentArea);
    newSpace->setObject(hunter);
    newSpace->setLeft(NULL);
    newSpace->setRight(NULL);
    newSpace->setUp(NULL);

    //If there is not area setup yet, set the first area equal to this.
    if ((*currentArea) == NULL)
    {
        (*currentArea) = newSpace;
        (*currentArea)->setDown(NULL);
        (*storeAddress) = (*currentArea);
        return;
    }
    
    //Transverse in a single direction till null is hit.
    while (pointer->getDown() != NULL)
    {
        pointer = pointer->getDown();
    }
    
    //Sets the prev's next space to the new space
    pointer->setDown(newSpace);

    //Sets the new space's last space to the prev space
    newSpace->setUp(pointer);

    //stores the address of the new space
    (*storeAddress) = newSpace;
    return;    
}

/***************************************************************
 * Function:    addLeft()
 * Purpose:     Adds space class in the Left position
****************************************************************/
void Map::addLeft(Space** currentArea, Hunter* hunter, char type, Space** storeAddress)
{
    //Key:
    //A - Empty      B - Basement       C - Hallway
    //D - Baracks    E - Armory         F - Training Hall
    //G - Blood      H - mini-boss      I - Boss      
    //J - Garden     K - Trap           L - Hidden Room 

    //Creates a newSpace based on key
    switch (type)
    {
    case 'A':
        newSpace = new rmEmpty;
        break;
    case 'B':
        newSpace = new rmBase;
        break;
    case 'C':
        newSpace = new rmHall;
        break;
    case 'D':
        newSpace = new rmBarrack;
        break;
    case 'E':
        newSpace = new rmArmory;
        break;
    case 'F':
        newSpace = new rmTH;
        break;
    case 'G':
        newSpace = new rmBlood;
        break;
    case 'H':
        newSpace = new rmMBoss;
        break;
    case 'I':
        newSpace = new rmBoss;
        break;
    case 'J':
        newSpace = new rmGarden;
        break;
    case 'K':
        newSpace = new rmTrap;
        break;
    case 'L':
        newSpace = new rmHide;
        break;
    }

    //Sets other direction pointers of the new space to null
    //Sets a transversing pointer equal to start position
    pointer = (*currentArea);
    newSpace->setObject(hunter);
    newSpace->setUp(NULL);
    newSpace->setRight(NULL);
    newSpace->setDown(NULL);

    //If there is not area setup yet, set the first area equal to this.
    if ((*currentArea) == NULL)
    {
        (*currentArea) = newSpace;
        (*currentArea)->setLeft(NULL);

        //saves address of new space
        (*storeAddress) = (*currentArea);
        return;
    }
    
    //Transverse in a single direction till null is hit.
    while (pointer->getLeft() != NULL)
    {
        pointer = pointer->getLeft();
    }
    
    //Sets the prev's next space to the new space
    pointer->setLeft(newSpace);

    //Sets the new space's last space to the prev space
    newSpace->setRight(pointer);

    //Saved address of new space
    (*storeAddress) = newSpace;
    return;     
}

/***************************************************************
 * Function:    addRight()
 * Purpose:     Adds space class in the Right position
****************************************************************/
void Map::addRight(Space** currentArea, Hunter* hunter, char type, Space** storeAddress)
{
    //Key:
    //A - Empty      B - Basement       C - Hallway
    //D - Baracks    E - Armory         F - Training Hall
    //G - Blood      H - mini-boss      I - Boss      
    //J - Garden     K - Trap           L - Hidden Room 

    //Creates a newSpace  
    switch (type)
    {
    case 'A':
        newSpace = new rmEmpty;
        break;
    case 'B':
        newSpace = new rmBase;
        break;
    case 'C':
        newSpace = new rmHall;
        break;
    case 'D':
        newSpace = new rmBarrack;
        break;
    case 'E':
        newSpace = new rmArmory;
        break;
    case 'F':
        newSpace = new rmTH;
        break;
    case 'G':
        newSpace = new rmBlood;
        break;
    case 'H':
        newSpace = new rmMBoss;
        break;
    case 'I':
        newSpace = new rmBoss;
        break;
    case 'J':
        newSpace = new rmGarden;
        break;
    case 'K':
        newSpace = new rmTrap;
        break;
    case 'L':
        newSpace = new rmHide;
        break;
    }

    //Sets other direction pointers of the new space to null
    //Sets a transversing pointer equal to start position
    pointer = (*currentArea);
    newSpace->setObject(hunter);
    newSpace->setUp(NULL);
    newSpace->setLeft(NULL);
    newSpace->setDown(NULL);

    //If there is not area setup yet, set the first area equal to this.
    if ((*currentArea) == NULL)
    {
        (*currentArea) = newSpace;
        (*currentArea)->setRight(NULL);

        //saves address of new space
        (*storeAddress) = (*currentArea);
        return;
    }
    
    //Transverse in a single direction till null is hit.
    while (pointer->getRight() != NULL)
    {
        pointer = pointer->getRight();
    }
    
    //Sets the prev's next space to the new space
    pointer->setRight(newSpace);

    //Sets the new space's last space to the prev space
    newSpace->setLeft(pointer);

    //Saved address of new space
    (*storeAddress) = newSpace;
    return;     
}

//Changes the object within a specific space class
void Map::movChar(Space** position, Hunter* character)
{
    (*position)->setObject(character);
    return;
}