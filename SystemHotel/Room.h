#pragma once
#include <iostream>

/** @file Room.h

 *  @brief Brief description of file.
	Room. h is for the admin
 *

 *  Longer description of file.
 The admin will input the room specifications and how many rooms 
 *

 *  @author Gabriela Alvarez

 *  @bug No known bugs.

 */

//LO1.Designand implement a class.

class Room
{
public:
	char type;				//COMFORT SUITE OR NORMAL ROOM
	char stype;				//BIG SIZE OR SMALL SIZED ROOM
	char ac;				//AC OR NON AC
	int roomNumber;			//ROOM NUMBER
	double rent;			//DAILY RENT OF ROOM
	int status = 0;			//ROOM IS BOOKED OR NOT
	int rno;		//ADD ROOMS TO HOTEL DATABASE

	Room()				//DEFAULT CONSTRUCTOR
	{
		type = '\0';
		stype = '\0';
		ac = '\0';
		roomNumber = 0;
		rent = 0;
		status = 0;
		rno = 0;
	}
	void acceptroom(int rno);		//ACCEPTING ALL ROOM DETAILS
	void displayroom();
};