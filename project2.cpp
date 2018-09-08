/*****************************************************************
//
//  NAME:        Dylan Ubongen
//
//  HOMEWORK:    Project 2
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        November 11, 2017
//
//  FILE:        project2.cpp
//
//  DESCRIPTION:
//   This file contains the driver and the user-interface functions
//   for Project 2 - Create a program that makes a user-interface
//   for the user so that they're able to add and delete addresses.
//
****************************************************************/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include "llist.h"

#define debugmode

/*****************************************************************
//
// Function name: getaddress
//
// DESCRIPTION:   The user's input is taken as an address
//
// Parameters:    char address[] - Stores the address in here
//
//                int check - Checks the limit of the users input
//
// Return values: void
//
****************************************************************/

#ifndef addressH
#define addressH

void getaddress(char address[], int check)
{

    char space[80];
    int i;

    #ifdef debugmode
    {

        std::cout << "\n///////////////////////////////////////\n";
        std::cout << "////////////// DEBUGGER ///////////////\n";
        std::cout << "\t    Get Address\n";
        std::cout << "///////////////////////////////////////\n\n";

    }

    #endif

    std::cin.get(space, check, '\n');
    std::cin.get();

    for(i = 0; space[i] != '\0'; i++)
    {

        if(space[i] == '\n')
        {

            space[i] = ' ';

        }

    }

    strcpy(address, space);

}

#endif

/*****************************************************************
//
// Function name: main
//
// DESCRIPTION:   Create a program that creates a user-interface and
//                prints out the debugging of the program
//
// Parameters:    int argc - Number of arguments that is passed
//                           into the program
//
//                char* argv[] - Arguments that is passed into
//                               the program
//
// Return values: 0
//
****************************************************************/

int main(int argc, char* argv[])
{

    int endP = 0;
    int option;
    char value[20];

    #ifdef debugmode

        std::cout << "\n///////////////////////////////////////\n";
        std::cout << "\n              DEBUG MODE         \n";
        std::cout << "\n///////////////////////////////////////\n\n";

    #endif

    llist l;

    while (endP != 1)
    {

        int accountno;
        char name[25];
        char address[80] = {'\0'};

        std::cout << "\n\n/// Menu Options ///\n\n";
        std::cout << "1 - Add a new record\n";
        std::cout << "2 - Modify a record\n";
        std::cout << "3 - Print a record\n";
        std::cout << "4 - Print the database\n";
        std::cout << "5 - Delete a record\n";
        std::cout << "6 - Reverse the database\n";
        std::cout << "7 - Exit\n\n";

        std::cout << "Please enter the number cooresponding to the task you would like to do: ";
        std::cin >> value;
        option = atoi(value);

        switch (option)
        {

            case 1:

                std::cout << "\n\n/// Adding new record ///\n\n";
                std::cout << "Enter the account number: ";
                std::cin >> accountno;
                std::cin.get();

                std::cout << "\nEnter your full name: ";
                std::cin.get(name, 25);
                std::cin.get();

                std::cout << "Enter your address in the same order as the following:\n";
                std::cout << "\nStreet Number, Street Name, (If Applicable) Room/Apartment Number\n";
                std::cout << "Please press the enter key when you are finished\n";

                getaddress(address, 80);
                l.addRecord(accountno, name, address);

                break;

            case 2:

                std::cout << "\n\n/// Modifying a record ///\n\n";
                std::cout << "What is the number of the account you would like to modify?: ";
                std::cin >> accountno;
                std::cin.get();

                std::cout << "Enter your address in the same order as the following:\n";
                std::cout << "\nStreet Number, Street Name, Apartment Number\n";
                std::cout << "Please press the enter key when you are finished\n";

                getaddress(address, 80);
                l.modifyRecord(accountno, address);

                break;

            case 3:

                std::cout << "\n\n/// Printing a record ///\n\n";
                std::cout << "Which record would you like to print?: ";
                std::cin >> accountno;
                std::cin.get();

                l.printRecord(accountno);

                break;

            case 4:

                std::cout << "\n\n/// Printing the database ///\n\n";
                std::cout << l;

                break;

            case 5:

                std::cout << "\n\n/// Deleting a record ///\n\n";
                std::cout << "Which record would you like to delete?: ";
                std::cin >> accountno;
                std::cin.get();

                l.deleteRecord(accountno);

                break;

            case 6:

                std::cout << "\n\n/// Reversing the database ///\n\n";
                l.reverse();

                break;

            case 7:

                endP = 1;

            default:

                break;

        }

    }

    return 0;

}
