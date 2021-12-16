#pragma once
#include<iostream>
#include<string>
#include <iomanip>
#include<ctime> /* time_t, time, ctime */
/** @file Costumer.h

 *  @brief Brief description of file.
  Costumers and admin inputs 
 *

 *  Longer description of file.
 this file will declare all the information where the costumer and admin will input personal info

 *  @ Gabriela Alvarez.

 *  @bug No known bugs. 

 */


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
 public:
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


