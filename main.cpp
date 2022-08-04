#include <iostream>
#include <stdlib.h>

#include "User.h"
#include "Courier.h"
#include "Admin.h"
#include "Delivery.h"

using namespace std;
	
int main(){
	int choice;	 // to prmpt the user to choose the option	
	
	Admin admin;
	User user;
	Courier courierObj;
	Fragile fragile;
	Book book;
	Ordinary ordinary;
	
	Delivery deliveryObj;
	
	while(1)
	{
		system("color 0b");
		system("cls");
		cout << "\t\t\t ================================================\n";
		cout << "\t\t\t|USER MANAGEMENT SYSTERM - LOGIN MENU\t\t |\n";
		cout << "\t\t\t ================================================\n\n\n";
		cout << "\t\t\t-------------------------------------------------\n";
		cout << "\t\t\t|\t1. SIGN UP        \t\t\t|\n";
		cout << "\t\t\t-------------------------------------------------\n";
		cout << "\t\t\t-------------------------------------------------\n";
		cout << "\t\t\t|\t2. USER        \t\t\t\t|\n";
		cout << "\t\t\t-------------------------------------------------\n";
		cout << "\t\t\t-------------------------------------------------\n";
		cout << "\t\t\t|\t3. COURIER         \t\t\t|\n";
		cout << "\t\t\t-------------------------------------------------\n";
		cout << "\t\t\t-------------------------------------------------\n";
		cout << "\t\t\t|\t4. ADMIN         \t\t\t|\n";
		cout << "\t\t\t-------------------------------------------------\n\n";
		cout << "\t\t\t-------------------------------------------------\n";
		cout << "\t\t\t|\t5. SEND PACKAGE      \t\t\t|\n";
		cout << "\t\t\t-------------------------------------------------\n";
		cout << "\t\t\t-------------------------------------------------\n";
		cout << "\t\t\t|\t6. RECEIVE PACKAGE        \t\t|\n";
		cout << "\t\t\t-------------------------------------------------\n";
		cout << "\t\t\t-------------------------------------------------\n";
		cout << "\t\t\t|\t7. EXIT        \t\t\t\t|\n";
		cout << "\t\t\t-------------------------------------------------\n";
		cout << "\t\t\tplease enter your choice: ";
	
		fflush(stdin);
		cin >> choice;
		if (cin.fail())
		{
			cin.clear();	// clears error flag
			cin.ignore(10000, '\n');
			cout << "\t\t\t-------------------------------------------------\n";
			cout << "\t\t\tplease enter a valid option!!" <<endl;
			cout << "\t\t\t-------------------------------------------------\n";
			system("pause");
		}else{
			switch(choice)
			{
				case 1:
						// register new user
						user.insertRecord();						
					break;
				case 2:
						// user login
						user.userLogin();
					break;
				case 3:
					courierObj.courierLogin(deliveryObj);
						// courier login
					break;
				case 4:
						// admin login
						admin.adminLogin(user, deliveryObj, courierObj);
					break;
				case 5:
					deliveryObj.sendPackage(user, fragile, book, ordinary);
					break;
				case 6:
					deliveryObj.userReceive();
					break;
				case 7:
					cout << "\t\t\t-------------------------------------------------\n";
					cout << "\t\t\tThank you!!\n";
					cout << "\t\t\t-------------------------------------------------\n";
					exit(1);
					break;
				default:
					cout << "\t\t\t-------------------------------------------------\n";
					cout << "\n\t\t\tINVALID OPTION!!\n";
					cout << "\t\t\tPlease select from the options given above.\n";
					cout << "\t\t\t-------------------------------------------------\n";
					system("pause");
					break;
	 		}	// switch
		} // else 
	}	//while	
	return 0;
}
