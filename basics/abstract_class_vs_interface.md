# Abstract Class vs Interface in OOP

This document explains **when to use an abstract class** and **when to use an interface**, using real-world examples and key object-oriented programming concepts.

---

## 1. Polymorphism with Abstract Classes and Interfaces

We can use both an **interface** and an **abstract class** as a reference type to enable **polymorphism**.

### Example:

Suppose we have an abstract class `Animal` that is inherited by `Dog` and `Lion`.

```cpp
void function(Animal* a) {
    // Can accept Dog or Lion
}
```

Here, the `function` can accept any object that is a subclass of `Animal`. This is an example of **runtime polymorphism**.

Similarly, we can use the abstract class or interface as the return type to return any of its implementing classes or subclasses.

---

## 2. Interface vs Abstract Class

| Aspect | Abstract Class | Interface |
|--------|----------------|-----------|
| Contains | Both implemented and non-implemented methods | Only non-implemented (abstract) methods |
| Inheritance | A class can extend only one abstract class | A class can implement multiple interfaces |
| Use-case | When there are some shared functionalities | When every class needs to provide its own implementation |

Use an **interface** when each class has a completely different implementation of all methods. Use an **abstract class** when there is **common code** across classes.

---

## 3. Use Case: Adding Pet Behaviors

Imagine we have an abstract class `Animal` with the following methods:

```java
abstract class Animal {
    abstract void walk();
    abstract void sleep();
    abstract void eat();
    abstract void makeSound();
}
```

Subclasses:
- `Dog`
- `Cat`
- `Lion`

Now we want to add **pet behaviors**:

- `play()`
- `guard()`

These should only apply to `Dog` and `Cat`, not `Lion`.

### Design Options:

#### ❌ Option 1: Add pet methods in `Animal`  
This adds pet behavior to all animals, including `Lion`, which is incorrect.

#### ❌ Option 2: Add pet methods manually in `Dog`, `Cat`
Not scalable and inconsistent if multiple developers are working.

#### ❌ Option 3: Inherit from a new `Pet` abstract class  
This introduces **multiple inheritance**, which causes the **Deadly Diamond of Death (DDD)** problem.

#### ✅ Option 4: Use a Pet Interface  
```java
interface IPet {
    void play();
    void guard();
}

class Dog extends Animal implements IPet {
    public void play() { ... }
    public void guard() { ... }
}
```

This ensures:
- Only pets implement pet behavior.
- `Dog` "is a" `Pet`.
- Avoids multiple inheritance issues.

---

## 4. Deadly Diamond of Death Explained

In multiple inheritance:

```cpp
class A {
    void func() {}
}

class B {
    void func() {}
}

class C : public A, public B {
    // Ambiguous func() call
}
```

Which `func()` should `C` inherit? This ambiguity is the **Deadly Diamond of Death**.

### Why Interfaces Avoid DDD

Interfaces avoid DDD by:
- Providing **only abstract methods** (this means you need to definitely implement the method in the child class)
- Forcing concrete subclasses to implement those methods
- Eliminating ambiguity at runtime

---

## Summary

- Use **abstract classes** when:
  - You want to provide **default/shared behavior**
  - You want to enforce a base structure for subclasses

- Use **interfaces** when:
  - You want to enforce certain capabilities/behaviors across unrelated classes
  - You want to avoid issues with multiple inheritance

---

### 📌 Notes

- Interface methods are **implicitly public and abstract**
- Use interfaces for flexible design and multiple inheritance-safe extension
- Both abstract classes and interfaces enable **runtime polymorphism**
- Reference: *Head First Java, 2nd Edition - Page 224*

---
