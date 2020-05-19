#pragma once		//prevents confusion in the compiler when we write duplicate code such as #include <iostream>
#include <iostream>
#include <string>
#include "Address.h"
#include "Date.h"
using namespace std;

class Employee
{
private:
	string name;
	Address* addr;
	Date date;

public:
	Employee(string a_name, int a_year, int a_month, int a_day) : date(a_year, a_month, a_day), name(a_name), addr(nullptr) {};    //after the colon is the initializer list- its like it says name=n
	//															^ aggregation - initialize to a known value
	//										^composition
	~Employee()
	{
		if (addr != nullptr)
			delete addr;
	}

	void setAddress(string a_street, string a_city)
	{
		if (addr != nullptr)
			delete addr;
		addr = new Address(a_street, a_city);
	}

	virtual void display()
	{
		cout << name << endl;
		date.display();			//composition
		if (addr != nullptr)
			addr->display();	//aggregation
	}

	friend ostream& operator<<(ostream & out, Employee & me)
	{
		out << me.name << endl;
		out << me.addr << endl;		//composition
		if (me.addr != nullptr)
			out << *me.addr;	//aggregation
		out << endl;
		return out;
	}

	virtual double calcPay() = 0;

	string getName()
	{
		return name;
	}
	
};