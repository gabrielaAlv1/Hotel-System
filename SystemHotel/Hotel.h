#pragma once
#include<iostream>
#include<string>
#include<string.h>
#include <iomanip>
#include <time.h>
#include<ctime> 
#include "Costumer.h"
#include "Room.h"
using namespace std;

class Hotel: public Room
{

		 Room a[100];			//ARRAY OF ROOMS
		Costumer c[100];			//ARRAY OF CUSTOMERS
		int nroom = 0, ncust = 0;	//NO OF ROOMS AND CUSTOMERS
				
		void addRooms()
		{
			int rno;
			cout << "Enter number of rooms: ";
			cin >> nroom;		//ACCEPTING NUMBER OF ROOMS
			while (nroom <= 0)
			{
				cout << "Invalid. Enter valid number of rooms.";
				cin >> nroom;
			}
			for (int i = 0; i < nroom; i++)
			{
				cout << "ROOM " << (i + 1) << endl;
			flag:
				cout << endl << "Enter room number : ";
				cin >> rno;
				if (rno <= 0)		//VALIDATIONS
				{
					cout << endl << "This room number is invalid! Please Re-enter the room number : ";
					goto flag;
				}
				for (int i = 0; i < nroom; i++)	//VALIDATIONS FOR REPETITIVE ROOM NUMBERS
				{
					if (a[i].roomNumber == rno)
					{
						cout << "Invalid. Repetitive room numbers." << endl;
						goto flag;
					}
				}
				a[i].acceptroom(rno);		//CALLING FUNCTION ACCEPT ROOM FROM CLASS ROOM
			}
		}
		void availability()		//CHECKING AVAILABILITY OF THE ROOMS
		{
			if (nroom == 0)
			{
				cout << "Please add rooms." << endl;
				return;
			}
			cout << "The list of all available rooms:" << endl;
			cout << "| Room No.\t|\tAC/Non-AC\t|\tType\t\t|\tStype\t\t|\tRent\t\t|\tAvailability  \t|" << endl;
			for (int i = 0; i < nroom; i++)
			{
				a[i].displayroom();	//DISPLAYING ROOM DETAILS
			}
		}
		void searchroom()	//SEARCH FOR A PARTICULAR TYPE OF A ROOM
		{
			if (nroom == 0)
			{
				cout << "Please add rooms." << endl;
				return;
			}
			int flag = 0;
			char ac1, type1, stype1;
			cout << "Do you want AC or Non-AC? (A/N): " << endl;
			cin >> ac1;
			cout << "Do you want suite or normal room?" << endl;
			cin >> type1;
			cout << "Size? (B/S)" << endl;
			cin >> stype1;
			for (int i = 0; i < nroom; i++)
			{
				if (a[i].ac == ac1 && a[i].type == type1 && a[i].stype == stype1)		//MAKING SURE ALL CONDITIONS ARE SATISFIED
				{
					flag = 1;
					cout << "Room found" << endl;
					a[i].displayroom();
				}
			}
			if (flag == 0)
			{
				cout << "No such room is available." << endl;
			}
		}
		void CheckIn()		//CHECK IN OF A CUSTOMER
		{
			if (nroom == 0)
			{
				cout << "Please add rooms." << endl;
				return;
			}
			int i, rno;
			if (ncust <= nroom) {	//CHECKING CONDITION IF HOTEL HAS EMPTY ROOMS
				c[ncust].booking_id = ncust + 1;	//ALLOTING CUSTOMER ID TO THE CUSTOMER
			flag:
				int flag1 = 0;
				cout << "Enter room number=";		//ASKING WHAT ROOM NUMBER CUSTOMER WANTS TO STAY IN
				cin >> rno;
				for (i = 0; i < nroom; i++) {
					if (rno == a[i].roomNumber)
					{
						flag1 = 1;
						break;
					}
				}
				if (flag1 == 0) {
					cout << "Invalid room number. Please Enter again.\n";
					goto flag;
				}
				if (a[i].status == 0)		//CHECKING IF ROOM IS UNOCCUPIED
				{
					char ch2;
					cout << "Room available." << endl;
					a[i].displayroom();
					cout << "Do you wish to continue? Press(Y/N)";		//CONFIRMATION
					cin >> ch2;
					if (ch2 == 'Y' || ch2 == 'N')
					{
						c[ncust].accept();		//ACCEPTING CUSTOMER DETAILS
						cout << "Enter number of days of stay: ";
						cin >> c[ncust].days;
						c[ncust].bill = c[ncust].days * a[i].rent;		//generating bill. bill= No. of days * rent per day.
						cout << "Your total bill will be." << (c[ncust].bill) << "." << endl << ". Min adv payment=" << c[ncust].bill / 4 << "What will you be paying?";
						cin >> c[ncust].payment_advance;
						while (c[ncust].payment_advance<c[ncust].bill / 4 || c[ncust].payment_advance>c[ncust].bill)
						{
							cout << "Enter valid amount.";
							cin >> c[ncust].payment_advance;
						}
						cout << "Thank you. Booking confirmed." << endl;		//confirmed booking
						cout << "--------------------------------------------------------------" << endl;		//printing booking details
						cout << "Booking Id: " << c[ncust].booking_id << "\nName: " << c[ncust].name << "\nRoom no.: " << rno << "\nDate: ";
						time_t my_time = time(NULL);
						// ctime() used to give the present time
						printf("%s", time(&my_time));
						a[i].status = 1;		//changing room status to booked
						c[ncust].room = rno;		//alloting room to customer
						c[ncust].status = 1;
						ncust++;
					}
					else		//if needs to change room number
					{
						goto flag;
					}
				}
				else		//if room is occupied
				{
					cout << "Room Occupied. Please choose another room." << endl;
				}
			}
			else		//CONDITION ALL ROOMS ARE BOOKED
			{
				cout << "Sorry! Hotel is Full." << endl;
			}
		}
		void CheckOut()		//CHECKING OUT
		{
			int rno, i, j;
			cout << "Enter room number= ";
			cin >> rno;
			for (j = 0; j < nroom; j++) {
				if (rno == a[j].roomNumber)
				{
					break;
				}
			}
			if (a[j].status == 0)		//IF ROOM NOT FOUND OCCUPIED
			{
				cout << "Invalid." << endl;
			}
			for (i = 0; i < ncust; i++)	//CHECKING CUSTOMER DETAILS
			{
				if (c[i].room == rno)
				{
					cout << "Check Out!." << endl;
					c[i].display();		//CUSTOMER DETAILS
					cout << "Your total bill is " << c[i].bill << endl;
					cout << "Advance payment: " << c[i].payment_advance;
					cout << endl << "Hence, pending payment." << c[i].bill - c[i].payment_advance;		//PENDING PAYMENTS
					cout << endl << "Thank you! Visit Again :)" << endl;
					a[j].status = 0;	//CHANGING STATUS OF ROOM TO UNOCCUPIED
					c[i].status = 0;	//CHECKED OUT
					break;
				}
			}
			
		}
};

