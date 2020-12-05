#ifndef _Header_H_
#define _Header_H_

#include <iostream>
using namespace std;

struct d_NODE
{
    int key;
    d_NODE *pNext;
    d_NODE *pPrev;
};

struct d_List
{
    d_NODE *pHead;
    d_NODE *pTail;
};

d_NODE *getNode(int k);
void init(d_List &l, int k);
void addFront(d_List &l, int k);
void addBefore(d_List &l, int k, int given);
void addAfter(d_List &l, int k, int given);
void addEnd(d_List &l, int k);
void removeFront(d_List &l);
void removeEnd(d_List &l);
void removeFirstValue(d_List &l, int given);

#endif