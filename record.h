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
//  FILE:        record.h
//
//  DESCRIPTION:
//   This file contains the driver and the user-interface functions
//   for Project 2 - Create a header file called record that holds
//   all of the deinitions.
//
****************************************************************/
#ifndef recordH
#define recordH

struct record
{
    int                accountno;
    char               name[25];
    char               address[80];
    struct record*     next;
};

#endif
