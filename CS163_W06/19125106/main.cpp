#include "header.h"

int main()
{
    int choice, n, M;
    string exp;
    cout << "1. The Josephus problem" << endl;
    cout << "2. Polish notation" << endl;
    cout << "0. Exit" << endl;;
    while (1)
    {
        cout << "Enter the choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            Queue q;
            q.head = q.tail = nullptr;
            cout << "Enter the number of pirate (At least 1): ";
            cin >> n;
            cout << "Enter the amount of money (At least 10): ";
            cin >> M;
            JosephusProblem(q, n, M);
            deleteAll(q.head);
            break;
        }
        case 2:
        {
            Stack s;
            s.head = nullptr;
            cout << "Enter the expression: ";
            cin >> exp;
            cin.ignore(1);
            cout << "The polish notation of the expression: " << endl;
            PolishNotation(s, exp);
            deleteAll(s.head);
            break;
        }
        default:
            return 0;
        }
    }

}