#include "header.h"

d_NODE *getNode(int k)
{
    d_NODE *temp = new d_NODE;
    temp->key = k;
    temp->pNext = nullptr;
    temp->pPrev = nullptr;
    return temp;
}

void init(d_List &l, int k)
{
    l.pHead = getNode(k);

    l.pTail = l.pHead;
}

void addFront(d_List &l, int k)
{
    if (!l.pHead)
    {
        init(l, k);
        return;
    }

    d_NODE *temp = getNode(k);
    temp->pNext = l.pHead;
    l.pHead->pPrev = temp;
    l.pHead = temp;
    cout << "Successfully added node " << k << " at the front of the linked list." << endl;
}

void addBefore(d_List &l, int k, int given)
{
    d_NODE *temp = l.pHead;
    while (temp != l.pTail && temp->key != given)
        temp = temp->pNext;
    if (temp->key == given)
    {
        d_NODE *newNode = getNode(k);
        newNode->pNext = temp;
        if (temp == l.pHead)
        {
            temp->pPrev = newNode;
            l.pHead = newNode;
        }
        else
        {
            newNode->pPrev = temp->pPrev;
            temp->pPrev->pNext = newNode;
            temp->pPrev = newNode;
        }
        cout << "Successfully added node " << k << " before node " << given << "." << endl;
    }
    else
        cout << "Can't find the given node " << k << endl;
}

void addAfter(d_List &l, int k, int given)
{
    d_NODE *temp = l.pHead;
    while (temp != l.pTail && temp->key != given)
        temp = temp->pNext;
    if (temp->key == given)
    {
        d_NODE *newNode = getNode(k);
        newNode->pNext = temp->pNext;
        if (temp == l.pTail)
        {
            temp->pNext = newNode;
            newNode->pPrev = temp;
            l.pTail = newNode;
        }
        else
        {
            newNode->pPrev = temp;
            temp->pNext->pPrev = newNode;
            temp->pNext = newNode;
        }
        cout << "Successfully added node " << k << " after node " << given << "." << endl;
    }
    else
        cout << "Can't find the given node " << k << endl;
}

void addEnd(d_List &l, int k)
{
    if (!l.pTail)
    {
        init(l, k);
        return;
    }

    d_NODE *temp = getNode(k);
    l.pTail->pNext = temp;
    temp->pPrev = l.pTail;
    l.pTail = temp;
    cout << "Successfully added node " << k << " at the end of the linked list." << endl;
}

void removeFront(d_List &l)
{
    if (!l.pHead)
    {
        cout << "Linked list is empty" << endl;
        return;
    }

    d_NODE *del = l.pHead;
    if (l.pHead == l.pTail)
    {
        delete del;
        l.pHead = l.pTail = nullptr;
    }
    else
    {
        l.pHead = l.pHead->pNext;
        l.pHead->pPrev = nullptr;
        delete del;
    }
    cout << "Successfully removed the front node." << endl;
}

void removeEnd(d_List &l)
{
    if (!l.pTail)
    {
        cout << "Linked list is empty." << endl;
        return;
    }

    d_NODE *del = l.pTail;
    if (l.pHead == l.pTail)
    {
        delete del;
        l.pHead = l.pTail = nullptr;
    }
    else
    {
        l.pTail = l.pTail->pPrev;
        l.pTail->pNext = nullptr;
        delete del;
    }
    cout << "Successfully removed the end node." << endl;
}

void removeFirstValue(d_List &l, int given)
{
    if (!l.pHead)
    {
        cout << "Linked list is empty" << endl;
        return;
    }

    d_NODE *temp = l.pHead, *del;
    while (temp != l.pTail && temp->key != given)
        temp = temp->pNext;

    if (temp->key == given)
    {
        if (l.pHead == l.pTail)
        {
            delete l.pHead;
            l.pHead = l.pTail = nullptr;
            return;
        }

        del = temp;

        if (del == l.pHead)
        {
            l.pHead = l.pHead->pNext;
            l.pHead->pPrev = nullptr;
        }
        else if (del == l.pTail)
        {
            l.pTail = l.pTail->pPrev;
            l.pTail->pNext = nullptr;
        }
        else
        {
            del->pPrev->pNext = del->pNext;
            del->pNext->pPrev = del->pPrev;
        }
        delete del;
        cout << "Successfully removed the first node with value " << given << ".";
    }
    else
        cout << "Can't find the given node." << endl;
}