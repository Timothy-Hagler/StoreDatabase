//
// Author: Timmy Hagler CS 221-01
//
#define _CRT_SECURE_NO_WARNINGS
#include "EmployeeDatabase.h"
//Default Constructor
EmployeeDatabase::EmployeeDatabase()
{
	m_pRoot = NULL;
}

//Add an employee to the database
bool EmployeeDatabase::addEmployee(EmployeeRecord *e)
{
	EmployeeRecord *temp;
	EmployeeRecord *back;
	temp = m_pRoot;
	back = NULL;

	while (temp != NULL)
	{
		back = temp;
		if (e->getID() < temp->getID())
			temp = temp->m_pLeft;
		else
			temp = temp->m_pRight;
	}

	if (back == NULL)
		m_pRoot = e;
	else
	{
		if (e->getID() < back->getID())
			back->m_pLeft = e;
		else
			back->m_pRight = e;
	}
	return true;
}

//NEED TO BUG FIX GETEMPLOYEE AND GETSTORE
EmployeeRecord * EmployeeDatabase::getEmployee(int ID)
{
	EmployeeRecord *temp;// = new EmployeeRecord();
	EmployeeRecord *dupNode;

	temp = m_pRoot;
	while ((temp != NULL) && (temp->getID() != ID))
	{
		if (ID < temp->getID())
			temp = temp->m_pLeft; //Move left if search ID is less than node ID
		else
			temp = temp->m_pRight; //Move right because ID is greater than node ID
	}
	
	if (temp == NULL)
		return NULL;	//Only runs if ID was not found
	else
	{
		dupNode = new EmployeeRecord();
		*dupNode = *temp;
		dupNode->m_pLeft = NULL;
		dupNode->m_pRight = NULL;
		return dupNode;
	}

}

EmployeeRecord *EmployeeDatabase::removeEmployee(int ID)
{
	EmployeeRecord * back, *temp, *delParent, *delNode;

	temp = m_pRoot;
	back = NULL;

	while ((temp != NULL) && (ID != temp->getID()))
	{
		back = temp;
		if (ID < temp->getID())
			temp = temp->m_pLeft;
		else
			temp = temp->m_pRight;
	}
	if (temp == NULL)
		return NULL;
	else
	{
		delNode = temp;
		delParent = back;
	}

	if (delNode->m_pRight == NULL)
	{
		if (delParent == NULL)
		{
			m_pRoot = delNode->m_pLeft;
			delNode->m_pLeft = NULL;
			return delNode;
		}
		else
		{
			if (delParent->m_pLeft == delNode)
				delParent->m_pLeft = delNode->m_pLeft;
			else
				delParent->m_pRight = delNode->m_pLeft;
			delNode->m_pLeft = NULL;
			return delNode;
		}
	}
	else
	{
		if (delNode->m_pLeft == NULL)
		{
			if (delParent == NULL)
			{
				m_pRoot = delNode->m_pRight;
				delNode->m_pRight = NULL;
				return delNode;
			}
			else
			{
				if (delParent->m_pLeft == delNode)
					delParent->m_pLeft = delNode->m_pRight;
				else
					delParent->m_pRight = delNode->m_pRight;
				delNode->m_pRight = NULL;
				return delNode;
			}
		}
		else
		{
			EmployeeRecord *dupNode = new EmployeeRecord();
			*dupNode = *delNode;
			dupNode->m_pLeft = NULL;
			dupNode->m_pRight = NULL;
			
			EmployeeRecord *retNode = dupNode;

			temp = delNode->m_pLeft;
			back = delNode;

			while (temp->m_pRight != NULL)
			{
				back = temp;
				temp = temp->m_pRight;
			}

			char fName[32], lName[32];
			delNode->setID(temp->getID());
			delNode->setDept(temp->getDept());
			temp->getName(fName, lName);
			delNode->setName(fName, lName);
			delNode->setSalary(temp->getSalary());

			if (back == delNode)
				back->m_pLeft = temp->m_pLeft;
			else
				back->m_pRight = temp->m_pLeft;
			delete temp;
			return retNode;

		}
	}
}

//Build the Database
bool EmployeeDatabase::buildDatabase(char *dataFile)
{

		bool OK = true;
		int numEmp, id, dept, numStores, sID;
		double sal;
		EmployeeRecord *empRec;
		CustomerList *theList;
		Store *theStore;
		char inStr[128];
		char fName[32];
		char lName[32];
		char sName[64];
		char sAddr[64];
		char sSt[32];
		char sCity[32];
		char sZip[12];


		inFile.open(dataFile, ifstream::in);
		if (!inFile.is_open())
		{
			// inFile.is_open() returns false if the file could not be found or
			//    if for some other reason the open failed.
			cout << "Unable to open file" << dataFile << "\nProgram terminating...\n";
			cout << "Press Enter to continue...";
			getc(stdin);
			return false;
		}

		// Get number of employees
		getNextLine(inStr, 128);
		numEmp = atoi(inStr);
		for (int i = 0; i < numEmp; i++)
		{
			// Instantiate an EmployeeRecord
			empRec = new EmployeeRecord();
			// Read and set the ID
			getNextLine(inStr, 128);
			id = atoi(inStr);
			empRec->setID(id);
			// Read and set the name
			getNextLine(fName, 32);
			getNextLine(lName, 32);
			empRec->setName(fName, lName);
			// Read and set the Department ID
			getNextLine(inStr, 128);
			dept = atoi(inStr);
			empRec->setDept(dept);
			// Read and set the Salary
			getNextLine(inStr, 128);
			sal = atof(inStr);
			empRec->setSalary(sal);
			// Get the customer list
			theList = empRec->getCustomerList();
			// Get the number of stores
			getNextLine(inStr, 128);
			numStores = atoi(inStr);
			for (int j = 0; j < numStores; j++)
			{
				// Read the store ID
				getNextLine(inStr, 128);
				sID = atoi(inStr);
				// Read the store name
				getNextLine(sName, 64);
				// Read the store address
				getNextLine(sAddr, 64);
				// Read the store city
				getNextLine(sCity, 32);
				// Read the store state
				getNextLine(sSt, 32);
				// Read the store zip
				getNextLine(sZip, 11);
				// Create a new Store object
				theStore = new Store(sID, sName, sAddr, sCity, sSt, sZip);
				theList->addStore(theStore);
			}
			cout.flush();
			addEmployee(empRec);
		}
		inFile.close();
		return true;	// Successfully built the database
	

}

//--------------------------------------------
// GetNextLine() 
// Read a line from a data file.
//--------------------------------------------
bool EmployeeDatabase::getNextLine(char *line, int lineLen)
{
	int    done = false;
	while (!done)
	{
		inFile.getline(line, 128);

		if (inFile.good())    // If a line was successfully read
		{
			if (strlen(line) == 0)  // Skip any blank lines
				continue;
			else if (line[0] == '#')  // Skip any comment lines
				continue;
			else return true;    // Got a valid data line so return with this line
		}
		else
		{
			strcpy(line, "");
			return false;
		}
	} // end while
	return false;
}

//Call private function to print the tree
void EmployeeDatabase::printEmployeeRecords()
{
	printEmployeeRecords(m_pRoot);
}

//Print the tree
void EmployeeDatabase::printEmployeeRecords(EmployeeRecord *rt)
{
	if (rt != NULL)
	{
		printEmployeeRecords(rt->m_pLeft);
		rt->printRecord();
		printEmployeeRecords(rt->m_pRight);
	}
}

void EmployeeDatabase::destroyTree(EmployeeRecord *rt)
{
	
	if (rt == NULL)
		return;
	if (rt->m_pLeft != NULL)
		destroyTree(rt->m_pLeft);
	if (rt->m_pRight != NULL)
		destroyTree(rt->m_pRight);
	delete rt;
	
	return;
}



//Destructor
EmployeeDatabase::~EmployeeDatabase()
{
	
	destroyTree(m_pRoot);
	return;
}