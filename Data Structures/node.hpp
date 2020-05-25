/*************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/12/19
 * Purpose:     Node class contains the general memeber variables
 *              that make up a node object. Will have points to
 *              help link up node objects to create a list.
***************************************************************/
#ifndef NODE_HPP
#define NODE_HPP

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "character.hpp"
#include "vamp.hpp"
#include "barb.hpp"
#include "bm.hpp"
#include "harry.hpp"
#include "medusa.hpp"

class Node
{
    protected:
        Character* storedChar;
        Node* next;
        Node* prev;
    public:
        Node();
        void setData(Character*);
        void setNext(Node*);
        void setPrev(Node*);
        Character* getData();
        Node* getNext();
        Node* getPrev();
        ~Node();
};

#endif