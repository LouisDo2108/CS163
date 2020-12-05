#include "header.h"

NODE *CreateNode(int data)
{
    NODE *temp = new NODE;
    temp->key = data;
    temp->p_left = temp->p_right = nullptr;
    return temp;
}

void NLR(NODE *p_root)
{
    if (p_root)
    {
        cout << p_root->key << "->";
        NLR(p_root->p_left);
        NLR(p_root->p_right);
    }
}

void LNR(NODE *p_root)
{
    if (p_root)
    {
        LNR(p_root->p_left);
        cout << p_root->key << "->";
        LNR(p_root->p_right);
    }
}

void LRN(NODE *p_root)
{
    if (p_root)
    {
        LRN(p_root->p_left);
        LRN(p_root->p_right);
        cout << p_root->key << "->";
    }
}

void printLevel(NODE *p_root, int level)
{
    if (!p_root)
        return;
    if (level == 0)
        cout << p_root->key << "->";
    else if (level > 0)
    {
        printLevel(p_root->p_left, level - 1);
        printLevel(p_root->p_right, level - 1);
    }
}

void LevelOrder(NODE *p_root)
{
    int h = Height(p_root);
    for (int i = 0; i <= h; ++i)
        printLevel(p_root, i);
}

NODE *Search(NODE *p_root, int x)
{
    if (!p_root)
        return nullptr;
    if (x > p_root->key)
        return Search(p_root->p_right, x);
    else if (x < p_root->key)
        return Search(p_root->p_left, x);
    return p_root;
}

void Insert(NODE *&p_root, int x)
{
    if (!p_root)
        p_root = CreateNode(x);
    else if (x > p_root->key)
        return Insert(p_root->p_right, x);
    else if (x < p_root->key)
        return Insert(p_root->p_left, x);
}

void Remove(NODE *&p_root, int x)
{
    if (!p_root)
        return;
    else if (x > p_root->key)
        Remove(p_root->p_right, x);
    else if (x < p_root->key)
        Remove(p_root->p_left, x);
    else
    {
        NODE *del = p_root;
        if (!p_root->p_left)
        {
            p_root = p_root->p_right;
            delete del;
        }
        else if (!p_root->p_right)
        {
            p_root = p_root->p_left;
            delete del;
        }
        else
        {
            //Find successor
            NODE *successor = p_root->p_right;
            while (successor && successor->p_left)
                successor = successor->p_left;

            p_root->key = successor->key;
            Remove(p_root->p_right, p_root->key);
        }
    }
}

int Height(NODE *p_root)
{
    if (!p_root)
        return -1;
    return max(Height(p_root->p_left), Height(p_root->p_right)) + 1;
}

int CountNode(NODE *p_root)
{
    if (!p_root)
        return 0;
    int count = 1;
    if (p_root->p_left)
        count += CountNode(p_root->p_left);
    if (p_root->p_right)
        count += CountNode(p_root->p_right);
    return count;
}

int Level(NODE *p_root, NODE *p)
{
    if (!p || !p_root)
        return -1;
    if (p_root->key > p->key)
        return 1 + Level(p_root->p_left, p);
    if (p_root->key < p->key)
        return 1 + Level(p_root->p_right, p);
    return 1;
}

int CountLeaf(NODE *p_root)
{
    static int count = 0;
    if (!p_root)
        return 0;
    if (p_root->p_left)
        CountLeaf(p_root->p_left);
    if (!p_root->p_left && !p_root->p_right)
        ++count;
    if (p_root->p_right)
        CountLeaf(p_root->p_right);
    return count;
}

int CountLess(NODE *p_root, int x)
{
    if (!p_root)
        return 0;

    if (x > p_root->key)
        return 1 + CountLess(p_root->p_left, x) + CountLess(p_root->p_right, x);
    return CountLess(p_root->p_left, x) + CountLess(p_root->p_right, x);
}

int CountGreater(NODE *p_root, int x)
{
    if (!p_root)
        return 0;

    if (x < p_root->key)
        return 1 + CountGreater(p_root->p_left, x) + CountGreater(p_root->p_right, x);
    return CountGreater(p_root->p_left, x) + CountGreater(p_root->p_right, x);
}

bool IsBST(NODE *p_root)
{
    static NODE *prev = nullptr;

    if (p_root)
    {
        if (!IsBST(p_root->p_left))
            return false;

        if (prev && prev->key >= p_root->key)
            return false;

        prev = p_root;
        return IsBST(p_root->p_right);
    }
    return true;
}

void deleteTree(NODE *&p_root)
{
    if (!p_root)
        return;
    deleteTree(p_root->p_left);
    deleteTree(p_root->p_right);

    delete p_root;
    p_root = nullptr;
}