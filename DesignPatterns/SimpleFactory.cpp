#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
using namespace std;

/* 
simple factory design pattern : In simple factory, the client uses only the factory class to create new objects. 
*/

/*
Problem statement:Imagine you have to support payment through different gateways.
*/

/*
IMPORTANT : DO NOT USE ENUM VALUES FOR ANY CLASS NAMES. THIS COULD 
LEAD TO UNEXPECTED ERRORS. USE ALL CAPITAL LETTERS FOR VALUES !!*/
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


class PaymentMethodFactory
{
    public:
    static IPaymentMethod* getPaymentMethod(PaymentMethodType p)
    {
        if( p == PaymentMethodType::CREDITCARD)
        return new CreditCard();
        else if(p == PaymentMethodType::NETBANKING)
        return new NetBanking();
        return nullptr;
    }
};

int main() 
{
    // Now we get the payment method using factory class
    IPaymentMethod *credit_card = PaymentMethodFactory::getPaymentMethod(PaymentMethodType::CREDITCARD);
    IPaymentMethod *net_banking = PaymentMethodFactory::getPaymentMethod(PaymentMethodType::NETBANKING);
    credit_card->makePayment();
    net_banking->makePayment();
    /* SYNTAX NOTE : See how the static function is accessed using 
    the class name with 2 colons. Same for enum. We use :: to 
    call both the static methods and also to access the Enum values.
    */
}


/*
Let’s say in future, if PaymentMethodFactory has to make a new type of 
payment method called wallet payment.To adopt this new requirement, we 
have to change getPaymentMethod method and add one if condition for wallet 
case, define a new class and also add a new type in the enum. If again new 
kind of payment method is introduced, then again one more case needs to be added. 
This will be a violation of Open Close Principle of SOLID principles. This can 
be overcomed using Factory Method design pattern.
We have 3 methods 
1) Simple factory ( we have seen this in the above example)
2) Factory method 
3) Abstract Factory method

Simple Factory is a factory in the form of a class.For every new subclass of PaymentMethod 
you will have to edit if else conditions in the getPaymentMethod method. This is a violation 
of the Open/Close Principle.

Factory Method is a factory in the form of a method (hence the name). This doesn't violate 
the Open/Close Principle since you deal with change by extending and not by modifying code.

*/
