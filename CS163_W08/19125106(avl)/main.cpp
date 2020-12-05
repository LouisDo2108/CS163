#include "header.h"

int main()
{

    NODE *root = nullptr;
    int choice, x;

    while (1)
    {
        cout << endl;
        cout << endl;
        cout << "1. Initialize a NODE from a given value" << endl;
        cout << "2. Add a NODE with given value into a given AVL tree" << endl;
        cout << "3. Remove a NODE with given value from a given AVL Tree" << endl;
        cout << "4. Pre-order Traversal" << endl;
        cout << "5. In-order Traversal" << endl;
        cout << "6. Post-order Traversal" << endl;
        cout << "7. Level-order Traversal" << endl;
        cout << "8. Determine if a given Binary Tree is an AVL Tree" << endl;
        cout << "Enter the choice or 0 to exit: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter the data: ";
            cin >> x;
            CreateNode(x);
            break;
        }
        case 2:
        {
            cout << "Enter the data: ";
            cin >> x;
            Insert(root, x);
            break;
        }
        case 3:
        {
            cout << "Enter the key: ";
            cin >> x;
            Remove(root, x);
            break;
        }
        case 4:
        {
            NLR(root);
            cout << endl;
            break;
        }
        case 5:
        {
            LNR(root);
            cout << endl;
            break;
        }
        case 6:
        {
            LRN(root);
            cout << endl;
            break;
        }
        case 7:
        {
            LevelOrder(root);
            cout << endl;
            break;
        }
        case 8:
        {
            if (isAVL(root))
                cout << "True" << endl;
            else
                cout << "False" << endl;
            break;
        }
        default:
        {
            deleteTree(root);
            return 0;
        }
        }
    }
}