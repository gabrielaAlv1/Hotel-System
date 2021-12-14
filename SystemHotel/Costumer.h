#pragma once
#include<iostream>
#include<string>
#include<string.h>
#include <iomanip>
#include <time.h>
#include<ctime> /* time_t, time, ctime */
#include "costumer.h"



using namespace std;
class Costumer
{
public:
	string name;	   			 //costumer's name 
	string address;				//Costumer's adress
	string phone;				//CONTACT NUMBER
	int days = 0;	    			//DURATION OF STAY
	float payment_advance;		//ADVANCE PAYMENT
	double bill = 0;				//BILL AMT
	int booking_id;				//BOOKING ID
	int room;					//ROOM NO
	int status;
 
	Costumer()
	{
		days = 0;
		payment_advance = 0;
		bill = 0;
		booking_id = 0;
		status = 0;
		room = 0;
	}
	void accept();				//ACCEPT CUSTOMER DETAILS
	void display();				//DISPLAY CUSTOMER DETAILS
};

void Costumer::accept()		//ACCEPTING CUSTOMER DETAILS
{
	cout << "Enter customer name: ";
	getline(cin, name);
	cout << "Enter Customer address: ";
	getline(cin, address);
flag:
	cout << "Enter mobile number: ";
	cin >> phone;
	//Agregate functions 
	for (int i = 0; i < (phone.length()); i++)	//PHONE NUMBER VALIDATIONS
	{									//PHONE NUMBER NEEDS TO BE ALL DIGITS AND 10 IN LENGTH
		if (!isdigit(phone[i]))
		{
			cout << "Phone number has to be in digits.\n";
			goto flag;
		}
	}
	if (phone.length() != 10)		//PHONE LENGTH VALIDATIONS
	{
		cout << "Phone number should be 10 digits.\n";
		goto flag;
	}
}
//

void Costumer::display()		//DISPLAYING CUSTOMER DETAILS
{
	cout << booking_id << "\t\t";
	cout << "| " << left << setfill(' ') << setw(30) << name;
	cout << "| " << phone << "\t\t\t";
	cout << "| " << left << setfill(' ') << setw(30) << address;
	cout << "| " << room << "\t\t\t";
	if (status == 1) { cout << "|\t\t-\t\t|" << endl; }
	else { cout << "|\tCHECKED OUT.\t\t|" << endl; }
};

