// Like normal parameters, we can pass more than one data types as arguments to templates.
// The following example demonstrates the same.

#include <iostream>

template<class T, class U>
class A{
        T x;
        U y;
    public:
        A() { std::cout << "Constructor called" << std::endl;}
        ~A() { std::cout << "Destructor called" << std::endl;}
};

int main(int argc, char *argv[])
{
    A<char, char> a;
    A<int, double> b;

    return 0;
}