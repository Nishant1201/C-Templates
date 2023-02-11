#include <iostream>

typedef double myReal;

myReal function(myReal x);
myReal function_integrator(myReal a, myReal b, myReal dx);

int main(int argc, char *argv[])
{   
    myReal a(0.0), b(1.0), dx(0.0001);
    std::cout << "Value of arc(tan(1)) = " << function_integrator(a, b, dx) << std::endl;
    return 0;
}

myReal function(myReal x)
{
    return 1.0 / (1.0 + x*x);
}

myReal function_integrator(myReal a, myReal b, myReal dx)
{
    myReal sum(0.0);
    myReal x = a;
    while(x <= b)
    {
        sum += function(x);
        x += dx;
    }
    return sum*dx;
}