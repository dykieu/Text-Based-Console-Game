/*************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/12/19
 * Purpose:     queue class contains all the functions necessary
 *              to link nodes and add them into a double-linked
 *              list. It has the options to also print and add
 *              front a text. Lastly it contains functions to
 *              remove nodes from a queue too.
***************************************************************/
#include "node.hpp"
#include "queue.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <sstream>

using std::cout;
using std::endl;
using std::string;
using std::fstream;
using std::stringstream;
using std::ios;

Queue::Queue()
{
}

/***************************************************************
 *                  Queue::isEmpty()
 * Tests a queue to see if it has any nodes within it.
****************************************************************/
bool Queue::isEmpty(Node** head)
{
    //Checks if the head is pointing to null or not
    if ((*head) != NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
}

/***************************************************************
 *                  Queue::addBack()
 * Adds a node to the back of a queue. Receives the address of the
 * head and a character object.
****************************************************************/
void Queue::addBack(Node** head, Character* chosen)
{  
   //Creates a new node 
    newNode = new Node();

    //Sets tail to point at same thing as head
    tail = (*head);

    //Sets the value for the new node and its next value to be null (because it will be at end)
    newNode->setData(chosen);
    newNode->setNext(NULL);

    //If list is empty make the head the new node
    if ((*head) == NULL)
    {
        //Sets previous to null if the head is the first item (Nothing on the left side)
        //Makes head the first node
        (*head) = newNode;
        (*head)->setPrev(NULL);
    }
    else
    {
        //Keeps moving down list until the end
        while (tail->getNext() != NULL)
        {
            tail = tail->getNext();
        }
        
        //Once tail's next value is null, set next of the node tail is pointing at to the new node
        tail->setNext(newNode);

        //set the new node's previous value to be the one the tail is pointing at
        newNode->setPrev(tail);
        return;
    }
}

/***************************************************************
 *                  Queue::addFront()
 * adds a node to the front of a queue. Receives the address of
 * the head and a character object
****************************************************************/
void Queue::addFront(Node** head, Character* chosen)
{
    //Creates a new node and sets it previous value to null (the right)
    newNode = new Node();
    newNode->setData(chosen);
    newNode->setPrev(NULL);

    //makes the next position where the head currently is
    newNode->setNext(*head);

    //If list not empty, set the prev value of the node head is on to the new node
    if ((*head) != NULL)
    {
        (*head)->setPrev(newNode);
    }

    //Move head to the new node
    (*head) = newNode;
}

/***************************************************************
 *                  Queue::delFront()
 * deletes a node from the front of the list (What the head is
 * pointing to). Receives the address of the head.
****************************************************************/
int Queue::delFront(Node** head)
{
    //If List is empty
    if ((*head) == NULL)
    {
        //tells user that list and empty and does not remove anything
        cout << "**List empty, unable to remove anything." << endl;
        return 0;
    }
    //If list not empty  
    else
    {
        //Moves the tail to the head
        tail = (*head);

        //Finds the end of the link
        while (tail->getNext() != NULL)
        {
            tail = tail->getNext();
        }
        
        //If head if the only node
        if (tail == (*head))
        {
            //Removes the head node
            delete tail;

            //resets head and tail
            tail = NULL;
            (*head) = NULL;
          
        }
        //If There are more than 1 nodes
        else
        {
            //Sets the node pointer to same position as head
            prevNodePtr = (*head);

            //Keeps moving the pointer until the node its on has a previous pointer to head
            while (prevNodePtr->getPrev() != (*head))
            {
                prevNodePtr = prevNodePtr->getNext();
            }
            
            //delete node that was at head
            delete (*head);

            //Moves head forward one
            (*head) = prevNodePtr;
            prevNodePtr = NULL;
        }
        return 1;
    } 
}

/***************************************************************
 *                  Queue::delBack()
 * deletes a node from the back of the list(What the tail is
 * pointing to). Receives the address of the head.
****************************************************************/
int Queue::delBack(Node** head)
{
    //If List is empty
    if ((*head) == NULL)
    {
        cout << "**List empty, unable to remove anything." << endl;
        return 0;
    }  
    else
    {
        //Moves the tail to the head
        tail = (*head);

        //Finds the end of the link
        while (tail->getNext() != NULL)
        {
            tail = tail->getNext();
        }
        
        //If head if the only node
        if (tail == (*head))
        {
            //Removes head node
            delete tail;

            //resets head and tail
            tail = NULL;
            (*head) = NULL;
        }
        //If There are more than 1 nodes
        else
        {   
            //Sets the node pointer to be at the head
            prevNodePtr = (*head);

            //Moves node pointer till the node before tail
            while (prevNodePtr->getNext() != tail)
            {
                prevNodePtr = prevNodePtr->getNext();
            }

            //Unlinks from the node that tail is on
            prevNodePtr->setNext(NULL);
            delete tail;
        }

        return 1;
    }
    
}

/***************************************************************
 *                  Queue::printList()
 * Prints out the whole queue starting from the head
****************************************************************/
void Queue::printList(Node* head)
{
    cout << "This is the current list: " << endl;

    //Prints out list until you hit the end of the list
    while (head != NULL)
    {
        tempChar = head->getData();
        cout << tempChar->getClass() << " ";
        head = head->getNext();
    }
    cout << "\r\n";
    return; 
}

Queue::~Queue()
{
}