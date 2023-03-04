#include <iostream>
#include <memory>       // Requires C++11 or above
#include <cassert>

int main(int argc, char *argv[])
{   
    // We want to create a new integer object dynamically using the new operator and
    // assign its address to a unique_pointer.
    // The type description of the unique pointer contains the type of object to which it points,
    // in this case it is an <int> type
    std::unique_ptr<int> p_x(new int);
    // The purpose of (new int) in round brackets is to dynamicaly create an int and 
    // pass its location into p_x. The actual address of the dynamically created integer
    // may be accessed with the variable p_x

    // Let's use the pointer de-referencing to store a value in the memory location
    *p_x = 5; // 'de-reference' to alter contents
    std::cout << " Unique_ptr p_x points to the memory location : " << p_x.get() << std::endl;
    std::cout << " Value assigned using unique_ptr p_x : " << *p_x << std::endl;

    // Let's try to assign the value of p_x to a raw pointer
    // int *p_y = p_x; // Won't compile (Check in the terminal)

    // Let's try to assign the value of p_x to another unique pointer
    std::unique_ptr<int> p_z;
    // p_z = p_x;   // Won't compile (Check in the terminal)

    // The correct way to get the value out of p_x and assign it to a raw pointer is 
    // to use the get() function to get the actual address of the managed data
    int *p_y = p_x.get(); // get raw pointer
    std::cout << " Raw pointer p_y points to the memory location : " << p_y << std::endl;
    std::cout << " Accessing value using raw pointer p_y : " << *p_y << std::endl;

    // The correct way to assign from one unique_ptr to another is for the ownership 
    // of the resource to be transferred between them with the function move() from the standard library.
    p_z = std::move(p_x);   // Transfer ownership

    std::cout << " Unique_ptr p_z points to the memory location : " << p_z.get() << std::endl;
    std::cout << " Accessing value using unique_ptr p_z : " << *p_z << std::endl;

    // The unique pointer variables can be evaluated as Boolean values:
    // true if the variable is managing a resource
    // false if not
    // I can make use of the assert statement to check if a resource is being managed 
    assert(p_z);   // test if p_z is in use
    assert(!p_x);  // test that p_x is not in use

    // Because the memory management id done by the unique_ptr, there is no explicit call to delete operator
    // It is able to automatically free up the memory

    // If needed a unique pointer variable can be asked to relinquish ownership by calling the reset() method
    // and this implicitly calls delete on the memory originally allocated with a new operator
    p_z.reset();
    assert(!p_z);  // Test p_z is also not in use 

    return 0;
}
