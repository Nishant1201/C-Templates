#include <iostream>

// class template
template<class T>
class myIncrement
{
    T value;
    public:
        myIncrement(T arg) : value(arg) {}                  // myIncrement(T arg) {value = arg;}
        T toIncrement() {return value += 1 ;}
};

// class template specialization
template< >
class myIncrement<char>
{
    char value;
    public:
        myIncrement(char arg) {value = arg;}
        char uppercase()
        {
            if((value >= 'a') && (value <= 'z'))
            value += 'A' - 'a';
            return value;
        }
};

int main(int argc, char *argv[])
{
    myIncrement<int> myint(7);
    myIncrement<char> mychar('s');
    myIncrement<double> mydouble(11.0);

    std::cout << "Incremented int value: " << myint.toIncrement() << std::endl;
    std::cout << "Uppercase value: " << mychar.uppercase() << std::endl;
    std::cout << "Incremented double value: " << mydouble.toIncrement() << std::endl;

    return 0;
}