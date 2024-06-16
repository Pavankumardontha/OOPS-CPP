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



