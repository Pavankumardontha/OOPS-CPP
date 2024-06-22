#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
using namespace std;

/* 
Simple Factory is a factory in the form of a class.For every new subclass of PaymentMethod 
you will have to edit if else conditions in the getPaymentMethod method. This is a violation 
of the Open/Close Principle.
Factory Method is a factory in the form of a method (hence the name). This doesn't violate 
the Open/Close Principle since you deal with change by extending and not by modifying code.
*/

/* Problem statement: Imagine you have to support payment through different gateways.*/

// THIS IS NOT AT ALL REQUIRED IN FACTORY METHOD
enum PaymentMethodType 
{
    CREDITCARD,
    NETBANKING
};

class IPaymentMethod  // PaymentMethod interface
{
    public:
    virtual void makePayment() = 0;
};

class CreditCard: public IPaymentMethod // Credit card implememts paymentmethod interface
{
    public:
    void makePayment()
    {
        cout<<"payment through credit card"<<endl;
    }
};

class NetBanking: public IPaymentMethod // netbanking implements paymentmethod interface
{
    public:
    void makePayment()
    {
        cout<<"payment through netbanking"<<endl;
    }
};


// Now in the Factory method , Each PaymentMethod subclass will have a seperate Factory
class IPaymentMethodFactory // interface to be implemented by subclass factories
{
    virtual IPaymentMethod* getPaymentMethod();
};

class CreditCardFactory: public IPaymentMethodFactory
{
    public:
    IPaymentMethod* getPaymentMethod()
    {
        return new CreditCard();
    }
};

class NetBankingFactory: public IPaymentMethodFactory
{
    public:
    IPaymentMethod* getPaymentMethod()
    {
        return new NetBanking();
    }
};

int main()
{
    // NOTE: Here the client deals with the Factories of each subclass and not the actual subclasses itself
    IPaymentMethod* credit_card = CreditCardFactory().getPaymentMethod();
    IPaymentMethod* net_banking = NetBankingFactory().getPaymentMethod();
    net_banking->makePayment();
    credit_card->makePayment();
}

/*
Here the client deals only with the Factory classes of each PaymentMethod subclass
and not with the actual PaymentMethod subclasses.

In the above section, we have seen Factory Method Pattern follows Open Close Principle. 
When new requirement came, we did not make changes in existing code but need to create 
an additonal Factory.Writing unit test cases is easy with Factory Method Pattern in 
comparison to Simple Factory Pattern since switch case (or long if else blocks) is not used.
To support additional products, we do not modify existing code but just add one new Factory 
class, so no need to re-run existing old unit tests.
*/
