#pragma once

#include <iostream>
using namespace std;

class Date
{
private:
	int year;
	int month;
	int day;

public:
	Date(int y, int m, int d) : year(y), month(m), day(d) {}

	void display()
	{
		cout << year << "/" << month << "/" << day << endl;
	}

	friend ostream& operator<<(ostream& out, Date& me)
	{
		out << me.year << "/" << me.month << "/" << me.day << endl;
		return out;
	}

};
