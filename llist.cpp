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
//  FILE:        llist.cpp
//
//  DESCRIPTION:
//   This file contains the driver and the user-interface functions
//   for Project 2 - Create a file that contains the functions of
//   the Project 2 file and that contains the debug mode of the
//   program.
//
****************************************************************/

#define llistCpp

#define debugmode

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include "llist.h"
#include "record.h"

/*****************************************************************
//
// Function name: llist contructor
//
// DESCRIPTION:   Instantiates the llist class
//
// Parameters:    N/A
//
// Return values: None
//
****************************************************************/

llist::llist ()
{

    start = NULL;
    strcpy(filename, "records.txt");
    readfile();

}

/*****************************************************************
//
// Function name: llist contructor
//
// DESCRIPTION:   Instantiates the llist class
//
// Parameters:    char file[]
//
// Return values: None
//
****************************************************************/

llist::llist (char file[])
{

    start = NULL;
    strcpy(filename, file);
    readfile();

}

/*****************************************************************
//
// Function name: addRecord
//
// DESCRIPTION:   Adds the users inputted record to the database
//
// Parameters:    int accountno - The account number that needs to be added
//
//                char name[] - The name that's added to the record
//
//                char address[] - The address that's added to the record
//
// Return values: 0
//
****************************************************************/

int llist::addRecord (int accountno, char name[] , char address[])
{

    struct record *temp;

    struct record *point;

    #ifdef debugmode

        std::cout << "\n///////////////////////////////////////\n";
        std::cout << "////////////// DEBUGGER ///////////////\n";
        std::cout << "\tAdd Record\n";
        std::cout << "// Account Number: " << accountno << "\n";
        std::cout << "// Name: " << name << "\n";
        std::cout << "// Address: "  << address << "\n";
        std::cout << "///////////////////////////////////////\n\n";

    #endif

    temp = new(struct record);

    temp->accountno = accountno;

    strcpy(temp->name, name);
    strcpy(temp->address, address);

    temp->next = NULL;

    if (start == NULL)
    {

        start = temp;

    }
    else
    {

        point = start;

        if (point == NULL)
        {

            start = temp;

        }
        else
        {

            while (point->next != NULL)
            {

                point = point->next;

            }

            point->next = temp;

        }

    }

    return 0;

}

/*****************************************************************
//
// Function name: printRecord
//
// DESCRIPTION:   Prints a specified record from the database
//
// Parameters:    int accountno - The account number that needs to be printed
//
// Return values: 0
//
****************************************************************/

int llist::printRecord (int accountno)
{

    struct record *point;

    int add = 0;

    #ifdef debugmode

        std::cout << "\n///////////////////////////////////////\n";
        std::cout << "////////////// DEBUGGER ///////////////\n";
        std::cout << "\tPrint Record\n";
        std::cout << "\t// Account Number: " << accountno << "\n";
        std::cout << "///////////////////////////////////////\n\n";

    #endif

    point = start;

    if (point == NULL)
    {

        std::cout << "Sorry there are no recorded records right now.\n";

    }
    else
    {

        while (point != NULL)
        {

            if (point->accountno == accountno)
            {

                std::cout << point->accountno << "\n";
                std::cout << point->name << "\n";
                std::cout << point->address << "\n\n";

                add = 1;

            }

            point = point->next;

        }

        if (add == 0)
        {

            std::cout << "Sorry we weren't able to find the record with the accountno: " << accountno << "\n";

        }
        else
        {

            std::cout << "The record with the accountno: " << accountno << " is now printed.\n";

        }

    }

    return 0;

}

/*****************************************************************
//
// Function name: modifyRecord
//
// DESCRIPTION:   Modifies a record from the database
//
// Parameters:    int accountno - Gets the number of the account
//                that needs to be modified
//
//                char address[] - The address that needs to be modified
//
// Return values: 0
//
****************************************************************/

int llist::modifyRecord (int accountno, char address[])
{

    struct record *point;

    int add = 0;

    point = start;

    #ifdef debugmode

        std::cout << "\n///////////////////////////////////////\n";
        std::cout << "////////////// DEBUGGER ///////////////\n";
        std::cout << "\tModify Record\n";
        std::cout << "// Account Number: " << accountno << "\n";
        std::cout << "// Address: " << address << "\n";
        std::cout << "///////////////////////////////////////\n\n";

    #endif

    if (point == NULL)
    {

        std::cout << "Sorry there are no recorded records right now.\n";

    }
    else
    {

        while (point != NULL)
        {

            if (point->accountno == accountno)
            {

                strcpy (point->address, address);
                add = 1;

            }

            point = point->next;

        }

    }

    if (add == 0)
    {

        std::cout << "Sorry we weren't able to find the record with the accountno: " << accountno <<"\n";

    }
    else
    {

        std::cout << "The record with the accountno: " << accountno << " has now been changed.\n";

    }

    return add;

}

/*****************************************************************
//
// Function name: deleteRecord
//
// DESCRIPTION:   Deletes the specified record the user inputted
//                from the database
//
// Parameters:    int accountno - The account number that needs to be deleted
//
// Return values: 0
//
****************************************************************/

int llist::deleteRecord(int accountno)
{

    int test = 0;
    int add = 0;

    struct record *temp;
    struct record *prev;
    struct record *curr;

    #ifdef debugmode

        std::cout << "\n///////////////////////////////////////\n";
        std::cout << "////////////// DEBUGGER ///////////////\n";
        std::cout << "\tDelete Record\n";
        std::cout << "\t// Account Number: " << accountno << "\n";
        std::cout << "///////////////////////////////////////\n\n";

    #endif

    temp = start;

    if (temp == NULL)
    {

        std::cout << "Sorry there are no recorded records right now.\n";

    }
    else
    {

        while (test == 0)
        {

            if (temp->accountno == accountno)
            {

                curr = temp->next;

                delete temp;

                start = curr;

                temp = start;

                add = 1;

            }

            if (temp == NULL || temp->accountno != accountno)
            {

                test = 1;

            }

        }

        if(temp != NULL)
        {

            curr = temp->next;
            prev = start;

            while (curr != NULL)
            {

                if (curr->accountno == accountno)
                {

                    prev->next = curr->next;
                    delete curr;
                    curr = prev->next;
                    add = 1;

                }
                else
                {

                    prev = prev->next;
                    curr = prev->next;

                }

            }

        }

        if (add == 0)
        {

            std::cout << "Sorry we weren't able to find the record with the accountno: " << accountno << "\n";

        }
        else
        {

            std::cout << "The record with the accountno: " << accountno << " has now been deleted.\n";

        }

    }

    return 0;

}

/*****************************************************************
//
// Function name: readfile
//
// DESCRIPTION:   Reads a text file that holds records within it, reads the file
//                with each of the following account number, name, and address, it
//                repeats it until all records are in the input file.
//
// Parameters:    N/A
//
// Return values: valid - tells us if the file was a success(1) or a fail(0).
//
****************************************************************/

int llist::readfile ()
{

    int copy = 0;
    int accountno;
    int valid = 0;

    char space[800];
    char address[80] = {'\0'};
    char fullname[30];

    std::ifstream inf;

    #ifdef debugmode

        std::cout << "\n///////////////////////////////////////\n";
        std::cout << "////////////// DEBUGGER ///////////////\n";
        std::cout << "\tReading File : " << filename << "\n";
        std::cout << "///////////////////////////////////////\n\n";

    #endif

    inf.open(filename);

    if (inf == NULL)
    {

        valid = 1;

    }
    else
    {

        while (!inf.eof())
        {

            inf.getline(space, 100);
            if (copy == 0)
            {

                accountno = atoi(space);

            }
            else if (copy == 1)
            {

                strcpy(fullname, space);

            }
            else if (copy == 2)
            {

                strcpy(address, space);

            }

            if (strlen(space) == 0)
            {

                copy = 0;
                addRecord(accountno, fullname, address);
                accountno = 0;
                address[0] = '\0';

            }
            else
            {

                copy++;

            }

        }

        inf.close();

    }

    return valid;

}

/*****************************************************************
//
// Function name: writefile
//
// DESCRIPTION:   Writes all of the records within a text file, writes the file
//                with each of the following account number, name, and address, it
//                repeats it until all records are in the output file.
//
// Parameters:    N/A
//
// Return values: 0
//
****************************************************************/

int llist::writefile ()
{

    std::ofstream out;

    struct record *point;

    point = start;

    #ifdef debugmode

        std::cout << "\n///////////////////////////////////////\n";
        std::cout << "////////////// DEBUGGER ///////////////\n";
        std::cout << "Writing Database to file : " << filename << "\n";
        std::cout << "///////////////////////////////////////\n\n";

    #endif

    out.open(filename);

    if (out != NULL)
    {

        while (point != NULL)
        {

            out << point->accountno << "\n";
            out << point->name << "\n";
            out << point->address << "\n\n";

            point = point->next;

        }

    }

    out.close();
    return 0;

}

/*****************************************************************
//
// Function name: private reverse
//
// DESCRIPTION:   Reverses the list that stores all user data.
//
// Parameters:    record * data
//
// Return values: temp/data - The linked list head address
//
****************************************************************/

record * llist::reverse(record * data)
{

    #ifdef debugmode

        std::cout << "\n///////////////////////////////////////\n";
        std::cout << "////////////// DEBUGGER ///////////////\n";
        std::cout << "Database is being reversed\n";
        std::cout << "///////////////////////////////////////\n\n";

    #endif

    if (data->next == NULL)
    {

        return data;

    }
    else
    {

        record * temp = reverse(data->next);
        data->next->next = data;
        data->next = NULL;

        return temp;

    }

}

/*****************************************************************
//
// Function name: public reverse
//
// DESCRIPTION:   Calls the private reverse function and copies its value to start
//
// Parameters:    N/A
//
// Return values: Void
//
****************************************************************/

void llist::reverse()
{

    if(start == NULL)
    {

        std::cout << "The database is empty.\n";

    }
    else
    {

        start = reverse(start);
        std::cout << "The database was reversed.\n";

    }

}

/*****************************************************************
//
// Function name: cleanup
//
// DESCRIPTION:   Frees all memory on the heap when the exiting the program
//
// Parameters:    N/A
//
// Return values: Void
//
****************************************************************/

void llist::cleanup()
{

    #ifdef debugmode

        std::cout << "\n///////////////////////////////////////\n";
        std::cout << "////////////// DEBUGGER ///////////////\n";
        std::cout << "\tEntering cleanup\n";
        std::cout << "///////////////////////////////////////\n\n";

    #endif

    struct record * temp;
    struct record * cleanup;

    cleanup = start;

    while(cleanup != NULL)
    {

        temp = cleanup->next;
        delete cleanup;
        cleanup = temp;

    }

}

/*****************************************************************
//
// Function name: ~llist (The llist destructor)
//
// DESCRIPTION:   Destructor function for the llist class
//
// Parameters:    N/A
//
// Return values: void
//
****************************************************************/

llist::~llist()
{

    writefile();
    cleanup();

}

/*****************************************************************
//
// Function name: Overloaded operator<<
//
// DESCRIPTION:   Replacement function for the printAll funtion in project1
//
// Parameters:    ostream& os - ostream reference
//                llist& list - Linked list to print
//
// Return values: os - success
//
****************************************************************/

std::ostream& operator<<(std::ostream& os, const llist& list)
{

    struct record * temp;

    #ifdef debugmode
    {

        os << "\n///////////////////////////////////////\n";
        os << "////////////// DEBUGGER ///////////////\n";
        os << "\tPrint All Records\n";
        os << "///////////////////////////////////////\n\n";

    }

    temp = list.start;

    if (temp == NULL)
    {

        os << "There are no records in the database.\n";

    }
    else
    {

        while(temp != NULL)
        {

            os << temp->accountno << "\n";
            os << temp->name << "\n";
            os << temp->address << "\n\n";

            temp = temp->next;

        }

    }

    return os;

}

/*****************************************************************
//
// Function name: llist copy constructor
//
// DESCRIPTION:   Instantiates of a new llist variable and copies the parameter's data into the new llist
//
// Parameters:    llist& list
//
// Return values: None
//
****************************************************************/

llist::llist (const llist& list)
{

    *this = list;

}

/*****************************************************************
//
// Function name: Overloaded operator=
//
// DESCRIPTION:   Takes one llist variable and copies it's data over to another llist variable.
//
// Parameters:    llist& list - Grabs the data from the llist
//
// Return values: Copy of the list from the database
//
****************************************************************/

llist & llist::operator=(const llist& list)
{

    this->start = NULL;

    struct record * temp;

    temp = list.start;

    if(this == &list)
    {

        return *this;

    }

    while (temp != NULL)
    {

        addRecord(temp->accountno, temp->name, temp->address);
        temp = temp->next;

    }

    return *this;

}

#endif
