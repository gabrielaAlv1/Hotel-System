#pragma once
#include <iostream>
#include "Room.h"

/** @file Room.cpp

 *  @brief Brief description of file.
	this file will take the info inputed by the admin about the room
 *
 *  Longer description of file.
	The fuctions in this file will work with the admin inputs.
	Admin can input room information for the costumer to use when deciding for a room
 *
 *  @author Gabriela Alvarez

 *  @bug No known bugs.

 */

using namespace std;

void Room::acceptroom(int rno)		//ACCEPTING ALL ROOM DETAILS
{
	roomNumber = rno;	//ROOM NUMBER
	cout << "Type AC/Non-AC (A/N) : ";
	cin >> ac;
	while (ac != 'A' && ac != 'N')		//VALIDATIONS
	{
		cout << "Please Re-Enter Type: AC/Non-AC (A/N) : ";
		cin >> ac;
	}
	cout << "Type Comfort Suite or Normal (S/N) : ";
	cin >> type;
	while (type != 'S' && type != 'N')
	{
		cout << "Please Re-enter Type Comfort Suite or Normal (S/N) : ";
		cin >> type;
	}
	cout << "Type Size (B/S) : ";
	cin >> stype;
	while (stype != 'B' && stype != 'S')
	{
		cout << "Please Re-enter Type Size (B/S) : ";
		cin >> stype;
	}
	cout << "Daily Rent : ";
	cin >> rent;
	while (rent < 0 || rent>1000)
	{
		cout << "Please enter valid rent.";
		cin >> rent;
	}
	status = 0;	//BOOKING STATUS OF THE ROOM
	cout << "\nRoom Added Successfully!" << endl;
}

void Room::displayroom()
{
	cout << "| " << roomNumber << ".\t\t|\t" << ac << "\t\t|\t" << type << "\t\t|\t" << stype << "\t\t|\t" << rent << "\t\t|\t";
	if (status == 0) { cout << "Available.\t|"; }
	else { cout << "Booked.\t\t|"; }
	cout << endl;
}