#include <bits/stdc++.h>
#include <iostream>
using namespace std;
/*
Data Hiding: Encapsulation allows you to hide the implementation details of a class from the 
outside world. By making certain members private, you restrict access to them from outside the 
class, preventing direct modification and ensuring that the data remains in a valid state.

Encapsulation in C++ is defined as the wrapping up of data and information in a single unit.It 
is defined as binding together the data and the functions that manipulate them.

Consider a real-life example of encapsulation, in a company, there are different sections like 
the accounts section, finance section, sales section, etc. 
Now,The finance section handles all the financial transactions and keeps records of all the data 
related to finance.Similarly, the sales section handles all the sales-related activities and 
keeps records of all the sales.Now there may arise a situation when for some reason an official 
from the finance section needs all the data about sales in a particular month.

In this case, he is not allowed to directly access the data of the sales section. He will first 
have to contact some other officer in the sales section and then request him to give the 
particular data.

*/

class YoutubeChannel
{
    // by default all are private
    string name;
    string owner_name;
    int subscribers;
    
    public:
    YoutubeChannel(string name, string owner_name)
    {
        this->name = name;
        this->owner_name = owner_name;
        subscribers = 0;
    }
    
    string get_name()
    {
        return name;
    }
    
    string get_owner_name()
    {
        return owner_name;
    }
    
    void set_name(string new_name)
    {
        name = new_name;
    }
    
    void set_owner_name(string new_owner_name)
    {
        owner_name = new_owner_name;
    }
    
    void subscribe()
    {
        subscribers++;
    }
    
    void unsubsribe()
    {
        if(subscribers>0)
        subscribers--;
    }
    
    
    void info()
    {
        cout<<"name:"<<name<<"owner:"<<owner_name<<"subscribers:"<<subscribers<<endl;
    }
};


int main() 
{
    YoutubeChannel *yt = new YoutubeChannel("channel","pavan");
    yt->info();
    yt->set_owner_name("pradeep");
    yt->set_name("channel-1");
    yt->subscribe();
    yt->info();
}
