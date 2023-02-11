
#include <iostream>

template<typename T>
void my_func(T x)
{
    std::cout << "Generic template my_func(): " << x << std::endl;
}

template< >
void my_func(int x)
{
    std::cout << "Specialized template for integer type : " << x << std::endl;
}

int main(int argc, char *argv[])
{   
    my_func<char>('a');
    my_func<int>(3);
    my_func<float>(3.14);

    return 0;
}