#include <iostream>
#include "Header.h"
#include <cmath>

using namespace std;

void InputArray(int*& a, int& n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << "a[" << i << "]: ";
        cin >> a[i];
    }
    return;
}

void DellocateArray(int*& a)
{
    if (!a) return;
    delete[] a;
}

void PrintArray(int* a, int n)
{
    if (a == 0)
        cout << "Nothing to print" << endl;

    cout << "[";
    for (int i = 0; i < n - 1; ++i)
        cout << a[i] << ",";

    cout << a[n - 1] << "]" << endl;
    return;
}

int FindMin(int* a, int n)
{
    int min = INT_MAX;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] <= min)
            min = a[i];
    }
    return min;
}

int FindMaxModulus(int* a, int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; ++i)
    {
        if (abs(a[i]) >= max)
            max = abs(a[i]);
    }
    return max;
}

bool IsAscending(int* a, int n)
{
    for (int i = 0; i < (n - 1); ++i)
    {
        if (!(a[i] <= a[i + 1]))
            return false;
    }
    return true;
}

int SumOfArray(int* a, int n)
{
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += a[i];
    }
    return sum;
}

int CountPrime(int* a, int n)
{
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        if (isPrime(a[i]))
            ++count;
    }
    return count;
}

bool isPrime(int x)
{
    if (x == 2)
        return true;
    if (x <= 1 || (x % 2 == 0))
        return false;
    for (int i = 3; i <= sqrt(x); ++i)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

int ReverseArray(int*& a, int* b, int n)
{
    int index = 0;
    for (int i = n - 1; i >= 0; --i)
        b[index++] = a[i];
    DellocateArray(a);
    a = b;
    return 0;
}

int LinearSearch(int* a, int n, int key)
{
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == key)
            return i;
    }
    return -1;
}

int SentinelLinearSearch(int* a, int n, int key)
{
    int* b = new int[n + 1], i = 0;

    for (i = 0; i < n; ++i)
        b[i] = a[i];

    b[n] = key;
    i = 0;
    while (i < n && b[i] != key)
        ++i;

    delete[] b;

    if (a[i] == key)
        return i;
    else
        return -1;
}

int BinarySearch(int* a, int n, int key)
{
    int i = 0;
    while (i <= n)
    {
        int mid = i + (n - i) / 2;
        if (a[mid] == key)
            return mid;

        if (key > a[mid])
            i = mid + 1;
        else
            n = mid - 1;
    }
    return -1;
}

int RecursiveBinarySearch(int* a, int left, int right, int key)
{
    int mid = left + (right - left) / 2;
    if (left > right)
        return -1;
    if (a[mid] == key)
        return mid;

    if (key > a[mid])
        return RecursiveBinarySearch(a, mid + 1, right, key);
    else
        return RecursiveBinarySearch(a, left, mid - 1, key);
}
