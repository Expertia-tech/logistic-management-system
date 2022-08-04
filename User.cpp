#include "User.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include <time.h>
#include<string.h>

using namespace std; 

fstream file;

/********************************************************************************/
User::User()
{
	strcpy(userId,"none");
	strcpy(password,"none");
	strcpy(name,"none");
	strcpy(address,"none");
	balance = 0.0;
	phone = 0;	
}


/********************************************************************************/
void User::getRecords()
{
	cout << "-------------------------------------------------\n";
	cout << "please enter your information: \n";
	
	cout << "user ID: ";
	cin >> userId;
	fflush(stdin);
	
	cout << "password: ";
	cin >> password;
	fflush(stdin);
	
	cout << "name: ";
	cin >> name;
	fflush(stdin);
	
	cout << "address: ";
	cin >> address;
	fflush(stdin);
	
	cout << "balance: ";
	cin >> balance;
	fflush(stdin);
	
	cout << "phone: ";
	cin >> phone;
	fflush(stdin);
}


/********************************************************************************/
void User::showRecords()
{	// display with field width
	cout << setw(20) << userId
		 << setw(20) << password
		 << setw(20) << name
		 << setw(20) << address
		 << setw(20) << balance
		 << setw(20) << phone << endl;
		 //showDelivery();
	
}





/********************************************************************************/
// -15 from the user balance
void User::pay(char* username, float price)
{
	//float tempBalance = balance;
	//char holdUserId[20];	// to search the record in the file and update it
	//strcpy(holdUserId, userId);
	
	//tempBalance = tempBalance - 15;
	
	file.open("userRecords.dat", ios::in | ios::out | ios::binary);
	if(!file)
		cout << "File not found\n";
	else{
		file.seekg(0);
		
		while(file.read((char*)this, sizeof(*this)))
		{
			if(!strcmp(userId, username))
			{	
				balance = balance - price;	// update the amount			
				// move the pointer to current pos -1
				int pos = sizeof(*this);
				file.seekp(-pos, ios::cur);
				
				//write obj to file
				file.write((char*)this, sizeof(*this));
			}
		}	// while
	} // else
	file.close();
}// end of function



/********************************************************************************/
// user login 
void User::userLogin()
{
	int flag = 0;
	int option;
	char userIdCheck[20];
	char passCheck[20];
	
	file.open("userRecords.dat", ios::in | ios::binary);
	if(!file)
	{
		cout << "userLogin: File not found\n";
	}else{
		cout<<"\t\t\t-------------------------------------------------\n";
		cout << "\n\n\t\t\t Please enter the userId and password: " << endl;
		cout << "\t\t\t userId: ";
		cin >> userIdCheck;
		cout << "\t\t\t password: ";
		cin >> passCheck;
		
		//read record from a file into object
		file.read((char*)this, sizeof(*this));
		while(!file.eof())
		{
			if(strcmp(userIdCheck, userId) == 0 && strcmp(passCheck, password) == 0)
			{
				flag = 1;
				break;
			}
			file.read((char*)this, sizeof(*this));
		}
		file.close();
		if(flag == 1)
		{
			system("cls");
			cout << "\t\t\t-------------------------------------------------\n";
			cout << "\n\t\t\t _____________login successfull!_____________ \n\t\t\t Welcome back!! " << userId << endl;
			cout << "\t\t\t-------------------------------------------------\n";
			system("pause");
			userMenu();
		}else{
			system("cls");
			cout << "\t\t\t-------------------------------------------------\n";
			cout << "\n \t\t\tlogin failed! \n \t\t\tPlease check your user name and password\n";
			cout << "\t\t\talso if u are not regertered please register, \n\t\t\tit'll only take u a minute.\n";
			cout <<"\t\t\t-------------------------------------------------\n";
			cout << "\t\t\t1) Try again\n";
			cout << "\t\t\t2) signup\n";
			cout << "\t\t\t3) Exit\n";
			cout << "\t\t\t-------------------------------------------------\n";
			cout << "\t\t\toption: ";
			cin >> option;
			
			switch(option)
			{
				case 1:
					userLogin();
					break;
				case 2:
					insertRecord();
					break;
				case 3:
					break;
			}
			//system("pause");
		}	//else 2
	}	// else	1
}	// end of function



/********************************************************************************/
// user menu
void User::userMenu()
{
	int choice;		// for menu options
	int flag = 0;
	while(1)
	{
		system("cls");
		system("COLOR 79");		//Color to change background
		cout<<"\n";
   		cout<<"\t\t\t ================================================\n";
		cout<<"\t\t\t|USER MANAGEMENT SYSTERM - USER MENU\t\t |\n";
		cout<<"\t\t\t ================================================\n\n\n";

		cout<<"\t\t\t-------------------------------------------------\n";
		cout<<"\t\t\t|\t1. change password \t\t\t|\n";
		cout<<"\t\t\t-------------------------------------------------\n";
		cout<<"\t\t\t-------------------------------------------------\n";
		cout<<"\t\t\t|\t2. balance query \t\t\t|\n";
		cout<<"\t\t\t-------------------------------------------------\n";
		cout<<"\t\t\t-------------------------------------------------\n";
		cout<<"\t\t\t|\t3. balance recharge \t\t\t|\n";
		cout<<"\t\t\t-------------------------------------------------\n";
		cout<<"\t\t\t-------------------------------------------------\n";
		cout<<"\t\t\t|\t4. log out \t\t\t\t|\n";
		cout<<"\t\t\t-------------------------------------------------\n\n";
		cout <<"\t\t\tPlease enter your choice: ";
		fflush(stdin);
		if(choice == 4)
		{
			// return to login page
			break;	
		}
		cin >> choice;
		
		switch(choice)
		{
			case 1:
				changePassword();
				break;
			case 2:
				cout << "\t\t\t-------------------------------------------------\n";
				cout << "\t\t\tyour current balance is: " << balance << endl;
				cout <<"\t\t\t-------------------------------------------------\n";
				system("pause");
				break;
			case 3:
				rechargeBalance();
				break;
			/*case 4:
				sendPackage();
				break;
			case 5:
				receivePackage();
				break;
			*/
			case 4:
				cout << "\t\t\t-------------------------------------------------\n";
				cout << "\t\t\tback to login page.......\n";
				system("pause");
				cout << "\t\t\t-------------------------------------------------\n";
				break;
			default:
				cout << "\t\t\t-------------------------------------------------\n";
				cout << "\n\t\t\tINVALID OPTION!!\n";
				cout << "\t\t\tPlease select from the options given above.\n";
				cout << "\t\t\t-------------------------------------------------\n";
				system("pause");
				system("cls");
				break;
		}	// switch
	}	// while
}



/********************************************************************************/
// get hte balance of a particular user
void User::rechargeBalance()
{
	char ch = 'y';
	float tempBalance = balance;
	float amount;
	char holdUserId[20];	// to search the record in the file and update it
	strcpy(holdUserId, userId);
	
	while ( ch == 'y' || ch == 'Y')
	{
		cout << "\t\t\tplease enter the amount you want to deposit: ";
		cin >> amount;
		tempBalance = tempBalance + amount;
		cout << "\t\t\twould you like to make more deposits....(y/n)\n";
		cout << "\t\t\t-------------------------------------------------\n";
		cout << "\t\t\toption: ";
		cin >> ch;		
	}
	file.open("userRecords.dat", ios::in | ios::out | ios::binary);
	if(!file)
		cout << "rechargeBalance: File not found\n";
	else{
		file.seekg(0);
		
		while(file.read((char*)this, sizeof(*this)))
		{
			if(!strcmp(userId, holdUserId))
			{	
				balance = tempBalance;	// update the amount			
				// move the pointer to current pos -1
				int pos = sizeof(*this);
				file.seekp(-pos, ios::cur);
				
				//write obj to file
				file.write((char*)this, sizeof(*this));
			}
		}	// while
	} // else
	file.close();
}// end of function



/********************************************************************************/
// function to insert new record
void User::insertRecord()
{	
	system("cls");
	cout << "-------------------------------------------------\n";
	cout << "\t\t\tsign up\n";
	cout << "-------------------------------------------------\n";
	file.open("userRecords.dat", ios::app | ios::binary);
	getRecords();
	
	// write object into a file
	file.write((char*)this, sizeof(*this));
	file.close();
}	//end of function



/********************************************************************************/
// function to display all the recors fromthe file
void User::displayAllRecords()
{
	system("cls");
	cout << left << setw(20) << "userId"
		 << left << setw(20) << "password"
		 << left << setw(20) << "name"
		 << left << setw(20) << "address"
		 << left << setw(20) << "balance"
		 << left << setw(20) << "phone\n" << endl; 
		 
	file.open("userRecords.dat", ios::in | ios::binary);
	if(!file)
	{
		cout << "displayAllRecords: ERROR opening file!\n";
		exit(0);
	}else{
		// read records from the file into object
		file.read((char*)this, sizeof(*this));
		while(!file.eof())
		{
			showRecords();		// display obj records
			file.read((char*)this, sizeof(*this));
		}
	}
	file.close();
	system("pause");
}	// end of function



/********************************************************************************/
// function to search a particular record
void User::findRecord()
{
	int flag = 0;
	char userIdcheck[20];
	
	file.open("userRecords.dat", ios::in | ios::binary);
	if(!file)
	{
		cout << "findRecord: ERROR opening file\n";
		exit(0);
	}else{
		cout << "enter the user id you want to search: ";
		cin >> userIdcheck;
		
		//read record from a file into object
		file.read((char*)this, sizeof(*this));
		while(!file.eof())
		{
			if(!strcmp(userIdcheck, userId))
			{
				flag = 1;
				showRecords();		// display obj records
				break;
			}
			file.read((char*)this, sizeof(*this));
		}
		if(flag == 0)
		{
			cout << "ops!! seems like the user is not registered.\n";
			// can promt the user to register
			// call insertRecord function
		}		
	}	
	file.close();	// close the file obj	
}	// end of function



/********************************************************************************/
// delete a record from a file // admin previlage
void User::deleteRecord()
{
	char userIdcheck[20];	// user id of the user to delete
	ofstream fout;
	
	file.open("userRecords.dat", ios::in | ios::binary);
	if(!file)
		cout << "deleteRecord: File not found\n";
	else{
		cout << "enter the userId you want to delete:";
		cin >> userIdcheck;
		// open new temp.dat file
		fout.open("temp.dat", ios::out | ios::binary);
		
		// read record from userRecord.dat file into object
		file.read((char*)this, sizeof(*this));
		while(!file.eof())
		{
			// if user id dont match write to new file
			if(strcmp(userIdcheck, userId))
			{
				// write record to temp.dat file
				fout.write((char*)this, sizeof(*this));
			}
			file.read((char*)this, sizeof(*this));
		}	// while		
	}	//else
	file.close();
	fout.close();
	remove("userRecords.dat");
	rename("temp.dat", "userRecords.dat");
} // end of deleteRecord()



/********************************************************************************/
// updates the password of the user in the file
void User::changePassword() 
{
	char passCheck[20];	// user id of the user that you want to change the password of
	
	file.open("userRecords.dat", ios::in | ios::out | ios::binary);
	if(!file)
		cout << "\t\t\tchangePassword: File not found\n";
	else{
		file.seekg(0);
		cout << "\t\t\tenter your old password: ";
		cin >> passCheck;
		
		while(file.read((char*)this, sizeof(*this)))
		{
			if(!strcmp(password, passCheck))
			{
				cout << "\t\t\tenter your new password: ";
				cin >> password;	// update the pass word
				
				// move the pointer to current pos -1
				int pos = sizeof(*this);
				file.seekp(-pos, ios::cur);
				
				//write obj to file
				file.write((char*)this, sizeof(*this));
			}
		}	// while
			//cout << "\t\t\tincorrect password!!\n \t\t\ttry again..\n";
			system("pause");
	}
	file.close();
}	// end of function


void User::updateInfo()
{
	char idCheck[20];
	
	file.open("userRecords.dat", ios::in | ios::out | ios::binary);
	if(!file)
		cout << "\t\t\tchangePassword: File not found\n";
	else{
		file.seekg(0);
		cout << "\t\t\tenter your user id: ";
		cin >> idCheck;
		
		while(file.read((char*)this, sizeof(*this)))
		{
			if(!strcmp(userId, idCheck))
			{
				getRecords();
				// move the pointer to current pos -1
				int pos = sizeof(*this);
				file.seekp(-pos, ios::cur);
				
				//write obj to file
				file.write((char*)this, sizeof(*this));
			}
		}	// while
			//cout << "\t\t\tincorrect password!!\n \t\t\ttry again..\n";
			system("pause");
	}
	file.close();
	
}

