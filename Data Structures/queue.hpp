/*************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/12/19
 * Purpose:     List class contains all the functions necessary
 *              to link nodes and add them into a double-linked
 *              list. It has the options to also print and add
 *              front a text. Lastly it contains functions to
 *              remove nodes from a list too.
***************************************************************/
#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "character.hpp"
#include "vamp.hpp"
#include "barb.hpp"
#include "bm.hpp"
#include "harry.hpp"
#include "medusa.hpp"
#include "node.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>


using std::string;
using std::fstream;

class Queue
{
    private:
        Node* tail;
        Node* nodePtr;
        Node* prevNodePtr;
        Node* newNode;
        Node* deletedNodes;
        int temp;
        Character *tempChar;
        string line;
        fstream file_I;

    public:
        Queue();
        ~Queue();
        bool isEmpty(Node**);
        void addFront(Node**, Character*);
        void addBack(Node**, Character*);
        int delFront(Node**);
        int delBack(Node**);
        void printList(Node*);
};

#endif