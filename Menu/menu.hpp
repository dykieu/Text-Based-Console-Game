/**********************************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/25/19
 * Purpose:     Menu Class contains functions that prompt users
 *              with an interface and allows user to choose to
 *              play the game or quit. Also contains all user inferface
 *              questions.
**********************************************************************/
#ifndef MENU_HPP
#define MENU_HPP

#include <string>
#include <fstream>

using std::fstream;
using std::string;

class Menu
{
    private:
        int input;
        int play;
        fstream file_I;
        string line;
    public:
        int selection();
        void gameDescription();
        void gameEnd();
        void gameWon();
        int searchChoice();
        int directionChoice();
        int equipItem();
        int nameChar();
        int exitProg();
        int playAgain();
        int AttOrSpell();
        int drink();
        int fightRun();
        int train();
};

#endif
 