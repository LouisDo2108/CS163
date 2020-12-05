#include "header.h"

int main()
{
    cout << "Doubly linked list demo" << endl;
    int choice, k, given;
    d_List l;
    d_NODE *temp;

    while (1)
    {
        cout << "1. Initialize a list from a given integer." << endl;
        cout << "2. Add a node at the front of a given List." << endl;
        cout << "3. Add a node before a given node." << endl;
        cout << "4. Add a node after a given node." << endl;
        cout << "5. Add a node at the end of a given List." << endl;
        cout << "6. Remove a node at the front of a given List." << endl;
        cout << "7. Remove a node at the end of a given List." << endl;
        cout << "8. Remove the first node with given value." << endl;
        cout << endl;
        cout << "Enter 1 to 8 to execute a function or 0 to exit." << endl;
        cout << "Enter the number: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "Enter a key to init the linked list: ";
            cin >> k;
            init(l, k);
            break;
        }
        case 2:
        {
            cout << "Enter the key: ";
            cin >> k;
            addFront(l, k);
            break;
        }
        case 3:
        {
            cout << "Enter the given node's key: ";
            cin >> given;
            cout << "Enter the key of the node to be added before: ";
            cin >> k;
            addBefore(l, k, given);
            break;
        }
        case 4:
        {
            cout << "Enter the given node's key: ";
            cin >> given;
            cout << "Enter the key of the node to be added after: ";
            cin >> k;
            addAfter(l, k, given);
            break;
        }
        case 5:
        {
            cout << "Enter the key: ";
            cin >> k;
            addEnd(l, k);
            break;
        }
        case 6:
        {
            removeFront(l);
            break;
        }
        case 7:
        {
            removeEnd(l);
            break;
        }
        case 8:
        {
            cout << "Enter the key: ";
            cin >> given;
            removeFirstValue(l, given);
            break;
        }
        default:
            break;
        }

        if (choice)
        {
            cout << "Current linked list: ";
            temp = l.pHead;
            while (temp)
            {
                cout << temp->key << "->";
                temp = temp->pNext;
            }

            cout << endl;
            cout << endl;
            cout << endl;
        }
        else
            break;
    }

    while (l.pHead)
        removeFront(l);

    return 0;
}