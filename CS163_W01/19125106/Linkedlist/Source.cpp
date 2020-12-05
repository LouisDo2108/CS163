#include "Header.h"
#include <iostream>

using namespace std;

NODE* CreateNode(int data)
{
    NODE* temp = new NODE;
    temp->key = data;
    temp->p_next = 0;
    return temp;
}

List* CreateList(NODE* p_node)
{
    List* temp = new List;
    temp->p_head = p_node;
    temp->p_tail = p_node;
    return temp;
}

bool AddHead(List*& L, int data)
{
    if (!L)
        return false;
    NODE* newHead = CreateNode(data);
    newHead->p_next = L->p_head;
    L->p_head = newHead;
    return true;
}

bool AddTail(List*& L, int data)
{
    if (!L)
        return false;
    NODE* cur = L->p_head, * temp = CreateNode(data);
    while (cur != L->p_tail)
        cur = cur->p_next;
    cur->p_next = temp;
    L->p_tail = temp;
    return true;
}

void RemoveHead(List*& L)
{
    if (!L || !L->p_head)
        return;
    NODE* del = L->p_head;
    L->p_head = del->p_next;
    delete del;
}

void RemoveTail(List*& L)
{
    if (!L || !L->p_head || !L->p_tail)
        return;
    NODE* del, * cur = L->p_head;
    while (cur && cur->p_next != L->p_tail)
        cur = cur->p_next;
    if (cur && cur->p_next == L->p_tail)
    {
        cur->p_next = 0;
        delete L->p_tail;
        L->p_tail = cur;
    }
}

void RemoveAll(List*& L)
{
    if (!L || !L->p_head)
        return;
    NODE* del, * cur = L->p_head;
    while (cur)
    {
        del = cur;
        cur = cur->p_next;
        delete del;
    }
}

void PrintList(List* L)
{
    if (!L || !L->p_head)
    {
        cout << "List is empty" << endl;
        return;
    }
    NODE* cur = L->p_head;
    while (cur && cur->p_next)
    {
        cout << cur->key << "->";
        cur = cur->p_next;
    }
    cout << cur->key << endl;
}

int CountElements(List* L)
{
    if (!L || !L->p_head)
        return 0;
    int counter = 0;
    NODE* cur = L->p_head;
    while (cur)
    {
        ++counter;
        cur = cur->p_next;
    }
    return counter;
}

List* ReverseList(List* L)
{
    List* ReList = CreateList(CreateNode(L->p_head->key));

    NODE* cur = L->p_head->p_next;
    while (cur)
    {
        AddHead(ReList, cur->key);
        cur = cur->p_next;
    }
    return ReList;
}

void RemoveDuplicate(List*& L)
{
    NODE* cur1 = L->p_head, * prev = cur1, * cur2 = cur1->p_next;
    while (cur1 && cur1->p_next)
    {
        while (cur2)
        {
            if (cur1->key == cur2->key)
            {       
                prev->p_next = cur2->p_next;
                delete cur2;
                cur2 = prev->p_next;
                if (!cur2)
                    L->p_tail = prev;
            }
            else
            {
                prev = cur2;
                cur2 = cur2->p_next;
            }
        }
        if (cur1->p_next)
        {
            cur1 = cur1->p_next;
            prev = cur1;
            cur2 = prev->p_next;
        }
        else
            break;
    }
    return;
}

bool RemoveElement(List*& L, int key)
{
    if (!L || !L->p_head)
        return false;
    bool check = false;
    NODE* cur, * del;
    while (L->p_head->key == key)
    {
        RemoveHead(L);
    }
    cur = L->p_head;
    while (cur && cur->p_next)
    {
        if (cur->p_next->key == key)
        {
            if (cur->p_next == L->p_tail)
                RemoveTail(L);
            else
            {
                del = cur->p_next;
                cur->p_next = del->p_next;
                delete del;
            }
        }
        else cur = cur->p_next;
    }
    return check;
}
