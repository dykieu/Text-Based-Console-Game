/*************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/12/19
 * Purpose:     Node class contains the general memeber variables
 *              that make up a node object. Will have points to
 *              help link up node objects to create a list.
***************************************************************/
#include "node.hpp"
#include "queue.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using std::cout;
using std::endl;

/***************************************************************
 *                  Node::Node()
 * sets default values of the node
****************************************************************/
Node::Node()
{
    next = NULL;
    prev = NULL;
}

/***************************************************************
 *                  Node::setData()
 * sets data value of the node
****************************************************************/
void Node::setData(Character* tempChar)
{
    storedChar = tempChar;
}

/***************************************************************
 *                  Node::setNext()
 * sets what the next pointer points to
****************************************************************/
void Node::setNext(Node* next1)
{
    next = next1;      
}

/***************************************************************
 *                  Node::setPrev()
 * sets what the prev pointer points to
****************************************************************/
void Node::setPrev(Node* prev1)
{
    prev = prev1;
}

/***************************************************************
 *                  Node::getData()
 * returns the value of the node
****************************************************************/
Character* Node::getData()
{
    return storedChar;
}

/***************************************************************
 *                  Node::getNext()
 * sets what the next ptr is pointing to
****************************************************************/
Node* Node::getNext()
{
    return next;
}

/***************************************************************
 *                  Node::getPrev()
 * returns what the prev ptr is pointing to
****************************************************************/
Node* Node::getPrev()
{
    return prev;
}

Node::~Node()
{  
}
