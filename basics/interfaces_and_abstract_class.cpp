/*
When to use interface and when to use abstract class 
1) We can use both a reference to an interface or an abstract class to enable 
polymorphism. 

Lets say we have an animal abstract class which is being inherited by dog and lion
Now we want to write a generic function that takes the all animal subclasses as an
arugument then we can use 

void function(Animal* a)
{
	
}

here the animal can either be dog or lion. We can pass any object to this function. 
Same goes with the return type too. Once we set the return type as an abstract class
we can return any of its subclasses. This is polymorphism.



2) We use interface when each class implementing it will have a different implementation
of each method defined in an interface. If there are any common methods which are
applied to all the subclasses and also some different methods then we can use 
an abstract class.

abstract class -> Implemented + Non-implemented methods
interface -> Non-implemented methods only - all the methods should be implemented
by the class implementing it.


3) Imagine a situation where we have an animal abstract class and its been inherited
by lion , cat , dog. We have defined 4 methods in the abstract class which are 

walk()
sleep()
eat()
makesound()

Now after some days , our requirement changes. We want to implement pet behaviours
into the above system.

pet behaviours
1) play()
2) guard()

These pet behaviours cannot be applied to lion since its not a pet. These pet 
behavious should only be applied to dog and cat. 


we have 4 options
1) add these methods into abstract animal class -> this gives pet behaviour even to 
lion

2) Add pet behaviour methods to only dog class manually. This is not scalable since
has a when new animal comes which can be a pet , we need to add these methods 
and the method names should be same. We should impose some conditions on these
new type of classes which are pets that should implement the same play() and 
guard() behaviour to be a pet.


3) We can create a new abstract class called pet and then inherit the dog class
from it. But this is wrong. 
We should not do multiple inheritance. Multiple inheritance has a problem known as 
"The Deadly Diamond of Death".

Imagine a situation where we have 2 classes A and B. Both these classes have a
common method called func()


class A
{
	void func()
	{
	
	}
}

class B
{
	void func()
	{
	
	}
}

Now imagine another class C that inherits from both class A and class B

class C : public A, public B
{
	
}

Now when func() method is called on C object , which class method should be 
invoked ?? Either the func() method . This is called "Deadly Diamond of Death"
Problem in multiple inheritance.

A language that allows the Deadly Diamond of Death can lead to work for you both 
in learning those rules and watching out for some ugly complexities, because you 
have to have special rules to deal with the potential ambiguities. And extra 
rules means extra those “special cases”. 



4) The only option left is using a pet interface. We will create a pet interface
with pet behaviours in it and implement this interface in the dog class. Upcoming
pet animals can also implement this interface to exhibit pet behaviours.

A Java interface solves your multiple inheritance problem by giving you
much of the polymorphic benefits of multiple inheritance without the pain
and suffering from the Deadly Diamond of Death (DDD).

The way in which interfaces side-step the DDD is surprisingly simple: make
all the methods abstract! That way, the subclass must implement the methods
(remember, abstract methods must be implemented by the first concrete
subclass), so at runtime the JVM isn’t confused about which of the two
inherited versions it’s supposed to call.

interface methods are implicitly public and abstract. 

class Animal // abstract class
{
	
}

class IPet // pet interface
{
	
}


class Dog : public Animal , public Ipet
{
	
}

Dog "is a" Animal and dog "is a" pet since it implements pet behaviour.
The 'is a' relationship also holds true when a class implements an interface.
 
-> Refer compile time polymorphism and run time polymorphism. Also how function calls are being made to the subclasses using a reference to an abstract class.
refer page 224 - head first java 2nd edition
*/
