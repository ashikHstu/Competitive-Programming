
/// error 1 : iostream shouldn't have .h there is no external header file added
//#include<iostream.h>
/// correction 1:
#include <iostream>
int fun()
{
    return 1;
}

/// Error2 : Float must be start with small letter


///Error 3 : ambiguating new declaration of float fun(). function fun() already decleared
/// correction of 2 and 3
float fun2()
{
    return 10.23;
}

///error 4:  main function must have return type int
/// correction of 4:
int main()
{

    /// error 5 and 6: cout used, but std not decleared
    /// correction of 5 and 5
    std::cout<<(int)fun()<<" ";
    std::cout<<(float)fun2()<<" ";


    return 0;
}
