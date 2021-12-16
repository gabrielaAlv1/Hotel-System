#pragma once
#include<iostream>
#include<string>
#include <iomanip>
#include <time.h>
#include<ctime> 
#include "Costumer.h"
#include "Room.h"

/** @file Hotel.cpp

 *  @brief Brief description of file.
	This file will be hotel.cpp inputs 
 *

 *  Longer description of file.
	This file will take all the information inputed by 
	the costumer and user and let the costumer use that info 
 *

 *  @author Gabriela Alvarez

 *  @bug No known bugs.

 */



using namespace std;

//LO2.Use subclassing to design simple class hierarchies that allow code to be reused for distinct subclasses.
//LO2a.Include comments describing the visibility inheritance model
class Hotel :public Room    //Hotel is the parent class of room
{
	Room a[9];					//Array of Rooms
	Costumer c[9];				//Array of costumers
	int nroom = 0, ncust = 0;	//Number of Costumers and Rooms

	//LO6.Use object - oriented encapsulation mechanisms such as interfaces and private members.
public:
	void addRooms();		//Admin adds rooms 
	void availability();	//Checking availavility for the Rooms 
	void searchroom();		//Seach for an specifict room 
	void CheckIn();			//Costumer's check in 
	void CheckOut();		//Costumer's check out 
};

