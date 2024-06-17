/*
Dependency inversion principle: It states that high level modules should not directly 
depend on low level modules. Both should depend on abstractions/interfaces.
Abstract classes and interfaces will help in decoupling the high level module from low 
level modules. Low level modules act as utility classes for supporting high level module.
*/

/*
Problem statement: Imagine a situation where you are building a NotificationService. Our 
initial requirement is to send the notification via email.
*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

// WITHOUT FOLLOWING DIP
class EmailService // LOW LEVEL MODULE ( it supports high level module )
{
    public:
    void notify(string message)
    {
        // email notification service
        cout<<"Sending email.."<<endl;
    }
};

class NotificationService // HIGH LEVEL MODULE
{
    EmailService *e;
    public:
    NotificationService()
    {
        this->e = new EmailService();
    }
    void send(string type, string message)
    {
        if(type == "email")
        e->notify(message);
    }
};

/* 
Now lets say if a new service like SMSService comes then we need to change the high
level module also to accomodate this change. So there is high coupling between the low 
level modules and the high level module. An addition of new low level module is also 
accounting to changes in the high level module which is not desirable. Ofcourse we are not 
following dependency inversion principle but also not following Open-closed principle too. 
Since we are modifying the high level module (NotificationService class) and not extending it !! 
*/ 

class SMSService // NEW LOW LEVEL MODULE
{
    public:
    void notify(string message)
    {
        cout<<"Sending SMS.."<<endl;
    }
};

/*--------------------------------------------------------------------------------------------------------------*/

/* 
Now lets modify our code to decouple both the low level modules(EmailService and SMSService) and high level 
module(NotificationService) using abstract classes/interfaces. 
*/
// FOLLOWING DIP
class NotificationServiceProvider
{
    public:
    virtual void notify(string message) = 0; // PURE VIRTUAL FUNCTION
};
// Since we have all pure functions in the above class it is an interface. 
/* 
NOTE: we CANNOT create objects of abstract classes/interfaces but we can use their references
to point to the objects of their child classes and achieve run-time polymorphism.
*/

class EmailService: public NotificationServiceProvider
{
    void notify(string message)
    {
        cout<<"Sending email..."<<message<<endl;
    }
    
};

class SMSService: public NotificationServiceProvider
{
    void notify(string message)
    {
        cout<<"Sending SMS..."<<message<<endl;
    }
};

class NotificationService
{
    NotificationServiceProvider *np;
    public:
    NotificationService(NotificationServiceProvider* np)
    {
        this->np = np;
    }
    void send(string message)
    {
        np->notify(message); // RUN-TIME polymorphism. Which notify method to run will be determined at the run time
    }
};

int main()
{
    // creating email and SMS service objects
    EmailService *emailservice = new EmailService();
    SMSService *smsservice = new SMSService();
    
    // sending these objects while initiation of NotificationService
    NotificationService(emailservice).send("hi this is email");
    NotificationService(smsservice).send("hi this is SMS");
}
/*

OUPUT: 
Sending email...hi this is email
Sending SMS...hi this is SMS

Note here that the high level module(NotificationService) and also the low level modules 
(EmailService, SMSService) depend on the interface(NotificationServiceProvider) and are 
thus decoupled between themselves.

ADVANTAGES OF DIP: 
Decoupling: We decouple high-level modules from low-level modules using intermediate interfaces/abstract classes.
Whenever a new low level module comes , we need not edit the high level module.
Maintainability: Changes in low-level modules do not affect high-level modules if they only interact through 
abstractions. This makes the system easier to maintain.
Testability: High-level modules can be tested independently from their concrete implementations, as they depend 
on abstractions.
*/







