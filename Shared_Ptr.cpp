#include <iostream>
#include <memory>

int main()
{   
    // We want to create a new integer object dynamically using the new operator and
    // store its location in a shared_pointer.
    // The shared_pointer is templated with the type of its argument in angle brackets
    std::shared_ptr<int> p_x(new int);
    std::cout << " Shared pointer p_x is pointing to the memory location : " << p_x.get() << std::endl;
    // We can print out the use count of the shared pointer p_x to the console
    // by calling the use_count() method
    std::cout << " p_x use count: " << p_x.use_count() << "\n";  // count is 1 when p_x is created
    
    // // Let's use the pointer de-referencing to store a value in the memory location
    *p_x = 5;   // de-reference to alter contents
    std::cout << " Value assigned using shared_ptr p_x : " << *p_x << std::endl;

    // Let's create another shared_pointer variable and assign it the same value as p_x
    std::shared_ptr<int> p_y = p_x; // This kind of assignment was not possible with the unique_ptr type
    // I can again call the use_count method after the assignment
    std::cout << " p_x use count: " << p_x.use_count() << "\n"; // count is 2 when p_y shares the resource
    std::cout << " Shared pointer p_y points to the memory location : " << p_y << std::endl;
    std::cout << " Value assigned using shared_ptr p_y : " << *p_y << std::endl;


    // Now let us reset p_y so that it relinquishes any claim on memory
    p_y.reset();
    std::cout << " p_x use count: " << p_x.use_count() << "\n";  // count is 1, p_y relinquishes using the shared pointer

    // Now, let us reset the original pointer
    p_x.reset();    // This has the same effect as p_x going out of use, i.e. its claim on the data is relinquished
    // In this case, the use count will drop to 0 and the smart pointer will automatically
    // free up the original memory. let us verify this by calling the use_count() method
    std::cout << " p_x use count: " << p_x.use_count() << "\n";

    return 0;
}

// Output of the program reflects the number of uses of the shared resource
// The count is originally 1 when p_x is created
// Then 2 when p_y shares the resource,
// and 1 when p_y relinquishes its use
// Finally when p_x relinquishes its use, the count drops to zero

/*
Comments:
1. Although in our example, we have just done simple assignment and reset operations,
however their use here actually represents general wider uses of a shared pointer.
2. Copies of the pointers may be made when they are passed into functions or containers (vectors, sets)
3. When functions or containers finish, their copy of the pointer is not needed and is, in effect, reset.

Unique ptr and shared ptr are the two important features of modern C++ memory management.
*/