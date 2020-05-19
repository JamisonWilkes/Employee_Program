#include <iostream>
#include <string>
#include "CList.h"
using namespace std;

CList::~CList()
{
	if (link == nullptr)		// prevent run-away recursion
		return;

	// deallocate the entire list
	CList*	l = this->link;

	while (l != this)
	{
		CList*	t = l;
		l = l->link;
		t->link = nullptr;
		//delete t->data;
		delete t;
	}

	this->link = nullptr;
}


Person*	CList::insert(Person* key)
{
	CList*	l;

	// search for key in list
	for (l = this; l->link != this && l->link->data->getName() < key->getName(); l = l->link)
		;

	if (l->link->data != nullptr && key->getName() == l->link->data->getName())	// key is in list
		return l->link->data;

	// insert key
	CList*	t = new CList();
	t->data = key;
	t->link = l->link;
	l->link = t;

	return t->data;
}


Person*	CList::remove(Person* key)
{
	CList*	l;

	// search for key in the list
	for (l = this; l->link != this && l->link->data->getName() != key->getName(); l = l->link)
		;

	if (l->link->data != nullptr && l->link->data->getName() == key->getName())
	{
		CList*	t = l->link;
		Person*	d = t->data;
		l->link = t->link;
		t->link = nullptr;
		delete t;
		return d;
	}
	else
		return nullptr;
}



Person* CList::search(Person* key)
{
	for (CList* l = this->link; l != this; l = l->link)
		if (l->data->getName() == key->getName())
			return l->data;
	return nullptr;
}


void CList::list()
{
	for (CList* l = this->link; l != this; l = l->link)
		l->data->display();
}
