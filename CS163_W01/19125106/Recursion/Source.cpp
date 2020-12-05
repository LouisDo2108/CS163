#include "Header.h"
#include <iostream>

using namespace std;

int SumOfSquares(int n)
{
    if (n == 0)
        return 0;
    return n * n + SumOfSquares(n - 1);
}

int GCD(int a, int b)
{
    if (a == 0 || b == 0)
        return 0;
    else if (a == b)
        return a;
    else if (a > b)
        return GCD(a - b, b);
    else
        return GCD(a, b - a);
}

int FIB(int n)
{
    if (n <= 1)
        return n;
    if (n == 2)
        return 1;
    return FIB(n - 1) + FIB(n - 2);
}