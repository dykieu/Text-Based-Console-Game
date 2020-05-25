/*************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/25/19
 * Purpose:     Space class functions as "rooms" for characters
 *              to interact with.
***************************************************************/
#ifndef SPACE_HPP
#define SPACE_HPP

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "object.hpp"
#include "character.hpp"
#include "hunter.hpp"

class Space
{
    protected:
        string type;
        Hunter* storedObject; 
        Space* up;
        Space* down;
        Space* left;
        Space* right;
    public:
        Space();
        
        //Pure virtual functions
        virtual void specialEvent(Hunter*) = 0;
        virtual void search(Hunter*) = 0;
        
        //Set and get functions
        string getType();
        void setObject(Hunter*);
        void setUp(Space*);
        void setDown(Space*);
        void setLeft(Space*);
        void setRight(Space*);
        Hunter* getData();
        Space* getUp();
        Space* getDown();
        Space* getRight();
        Space* getLeft();
        friend ostream& operator<<(ostream& out, const Space& space);
};

#endif