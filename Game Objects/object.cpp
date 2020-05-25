/*************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/25/19
 * Purpose:     Object class serves to have game objects derived
 *              from it. All objects have a name. 
***************************************************************/
#include "object.hpp"

//Constructor
Object::Object()
{
}

//Returns name
string Object::getname()
{
    return name;
}

//sets object name
void Object::setname(string n)
{
    name = n;
} 

ostream& operator<<(ostream& out, const Object& obj)
{
    return out;
}