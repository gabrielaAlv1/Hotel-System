#include <iostream>
#include <string>
#include "Hotel.h"
//#include "Room.h"
//#include "Costumer.h"

/** @file name: SystemHotel.cpp
*
* @brief description of file. The admin display and the costumer display
* 
* Longer description of file. This file is my main and has the output display for the admin and costumer to use 
*
* @author Gabriela Alvarez

* @bug No known bugs.
*/

using namespace std;

int main()
{
	Hotel Gabs;		//CREATING OBJECT OF CLASS HOTEL
	char ch;
	cout << endl << "=================================================================================Welcome to Gabby's Hotel!============================================================================================";
	do
	{		//MENU TO USE AS EITHER ADMIN OR WHEN A CUSTOMER ENTERS
		cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Admin operates first~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		cout << endl << "\t\t\t\t\t\t\t\t\t\t\t"
			"MENU:\n\t\t\t\t\t\t\t\t\t\t\t"
			"1.Operate as Admin\n\t\t\t\t\t\t\t\t\t\t\t"
			"2.Operate as Costumer\n\t\t\t\t\t\t\t\t\t\t\t"
			"3.Exit\n\t\t\t\t\t\t\t\t\t\t\t"
			"Enter your choice:";
		cin >> ch;
		switch (ch)
		{
		case '1':
			cout << "Add database of rooms in the hotel:" << endl;
			Gabs.addRooms();
			cout << "Database updated. Going back to main menu." << endl;
			break;
		case '2':
			char ch1;
			do
			{
				//MENU 2 TO USE WHEN A CUSTOMER WANTS TO CHECK IN
				cout << endl << "*********************************************************************************************************************************************************" << endl;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Welcome to Gabby's Hotel!~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "\n\t\t\t\t\t\t\t\t\t\t\t"
					"Menu:\n\t\t\t\t\t\t\t\t\t\t\t"
					"1.Check Availability of rooms.\n\t\t\t\t\t\t\t\t\t\t\t"
					"2.Search Room\n\t\t\t\t\t\t\t\t\t\t\t"
					"3.Check In\n\t\t\t\t\t\t\t\t\t\t\t"
					"4.Checkout.\n\t\t\t\t\t\t\t\t\t\t\t"
					"5.Go back to Main Menu.\n\t\t\t\t\t\t\t\t\t\t\t"
					"Enter your choice:";
				cin >> ch1;
				switch (ch1)
				{
				case '1':
					Gabs.availability();
					break;
				case '2':
					Gabs.searchroom();
					break;
				case '3':
					Gabs.CheckIn();
					break;
				case '4':
					Gabs.CheckOut();
					break;
				default:
					cout << "Invalid Choice." << endl;
					break;
				}
			} while (ch1 != '4');
			break;
		case '3':
			cout << "Thank you for choosing us :) !";
			exit(0);
		default:
			cout << "Invalid Choice." << endl;
			break;
			
		}
	} while (ch != '3');
	return 0;
}