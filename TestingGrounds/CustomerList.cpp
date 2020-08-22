//
// Author: Timmy Hagler CS 221-01
//
#define _CRT_SECURE_NO_WARNINGS
#include "CustomerList.h"
#include "EmployeeRecord.h"
#include <iostream>
#include <iomanip>

using namespace std;
//Default Constructor
CustomerList::CustomerList()
{
	m_pHead = NULL;
}


//Add a store to the Linked List
bool CustomerList :: addStore(Store *s)
{
	Store *temp, *back, *newNode;

	newNode = new Store();
	temp = new Store();
	back = new Store();

	if (newNode == NULL)
		return false;
	

	newNode->setStoreID(s->getStoreID());
	newNode->setStoreAddress(s->getStoreAddress());
	newNode->setStoreCity(s->getStoreCity());
	newNode->setStoreName(s->getStoreName());
	newNode->setStoreState(s->getStoreState());
	newNode->setStoreZip(s->getStoreZip());
	newNode->m_pNext = NULL;


	if (m_pHead == NULL)
	{
		m_pHead = newNode;
	}
	else
	{
		//Find location for new node in the list
		temp = m_pHead;
		back = NULL;
		while (temp != NULL && temp->getStoreID() < s->getStoreID())	//New Edit here
		{
			back = temp;
			temp = temp->m_pNext;
		}
		//Check to see if adding at head of list
		if (back == NULL)
		{
			newNode->m_pNext = m_pHead;
			m_pHead = newNode;
		}
		else
		{
			//Insert somewhere else in the list
			back->m_pNext = newNode;
			newNode->m_pNext = temp;
		}
	}
	
	return true;



}

//Remove a Store Based on an Entered ID
Store *CustomerList::removeStore(int ID)
{
	Store *temp = new Store();
	Store *back = new Store();

	//Check if List is Empty
	if (m_pHead == NULL)
	{
		return NULL;
	}

	//Search for Item to delete
	temp = m_pHead;
	back = NULL;

	while ((temp != NULL) && (ID != temp->getStoreID()))
	{
		back = temp;
		temp = temp->m_pNext;
	}
	
	//Check to see if item was found
	if (temp == NULL)
	{
		return NULL;
	}
	else if (back == NULL)	//Check to see if node is first in the list
	{
		m_pHead = m_pHead->m_pNext;
		return temp;	//Return deleted Node
	}
	else  //Delete node elsewhere
	{
		back->m_pNext = temp->m_pNext;
		return temp;	//Return deleted Node
	}

	return NULL;	//Should not get here
}

//Find a specific Store based on an Entered ID
Store *CustomerList::getStore(int ID)
{
	Store *temp = new Store();

	temp = m_pHead;

	while ((temp != NULL) && (ID != temp->getStoreID()))
	{
		
		temp = temp->m_pNext;
	}

	//Check to see if Node is found
	if (temp == NULL)
	{
		
		return NULL;
	}
	else
	{
		Store *retItem = new Store();
		*retItem = *temp;
		retItem->m_pNext = NULL;
		return retItem;

	}


}

//Update a Store's Info
bool CustomerList::updateStore(int ID, char *name, char *addr, char *city, char *st, char *zip)
{
	Store *temp = new Store();
	temp = m_pHead;


	//Find the Store
	while ((temp != NULL) && (ID != temp->getStoreID()))
	{
		temp = temp->m_pNext;
	}
	if (temp == NULL)
		return NULL;
	else
	{
		//Update the data
		temp->setStoreAddress(addr);
		temp->setStoreCity(city);
		temp->setStoreName(name);
		temp->setStoreState(st);
		temp->setStoreZip(zip);
		return true;
	}
	return false;

}


//Print All Stores' Info
void CustomerList :: printStoresInfo()
{
	Store *temp;// = new Store();
	if (m_pHead == NULL)
		cout << "List is Empty." << endl;
	else
	{
		temp = m_pHead;
		while (temp != NULL)
		{
			cout << temp->getStoreID() << setw(20) << temp->getStoreName()
				<< setw(15) << temp->getStoreAddress() << setw(10) << temp->getStoreCity() << ","
				<< setw(15) << temp->getStoreState() << "," << setw(10)
				<< temp->getStoreZip() << endl;


			temp = temp->m_pNext;
		}
	}
}





//Destructor
CustomerList::~CustomerList()
{
	delete m_pHead, m_pNext;
}




