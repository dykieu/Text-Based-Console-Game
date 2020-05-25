/*************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/25/19
 * Purpose:     Dice class functions to roll dices depending on
 *              which attack or defense value is received. Reads
 *              the values of the strings.
***************************************************************/
#ifndef DICE_HPP
#define DICE_HPP

#include <string>

using std::string;

class Dice
{
    private:
        int dice1;
        int dice2;
        int dice3;
    public:
        Dice();
        ~Dice();
        int rollDie(string);

};

#endif