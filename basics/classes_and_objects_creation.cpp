#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class YoutubeChannel
{
    public: // by default all are private
    string name;
    string owner_name;
    int subscribers;
    
    void info()
    {
        cout<<"name:"<<name<<"owner:"<<owner_name<<"subscribers:"<<subscribers<<endl;
    }
};

int main()
{
    // creation type-1 (stack memory allocation)
    YoutubeChannel yt1;
    yt1.name = "first_channel";
    yt1.owner_name = "pavan";
    yt1.subscribers = 134;
    yt1.info();
    
    //creation type-2 (heap memory allocation)
    YoutubeChannel *yt2 = new YoutubeChannel(); // this returns a pointer
    yt2->name = "second_channel";
    yt2->owner_name = "pavan";
    yt2->subscribers = 156;
    yt2->info();
    
/*
NOTE: See how the variables are accessed , assigned values. Also see how functions are called in 
both the creation types.

In C++, the new keyword is used to dynamically allocate memory for an object on the heap, while 
creating an object without the new keyword allocates memory on the stack or in static memory. 

1.Stack Memory:
Allocation: Memory allocated on the stack is done automatically when a function is called or a 
block is entered.
Allocation Size: Typically limited in size, and the size is set at compile-time.
Lifetime: Variables allocated on the stack have a limited lifetime. They are automatically 
deallocated when the function exits or the block is exited.
Access Speed: Access is usually faster compared to heap memory due to its contiguous allocation 
and automatic management.
Usage: Used for local variables, function parameters, and function call frames.

2.Heap Memory:
Allocation: Memory allocated on the heap is done explicitly using operators like new and delete 
in C++.
Allocation Size: Heap memory can be dynamically allocated and resized at runtime. It's typically
larger than stack memory.
Lifetime: Objects allocated on the heap have a potentially longer lifetime than stack variables.
They exist until explicitly deallocated using delete.
Access Speed: Access is generally slower compared to stack memory due to dynamic allocation and 
deallocation.
Usage: Used when the size of memory needed isn't known at compile-time, or when memory needs to 
persist beyond the scope in which it was created (e.g., objects shared among multiple functions 
or objects that need to outlive their creator).

3.Static Memory (also known as Data Segment or BSS Segment):
Allocation: Memory is allocated at compile-time or program startup and persists for the entire 
duration of the program.
Allocation Size: The size is fixed and determined by the compiler.
Lifetime: Variables allocated in static memory have a lifetime equal to the duration of the 
program.
Access Speed: Access speed is generally fast.
Usage: Used for global variables, static variables, and constants.These variables are accessible
throughout the program and maintain their values between function calls.


CONCLUSION( on creating object with and without new operator)
1.Memory Allocation:
Using new: Memory is allocated on the heap. The object's lifetime extends beyond the scope 
in which it was created, and you need to manually deallocate the memory using delete when it's 
no longer needed.
Without new: Memory is allocated on the stack (for local variables) or in static memory (for 
global or static variables). The object's lifetime is tied to the scope in which it was created,
and memory is automatically deallocated when the scope is exited.

2.Ownership and Lifetime:
Using new: You're responsible for managing the object's memory explicitly, including its 
deallocation using delete. If you forget to delete it, it can lead to memory leaks.
Without new: Memory management is handled automatically by the compiler. The object is destructed
when it goes out of scope (for local variables) or when the program terminates (for static 
variables).

3.Pointer vs. Direct Object:
Using new: The result of new is a pointer to the object. You typically store this pointer in a 
pointer variable.
Without new: The object itself is created directly, and you can access it directly using its 
variable name.
*/
}
