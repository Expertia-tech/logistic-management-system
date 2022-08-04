#ifndef COURIER_H
#define COURIER_H
#include "Delivery.h"

class Courier
{
	public:
		Delivery delivery;
		Courier();
		void getCourierinfo();
		void courierRegister();
		
		void courierLogin(Delivery a_delivery);
		void courierMenu();
		
		void deletecourier();	// removes the courier name from the database // admin previlage
		void changePass();
		
		void displayCourierRec();
		void getPaid();
		void showRecords();
		void reduceManagerBal(float price);
		// receive package
		//void getBalance();
		
		
	private:
		char courierName[20];
		char password[20];
		int phone;
		float accountBal;
};

#endif
