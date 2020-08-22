//
// Author: Timmy Hagler CS 221-01
//
#pragma once
//#include "EmployeeRecord.h"
#include "CustomerList.h"
#include "Store.h"

#include <iostream>

using namespace std;

class EmployeeRecord
{
public:
	//First constructor
	EmployeeRecord();
	
	//Second Constructor
	EmployeeRecord(int ID, char* fName, char* lName, int dept, double sal);


	 ~EmployeeRecord();	//Destructor

	 //Public Variables
	 EmployeeRecord *m_pLeft, *m_pRight;

	
	//Declare functions
	int getID();
	void setID(int ID);
	void getName(char* fName, char* lName);
	void setName(char* fName, char* lName);
	int getDept();
	void setDept(int d);
	double getSalary();
	void setSalary(double sal);
	void printRecord();
	CustomerList *getCustomerList();
	void removeCustomerList();
	void destroyCustomerList();
	
	





private:
	int m_iEmployeeID;
	char m_sLastName[32];
	char m_sFirstName[32];
	int m_iDeptID;
	double m_dSalary;
	CustomerList *m_pCustomerList = new CustomerList();
	

};
