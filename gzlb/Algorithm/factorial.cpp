#include "factorial.h"

factorial::factorial()
{

}

int factorial::func(int n)
{
    int result;
    if(n == 0)
        result = 1;
    else
        result = n*func(n-1);
    return result;
}
