#include <iostream>

template<typename T>
class Array{
    private:
        T *mData;
        int msize;
    public:
        Array(T array[], int size);
        void print();
};

template<typename T>
Array<T>::Array(T array[], int size)
{   
    msize = size;
    mData = new T[msize];
    for(int i=0; i<msize; i++)
        mData[i] = array[i];
}

template<typename T>
void Array<T>::print()
{
    for(int i=0; i<msize; i++)
        std::cout << mData[i] << "  ";
    std::cout << std::endl;
}

int main(int argc, char *argv[])
{
    int arr[5] = {2, 4, 6, 8, 10};
    Array<int>  a(arr, 5);
    a.print();

    return 0; 
}