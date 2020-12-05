#ifndef _Header_H_
#define _Header_H_

#include <iostream>
#include <string>

using namespace std;

typedef struct node* ref;

struct node
{
    int key;
    char op;
    ref next;
};

struct Stack
{
    ref head;
};

struct Queue
{
    ref head, tail;
};

void enqueue(Queue& q, int k);
int dequeue(Queue& q, int k);
bool isEmptyQ(Queue q);
void JosephusProblem(Queue& q, int n, int M);

void push(Stack& s, char op);
char pop(Stack& s);
bool isEmptyS(Stack s);
void PolishNotation(Stack& s, string exp);
int Priority(char c);

ref getNodeK(int k);
ref getNodeC(char c);
void deleteAll(ref& head);

#endif
