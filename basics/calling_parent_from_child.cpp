/*
How do we call the constructor defined in the parent class to execute in the child class constructor ??

In C++, when a child class object is created, the parent (superclass) constructor is automatically called first before the child constructor.
However, if the parent class has a parameterized constructor, we must explicitly call it using an initializer list in the child class.
*/

/*
Example-1 : Default Constructor of Parent Class (Automatically Called)
If the parent class has a default constructor, it is automatically invoked when an object of the child class is created.
*/

#include <iostream>
using namespace std;

class Parent {
public:
    Parent() { // Default constructor
        cout << "Parent class constructor called!" << endl;
    }
};

class Child : public Parent {
public:
    Child() { // Child constructor
        cout << "Child class constructor called!" << endl;
    }
};

int main() {
    Child obj;  // Creating a child object
    return 0;
}

/*
output : 
Parent class constructor called!
Child class constructor called!
*/



/*
Example-2: Calling a Parameterized Constructor of Parent Class
If the parent class only has a parameterized constructor, the child must explicitly call it using an initializer list.
*/
#include <iostream>
using namespace std;

class Parent {
public:
    Parent(int x) { // Parameterized constructor
        cout << "Parent class constructor called with value: " << x << endl;
    }
};

class Child : public Parent {
public:
    Child(int y) : Parent(y) { // Calling Parent's constructor explicitly
        cout << "Child class constructor called with value: " << y << endl;
    }
};

int main() {
    Child obj(10); // Passes 10 to Parent's constructor
    return 0;
}

/*
output:
Parent class constructor called with value: 10
Child class constructor called with value: 10
*/

/*
Example - 3: 
Calling a Parameterized Constructor of Parent with Extra Parameters
If the child class has additional attributes, you can pass different values to both constructors.
*/

#include <iostream>
using namespace std;

class Parent {
public:
    Parent(int x) {
        cout << "Parent constructor: Value = " << x << endl;
    }
};

class Child : public Parent {
public:
    Child(int a, int b) : Parent(a) { // Parent constructor gets 'a'
        cout << "Child constructor: Value = " << b << endl;
    }
};

int main() {
    Child obj(5, 10);
    return 0;
}

/*
output:
Parent constructor: Value = 5
Child constructor: Value = 10
*/

/*
Example-4:
Calling Both Default and Parameterized Constructors
If the parent class has both a default and a parameterized constructor, the child class must decide which one to call.
*/
#include <iostream>
using namespace std;

class Parent {
public:
    Parent() {
        cout << "Default Parent constructor called!" << endl;
    }

    Parent(int x) {
        cout << "Parameterized Parent constructor called with value: " << x << endl;
    }
};

class Child : public Parent {
public:
    Child() : Parent(50) { // Explicitly calling parameterized constructor
        cout << "Child constructor called!" << endl;
    }
};

int main() {
    Child obj; // Calls Parent(50), not the default constructor
    return 0;
}

/*
output:
Parameterized Parent constructor called with value: 50
Child constructor called!
*/

/* 
Example-5
Calling a Parent Constructor in a Multilevel Inheritance Scenario
If there is multiple inheritance, constructors are called in a top-down manner.
*/

#include <iostream>
using namespace std;

class GrandParent {
public:
    GrandParent() {
        cout << "GrandParent constructor called!" << endl;
    }
};

class Parent : public GrandParent {
public:
    Parent() {
        cout << "Parent constructor called!" << endl;
    }
};

class Child : public Parent {
public:
    Child() {
        cout << "Child constructor called!" << endl;
    }
};

int main() {
    Child obj; // Calls GrandParent -> Parent -> Child
    return 0;
}

/*
output: 
GrandParent constructor called!
Parent constructor called!
Child constructor called!

*/




