#include <iostream>
#include "header.h"

using namespace std;

void initStack(Stack &s, int k)
{
    push(s, k);
    return;
}

void push(Stack &s, int k)
{
    NODE *temp = new NODE;
    temp->key = k;
    temp->pNext = nullptr;
    if (!s.head)
        s.head = temp;
    else
    {
        temp->pNext = s.head;
        s.head = temp;
    }
    return;
}

int pop(Stack &s)
{
    if (!s.head)
        cout << "Stack is empty" << endl;
    else
    {
        int result = s.head->key;
        NODE *del = s.head;
        s.head = s.head->pNext;
        delete del;
        del = nullptr;
        return result;
    }
    return INT_MIN;
}

bool isEmptyStack(Stack &s)
{
    if (!s.head)
        return true;
    return false;
}

int countStack(Stack &s)
{
    int i = 0;
    NODE *temp = s.head;
    while (temp)
    {
        ++i;
        temp = temp->pNext;
    }
    return i;
}

void initQueue(Queue &q, int k)
{
    enqueue(q, k);
}

void enqueue(Queue &q, int k)
{
    NODE *temp = new NODE;
    temp->key = k;
    temp->pNext = nullptr;
    if (!q.head)
    {
        q.head = temp;
        q.tail = q.head;
    }
    else
    {
        q.tail->pNext = temp;
        q.tail = temp;
    }
    return;
}

int dequeue(Queue &q)
{
    if (!q.head)
    {
        cout << "Queue is empty" << endl;
        return INT_MIN;
    }
    NODE *del = q.head;
    int result = q.head->key;
    if (q.head == q.tail)
    {
        q.head = nullptr;
        q.tail = nullptr;
    }
    else
        q.head = q.head->pNext;
    delete del;
    del = nullptr;
    return result;
}

bool isEmptyQueue(Queue &q)
{
    if (!q.head)
        return true;
    return false;
}

int countQueue(Queue &q)
{
    int i = 0;
    NODE *temp = q.head;
    while (temp)
    {
        ++i;
        temp = temp->pNext;
    }
    return i;
}

int main()
{
    Stack s;
    Queue q;
    int i, k;

    cout << "Stack, queue demo: " << endl;
    while (1)
    {
        cout << endl;
        cout << "1. Init stack with a given key." << endl;
        cout << "2. Push a key into a gven stack." << endl;
        cout << "3. Pop an element out of a given stack, return the key's value." << endl;
        cout << "4. Count the number of elements in the given stack" << endl;
        cout << "5. Determine if a given stack is empty." << endl;

        cout << "6. Init queue with a given key." << endl;
        cout << "7. Enqueue a key into a gven stack." << endl;
        cout << "8. Dequeue an element out of a given queue, return the key's value." << endl;
        cout << "9. Count the number of elements in the given queue" << endl;
        cout << "10. Determine if a given queue is empty." << endl;

        cout << "Enter 0 to exit or 1 to 10 to implement a function" << endl;
        cout << "Please enter the number: ";
        cin >> i;

        switch (i)
        {
        case 1:
        {
            cout << "Please enter the key: ";
            cin >> k;
            initStack(s, k);
            break;
        }
        case 2:
        {
            cout << "Please enter the key: ";
            cin >> k;
            push(s, k);
            break;
        }
        case 3:
        {
            cout << pop(s) << endl;
            break;
        }
        case 4:
        {
            cout << "Count: ";
            cout << countStack(s) << endl;
            break;
        }
        case 5:
        {
            if (isEmptyStack(s))
                cout << "Empty" << endl;
            else
                cout << "Not empty" << endl;
            break;
        }
        case 6:
        {
            cout << "Please enter the key: ";
            cin >> k;
            initQueue(q, k);
            break;
        }
        case 7:
        {
            cout << "Please enter the key: ";
            cin >> k;
            enqueue(q, k);
            break;
        }
        case 8:
        {
            cout << dequeue(q) << endl;
            break;
        }
        case 9:
        {
            cout << "Count: " << countQueue(q) << endl;
            break;
        }
        case 10:
        {
            if (isEmptyQueue(q))
                cout << "Empty" << endl;
            else
                cout << "Not empty" << endl;
            break;
        }
        default:
        {
            NODE *temp = s.head, *del;
            while (temp)
            {
                del = temp;
                temp = temp->pNext;
                delete del;
            }
            temp = q.head;
            while (temp)
            {
                del = temp;
                temp = temp->pNext;
                delete del;
            }
            return 0;
        }
        }
    }
}