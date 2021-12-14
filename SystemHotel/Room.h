#pragma once
#include "Hotel.h"
#include <iostream>

using namespace std;
class Room :
    public Hotel
{
public:
		char type;				//COMFORT SUITE OR NORMAL ROOM
		char stype;				//BIG SIZE OR SMALL SIZED ROOM
		char ac;				//AC OR NON AC
		int roomNumber;			//ROOM NUMBER
		double rent;			//DAILY RENT OF ROOM
		int status = 0;			//ROOM IS BOOKED OR NOT
		int rno;		//ADD ROOMS TO HOTEL DATABASE
	
		Room()					//DEFAULT CONSTRUCTOR
		{
			type = '\0';
			stype = '\0';
			ac = '\0';
			roomNumber = 0;
			rent = 0;
			status = 0;
		}
		void acceptroom(int rno)		//ACCEPTING ALL ROOM DETAILS
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
		 void displayroom()
		{
			cout << "| " << roomNumber << ".\t\t|\t" << ac << "\t\t|\t" << type << "\t\t|\t" << stype << "\t\t|\t" << rent << "\t\t|\t";
			if (status == 0) { cout << "Available.\t|"; }
			else { cout << "Booked.\t\t|"; }
			cout << endl;
		}
		
};

