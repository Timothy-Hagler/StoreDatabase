//
// Author: Timmy Hagler CS 221-01
//
#define _CRT_SECURE_NO_WARNINGS
#include "EmployeeRecord.h"
#include <iostream>


using namespace std;


//////////////////////////////
//		 Functions          //
//////////////////////////////

//Default Constructor
EmployeeRecord :: EmployeeRecord()
{
	//Set all default values to 0 or blank
	m_iEmployeeID = 0;
	strcpy(m_sLastName, "");
	strcpy(m_sFirstName, "");
	m_iDeptID = 0;
	m_dSalary = 0.0;
	CustomerList *customer = new CustomerList();
	m_pCustomerList = customer;

}

//Second Constructor
EmployeeRecord :: EmployeeRecord(int ID, char* fName, char* lName, int dept, double sal)
{
	
	//Sets the default values for variables as created
	m_iEmployeeID = ID;
	strcpy(m_sFirstName, fName);
	strcpy(m_sLastName, lName);
	m_iDeptID = dept;
	m_dSalary = sal;
	CustomerList *customer = new CustomerList();
	m_pCustomerList = customer;
}

//Get the current employee's ID
int EmployeeRecord :: getID()
{
	return m_iEmployeeID;
}

//Set a new Employee ID
void EmployeeRecord :: setID(int ID)
{
	m_iEmployeeID = ID;
	return;
}

//Get the Employee's Name
void EmployeeRecord :: getName(char* fName, char* lName)
{
	strcpy(fName, m_sFirstName);
	strcpy(lName, m_sLastName);
	return;
}

//Set the Employee's Name
void EmployeeRecord :: setName(char* fName, char* lName)
{
	
	strcpy(m_sFirstName, fName);
	strcpy(m_sLastName, lName);
	return;
}

//Get the Employee's Department Number
int EmployeeRecord :: getDept()
{
	return m_iDeptID;
	
}

//Set the Employee's Department Number
void EmployeeRecord :: setDept(int d)
{
	m_iDeptID = d;
	return;
}

//Get the Employee's Salary
double EmployeeRecord :: getSalary()
{
	return m_dSalary;
	
}

//Set the Employee's Salary
void EmployeeRecord :: setSalary(double sal)
{
	m_dSalary = sal;
	return;
}

//Print the Employee's Record
void EmployeeRecord :: printRecord()
{
	cout << m_iEmployeeID << "\t\t"
		<< m_sFirstName << "\t\t"
		<< m_sLastName << "\t\t"
		<< m_iDeptID << "\t\t"
		<< m_dSalary << endl;
	return;
}

CustomerList *EmployeeRecord :: getCustomerList()
{	
	return m_pCustomerList;	
}

//Set CustomerList pointer to NULL
void EmployeeRecord::removeCustomerList()
{
	m_pCustomerList = NULL;
}

void EmployeeRecord::destroyCustomerList()
{
	delete m_pCustomerList;
	m_pCustomerList = NULL;
}

//Destructor for Class EmployeeRecord
EmployeeRecord :: ~EmployeeRecord()
{
	if(m_pCustomerList != NULL)
		delete m_pCustomerList;

}

