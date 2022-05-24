// Names of Group:
// Julian Espinoza
// Wesley Goo
// Hamza Patel
// Arturo Islas Mejia
// Eduardo Garcia Ortiz
// Date: 5/11/2022

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <fstream>
#include <list>
#include "input.h"
#include "sortSim.h"
#include "appOf StudentRecords.h"

using namespace std;
int mainMenuOption();

int main()
{
    do
    {
        switch (mainMenuOption())
        {
        case 0: exit(1); break;
        case 1: sortOptions(); break;
        case 2: appOfStudentRec(); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");

    } while (true);
}

//Precondition:none
//PostCondition:displays the main menu
int mainMenuOption()
{
    cout << endl << "Chapter 13 Assignment by by Julian Espinoza, Wesley Goo, Hamza Patel, Arturo Islas Mejia, and Eduardo Garcia Ortiz";
    cout << endl << "==========================================";
    cout << endl << "1> Sorting simulations";
    cout << endl << "2> Application of student records";
    cout << endl << "==========================================";
    cout << endl << "Exit 0";
    cout << endl << "==========================================" << endl;
    int options = inputInteger("Options: ", 0, 2);
    cout << endl << endl << endl;
    return options;
}