#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
using namespace std;

/*
ProblemStatement:
As the name says , we decorate our objects with this decorator design pattern. Lets say 
we are in a burger shop and want to buy a burger. The cashier will take our order and 
asks for topplings which effect the final price of our burger. Each toppling has a fixed 
amount of price apart from the normal burger cost . So how do we calculate the entire cost
of the burger after adding topplings(decorators) to it. ??
*/

class IBurger 
{
    public:
    virtual string getDescription()=0;
    virtual double getCost()=0;
};

class ZingerBuger : public IBurger
{
    public:
    string getDescription()
    {
        return "Zinger burger";
    }
    
    double getCost()
    {
        return 200.00;
    }
};

class TandoriBurger: public IBurger
{
    public:
    string getDescription()
    {
        return "Tandori burger";
    }
    
    double getCost()
    {
        return 220.00;
    }
};

class IBurgerToppling: public IBurger // VERY IMPORTANT (The Toppling abstract class inherits from the Burger Interface since it should return a burger object)
{
    // this is an abstract class and not an interface
    protected: 
    IBurger* burger;
    IBurgerToppling(IBurger* burger):IBurger()
    {
        this->burger = burger;
    }
};

class CheeseToppling : public IBurgerToppling
{
    public:
    CheeseToppling(IBurger* burger):IBurgerToppling(burger)
    {
        
    }
    
    string getDescription()
    {
        return this->burger->getDescription() + " with extra cheese";
    }
    
    double getCost()
    {
        return this->burger->getCost() + 20.00;
    }
};


class MayoToppling : public IBurgerToppling
{
    public:
    MayoToppling(IBurger* burger):IBurgerToppling(burger)
    {
        
    }
    
    string getDescription()
    {
        return this->burger->getDescription() + " with extra mayonese";
    }
    
    double getCost()
    {
        return this->burger->getCost() + 25.00;
    }
};


int main()
{
    // Tandoori burger calculations
    IBurger* tb = new TandoriBurger();
    tb = new CheeseToppling(tb); // adding chesse
    tb = new MayoToppling(tb); // adding mayonese
    cout<<tb->getDescription()<<" :"<<tb->getCost()<<endl;
    
    //Zinger burger calculations
    IBurger* zb = new ZingerBuger();
    zb = new CheeseToppling(zb);
    zb = new MayoToppling(zb);
    cout<<zb->getDescription()<<" :"<<zb->getCost()<<endl;
}
