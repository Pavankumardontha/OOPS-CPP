/*
it states that objects of a parent class should be replaceable with objects of a child 
class without affecting the correctness of the program. In other words, if a program is 
using a parent class, it should be able to use any child class without knowing the difference.

Formal Definition
If S is a subtype of T, then objects of type T may be replaced with objects of type S.
Objects of type may substitute objects of type T without altering any of the desirable 
properties of the program (correctness, task performed, etc.).
*/

/*
Example : A square is a specific type of rectangle. So square inherits from rectangle
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Rectangle 
{
    protected:
    int width;
    int height;
    public:
    Rectangle(int width, int height)
    {
        this->width = width;
        this->height = height;
    }
    
    void description()
    {
        cout<<"this is rectangle"<<endl;
    }
    void set_width(int width)
    {
        this->width = width;
    }
    
    void set_height(int height)
    {
        this->height = height;
    }
    
    int area()
    {
        return this->height * this->width;
    }
};

class Square : public Rectangle
{
    public:
    Square(int length):Rectangle(length,length)
    {
        
    }
    void description()
    {
        cout<<"this is square"<<endl;
    }
    void set_width(int width)
    {
        this->height = width;
        this->width = width;
    }
    
    void set_height(int height)
    {
        this->height = height;
        this->width = height;
    }
};


int main()
{
    Rectangle *r1 = new Rectangle(10,10);
    r1->set_height(5);
    r1->set_width(15);
    
    /* if we replace the rectangle class with sqaure 
    and perform the same operations */ 
    Square *s1 = new Square(10);
    s1->set_height(5);
    s1->set_width(15);
    
    cout<<r1->area()<<endl; // 75 
    cout<<s1->area()<<endl; // 225 RESULTS ARE DIFFERENT WHEN REPLACED WITH SUBCLASS OBJECT
    /*
    In this case Square fails the Liskov Substitution Test with Rectangle and the 
    abstraction of having Square inherit from Rectangle is a bad one. If we replace 
    Rectangle with the child class ie Square class and run the main function , both 
    will yeild diferent results for area. This means we cannot Substitute square class 
    for rectangle class. Liskov substitution principle fails here.
    
    NOTE:-
    Well, a square clearly IS a type of rectangle in the real world. Whether we can model 
    this in our code depends on the spec. What the LSP indicates is that subtype behavior
    should match base type behavior as defined in the base type specification. If the 
    rectangle base type spec says that height and width can be set independently, then 
    LSP says that square cannot be a subtype of rectangle. If the rectangle spec says 
    that a rectangle is immutable, then a square can be a subtype of rectangle. It's all 
    about subtypes maintaining the behavior specified for the base type. So what ever 
    methods which are defined in the base/parent class should all yield the same results
    when substituted with the sub class/child class/derived class. So if set_height and 
    set_width functions are removed from the rectangle class then square can properly 
    inherit from rectangle class since this will not violate liskov substitution principle.
    
    We can also say that the methods set_height and set_width behave in a different way 
    for both the parent class object and for the child class object.
    
    SOLUTION : Remove the methods behaving in the same way in child and parent classes
    and keep them in a seperate class and inherit the rectangle and the square class from 
    this newly created class containing only the common methods which behave the same way.
    */
}
