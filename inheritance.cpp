/*
Use of protected keyword : variables or functions declared under protected access modifier can 
be accessed from the child classes as well.
-> inheritance syntax declaration
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class YoutubeChannel
{
    // by default all are private cannot be accessed in child classes also
    string name;
    string owner_name;
    int subscribers;
    
    protected:
    string description; //NOTE: this will be accessed in the child classes too
    
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
        cout<<"name: "<<name<<" owner: "<<owner_name<<" subscribers: "<<subscribers<<"description: "<<description<<endl;
    }
};

class CookingYoutubeChannel : public YoutubeChannel // we can access all public and protected members
{
    public:
    CookingYoutubeChannel(string name, string owner_name):YoutubeChannel(name,owner_name) //NOTE: take care of syntax
    {
        /*
        First the base class constructor code is executed and then child class constructor code
        is executed
        */
        this->description = "This is a cooking youtube channel";
        // we cannot access any other private members except public and protected.
    }
};
int main() 
{
    CookingYoutubeChannel *yt = new CookingYoutubeChannel("channel","pavan");
    yt->info();
}
