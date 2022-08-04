#ifndef ADMIN_H
#define ADMIN_H
#include "Delivery.h"
#include "User.h"
#include "Courier.h"

class Admin
{
	public:
		Admin();
		User user;
		Delivery delivery;
		Courier courier;
		
		void adminLogin(User a_user, Delivery a_delivery, Courier a_courier);
		void adminMenu();
		void getBalance();		// gets manager's accoount balance
		
	private:
		std::string adminName; //= "admin";
		std::string adminPassword; //= "pass";	
		float managerBalance;		// every payment made to will be added to manager account};
};
#endif
