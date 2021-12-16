#include "Costumer.h"
/** @file Costumer.cpp

 *  @brief Brief description of file.
 * This file will work with the costumer's information inputed

 *  Longer description of file.
 * Costumer file will ask user to input all the costumer's information needed 
 *then dysplay it.

 *  @author Gabriela Alvarez

 *  @bug No known bugs. NA

 */



void Costumer::accept()		//ACCEPTING CUSTOMER DETAILS
{
	/** @brief Short description of function.
	This function will ask specific costumer questions. Agregation being used.
 *
 *  Longer description of function.
	This function takes the information of a costumer like its name adress and phone number
 *

 *  @param One for each parameter with the name and a description

 *  @return The word void or a description of what is returned

 */
	cout << "Enter customer name: ";
	getline(cin, name);
	cout << "Enter Customer address: ";
	getline(cin, address);
flag:
	cout << "Enter mobile number: ";
	cin >> phone;

	//LO7.Defineand use iteratorsand other operations on aggregates, including operations that take functions as arguments.
	//Agregate functions 
	for (int unsigned i = 0; i < (phone.length()); i++)	//PHONE NUMBER VALIDATIONS
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
