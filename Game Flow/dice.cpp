/*************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/12/19
 * Purpose:     Dice class functions to roll dices depending on
 *              which attack or defense value is received. Reads
 *              the values of the strings.
***************************************************************/
#include "dice.hpp"
#include <iostream>
#include <stdlib.h>

using std::cout;
using std::endl;

Dice::Dice()
{
}

/***************************************************************
 *                      Dice::rollDie
 * recieves the specific defense or attack type. Rolls appropriate
 * amount of dice and the appropriate number of faces.
****************************************************************/
int Dice::rollDie(string type)
{
    //Roll 1 dice
    if (type[0] == '1')
    {
        //Roll 12 sided dice
        if (type[2] == '1' && type [3] == '2')
        {
            dice1 = (rand() % 12)+1;
            return dice1;
        }
        //Roll 6 sided dice
        if (type[2] == '6')
        {
            dice1 = (rand () % 6)+1;
            return dice1;
        }
    }
    //Roll 2 dice
    else if (type[0] == '2')
    {
        //Roll 12 sided dice
        if (type[2] == '1' && type [3] == '2')
        {
            dice1 = (rand() % 12)+1;
            dice2 = (rand() % 12)+1;     
            return dice1 + dice2;
        }
        //Roll 6 sided dice
        if (type[2] == '6')
        {
            dice1 = (rand () % 6)+1;
            dice2 = (rand () % 6)+1;
            return dice1 + dice2;
        }
        //Roll 10 sided dice
        if (type[2] == '1' && type [3] == '0')
        {
            dice1 = (rand() % 10)+1;
            dice2 = (rand() % 10)+1;     
            return dice1 + dice2;
        }
    }
    //Roll 3 dice
    else if (type[0] == '3')
    {
        //Roll 6 sided dice
        if (type[2] == '9' && type [3] == '9')
        {
            dice1 = (rand () % 99)+1;
            dice2 = (rand () % 99)+1;
            dice3 = (rand () % 99)+1;
            return dice1 + dice2 + dice3;
        }
    }
    return 0;
}

Dice::~Dice()
{
}