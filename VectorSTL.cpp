#include <iostream>
// to use the vector container, we must inlcude the vector header file
#include <vector>
// For using the algorithms on STL vectors (sorting), we must include the algorithm header file
#include <algorithm>        
#include <string>

int main(int argc, char *argv[])
{   
    // declare a vector of strings. 
    std::vector<std::string> universities;
    // We do not to have to state the size of the vector, STL will handle this for us. 
    // universities(50) if we wished to begin with a vector of 50 empty strings rather than an empty vector
    
    // reserve - sets the vectors capacity without changing the number of items in the vector
    universities.reserve(6); // we reserve 6 elements 
    // reserve may produce efficiency savings in more memory-intensive code because 
    // it establishes that n items can stored in the vector without having to reallocate any memory later.  
    
    // Adding elements to our empty vector container
    universities.push_back("MIT");  // introduce our first entry to the vector, 
    // member function push_back appends a copy of the string to the current vector
    universities.push_back("Caltech");  // append another entry to the end of the vector
    universities.push_back("Stanford"); // append a further entry to the vector

    // use of member function size for accessing the number of elements of the vector
    std::cout << "Length of vector is "
              << universities.size() << "\n";

    // Entries of the vector may be accessed in the same way as for a standard vector
    // using the square bracket operator
    std::cout << "Entries of vector are \n";

    for(int i=0; i<3; i++)
    {
        std::cout << universities[i] << "\n";
    }

    // Access entries of a vector using an iterator. 
    // First we define what type of vector the iterator is associated with, 
    // in this case it is a vector of strings.
    std::vector<std::string>::const_iterator c;
    
    // Construct a for loop that iterates from the start of the vector to the end of the vector
    // using the iterator object
    for(c=universities.begin(); c!=universities.end(); c++)
    {   
        // Print out the contents of the vector entry that the iterator is pointing at
        std::cout << *c << "\n";
        // The * operator is overloaded which looks like a pointer de-reference
    }

    // Add a string to the start of the vector by using the insert and begin method together
    // Insert at the start of the vector using the begin method: 
    universities.insert(universities.begin(), "Princeton"); // all subsequent entries are moved one place back
    // Add a string to the vector and place it in the second position: 
    universities.insert(universities.begin()+1, "Cornell"); // all subsequent entries are moved one place back
    /// Add another entry to the end of the vector
    universities.push_back("Yale");

    // Print out the number of entries of the vector
    std::cout << "Length of vector is " 
            << universities.size() << "\n";
    std::cout << "Entries of vector are\n";

    // Print out the entries of the vector using the iterator with a for loop
    for(c=universities.begin(); c!=universities.end(); c++)
    {
        std::cout << *c << "\n";
    }

    // Erase all entries of the vector that appear after the third entry
    universities.erase(universities.begin()+3, universities.end());

    // Print out the number of entries
    std::cout << "Length of vector is " 
                << universities.size() << "\n";
    std::cout << "Entries of vector are \n";

    // Print out the entries
    for(c=universities.begin(); c!=universities.end(); c++)
    {
        std::cout << *c << "\n";
    }
    
    // Use the algorithm sort (sort of a vector of strings into alphabetical order)
    sort(universities.begin(), universities.end());

    // print out the number of entries
    std::cout << "Length of vector is " << universities.size() << "\n";
    std::cout << "Entries of vector are\n";

    // Print the strings sorted in alphabetical order
    for(c=universities.begin(); c!=universities.end(); c++)
        std::cout << *c << "\n";

    return 0;
}