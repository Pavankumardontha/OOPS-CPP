#include<bits/stdc++.h>
#include<iostream>
using namespace std;

/*
Imagine we have PizzaStore to OrderPizzas
*/
class Pizza
{
public:
	virtual void prepare()=0;
	virtual void bake()=0;
};

class OnionPizza : public Pizza
{
public:
	void prepare()
	{
		cout<<"Preparing OnionPizza"<<endl;
	}
	void bake()
	{
		cout<<"Baking OnionPizza"<<endl;
	}
};

class CornPizza : public Pizza
{
public:
	void prepare()
	{
		cout<<"Preparing TamatoPizza"<<endl;
	}
	void bake()
	{
		cout<<"Baking TamatoPizza"<<endl;
	}
};


class PizzaStore // this class is used to OrderPizza 
{
public:		
	Pizza* OrderPizza(string name)
	{
		Pizza* pizza = NULL;
		
		/* we need to move this part of the code outside to make PizzaStore not depend on 
		concrete implementations of pizzas concrete classes = OnionPizza and CornPizza
		*/
		if(name == "onion")
			pizza = new OnionPizza();
		else if(name == "corn")
			pizza = new CornPizza();
		
		if(pizza != NULL)
		{
			pizza->bake();
			pizza->prepare();
		}
		return pizza;
	}
};

/*
Look at the object dependencies: 
This version of the pizzastore depends on all those pizza objects because its directly 
creating them. 
For now, the pizza store is dependent on onionpizza and cornpizza class. For every new kind of 
pizza we add creates another dependency for pizzastore.

Here the high-level module is Pizza store and the pizza objects are the low level modules.
The low level modules are concrete classes. 
Lets change the code to make the high-level concrete classes and the low level concrete classes
to depend on abstractions. 

*/
