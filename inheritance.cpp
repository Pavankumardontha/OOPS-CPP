/*
Use of protected keyword : variables or functions declared under protected access modifier can 
be accessed from the child classes as well.
-> inheritance syntax declaration
-> inheritance is "IS A" relationship.

-> Association : It is a relationship between two classes where one class “HAS A” relationship with the other class. 
In other words, an instance of one class has an instance of the other class as a member.
Types of association : Aggregation and composition

-> Aggregation : In C++, aggregation is a special type of association between classes that represents a weaker relationship than a composition. In an aggregation relationship, 
one class is a container for objects of another class, but it is not responsible for the creation or destruction of those objects.This relationship is often referred to as a 
“has-a” relationship, because one class has objects of another class as members.
An aggregation relationship is represented in C++ as an object of one class containing pointers to objects of another class. The contained objects are said to be part of 
the containing object, but they can exist independently of the containing object. If the containing object is destroyed, the contained objects are not automatically destroyed 
along with it.
*/

/* AGGREGATION EXAMPLE : For example, consider a class Department and a class Employee. If a department "has many" employees, we can say that there is an aggregation relationship 
between the two classes. We can implement this aggregation relationship in C++ as follows: */
class Employee {
  // Class members and methods
};

class Department {
  std::vector<Employee*> employees;
  // Class members and methods
};
/*
The contained objects employees can exist independently of the containing object Department, and if the Department object is destroyed, the Employee objects are not automatically
destroyed along with it.
*/

/*
-> Composition : In C++, composition is a special type of association between classes that represents a stronger relationship than a regular association. In a composition 
relationship, one class is the owner of the other class and is responsible for its creation and destruction. This relationship is often referred to as a “has-a” relationship, 
because one class has an instance of another class as a member.
A composition relationship is represented in C++ as an object of one class being contained within another class. The contained object is said to be a part of the containing object,
and it cannot exist independently of the containing object. If the containing object is destroyed, the contained object is automatically destroyed along with it.

example : For example, consider a class Car and a class Engine. If a car "has an" engine, we can say that there is a composition relationship between the two classes. 
We can implement this composition relationship in C++ as follows:
*/

class Engine {
  // Class members and methods
};

class Car {
  Engine engine;
  // Class members and methods
};

/*
In this example, an instance of the Engine class is contained within an instance of the Car class, representing the composition relationship between the two classes. 
The contained object engine cannot exist independently of the containing object Car, and if the Car object is destroyed, the Engine object is automatically destroyed along with it.
*/


#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class YoutubeChannel
{
    // by default all are private cannot be accessed in child classes also
    string name;
    string owner_name;
    int subscribers;
    
    protected:
    string description; //NOTE: this will be accessed in the child classes too
    
    public:
    YoutubeChannel(string name, string owner_name)
    {
        this->name = name;
        this->owner_name = owner_name;
        subscribers = 0;
    }
    
    string get_name()
    {
        return name;
    }
    
    string get_owner_name()
    {
        return owner_name;
    }
    
    void set_name(string new_name)
    {
        name = new_name;
    }
    
    void set_owner_name(string new_owner_name)
    {
        owner_name = new_owner_name;
    }
    
    void subscribe()
    {
        subscribers++;
    }
    
    void unsubsribe()
    {
        if(subscribers>0)
        subscribers--;
    }
    
    
    void info()
    {
        cout<<"name: "<<name<<" owner: "<<owner_name<<" subscribers: "<<subscribers<<"description: "<<description<<endl;
    }
};

class CookingYoutubeChannel : public YoutubeChannel // we can access all public and protected members
{
    public:
    CookingYoutubeChannel(string name, string owner_name):YoutubeChannel(name,owner_name) //NOTE: take care of syntax
    {
        /*
        First the base class constructor code is executed and then child class constructor code
        is executed
        */
        this->description = "This is a cooking youtube channel";
        // we cannot access any other private members except public and protected.
    }
};

int main() 
{
    CookingYoutubeChannel *cyt1 = new CookingYoutubeChannel("t-series","pavan");
    cyt1->info();
    /*
    In C++, a pointer to a base class can point to an object of a derived class, but not vice versa. This means that a pointer
    to a derived class cannot directly hold a reference to a base class object.
    */
    YoutubeChannel *yt = new CookingYoutubeChannel("aditya-cooking","vanitha"); // CORRECT 
    CookingYoutubeChannel *cyt2 = new YoutubeChannel("meme-content","pavan"); // WRONG
    /*
    1) CookingYoutubeChannel object is a YoutubeChannel object. So a pointer of YoutubeChannel can point to the object of the 
    CookingYoutubeChannel object.
    2) YoutubeChannel object is NOT a CookingYoutubeChannel object. So a pointer of CookingYoutubeChannel CANNOT point to the 
    object of the YoutubeChannel object.
    */
}
/*
1. Single Inheritance: In single inheritance, a class is allowed to inherit from only one class. i.e. one subclass is inherited by one base class only.
2. Multiple Inheritance: Multiple Inheritance is a feature of C++ where a class can inherit from more than one class. i.e one subclass is inherited 
from more than one base class.
3. Multilevel Inheritance: In this type of inheritance, a derived class is created from another derived class. 
4. Hierarchical Inheritance: In this type of inheritance, more than one subclass is inherited from a single base class. i.e. more than one derived class 
is created from a single base class.
5. Hybrid (Virtual) Inheritance: Hybrid Inheritance is implemented by combining more than one type of inheritance. For example: Combining Hierarchical
inheritance and Multiple Inheritance. 
*/

/*
EXAMPLES OF AGGREGATION AND COMPOSITION: 
Imagine swiggy use case. Each restaurant can have multiple owners. Each owner can be the owner of multiple restaurants. There is a many to many relationship
between the owner and the restaurant. So if we delete the restautant object, we will not automatically delete the corresponding owner objects since they might
be the owners to some other restaurants also. So this is a aggregation relationship between the the restaurant and owner. 

Imagine you have a user class and an address class. One user object can have multiple address objects. If we delete the user object, the corresponding address 
objects associated with that user object will have no use and thus the address objects cannot exist without the user object. This is composition relationship.

*/



