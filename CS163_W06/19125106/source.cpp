#include "header.h"

ref getNodeK(int k)
{
    ref temp = new node;
    temp->key = k;
    temp->next = nullptr;
    return temp;
}

ref getNodeC(char c)
{
    ref temp = new node;
    temp->op = c;
    temp->next = nullptr;
    return temp;
}

void enqueue(Queue &q, int k)
{
    if (!q.head)
        q.head = q.tail = getNodeK(k);
    else
    {
        q.tail->next = getNodeK(k);
        q.tail = q.tail->next;
    }
}

int dequeue(Queue &q)
{
    if (isEmptyQ(q))
        return -1;

    ref temp = q.head;
    int output = temp->key;
    if (q.head == q.tail)
        q.head = q.tail = nullptr;
    else
        q.head = q.head->next;

    delete temp;
    return output;
}

bool isEmptyQ(Queue q)
{
    if (q.head)
        return false;
    return true;
}

void JosephusProblem(Queue &q, int n, int M)
{
    if (n < 1 || M < 10)
    {
        cout << "Invalid input." << endl;
        return;
    }

    int *a = new int[n + 1]{};
    ref current;

    //Initialization:
    for (int i = 0; i < n; ++i)
        enqueue(q, i + 1);

    //Process:
    while (q.head != q.tail && M >= 10)
    {
        a[q.head->key] += 10;
        M -= 10;
        enqueue(q, dequeue(q));
        dequeue(q);
    }

    a[q.head->key] += M;
    dequeue(q);

    //Print the problem output
    for (int i = 0; i < n; ++i)
        cout << i + 1 << ": " << a[i + 1] << endl;

    delete[] a;
}

void push(Stack &s, char op)
{
    if (!s.head)
        s.head = getNodeC(op);
    else
    {
        ref temp = getNodeC(op);
        temp->next = s.head;
        s.head = temp;
    }
}

char pop(Stack &s)
{
    if (!s.head)
        return '$';
    char output = s.head->op;
    if (!s.head->next)
    {
        delete s.head;
        s.head = nullptr;
    }
    else
    {
        ref temp = s.head;
        s.head = s.head->next;
        delete temp;
    }
    return output;
}

bool isEmptyS(Stack s)
{
    if (s.head)
        return false;
    return true;
}

void PolishNotation(Stack &s, string exp)
{
    string output;
    int currentPriority;

    for (int i = 0; i < exp.length(); ++i)
    {
        currentPriority = Priority(exp[i]);

        if (currentPriority < 0)
            output += exp[i];
        else
        {
            if (exp[i] == ')')
            {
                while (s.head->op != '(')
                    output += pop(s);
                pop(s);
            }
            else if (s.head && s.head->op != '(' && exp[i] != '(' && currentPriority < Priority(s.head->op))
            {
                while (s.head)
                    output += pop(s);
                push(s, exp[i]);
            }
            else
                push(s, exp[i]);
        }
    }

    while (s.head)
        output += pop(s);

    cout << output << endl;
}

int Priority(char c)
{
    if (c == '(' || c == ')')
        return 0;
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    if (c == '^')
        return 3;
    return -1;
}

void deleteAll(ref &head)
{
    ref del;
    while (head)
    {
        del = head;
        head = head->next;
        delete del;
    }
}