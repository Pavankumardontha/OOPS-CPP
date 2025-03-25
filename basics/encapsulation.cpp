#include <bits/stdc++.h>
#include <iostream>
using namespace std;
/*
Encapsulation is the concept of bundling data (variables) and methods (functions) that operate on that data into a single unit (class) and restricting direct 
access to some details of the object to enforce data hiding.By making certain members private, you restrict access to them from outside the class, preventing direct 
modification and ensuring that the data of an object remains in a valid state.
Imagine you have a car class with has max_speed has one of the data member. If we expose this data variable to public , someone might change the max_speed variable of a 
car object to -90. But generally , a car object cannot have a negative max_speed making the object state INVALID. So to avoid these situations , we make the data variables
private and unaccessible to the outside world directly. Instead we use getter methods and setter methods to provide access to the data variables to the outer world.
We can write some validations inside the setter methods to make sure that the object state is not made INVALID by setting the data variables to absurd and non-realistic values.
*/

class YoutubeChannel
{
    // by default all are private
private:
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

    void set_subscribers(int new_subscribers)
    {
        // add validation to check the new_subscribers count is NOT negative
        if(new_subcribers >= 0)
            subscribers = new_subscribers
    }

    void set_name(string new_name)
    {
        // add validation to make sure name is not set to empty 
        if(new_name != "")
        name = new_name;
    }
    
    void set_owner_name(string new_owner_name)
    {
        // add validation to make sure owner_name is not set to empty
        if(new_owner_name != "")
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
