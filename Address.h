#pragma once

#include <iostream>
#include <string>
using namespace std;

class Address
{
private:
	string street;
	string city;

public:
	Address(string s, string c) : street(s), city(c) {}

	void display()
	{
		cout << street << " " << city << endl;
	}

	friend ostream& operator<<(ostream& out, Address& me)
	{
		out << me.street << " " << me.city << endl;
		return out;
	}

}; 
