/*
In C++, a static method (also called a static member function) belongs to the class itself, not to any particular object of the class. This means:

It can be called without creating an object.

It can only access other static members of the class (not non-static members).
*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Vehicle
{
public:
	static void drive()
	{
		cout<<"driving vehicle"<<endl;
	}
};

int main()
{
	Vehicle::drive(); // NOTE SYNTAX
}

/*
You use the scope resolution operator :: to define and call the static method.

You do not need to create an object of Vehicle to call drive().
*/
