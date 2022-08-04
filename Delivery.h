#ifndef DELIVERY_H
#define DELIVERY_H
#include "Comodity.h"
#include "User.h"


class Delivery
{
	public:
		//Comodity comodityObj;
		Fragile fragile;
		Book book;
		Ordinary ordinary;
		
		User user;
		Delivery();
	
		void sendPackage(User u1, Fragile f1, Book b1, Ordinary o1);		// applies to send the package
		void applyDelivery();	// delivery form
		void showDeliveryRec();	// display query to the user
		
		void showAllDeliveryRec();	// display all the record from the file to the console
		
	//	void userPay(char* username, int payment);
		
		int receivePackage();	// receive the package by courier
		void userReceive();		// receives the package by the user
		
		void modifyRecord();	// modify user record // admin previlage
		void showPending(char* courierName);		// for courier to receive the delivery
		
		void assignDelivery(char* worker, int id);	// admin previlage // assigns delivery person
		
		void transBalance(float price);	// increase admin balance
		void deleteRecord();	// admin previlage deletes the delivery record
		void searchRecord();
		
	private:
		int deliveryId;
		char sender[20];
		char deliveryPerson[20];	// courier that the admin assigns the task to 
		char destinationUser[20];
		// assign 
		char date[10];
		int type;		// 1 for fragile 2 for book 3 for ordinary
		
		bool pending;
		bool notsigned;
		bool received;
};

#endif
