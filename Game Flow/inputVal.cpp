/*******************************************************
 * Programmer:  Dylan Kieu
 * Date:        11/25/19
 * Purpose:     Contains various functions specified for user
 *              input and input validation. Each function is 
 *              tailored to its specific use.
********************************************************/
#include <iostream>
#include <string>
#include <sstream>
#include "inputVal.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::getline;

/***************************************************************
 *                 introCheck()
 * receives a min and max value. It will then retrieve a input from
 * user that meets that requirement along with making sure that
 * it is an integer, not a float or string.
****************************************************************/
int introCheck(int min, int max)
{
    cin.clear();
    int input;
    string line;
    char errorTest;
    bool flag = true;

        while (flag == true)
        {
            getline(cin, line);
            stringstream linestream(line);
            if ((!(linestream >> input)) || ((input < min) || (input > max)) || (linestream >> errorTest))
            {
                //Checks if input is a number
                cout << "ERROR: That is not a valid input, please try again: ";
            }
            else
            {
                flag = false;
                break;
            }
        }
        return input;
}
