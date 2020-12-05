#include <iostream>

using namespace std;

typedef struct node *ref;

struct node
{
    int key;
    ref next = nullptr;
};

struct list
{
    ref head, tail;
};

void removeEnd(list &l);
void removeBegin(list &l);

ref getNode(int k)
{
    ref temp = new node;
    temp->key = k;
    return temp;
}

void insertNode(list &l, int k)
{
    if (!l.head)
        l.head = l.tail = getNode(k);
    else
    {
        l.tail->next = getNode(k);
        l.tail = l.tail->next;
    }
}

void insertNodeOrdered(list &l, int k)
{
    if (!l.head)
        l.head = l.tail = getNode(-1);

    ref t1, t2;
    t1 = l.head;
    t2 = l.head->next;

    while (t2 && k > t2->key)
    {
        t1 = t2;
        t2 = t2->next;
    }

    t1->next = getNode(k);
    t1 = t1->next;
    t1->next = t2;

    if (!t1->next)
        l.tail = t1;
    else if (!t2->next)
        l.tail = t2;
}

void show(list l)
{
    ref t = l.head;
    while (t)
    {
        cout << t->key << " ";
        t = t->next;
    }
}

void removeList(list &l)
{
    ref temp;
    while (l.head)
    {
        temp = l.head;
        l.head = l.head->next;
        delete temp;
        temp = nullptr;
    }
}

void removeAllNode(list &l, int k)
{
    if (!l.head)
        return;

    ref del;

    while (l.head && l.head->key == k)
    {
        del = l.head;
        l.head = l.head->next;

        if (!l.head)
            l.head = l.tail = nullptr;

        delete del;
        del = nullptr;
    }

    ref t1, t2;
    t1 = l.head;
    t2 = l.head->next;

    while (t2)
    {
        if (t2->key == k)
        {
            del = t2;
            t2 = t1->next = del->next;
            if (del == l.tail)
                l.tail = t1;
            delete del;
            del = nullptr;
        }
        else
        {
            t1 = t2;
            t2 = t2->next;
        }
    }
}

void removeEnd(list &l)
{
    if (l.head)
    {
        if (l.head == l.tail)
            return removeBegin(l);

        ref temp = l.head;
        while (temp && temp->next != l.tail)
            temp = temp->next;
        ref del = l.tail;
        l.tail = temp;
        temp->next = nullptr;
        delete del;
        del = nullptr;
    }
}

void removeBegin(list &l)
{
    if (l.head)
    {
        ref del = l.head;
        l.head = l.head->next;
        if (!l.head)
            l.head = l.tail = nullptr;
        delete del;
        del = nullptr;
    }
}

void insertNodeCir(list &l, int k)
{
    if (!l.head)
    {
        l.head = getNode(k);
        l.head->next = l.head;
    }
    else
    {
        ref temp = l.head;
        while (temp && temp->next != l.head)
            temp = temp->next;
        temp->next = getNode(k);
        temp = temp->next;
        temp->next = l.head;
    }
}

void traverseCir(list l)
{
    ref temp = l.head;
    while (temp && temp->next != l.head)
    {
        cout << temp->key << " ";
        temp = temp->next;
    }
    cout << temp->key << endl;
}

int intersort(ref &head)
{
    int count = 1;
    ref t1 = head, t2;
    while (t1 && t1->next != head)
    {
        t2 = t1;
        while (t2 && t2->next != head)
        {
            if (t2->key > t2->next->key)
            {
                int temp = t2->key;
                t2->key = t2->next->key;
                t2->next->key = temp;
            }
            t2 = t2->next;
        }
        t1 = t1->next;
        ++count;
    }
    return count;
}

void removeCir(list &l)
{
    ref temp = l.head;
    while (temp->next != l.head)
        temp = temp->next;
    temp->next = nullptr;

    while (l.head)
    {
        temp = l.head;
        l.head = l.head->next;
        delete temp;
    }
}
int getMedian(ref head)
{
    int n = intersort(head), i;
    ref temp = head;

    for (i = 0; i < (n / 2) - 1; ++i)
        temp = temp->next;

    return (n % 2 == 0) ? (temp->key + temp->next->key) / 2 : (temp->next->key);
}

int main()
{
    list l;
    l.head = nullptr;
    insertNodeCir(l, 1);
    insertNodeCir(l, 2);
    insertNodeCir(l, 3);
    insertNodeCir(l, 4);
    insertNodeCir(l, 5);
    insertNodeCir(l, 6);
    traverseCir(l);
    cout << getMedian(l.head);
    removeCir(l);
    return 0;
}