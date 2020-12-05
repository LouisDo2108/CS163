#ifndef _Header_H_
#define _Header_H_

#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

struct NODE
{
    int key, height;
    NODE *p_left, *p_right;
};

NODE *CreateNode(int data);

bool Search(NODE *p_root, int x);

int getHeight(NODE *p_root);

int getBalance(NODE *p_root);

NODE *leftRotation(NODE *&p_root);

NODE *rightRotation(NODE *&p_root);

NODE *InsertNode(NODE *&p_root, int x);

void Insert(NODE *&p_root, int x);

NODE *getSuccessor(NODE *p_root);

NODE *RemoveNode(NODE *&p_root, int x);

void Remove(NODE *&p_root, int x);

void NLR(NODE *p_root);

void LNR(NODE *p_root);

void LRN(NODE *p_root);

void LRN(NODE *p_root);

void LevelOrder(NODE *p_root);

bool isAVL(NODE *p_root);

void deleteTree(NODE *&p_root);

#endif
