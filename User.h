////////////////////////////////////
// user for final project 2       //
/* this module consist of class Use
	all the necessary functions 
	related to it				*/
////////////////////////////////////
#ifndef USER_H
#define USER_H
#include <fstream>


class User
{
	public:
		User();					// constructor that initiate the recordswiht 0(creates empty string)
		void getRecords();		// gets all the records and initiate the user obj
		void showRecords();		// displays the records in the obj class
		
		void userLogin();		// for user login
		void userMenu();		// user menu
		
		void rechargeBalance();		// returns the balance
		void pay(char* username, float price);				// -15 from the user acount

		void insertRecord();	// for registration // inserts into the file(database)
		void findRecord();		// to search a particular record
		void displayAllRecords();	// function to display all the records fromthe file	
		void deleteRecord();	//deletes the record form the file // only for admin previlage
		void changePassword();	// change the password of a particular user
		void updateInfo();		// admin previlage

	private:
		char userId[20];
		char password[20];
		char name[20];
		char address[20];
		float balance;
		int phone;		
};



#endif
