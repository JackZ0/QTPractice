#include "fibonacci.h"

Fibonacci::Fibonacci()
{

}

int Fibonacci::func(int n)
{
    int result;
    if(n == 1)
        result = 1;
    if(n == 2)
        result = 2;
    if(n > 2)
        result = func(n-1) + func(n -2);
    return  result;
}
