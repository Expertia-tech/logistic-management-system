#include "Admin.h"
#include "Delivery.h"
#include "User.h"
#include <iostream>


using namespace std;

// constructor
Admin::Admin()
{
	adminName = "admin";
	adminPassword = "pass";
	
}

void Admin::adminMenu()
{
	int choice;		// for menu option selection
	while(1)
	{
		system("cls");
		system("COLOR 03");
		cout<<"\n";
   		cout<<"\t\t\t ================================================\n";
		cout<<"\t\t\t|USER MANAGEMENT SYSTERM - ADMIN MENU\t\t |\n";
		cout<<"\t\t\t ================================================\n\n\n";

		cout<<"\t\t\t-------------------------------------------------\n";
		cout<<"\t\t\t|\t1. display user records \t\t|\n";
		cout<<"\t\t\t-------------------------------------------------\n";
		cout<<"\t\t\t-------------------------------------------------\n";
		cout<<"\t\t\t|\t2. delete user record \t\t\t|\n";
		cout<<"\t\t\t-------------------------------------------------\n";
		cout<<"\t\t\t-------------------------------------------------\n";
		cout<<"\t\t\t|\t3. insert user records \t\t\t|\n";
		cout<<"\t\t\t-------------------------------------------------\n";
		cout<<"\t\t\t-------------------------------------------------\n";
		cout<<"\t\t\t|\t4. courier register \t\t\t|\n";
		cout<<"\t\t\t-------------------------------------------------\n";
		cout<<"\t\t\t-------------------------------------------------\n";
		cout<<"\t\t\t|\t5. remove courier \t\t|\n";
		cout<<"\t\t\t-------------------------------------------------\n";
		cout<<"\t\t\t-------------------------------------------------\n";
		cout<<"\t\t\t|\t6. display courier records \t\t|\n";
		cout<<"\t\t\t-------------------------------------------------\n";
		cout<<"\t\t\t-------------------------------------------------\n";
		cout<<"\t\t\t|\t7. assign courier \t\t|\n";
		cout<<"\t\t\t-------------------------------------------------\n";
		cout<<"\t\t\t-------------------------------------------------\n";
		cout<<"\t\t\t|\t8. display delivery records \t\t|\n";
		cout<<"\t\t\t-------------------------------------------------\n";
		cout<<"\t\t\t-------------------------------------------------\n";
		cout<<"\t\t\t|\t9. search records \t\t|\n";
		cout<<"\t\t\t-------------------------------------------------\n";
		cout<<"\t\t\t-------------------------------------------------\n";
		cout<<"\t\t\t|\t10. log out \t\t\t\t|\n";
		cout<<"\t\t\t-------------------------------------------------\n\n";
		cout <<"\t\t\tPlease enter your choice: ";
		fflush(stdin);
		cin >> choice;
		if(choice == 10)
		{
			// return to login page
			break;	
		}
		
		switch (choice)
		{
			case 1:
				user.displayAllRecords();
				break;
			case 2:
				user.deleteRecord();
				break;
			case 3:
				user.insertRecord();	// basically register new records
				break;
			case 4:
				courier.courierRegister();
				break;
			case 5:
				courier.deletecourier();
				break;
			case 6:
				courier.displayCourierRec();
				break;
			case 7:
				int id;
				char courierName[20];
				//displayShipmentRecord();
			//	delivery.showAllDeliveryRec();
				cout << "-------------------------------------------------------------\n";
				cout << "please enter the id of the shipment order: ";
				cin >> id;
				
				cout << "courier name: ";
				cin >> courierName;
				
				delivery.assignDelivery(courierName, id);
				break;
			case 8:
				// display shipment records
				delivery.showAllDeliveryRec();
				break;
			case 9:
				// display shipment records
				delivery.searchRecord();
				break;
			case 10:
				cout<<"\t\t\t-------------------------------------------------\n";
				cout << "\t\t\tThank you!\n";
				cout << "\t\t\tback to login page..........\n";
				cout<<"\t\t\t-------------------------------------------------\n";
				system("pause");
				break;
			default:
				cout<<"\t\t\t-------------------------------------------------\n";
				cout << "\n\t\t\tINVALID OPTION!!\n";
				cout << "\t\t\tPlease select from the options given above.\n";
				cout<<"\t\t\t-------------------------------------------------\n";
				system("pause");
				system("cls");
				break;
		}
	}
}


void Admin::adminLogin(User a_user, Delivery a_delivery, Courier a_courier)
{
	user = a_user;
	delivery = a_delivery;
	courier = a_courier;
	
	string userName, adminPass;
	cout << "\t\t\tadmin name: ";
	cin >> userName;
	cout << "\t\t\tpassword: ";
	cin >> adminPass;
	
	if (userName == adminName && adminPass == adminPassword)
	{
		system("cls");
		cout << "\n\t\t\t _____________login successfull!_____________ \n \t\t\t Welcome back!! " << endl;
		cout << "\t\t\t ____________________________________________ \n";
		system("pause");
		adminMenu();
	}else{
		cout << "\t\t\t____________________________________________ \n";
		cout << "\t\t\t  login failed! \n\t\t\t not authorized user!!\n";
		cout << "\t\t\t____________________________________________ \n";
		system("pause");
	}
}

void Admin::getBalance()
{
	//
}

