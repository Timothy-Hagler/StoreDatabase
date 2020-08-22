//
//Created by Timmy Hagler
//
#define _CRT_SECURE_NO_WARNINGS
//#define DEBUG_1
#include "EmployeeRecord.h"
#include "CustomerList.h"
#include "Store.h"
#include "EmployeeDatabase.h"
#include <iostream>


using namespace std;



int main()
{
	
	EmployeeRecord* er = new EmployeeRecord();	//Declare first object of EmployeeRecord

	//Declare all variables local to main
	int ID = 0;
	int dept = 0;
	double sal = 0;
	char fName[32], lName[32];
	char addr[25];
	char sName[64];
	char city[25];
	char st[20];
	char zip[11];
	int testNum = 2234;
	CustomerList *cus = new CustomerList();
	//EmployeeRecord *er2 = new EmployeeRecord();



	//All employee functions tested

	er->setID(5094);
	ID = er->getID();
	er->setName(strcpy(fName, "John") , strcpy(lName, "Doe"));
	er->getName(fName, lName);
	er->setDept(123);
	dept = er->getDept();
	er->setSalary(80500);
	sal = er->getSalary();
#ifdef DEBUG_1
	if (ID == 1234)
		cout << "Get/setID success. " << ID << endl;



	if (dept == 123)
		cout << "Get/setDept success. "  << dept << endl;

	if ((strcmp(fName, "John") == 0) && (strcmp(lName, "Doe") == 0))
		cout << "Get/setName success " << fName << " " << lName << endl;



	if (sal == 80500)
		cout << "Get/setSalary success " << sal << endl;
#endif

	cout << "PRINTING EMPLOYEE RECORD . . ." << endl;
	er->printRecord();




	//Create second object with second costructer
	EmployeeRecord *er2 = new EmployeeRecord(784578, fName, lName, 758965, 85740.5789);
	
	
	cout << endl << endl;

	//Run all Methods for er2
	er2->setID(5432);
	ID = er2->getID();
	er2->setName(strcpy(fName, "Jack"), strcpy(lName, "Doe"));
	er2->getName(fName, lName);
	er2->setDept(75489);
	dept = er2->getDept();
	er2->setSalary(87000.52);
	sal = er2->getSalary();

	//Debugging Statements
#ifdef DEBUG_1
	if (ID == 5432)
		cout << "Get/setID success. " << ID << endl;

	if ((strcmp(fName, "Jack") == 0) && (strcmp(lName, "Doe") == 0))
		cout << "Get/setName success" << endl;

	if (dept == 75489)
		cout << "Get/setDept success. " << dept << endl;

	if (sal == 87000.52)
		cout << "Get/setSalary success " << sal << endl;
#endif
	
	cout << "PRINTING NEXT EMPLOYEE RECORD . . ." << endl;

	er2->printRecord();	//Print er2 record
	
	cout << endl << endl;

	cout << "STORE LIST" << endl;


	//Testing CustomerList
	er->getCustomerList()->setStoreID(2234);
	er->getCustomerList()->setStoreName(strcpy(fName, "Walmart"));
	er->getCustomerList()->setStoreAddress(strcpy(fName, "54356"));
	er->getCustomerList()->setStoreCity(strcpy(fName, "Toney"));
	er->getCustomerList()->setStoreState(strcpy(fName, "Alabama"));
	er->getCustomerList()->setStoreZip(strcpy(fName, "35773"));
	er->getCustomerList()->addStore(er->getCustomerList());
	er->getCustomerList()->setStoreID(54321);
	er->getCustomerList()->setStoreName(strcpy(fName, "K-Mart"));
	er->getCustomerList()->setStoreAddress(strcpy(fName, "889977"));
	er->getCustomerList()->setStoreCity(strcpy(fName, "Athens"));
	er->getCustomerList()->setStoreState(strcpy(fName, "Alabama"));
	er->getCustomerList()->setStoreZip(strcpy(fName, "35773"));
	er->getCustomerList()->addStore(er->getCustomerList());
	er->getCustomerList()->setStoreID(2134);
	er->getCustomerList()->setStoreName(strcpy(fName, "JCP"));
	er->getCustomerList()->setStoreAddress(strcpy(fName, "4548"));
	er->getCustomerList()->setStoreCity(strcpy(fName, "Florence"));
	er->getCustomerList()->setStoreState(strcpy(fName, "Alabama"));
	er->getCustomerList()->setStoreZip(strcpy(fName, "35773"));
	er->getCustomerList()->addStore(er->getCustomerList());
	er->getCustomerList()->printStoresInfo();
	//End of base Store list

	//cout << er2->getCustomerList()->getStore(testNum);

	//Update info for updateStore()
	strcpy(addr, "4685");
	strcpy(city, "Knoxville");
	strcpy(st, "TN");
	strcpy(zip, "35975");
	strcpy(sName, "Target");

	//Update the Store
	er->getCustomerList()->updateStore(2234, sName, addr, city, st, zip);

	cout << endl;
	//Remove the Store
	er->getCustomerList()->removeStore(54321);

	//Print all stores after the removal
	er->getCustomerList()->printStoresInfo();


	cout << endl;
	//End testing CustomerList


	//Delete pointers to prevent Memory Leak
	//delete er, er2; 
	//delete [] sName, addr, city, st, zip;

	delete cus;
	
	
	EmployeeDatabase *emp = new EmployeeDatabase();
	char dataFile[100];
	emp->buildDatabase(strcpy(dataFile, "C:/Users/Owner/source/repos/TestingGrounds/TestingGrounds/Prog3Data.txt"));
	cout << "BUIILDING DATABASE. PRESS 'ENTER' TO CONTINUE." << endl;
	cin.ignore();

	cout << endl;

	cout << "PRINTING ALL EMPLOYEES . . . " << endl;
	emp->printEmployeeRecords();
	cout << endl << endl;
	 
	cout << "ADDING NEW EMPLOYEE AND PRINTING NEW RECORD . . ." << endl;
	emp->addEmployee(er);
	emp->printEmployeeRecords();

	cout << endl << endl;
	cout << emp->getEmployee(1234) << endl;

	cout << "REMOVING ALL EMPLOYEES . . . " << endl;
	emp->removeEmployee(5678);
	emp->removeEmployee(6789);
	emp->removeEmployee(1234);
	emp->removeEmployee(2345);
	emp->removeEmployee(4567);
	emp->removeEmployee(9876);
	emp->removeEmployee(5094);
	emp->removeEmployee(7890);
	emp->removeEmployee(8765);
	emp->removeEmployee(3456);
	emp->removeEmployee(7654);


	cout << "ALL EMPLOYEES REMOVED" << endl;
	emp->printEmployeeRecords();


	delete emp;

	

	return 0;
}



