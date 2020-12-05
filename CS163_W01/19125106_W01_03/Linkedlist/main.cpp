#include "Header.h"
#include <iostream>

using namespace std;

int main()
{
	List* l;
	int key;
	cout << "Init a list with a node, enter the node's key: ";
	cin >> key;
	l = CreateList(CreateNode(key));

	cout << "Add Head, enter the node's key: ";
	cin >> key;
	AddHead(l, key);

	cout << "Add Tail, enter the node's key: ";
	cin >> key;
	AddTail(l, key);

	cout << "Add some random elements to the tail of the list." << endl;
	for (int i = 0; i < 3; ++i)
	{
		AddTail(l, i);
		AddTail(l, i);
	}
	cout << "List: ";
	PrintList(l);

	cout << "Reversed list:";
	List* r = ReverseList(l);
	PrintList(r);

	cout << "Count elements: " << CountElements(l) << endl;

	RemoveDuplicate(l);

	cout << "List after removed duplicate: ";
	PrintList(l);

	cout << "Remove all key value in the list, enter the key: ";
	cin >> key;
	RemoveElement(l, key);
	cout << "List after removed all key value " << key << ": ";
	PrintList(l);

	cout << "List after removed head: ";
	RemoveHead(l);
	PrintList(l);

	cout << "List after removed tail: ";
	RemoveTail(l);
	PrintList(l);
	
	RemoveAll(l);
	RemoveAll(r);
	return 0;
}