
#pragma once
#include <iostream>

using namespace std;

class point
{
public:
	unsigned short id;
	double x, y;

	point()
	{
		id = 0;
		x = 0.0;
		y = 0.0;

	}

	~point() {}

	friend istream& operator >> (istream &s, point &ptIn)
	{
		cout << "ID: ";
		cin >> ptIn.id;
		cout << "X: ";
		cin >> ptIn.x;
		cout << "Y: ";
		cin >> ptIn.y;
		return s;
	}

	friend ostream& operator << (ostream &s, const point &ptOut)
	{
		s << "\nID: " << ptOut.id << " \nX: " << ptOut.x << " \nY: " << ptOut.y << " \n";
		return s;
	}
};