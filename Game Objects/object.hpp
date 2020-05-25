/*************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/25/19
 * Purpose:     Object class serves to have game objects derived
 *              from it. All objects have a name. 
***************************************************************/
#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>

using std::string;
using std::ostream;

class Object
{
    protected:
        string name;
    public:
        Object();
        string getname();
        void setname(string);
        friend ostream& operator<<(ostream& out, const Object& obj);
};

#endif