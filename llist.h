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
//  FILE:        llist.h
//
//  DESCRIPTION:
//   This file contains the driver and the user-interface functions
//   for Project 2 - Create a header file called llist that holds
//   all of the deinitions.
//
****************************************************************/
#ifndef llistH
#define llistH

#include "record.h"

class llist
{

    private:
      record *    start;
      char        filename[16];
      int         readfile();
      int         writefile();
      record *    reverse(record * );
      void        cleanup();

    public:
      llist();
      llist(char[]);
      ~llist();
      llist(const llist&);
      int addRecord (int, char [ ],char [ ]);
      int printRecord (int);
      int modifyRecord ( int, char [ ]);
      // replace printAll() with the << operator
      llist& operator=(const llist&);
      friend std::ostream& operator<<(std::ostream&, const llist&);
      int deleteRecord(int);
      void reverse();

};

#endif
