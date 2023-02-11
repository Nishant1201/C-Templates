#include <iostream>

template<class T>
class myclass
{
    T a, b;
    public:
        myclass (T first, T second) : a(first), b(second) {}
        T getMaxval();
};

template<class T>
T myclass<T>::getMaxval()
{
    return (a > b ? a:b) ;
}

int main(int argc, char *argv[])
{
    myclass<int> myobject(100, 75);
    std::cout << " Maximum of 100 and 75 is " << myobject.getMaxval() << std::endl;

    myclass<char> mychobject('A', 'a');
    std::cout << " Maximum of 'A' and 'a' is " << mychobject.getMaxval() << std::endl;

    return 0;
}