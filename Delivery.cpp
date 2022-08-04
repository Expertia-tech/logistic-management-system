///////////////////////////////////
//delivery.cpp : final project 2///
///////////////////////////////////
#include "Delivery.h"
#include "User.h"
#include "Comodity.h"
#include<iostream>
#include<string.h>
#include<cstdlib>
#include<fstream>
#include <time.h>
#include<iomanip>

using namespace std;

Delivery::Delivery()
{
	deliveryId = 0;
	strcpy(sender,"none");
	strcpy(deliveryPerson,"none");
	strcpy(destinationUser,"none");
	strcpy(date,"00-00-00");
	pending  = false;
	notsigned = false;
	received = false;
}



void Delivery::sendPackage(User u1, Fragile f1, Book b1, Ordinary o1)
{
	user = u1;
	fragile = f1;
	book = b1;
	ordinary = o1;
	
	int price;
	int quantity;
	
	fstream fout;
	cout << "\t\t\t-------------------------------------------------\n";
	cout << "\t\t\t|\t       DELIVERY     \t\t\t|\n";
	cout << "\t\t\t-------------------------------------------------\n";
	
	// get info
	applyDelivery();
	
	cout << "quantity: ";
	fflush(stdin);
	cin >> quantity;
	
	switch(type){
		case 1:
			price = f1.getPrice(quantity);
			break;
		case 2:
			price = b1.getPrice(quantity);
	
			break;
		case 3:
			price = o1.getPrice(quantity);
			break;
	}
	cout << "total cost: " << price <<endl;
	// define which user
	 
	user.pay(sender, price);
	//instead open the file directly and update price
	transBalance(price);
	fstream amount;
	amount.open("amount.txt",ios::out);
	if(!amount){
		cout<< "snedPackage: file amount.txt not found!!";
	}else{
		amount.seekg(0);
		amount << price;
	}
	amount.close();
	// increase the balance of admin
	
	fout.open("deliveryRecords.dat", ios::app | ios::binary);
	if(!fout)
		cout << "snedPackage: file not found!!";
	else{
		fout.write((char*)this, sizeof(*this));
	}
	fout.close();
	
	cout << "applied for delivery successfully!\n";
	system("pause");
	
}

void Delivery::applyDelivery()
{
	cout << "\t\t\t-------------------------------------------------\n";
	// we can check if the user exist
	cout << "\t\t\tplease enter you user Id(sender): ";
	cin >> sender;
	
	cout << "\t\t\tdestination user: ";
	cin >> destinationUser;
	
	cout << "\t\t\tDate(day(00)-month(00)-year(00)): ";
	cin >> date;
	
	int flag = 0;
	while( flag == 0 )
	{
		cout << " \t\t\tpackage type: \n\n";
		cout << " \t\t\t1. fragile\n";
		cout << " \t\t\t2. book\n";
		cout << " \t\t\t3. ordinary\n";
		cout << "\t\t\tType: ";
		cin >> type;
		flag = 1;
		if (cin.fail())
			{
				cin.clear();	// clears error flag
				cin.ignore(10000, '\n');
				cout << "\t\t\t-------------------------------------------------\n";
				cout << "\t\t\tplease enter a valid option!!" <<endl;
				cout << "\t\t\t-------------------------------------------------\n";
				flag = 0;
				system("pause");
			}
	}
	
	
	pending = true;
		
	// generate random 4 digit num and give it to deliveryId
	srand(time(NULL));
	deliveryId = rand()%10000;
	cout << "\t\t\tyour package id is: " << deliveryId << endl;
}




void Delivery::showDeliveryRec()
{
	cout << setw(20) << deliveryId
		 << setw(20) << sender
		 << setw(20) << deliveryPerson
		 << setw(20) << destinationUser
		 << setw(10) << date
		 << setw(10) << type
		 << setw(10) << pending
		 << setw(10) << notsigned
		 << setw(10) << received << endl;
}

void Delivery::showAllDeliveryRec()
{
	fstream file;
	system("cls");
	cout << left << setw(20) << "deliveryId"
		 << left << setw(20) << "sender"
		 << left << setw(20) << "deliveryPerson"
		 << left << setw(20) << "destinationUser"
		 << left << setw(10) << "date"
		 << left << setw(10) << "type"
		 << left << setw(10) << "pending"
		 << left << setw(10) << "notsigned"
		 << left << setw(10) << "received" << endl;
	
	file.open("deliveryRecords.dat", ios::in | ios::binary);
	if(!file)
	{
		cout << "Delivery:showAllDeliveryRec: file not found!!\n";
		exit(0);
	}else{
		// read records from the file: deliveryRecords.dat
		file.read((char*)this, sizeof(*this));
		while(!file.eof())
		{
			showDeliveryRec();
			file.read((char*)this, sizeof(*this));
		}
	}
	file.close();
	system("pause");
}

void Delivery::showPending(char* courierName)
{
	fstream file;
	system("cls");
	cout << left << setw(20) << "deliveryId"
		 << left << setw(20) << "sender"
		 << left << setw(20) << "deliveryPerson"
		 << left << setw(20) << "destinationUser"
		 << left << setw(10) << "date"
		 << left << setw(10) << "type"
		 << left << setw(10) << "pending"
		 << left << setw(10) << "notsigned"
		 << left << setw(10) << "received" << endl;
	file.open("deliveryRecords.dat", ios::in | ios::binary);
	if(!file)
	{
		cout << "showPending: ERROR opening file\n";
		exit(0);
	}else{
		//cout << "enter the user id you want to search: ";
		//cin >> userIdcheck;
		
		//read record from a file into object
		file.read((char*)this, sizeof(*this));
		while(!file.eof())
		{
			if(!strcmp(courierName, deliveryPerson))
			{
				//flag = 1;
				showDeliveryRec();		// display obj records
				//break;
			}
			file.read((char*)this, sizeof(*this));
		}
	}	
	file.close();	// close the file obj
	system("pause");
}

// function to search a particular record
void Delivery::searchRecord()
{
	fstream file;
	int flag = 0;
	char check[20];
	
	file.open("deliveryRecords.dat", ios::in | ios::binary);
	if(!file)
	{
		cout << "searchRecord: ERROR opening file\n";
		exit(0);
	}else{
		cout << "enter sender name/date/destination of the  order you want to search: ";
		cin >> check;
		
		//read record from a file into object
		file.read((char*)this, sizeof(*this));
		while(!file.eof())
		{
			if(!strcmp(check, sender)||!strcmp(check, destinationUser)||!strcmp(check, date))
			{
				flag = 1;
				showDeliveryRec();		// display obj records
				//break;
			}
			file.read((char*)this, sizeof(*this));
		}
		if(flag == 0)
		{
			cout << "ops!! record is not found.\n";
			// can promt the user to register
			// call insertRecord function
		}		
	}	
	file.close();	// close the file obj
	system("pause");	
}	// end of function

int Delivery::receivePackage() // courier receives the package
{
	int flag=0;
	int packageId;
	cout << "please enter the package Id that u want to receive: ";
	cin >>packageId;
	fstream file;
	file.open("deliveryRecords.dat", ios::in | ios:: out | ios::binary);
	if(!file)
		cout << "Delivery:modifyRecord: file not found.\n";
	else{
		file.seekg(0);
		while(file.read((char*)this, sizeof(*this)))
		{
			if(packageId == deliveryId)
			{
				pending = false;
				notsigned = true;
			//	received = ;
				flag= 1;		// received successfully
				
				// move the pointer to current pos -1
				int pos = sizeof(*this);
				file.seekp(-pos, ios::cur);
				
				//write obj to file
				file.write((char*)this, sizeof(*this));
			}
		}	// while
	}	// else	
	file.close();
	return flag;
}

void Delivery::userReceive()
{
	int packageId;
	cout << "please enter the package Id: ";
	cin >>packageId;
	fstream file;
	file.open("deliveryRecords.dat", ios::in | ios:: out | ios::binary);
	if(!file)
		cout << "Delivery:modifyRecord: file not found.\n";
	else{
		file.seekg(0);
		while(file.read((char*)this, sizeof(*this)))
		{
			if(packageId == deliveryId && pending != true && notsigned == true)
			{
				pending = false;
				notsigned = false;
				received = true;
				
				
				// move the pointer to current pos -1
				int pos = sizeof(*this);
				file.seekp(-pos, ios::cur);
				
				//write obj to file
				file.write((char*)this, sizeof(*this));
			}else{
				cout << "package not arrived yet.\n";
			}
		}	// while
	}	// else	
	file.close();
}

void Delivery::modifyRecord()
{
	
}


// assign delivery person to a particular id
void Delivery::assignDelivery(char* worker, int id)
{
	fstream file;
	file.open("deliveryRecords.dat", ios::in | ios:: out | ios::binary);
	if(!file)
		cout << "Delivery:modifyRecord: file not found.\n";
	else{
		file.seekg(0);
		while(file.read((char*)this, sizeof(*this)))
		{
			if(id == deliveryId)
			{
				strcpy(deliveryPerson, worker);
				 				
				cout << "express id: " << id << "assigned to: " << worker << endl;
				// move the pointer to current pos -1
				int pos = sizeof(*this);
				file.seekp(-pos, ios::cur);
				
				//write obj to file
				file.write((char*)this, sizeof(*this));
			}
		}	// while
	}
	
	file.close();
}

/*
void Delivery::userPay(char* username, int payment)
{
	fstream file;
	file.open("userRecords.dat", ios::in | ios::out | ios::binary);
	if(!file)
		cout << "File not found\n";
	else{
		file.seekg(0);
		
		while(file.read((char*)this, sizeof(*this)))
		{
			if(!strcmp(userId, username))
			{	
				balance = balance - payment;	// update the amount			
				// move the pointer to current pos -1
				int pos = sizeof(*this);
				file.seekp(-pos, ios::cur);
				
				//write obj to file
				file.write((char*)this, sizeof(*this));
			}
		}	// while
	} // else
	file.close();
}
*/

void Delivery::transBalance(float price)
{
	float adminBal;
	fstream file;
	
	file.open ("adminBalance.txt", ios::in | ios::out);
	file >> adminBal;
	adminBal = adminBal + price;
	cout << "\t\t\tmanager balance: " << adminBal << endl;
	system("pause");
	file.seekg(0);
	file << adminBal;
	file.close();
}

void Delivery::deleteRecord()
{
	
}
