//
// Author: Timmy Hagler CS 221-01
//
#pragma once
#include "EmployeeRecord.h"
#include <fstream>
class EmployeeDatabase
{
public:
	//Public Functions
	EmployeeDatabase();
	~EmployeeDatabase();
	bool addEmployee(EmployeeRecord *e);
	EmployeeRecord *getEmployee(int ID);
	EmployeeRecord *removeEmployee(int ID);
	void printEmployeeRecords();
	bool buildDatabase(char *dataFile);



private:
	//Private Variables
	EmployeeRecord *m_pRoot;
	ifstream inFile;

	//Private Functions
	void printEmployeeRecords(EmployeeRecord *rt);
	void destroyTree(EmployeeRecord *rt);
	bool getNextLine(char *line, int lineLen);
};

