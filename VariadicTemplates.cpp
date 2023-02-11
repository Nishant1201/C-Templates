#include <iostream>
#include <string>

template<typename T>
T summation(T val)
{
    return val;
}

template<typename T, typename ... Args>
T summation(T first, Args ... args)
{
    return first + summation(args...);
}

int main(int argc, char *argv[])
{   
    int sum = summation(1, 2, 3, 8, 7);
    std::cout << "Sum of integers = " << sum << std::endl;

    std::string s1 = "H", s2 = "e", s3 = "l", s4 = "l", s5 = "o";
    std::string s_concat = summation(s1, s2, s3, s4, s5);
    
    std::cout << "Sum of strings = " << s_concat << std::endl;

    return 0;
}