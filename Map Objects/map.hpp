/*************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/25/19
 * Purpose:     Map class functions as a queue class that 
 *              facilitates the linkage and adding of space objects
 *              to each other. User to create a virtual map the the
 *              character can use to move around in. 
***************************************************************/
#ifndef MAP_HPP
#define MAP_HPP

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

//Space and its derived classes
#include "space.hpp"
#include "rm_Empty.hpp"
#include "rm_Hallway.hpp"
#include "rm_Base.hpp"
#include "rm_Hide.hpp"
#include "rm_Garden.hpp"
#include "rm_Barrack.hpp"
#include "rm_Armory.hpp"
#include "rm_TH.hpp"
#include "rm_Blood.hpp"
#include "rm_MBoss.hpp"
#include "rm_Boss.hpp"
#include "rm_Trap.hpp"

//Object and its derived classes
#include "object.hpp"
#include "character.hpp"
#include "hunter.hpp"
#include "orc.hpp"

using std::cout;
using std::endl;
using std::string;
using std::fstream;
using std::stringstream;
using std::ios;

class Map
{
    private:
        Space* pointer;
        Space* newSpace;
        Space* deletedSpace;
        Space* up;
        Space* down;
        Space* left;
        Space* right;

        Object* tempObj;

        int temp;
        string line;
        fstream file_I;
    public:
        Map();
        bool isEmpty(Space**);
        void addUp(Space**, Hunter*, char, Space**);
        void addDown(Space**, Hunter*, char, Space**);
        void addLeft(Space**, Hunter*, char, Space**);
        void addRight(Space**, Hunter*, char, Space**);
        void movChar(Space**, Hunter*);
};

#endif