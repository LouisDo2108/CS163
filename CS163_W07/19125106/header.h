#ifndef _Header_H_
#define _Header_H_

#include <iostream>

using namespace std;

struct NODE
{
    int key;
    NODE *p_left;
    NODE *p_right;
};

NODE *CreateNode(int data);
void NLR(NODE *p_root);
void LNR(NODE *p_root);
void LRN(NODE *p_root);
void printLevel(NODE *p_root, int level);
void LevelOrder(NODE *p_root);
NODE *Search(NODE *p_root, int x);
void Insert(NODE *&p_root, int x);
void Remove(NODE *&p_root, int x);
int Height(NODE *p_root);
int CountNode(NODE *p_root);
int Level(NODE *p_root, NODE *p);
int CountLeaf(NODE *p_root);
int CountLess(NODE *p_root, int x);
int CountGreater(NODE *p_root, int x);
bool IsBST(NODE *p_root);
void deleteTree(NODE *&p_root);
NODE *findPre(NODE *p_root, int x);

#endif