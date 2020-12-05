#include "header.h"

int main()
{
    int choice, key;
    NODE *p_root = nullptr;
    while (1)
    {
        cout << "1. Create node" << endl;
        cout << "2. Pre-order Traversal" << endl;
        cout << "3. In-order Traversal" << endl;
        cout << "4. Post-order Traversal" << endl;
        cout << "5. Level-Order Traversal" << endl;
        cout << "6. Find and return a NODE with given value from a given Binary Tree" << endl;
        cout << "7. Add a NODE with given value into a given Binary Tree" << endl;
        cout << "8. Remove a NODE with given value from a given Binary Tree" << endl;
        cout << "9. Calculate the height of a given Binary Tree " << endl;
        cout << "10. Count the number of NODE from a given Binary Tree:" << endl;
        cout << "11. Calculate the level of a given NODE:" << endl;
        cout << "12. Count the number leaves from a given Binary Tree:" << endl;
        cout << "13. Count the number of NODE from a given Binary Search Tree which key value is less than a given value:" << endl;
        cout << "14. Count the number of NODE from a given Binary Search Tree which key value is greater than a given value:" << endl;
        cout << "15. Determine if a given Binary Tree is Binary Search Tree:" << endl;
        cout << "Please enter the choice or 0 to exit: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "Enter the key: ";
            cin >> key;
            CreateNode(key);
            break;
        }
        case 2:
        {
            NLR(p_root);
            cout << endl;
            break;
        }
        case 3:
        {
            LNR(p_root);
            cout << endl;
            break;
        }
        case 4:
        {
            LRN(p_root);
            cout << endl;
            break;
        }
        case 5:
        {
            LevelOrder(p_root);
            cout << endl;
            break;
        }
        case 6:
        {
            cout << "Enter the key: ";
            cin >> key;
            NODE *temp = Search(p_root, key);
            if (temp)
                cout << "Found the node with the given value" << endl;
            else
                cout << "Can't find the node with the given value" << endl;
            break;
        }
        case 7:
        {
            cout << "Enter the key: ";
            cin >> key;
            Insert(p_root, key);
            break;
        }
        case 8:
        {
            cout << "Enter the key: ";
            cin >> key;
            Remove(p_root, key);
            break;
        }
        case 9:
        {
            cout << Height(p_root) << endl;
            break;
        }
        case 10:
        {
            cout << CountNode(p_root) << endl;
            break;
        }
        case 11:
        {
            cout << "Enter the key: ";
            cin >> key;
            cout << Level(p_root, Search(p_root, key)) << endl;
            break;
        }
        case 12:
        {
            cout << CountLeaf(p_root) << endl;
            break;
        }
        case 13:
        {
            cout << "Enter the key: ";
            cin >> key;
            if (Search(p_root, key))
                cout << CountLess(p_root, key) << endl;
            else
                cout << "-1" << endl;
            break;
        }
        case 14:
        {
            cout << "Enter the key: ";
            cin >> key;
            if (Search(p_root, key))
                cout << CountGreater(p_root, key) << endl;
            else
                cout << "-1" << endl;
            break;
        }
        case 15:
        {
            if (IsBST(p_root))
                cout << "True" << endl;
            else
                cout << "False" << endl;
            break;
        }
        default:
        {
            deleteTree(p_root);
            return 0;
        }
        }
    }
    return 0;
}