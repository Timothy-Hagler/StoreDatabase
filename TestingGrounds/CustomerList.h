//
// Author: Timmy Hagler CS 221-01
//

//#ifndef CUSTOMERLIST_H
//#define CUSTOMERLIST_H



#pragma once
#include "Store.h"
//#include "EmployeeRecord.h"
#include <iostream>

using namespace std;

class CustomerList:public Store
{
public:
	CustomerList();
	~CustomerList();


	bool addStore(Store *s);
	Store *removeStore(int ID);
	Store *getStore(int ID);
	bool updateStore(int ID, char *name, char *addr, char *city, char *st, char *zip);
	void printStoresInfo();
	
private:
	Store *m_pHead = m_pNext;;

};

//#endif
