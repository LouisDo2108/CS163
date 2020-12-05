#ifndef _Header_H_
#define _Header_H_

struct NODE
{
    int key;
    NODE *pNext;
};

struct Stack
{
    NODE *head = nullptr;
};

struct Queue
{
    NODE *head = nullptr, *tail = nullptr;
};

void initStack(Stack &s, int k);
void push(Stack &s, int k);
int pop(Stack &s);
bool isEmpty(Stack &s);
int countStack(Stack &s);

void initQueue(Queue &q, int k);
void enqueue(Queue &q, int k);
int dequeue(Queue &q);
bool isEmptyQueue(Queue &q);
int countQueue(Queue &q);

#endif