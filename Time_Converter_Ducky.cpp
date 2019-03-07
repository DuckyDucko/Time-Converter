// Made By Ducky
// Version 1.0.1
// 6/3/2019

#include <iostream>
#include <cstring>

using namespace std;

bool inRange(unsigned low, unsigned high, unsigned x) // Calibrate inRange for interger range testing
	{
	return (low <= x && x <= high);
	};

int h, m, s;
int hh;
char repeat;
string hours = "hours", minutes = "minutes", seconds = "seconds";

int range(int a, int b, int &c, string unit)
	{  
		cout << unit << ":";
		cin >> c;
		while(inRange(a, b, c) == 0) // If not in range, restart
		{
			cout << "Error: Please enter a valid " << unit << " between " << a << " - " << b << endl;
			cout << unit << ":";
			cin >> c;
		};
	return 0;
	};

int main ()
	{
	
	do
		{
	
	cout << "Enter the current time to convert to and from the 24 hour format" << endl;
	range(0, 23, h, hours);
	range(0, 59, m, minutes);
	range(0, 59, s, seconds);
			
	bool apm = 0;
	
	if(h <= 12)
	{
		apm = 1;
	}
	
	if(m <= 9 && s <= 9)
		{
			cout << h << ":0" << m << ":0" << s << endl;
		}
		
		else if(m <= 9)
		{
			cout << h << ":0" << m << ":" << s << endl;
		}
		else if(s <= 9)
		{
			cout << h << ":" << m << ":0" << s << endl;
		}
		else
		{
			cout << h << ":" << m << ":" << s << endl;
		}
	
	switch(apm)
		{
		case 1:
			cout << "12 hour format" << "convertting to 24-hour format ... " << endl;
			hh = h + 12;
			cout << "The time is: " << hh << ":" << m << ":" << s << endl;
			break;
		
		case 0:
			cout << "24 hour format" << "convertting to 12-hour format ... " << endl;
			hh = h - 12;
			cout << "The time is: " << hh << ":" << m << ":" << s << endl;
			break;
			
		default:
			cout << "Error: Invalid value stored in 'h'" << endl << "'h' = " << h;
			break; 
		}
		
		cout << endl << "Enter y/Y to go again, or any other key to exit: ";
		cin >> repeat;
		
		}
		while(repeat == 'y' || repeat == 'Y');
		
return 0;
};
