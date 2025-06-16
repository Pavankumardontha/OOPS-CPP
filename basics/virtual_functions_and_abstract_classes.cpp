// pure virtual functions , virtual functions and abstract classes

/*
A virtual fuction is a function that is defined in the base class and redefined in the derived class.The 
main purpose of the virtual function is to give you the ability of run-time polymorphism. Imagine the 
following situation. You have a base class and inside that base class you implement a function and then 
you decide to create another derived class which will inherit from this base class. Inside this dervied 
class , you also decide to make the implementation of that same function implemented in the base class.
Now the base class has its own implementation and the derived class has its own implementation. Virtual 
functions allow us to execute THE MOST DERIVED VERSION of that function when you invoke that function 
using a base class pointer . So the derived class has its own implementation , then the derived class 
function will be executed. But if the derived class does not have its own implementation , then the 
implementation inside the base class will be executed. 

We will see the examples of using and not using the virtual function.
*/

#include <bits/stdc++.h>
using namespace std;

// WITHOUT VIRTUAL FUNCTION
class Vehicle 
{
    public:
    void drive()
    {
        cout<<"Driving vehicle"<<endl;
    }
};

class Car: public Vehicle
{
    public:
    void drive()
    {
        cout<<"Driving car"<<endl;
    }
};

int main() 
{
    Vehicle *v = new Car(); // NOTE: We have assigned the vehicle type reference to the car object.
    v->drive(); // OUTPUT : Driving vehicle
}

/*--------------------------------------------------------------------------------------------------------*/

// WITH VIRTUAL FUNCTION 
class Vehicle 
{
    public:
    virtual void drive() // NOTE THE SYNTAX
    {
        cout<<"Driving vehicle"<<endl;
    }
};

class Car: public Vehicle
{
    public:
    void drive()
    {
        cout<<"Driving car"<<endl;
    }
};

int main() 
{
    Vehicle *v = new Car(); // IMPORTANT
    v->drive(); // OUTPUT : Driving car 
    /* Here since the drive method is virtual , the latest implementation of the derived class is executed. */
}


/*-------------------------------------------------------------------------------------------------------------*/
// PURE VIRTUAL FUNCTIONS 

/*
There might be a case where we do not want the base class to have the implementation of a function but enforce a 
condition to implement the function in all its derived classes. So which ever class is inheriting from the base
class, it should definitely implement its own implementation of the function. This is what is called pure virtual 
function.There will be no implementation present in the base class. Implementation should be provided in the derived 
class.

An ABSTRACT CLASS is a class which has ATLEAST ONE pure virtual function. We cannot create instances of abstract classes 
but we can create pointers of abstract classes and make them point to the objects of the derived classes.
*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Vehicle
{
    public:
    virtual void drive() = 0; // PURE VIRTUAL FUNCTION
};

class Car: public Vehicle
{
    public:
    void drive() // THIS FUNCTION SHOULD BE IMPLEMENTED
    {
        cout<<"Driving car"<<endl;
    }
};

class Bike: public Vehicle
{
    public:
    void drive() // THIS FUNCTION SHOULD BE IMPLEMENTED
    {
        cout<<"Driving bike"<<endl;
    }
}

int main()
{
    Vehicle *v1 = new Car(); // NOTE: abstract class reference/pointer is pointing to car object.
    Vehicle *v2 = new Bike(); // NOTE: abstract class reference/pointer is pointing to a bike object.
    v1->drive(); // OUTPUT : Driving car
    v2->drive(); //OUTPUT : Driving bike
}

/*-----------------------------------------------------------------------------*/
// final conclusion
class Car
{
public:
	void accelerate()
	{
		/*
		this will execute even if we have the same method in the
		child class also
		*/
		cout<<"accelerating car"<<endl;
	}
	virtual void drive()
	{
		/*
		if this method is overiden in the child class ,
		then the overriden method in the child class will be 
		executed
		*/ 
		cout<<"Driving car"<<endl;
	}
	virtual void stop()=0; // this should be implemented by child class so child class method will be executed when called
};

class Alto : public Car
{
public:
	void accelerate()
	{
		cout<<"accelerating Alto"<<endl;
	}
	void drive()
	{
		cout<<"Driving Alto"<<endl;
	}
	void stop()
	{
		cout<<"Stopping Alto"<<endl;
	}
};
int main()
{
	Car* c1 = new Alto();
	c1->accelerate(); // accelerate method of car
	c1->drive(); // drive method of alto
	c1->stop(); // stop method of alto
}


/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* HOW TO CALL A PARENT METHOD FROM A CHILD METHOD ?? */
class Car
{
public:
	virtual void drive() // this implies if a child implements this method, the child method will be executed when we call this
	{
		cout<<"drive car"<<endl;
	} 
};

class Alto : public Car
{
public:
	void drive()
	{
		Car::drive(); // NOTE SYNTAX
		cout<<"Driving alto"<<endl;
		Car::drive(); // NOTE SYNTAX
	}
};

int main()
{
	Car* c1 = new Alto();
	c1->drive();
}

/*
output:
drive car
Driving alto
drive car
*/


























