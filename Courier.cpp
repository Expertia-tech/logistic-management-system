#include "Courier.h"
#include "Delivery.h"
#include <iostream>
#include <fstream>
#include<string.h>
#include <iomanip>

using namespace std;

Courier::Courier()
{
	strcpy(courierName,"none");
	strcpy(password,"none");
	phone = 0;
	accountBal = 0.0;
}



/****************************************************************************/
void Courier::getCourierinfo()
{
	cout << "-------------------------------------------------\n";
	cout << "please enter your information: \n";
	
	cout << " courier name: ";
	cin >> courierName;
	
	cout << "password: ";
	cin >> password;
	
	cout << "phone: ";
	cin >> phone;
	
	cout << "Balance: ";
	cin >> accountBal;
}


/****************************************************************************/
void Courier::courierRegister()
{
	fstream file;
	system("cls");
	cout << "-------------------------------------------------\n";
	cout << "\t\t\tcourier sign up\n";
	cout << "-------------------------------------------------\n";
	
	file.open("courierRecords.dat", ios::app | ios::binary);
	getCourierinfo();
	
	file.write((char*)this, sizeof(*this));
	file.close();
		
}
		
void Courier::courierLogin(Delivery a_delivery)
{
	Delivery delivery = a_delivery;
	fstream file;
	int flag = 0;
//	int option;
	char userIdCheck[20];
	char passCheck[20];
	
	file.open("courierRecords.dat", ios::in | ios::binary);
	if(!file)
	{
		cout << "courierLogin: File not found\n";
	}else{
		cout<<"\t\t\t-------------------------------------------------\n";
		cout << "\n\n\t\t\t Please enter the courier user name and password: " << endl;
		cout << "\t\t\t userId: ";
		cin >> userIdCheck;
		cout << "\t\t\t password: ";
		cin >> passCheck;
		
		//read record from a file into object
		file.read((char*)this, sizeof(*this));
		while(!file.eof())
		{
			if(strcmp(userIdCheck, courierName) == 0 && strcmp(passCheck, password) == 0)
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
			cout << "\n\t\t\t _____________login successfull!_____________ \n\t\t\t Welcome back!! " << courierName << endl;
			cout << "\t\t\t-------------------------------------------------\n";
			system("pause");
			courierMenu();
		}else{
			system("cls");
			cout << "\t\t\t-------------------------------------------------\n";
			cout << "\n \t\t\tlogin failed! \n \t\t\tPlease check your user name and password\n";
		//	cout << "\t\t\talso if u are not regertered please register, \n\t\t\tit'll only take u a minute.\n";
			//cout <<"\t\t\t-------------------------------------------------\n";
			//cout << "\t\t\t1) Try again\n";
		//	cout << "\t\t\t2) signup\n";
			//cout << "\t\t\t3) Exit\n";
		//	cout << "\t\t\t-------------------------------------------------\n";
		//	cout << "\t\t\toption: ";
		//	cin >> option;
			
		//	switch(option)
		//	{
		//		case 1:
					//courierLogin();
		//			break;
		//		case 2:
		//			courierRegister();
		//			break;
		//		case 3:
		//			break;
		//	}
			//system("pause");
		}	//else 2
	}	// else	1
}
		
void Courier::courierMenu()
{
	int choice;
	while(1)
	{
		system("cls");
		cout << "\n";
		cout<<"\t\t\t ================================================\n";
		cout<<"\t\t\t|COURIER MANAGEMENT SYSTERM - USER MENU\t\t |\n";
		cout<<"\t\t\t ================================================\n\n\n";
		
		cout<<"\t\t\t-------------------------------------------------\n";
		cout<<"\t\t\t|\t1. change password \t\t\t|\n";
		cout<<"\t\t\t-------------------------------------------------\n";
		cout<<"\t\t\t-------------------------------------------------\n";
		cout<<"\t\t\t|\t2. balance query \t\t\t|\n";
		cout<<"\t\t\t-------------------------------------------------\n";
		cout<<"\t\t\t-------------------------------------------------\n";
		cout<<"\t\t\t|\t3. show assigned orders \t\t|\n";
		cout<<"\t\t\t-------------------------------------------------\n";
		cout<<"\t\t\t-------------------------------------------------\n";
		cout<<"\t\t\t|\t4. receive orders \t\t\t|\n";
		cout<<"\t\t\t-------------------------------------------------\n";
		cout<<"\t\t\t-------------------------------------------------\n";
		cout<<"\t\t\t|\t5. log out \t\t\t\t|\n";
		cout<<"\t\t\t-------------------------------------------------\n";
		cout << "please enter your choice:  ";
		fflush(stdin);
		cin >> choice;
		
		if(choice == 5)
		{
			break;
		}
		
		switch(choice)
		{
			case 1:
				changePass();
				break;
			case 2:
				cout << "current balance: " << accountBal << endl;
				system("pause");
				break;
			case 3:
				char holdName[20];
				strcpy(holdName, courierName);
				delivery.showPending(holdName);
				break;
			case 4:
				int result;
				 result = delivery.receivePackage();
				if(result = 1){
					getPaid();
				}else{
					cout << "package not received\n";
				}
				break;
			case 5:
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
		}	
	}
}


void Courier::reduceManagerBal(float price){
	float adminBal;
	fstream file;
	
	file.open ("adminBalance.txt", ios::in | ios::out);
	file >> adminBal;
	adminBal = adminBal - price;
	cout << "\t\t\tmanager balance: " << adminBal << endl;
	system("pause");
	file.seekg(0);
	file << adminBal;
	file.close();
}


void Courier::getPaid(){
	float amount, tempBal;
	tempBal = accountBal;
	fstream file;
	fstream filemod;
	file.open("amount.txt",ios::in);
	if(!file){
		cout<< "file not found:getPaid\n";
		return;
	}
	file >> amount;
	
	amount = amount/2;
	cout << "amount getting paid: " << amount << endl;
	tempBal = tempBal + amount;
	cout << "account balance: " <<tempBal<<endl;
	file.close();
	reduceManagerBal(amount);
	
	char holdUserName[20];
	strcpy(holdUserName, courierName);
	filemod.open("courierRecords.dat",ios::in | ios::out | ios::binary);
	if(!filemod)
	{
		cout << "courierRecords.dat not found:getPaid\n";
	} else{
	 	filemod.seekg(0);
		while(filemod.read((char*)this, sizeof(*this)))
		{
			if(!strcmp(courierName, holdUserName))
			{		
				accountBal = tempBal;		
				// move the pointer to current pos -1
				int pos = sizeof(*this);
				filemod.seekp(-pos, ios::cur);
				
				//write obj to file
				filemod.write((char*)this, sizeof(*this));
			}
		}
	} // else
	filemod.close();
}
		
void Courier::deletecourier()
{
	fstream file;
	char userIdcheck[20];	// user id of the user to delete
	ofstream fout;
	
	file.open("courierRecords.dat", ios::in | ios::binary);
	if(!file)
		cout << "deletecourier: File not found\n";
	else{
		cout << "enter the courier name you want to delete:";
		cin >> userIdcheck;
		// open new temp.dat file
		fout.open("temp.dat", ios::out | ios::binary);
		
		// read record from userRecord.dat file into object
		file.read((char*)this, sizeof(*this));
		while(!file.eof())
		{
			// if user id dont match write to new file
			if(strcmp(userIdcheck, courierName))
			{
				// write record to temp.dat file
				fout.write((char*)this, sizeof(*this));
			}
			file.read((char*)this, sizeof(*this));
		}	// while		
	}	//else
	file.close();
	fout.close();
	remove("courierRecords.dat");
	rename("temp.dat", "courierRecords.dat");
}	



void Courier::changePass()
{
	fstream file;
	char passCheck[20];	// user id of the user that you want to change the password of
	
	file.open("courierRecords.dat", ios::in | ios::out | ios::binary);
	if(!file)
		cout << "\t\t\tcourier: changePass: File not found\n";
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
}



void Courier::showRecords()
{	// display with field width
	cout << setw(20) << courierName
		 << setw(20) << password
		 << setw(20) << phone
		 << setw(20) << accountBal << endl;
		 //showDelivery();
	
}

void Courier::displayCourierRec()
{
	ifstream file;
	system("cls");
	cout << left << setw(20) << "courierName"
		 << left << setw(20) << "password"
		 << left << setw(20) << "phone"
		 << left << setw(20) << "accountBal\n" << endl; 
		 
	file.open("courierRecords.dat", ios::in | ios::binary);
	if(!file)
	{
		cout << "displayCourierRec: ERROR opening file!\n";
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
}

		

