#include <iostream>
#include <algorithm>
#include "Header.h"

using namespace std;

int main()
{
	int size, key;
	cout << "Enter the array size: ";
	cin >> size;
	int* a = new int[size];
	int* b = new int[size];
	
	InputArray(a, size);
	cout << "The array: ";
	PrintArray(a, size);
	cout << "Find min: " << FindMin(a, size) << endl;
	cout << "Find max modulus: " << FindMaxModulus(a, size) << endl;
	cout << "Sum of Array: " << SumOfArray(a, size) << endl;
	cout << "Count prime: " << CountPrime(a, size) << endl;
	cout << "Linear search, enter the key: ";
	cin >> key;
	cout << key << ": a[" << LinearSearch(a, size, key) << "]" << endl;
	cout << "Sentinel Linear search, enter the key: ";
	cin >> key;
	cout << key << ": a[" << SentinelLinearSearch(a, size, key) << "]" << endl;

	cout << "Is ascending: ";
	if (IsAscending(a, size)) cout << "true" << endl;
	else cout << "false" << endl;
	sort(a, a + size);
	cout << "The sorted version of the array: ";
	PrintArray(a, size);
	cout << "Binary search, enter the key: ";
	cin >> key;
	cout << key << ": a[" << BinarySearch(a, size, key) << "]" << endl;
	cout << "Recursive Binary search, enter the key: ";
	cin >> key;
	cout << key << ": a[" << RecursiveBinarySearch(a, 0, size, key) << "]" << endl;
	cout << "Reverse Array: ";
	ReverseArray(a, b, size);
	PrintArray(a, size);
	DellocateArray(a);
	return 0;
}