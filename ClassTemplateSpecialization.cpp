// An Example Program for class template specialization
// A specialized version of class Test is written for int data type.

#include <iostream>

template<class T>
class Test
{
    // Data members of test
    public:
        Test()
        {
            // Initialization of data members
            std::cout << "General template object" << std::endl;
        }
        // Other methods of Test class
};

template< >
class Test<int>
{
    public:
        Test()
        {
            std::cout << "Specialized template object" << std::endl;
        }
};

int main(int argc, char *argv[])
{
    Test<int> a;
    Test<char> b;
    Test<float> c;
    
    return 0;
}