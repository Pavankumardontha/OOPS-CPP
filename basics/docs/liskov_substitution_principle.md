# Liskov Substitution Principle (LSP)

## Principle Overview

The Liskov Substitution Principle states that:

> Objects of a parent class should be replaceable with objects of a child class without affecting the correctness of the program.

### Formal Definition:
If `S` is a subtype of `T`, then objects of type `T` may be replaced with objects of type `S` without altering any of the desirable properties of the program (correctness, task performed, etc.).

---

## Example in C++

A `Square` is a specific type of `Rectangle`. So `Square` inherits from `Rectangle`.

```cpp
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
        cout << "this is rectangle" << endl;
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
    Square(int length): Rectangle(length, length) {}

    void description()
    {
        cout << "this is square" << endl;
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
```

### Main Function
```cpp
int main()
{
    Rectangle *r1 = new Rectangle(10, 10);
    r1->set_height(5);
    r1->set_width(15);

    // Substituting Rectangle with Square
    Square *s1 = new Square(10);
    s1->set_height(5);
    s1->set_width(15);

    cout << r1->area() << endl; // 75 
    cout << s1->area() << endl; // 225 (Results are different)
}
```

---

## Why LSP Fails Here

In this case, `Square` fails the Liskov Substitution Test with `Rectangle`. If we replace `Rectangle` with its child class `Square` and run the main function, both yield different results for `area()`. This violates the Liskov Substitution Principle.

Although a square **is** a rectangle in the real world, modeling this in code must ensure consistent behavior:

- If the base class (`Rectangle`) allows independent setting of width and height, then `Square` should not override this in a way that breaks behavior.
- If these setters are essential, `Square` cannot be a subtype of `Rectangle`.

---

## Solution

To respect LSP:

1. Remove methods (`set_width`, `set_height`) that behave differently in parent and child classes.
2. Put shared behavior in a new abstract class/interface.
3. Let `Rectangle` and `Square` inherit from this base class only if they comply with its specification.

---
