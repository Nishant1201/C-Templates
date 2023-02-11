// Code to get maximum among two quantities using template function
#include <iostream>

// One function works for all data types.
// For user defined types operator '>' should be overloaded.

template<typename T>
T GetMaximum(T x, T y)
{
    return (x > y) ? x : y;
}

int main(int argc, char *argv[])
{
    std::cout << GetMaximum<int>(12, 16) << std::endl;   // Call GetMaximum for int
    std::cout << GetMaximum<double>(12.0, 16.0) << std::endl;   // Call GetMaximum for double
    std::cout << GetMaximum<char>('A', 'a') << std::endl;   // Call GetMaximum for char

    return 0;
}