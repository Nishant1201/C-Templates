/*******************************************************************************************
* C++ template program to perform numerical integration for calculating value of M_PI / 4  * 
*                                                                                          *
* This program contains functions to calculate the definite integral of function           *
*                                 f(x) = 1.0 / (1.0 + x^2)                                 *
*           using the following five methods:                                              *
*           1. rectangular                                                                 *
*               a. left                                                                    *     
*               b. right                                                                   *
*               c. midpoint                                                                *
*           2. trapezium                                                                   *
*           3. Simpson's                                                                   * 
*               a. composite                                                               *
*   Functions take in the upper and lower bounds (a and b), and the number  of             *
*   approximations to make in that range (n).                                              *
*                                                                                          *
*   Simpson's method is defined by the following pseudo-code :                             *
*   Algorithm Simpson_composite(f, a, b, n)                                                *
*            h = (b - a) / n                                                               *
*            sum1 = f(a + h/2)                                                             *
*            sum2 = 0.0                                                                    *
*                                                                                          *
*            loop on i from 1 to (n-1)                                                     *
*               sum1 = sum1 + f(a + h * i + h/2)                                           *
*               sum2 = sum2 + f(a + h * i)                                                 *
*            answer = (h / 6) * (f(a) + f(b) + 4*sum1 + 2*sum2)                            *
*                                                                                          *
*                               Author : Nishant Soni                                      *
*                               email  : nishant.aesidel@gmail.com                         *
********************************************************************************************/

#include <iostream>

typedef double myReal;

// Function prototype
myReal my_func(myReal x) { return 1.0 / (1.0 + x*x) ; }

template<typename Function, typename Float, typename Method>
myReal integrate(Function my_func, Float a, Float b, int steps, Method my_method);

// methods for numerical integration as classes
class rectangular
{
    public:
        enum position_type {left, middle, right};
        rectangular(position_type pos) : position(pos) {}
        template<typename Function, typename Float>
        myReal operator()(Function my_func, Float x, Float dx) const;
    private:
        const position_type position;
};

class trapezium
{
    public:
        template<typename Function, typename Float>
        myReal operator()(Function my_func, Float x, Float dx) const
        {
            return (my_func(x) + my_func(x+dx)) * 0.5;
        }
};

class Simpson
{
    public:
        template<typename Function, typename Float>
        myReal operator()(Function my_function, Float x, Float dx) const
        {
            return (my_func(x) + 4.0*my_func(x + dx*0.5) + my_func(x + dx)) / 6.0;
        }
};

int main(int argc, char *argv[])
{   
    // Perform numerical integration with diffferent schemes   
    myReal rectangular_left = integrate(my_func, 0.0, 1.0, 100, rectangular(rectangular::left));
    myReal rectangular_middle = integrate(my_func, 0.0, 1.0, 100, rectangular(rectangular::middle));
    myReal rectangular_right = integrate(my_func, 0.0, 1.0, 100, rectangular(rectangular::right));
    myReal trapezoid  = integrate(my_func, 0.0, 1.0, 100, trapezium());
    myReal simpson  = integrate(my_func, 0.0, 1.0, 100, Simpson());

    std::cout << rectangular_left << std::endl;
    std::cout << rectangular_middle << std::endl;
    std::cout << rectangular_right << std::endl;
    std::cout << trapezoid << std::endl;
    std::cout << simpson << std::endl;

    return 0;
}   

// function integrator
template<typename Function, typename Float, typename Method>
myReal integrate(Function my_func, Float a, Float b, int steps, Method my_method)
{
    myReal sum(0.0);
    myReal dx = (b-a) / (steps);

    for(int i=0; i<steps; i++)
        sum += my_method(my_func, a + i*dx, dx);

    return sum*dx;
}

// Overload () for class rectangular
template<typename Function, typename Float>
myReal rectangular::operator()(Function my_func, Float x, Float dx) const
{
    switch(position)
    {
        case left:
            return my_func(x);
            break;
        case middle:
            return my_func(x + 0.5*dx);
            break;
        case right:
            return my_func(x + dx);
            break;
        default:
            std::cout << "Something went wrong, shouldn't reach here :/" << std::endl;
            return 0.0;
    }
}

/* Alternate call intructions in main program
    rectangular obj_rect_left(rectangular::left);
    rectangular obj_rect_middle(rectangular::middle);
    rectangular obj_rect_right(rectangular::right);
    trapezium trapezoid2;
    Simpson simpson2;

    double rectangular_left = integrate(f, 0.0, 1.0, 11, obj_rect_left);
    double rectangular_middle = integrate(f, 0.0, 1.0, 11, obj_rect_middle);
    double rectangular_right = integrate(f, 0.0, 1.0, 11, obj_rect_right);
    double trapezoid  = integrate(f, 0.0, 1.0, 11, trapezoid2);
    double simpson  = integrate(f, 0.0, 1.0, 11, simpson2);

    std::cout << rectangular_left << std::endl;
    std::cout << rectangular_middle << std::endl;
    std::cout << rectangular_right << std::endl;
    std::cout << trapezoid << std::endl;
    std::cout << simpson << std::endl;
*/