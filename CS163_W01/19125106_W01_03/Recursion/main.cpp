#include "Header.h"
#include <iostream>

using namespace std;

int main()
{
	int n, a, b;
	cout << "Sum of Squares, enter the number n: ";
	cin >> n;
	cout << "Result: " << SumOfSquares(n) << endl;

	cout << "Greatest common divisor of a and b, please enter" << endl;
	cout << "a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;
	cout << "GCD of a and b: " << GCD(a, b) << endl;

	cout << "Fibonacci number, enter the number nth: ";
	cin >> n;
	cout << "Fib(" << n << "): " << FIB(n);
	return 0;
}