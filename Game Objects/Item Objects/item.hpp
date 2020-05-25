/*************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/25/19
 * Purpose:     Item class is derived from object class. 
 *              Functions to be a template for item creation
 *              during the game.
***************************************************************/
#ifndef ITEM_HPP
#define ITEM_HPP

#include "object.hpp"

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>

using std::string;
using std::ostream;

class Item : public Object
{
    protected:
        string name;
        string type;
        int attackPower;
        int defensePower;
    public:
        Item();
        void setType(string);
        void setAttPwr(int);
        void setDefPwr(int);
        string getType();
        int getAttPwr();
        int getDefPwr();
};

#endif