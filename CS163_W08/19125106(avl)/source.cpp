#include "header.h"

NODE *CreateNode(int data)
{
    NODE *temp = new NODE;
    temp->key = data;
    temp->height = 0;
    temp->p_left = temp->p_right = nullptr;
    return temp;
}

bool Search(NODE *p_root, int x)
{
    if (!p_root)
        return false;

    if (x < p_root->key)
        return Search(p_root->p_left, x);
    if (x > p_root->key)
        return Search(p_root->p_right, x);
    return true;
}

int getHeight(NODE *p_root)
{
    if (!p_root)
        return -1;
    return p_root->height;
}

int getBalance(NODE *p_root)
{
    if (!p_root)
        return 0;
    return getHeight(p_root->p_left) - getHeight(p_root->p_right);
}

NODE *leftRotation(NODE *&p_root)
{
    NODE *temp = p_root->p_right;
    p_root->p_right = temp->p_left;
    temp->p_left = p_root;

    p_root->height = max(getHeight(p_root->p_left), getHeight(p_root->p_right)) + 1;
    temp->height = max(getHeight(temp->p_left), getHeight(temp->p_right)) + 1;
    return temp;
}

NODE *rightRotation(NODE *&p_root)
{
    NODE *temp = p_root->p_left;
    p_root->p_left = temp->p_right;
    temp->p_right = p_root;

    p_root->height = max(getHeight(p_root->p_left), getHeight(p_root->p_right)) + 1;
    temp->height = max(getHeight(temp->p_left), getHeight(temp->p_right)) + 1;
    return temp;
}

NODE *InsertNode(NODE *&p_root, int x)
{
    if (!p_root)
        return CreateNode(x);
    else if (x < p_root->key)
        p_root->p_left = InsertNode(p_root->p_left, x);
    else if (x > p_root->key)
        p_root->p_right = InsertNode(p_root->p_right, x);

    p_root->height = max(getHeight(p_root->p_left), getHeight(p_root->p_right)) + 1;
    int balance = getBalance(p_root);

    //left left
    if (balance > 1)
    {
        if (x < p_root->p_left->key) //left left
            return rightRotation(p_root);
        else //left right
        {
            p_root->p_left = leftRotation(p_root->p_left);
            return rightRotation(p_root);
        }
    }
    else if (balance < -1)
    {
        if (x > p_root->p_right->key)
            return leftRotation(p_root); //right right
        else                             //right left
        {
            p_root->p_right = rightRotation(p_root->p_right);
            return leftRotation(p_root);
        }
    }

    return p_root;
}

void Insert(NODE *&p_root, int x)
{
    if (Search(p_root, x))
    {
        cout << "Node already exists" << endl;
        return;
    }
    p_root = InsertNode(p_root, x);
    cout << "Inserted successfully" << endl;
}

NODE *getSuccessor(NODE *p_root)
{
    if (p_root->p_right)
        return getSuccessor(p_root->p_right);
    return p_root;
}

NODE *RemoveNode(NODE *&p_root, int x)
{
    if (!p_root)
        return p_root;

    if (x < p_root->key)
        p_root->p_left = RemoveNode(p_root->p_left, x);
    else if (x > p_root->key)
        p_root->p_right = RemoveNode(p_root->p_right, x);
    else
    {
        if (!p_root->p_left || !p_root->p_right)
        {
            NODE *del = p_root->p_left ? p_root->p_left : p_root->p_right;

            if (!del)
            {
                del = p_root;
                p_root = nullptr;
            }
            else
            {
                *p_root = *del;
                del = p_root;
            }
            delete del;
        }
        else
        {
            NODE *successor = getSuccessor(p_root->p_left);
            p_root->key = successor->key;
            p_root->p_left = RemoveNode(p_root->p_left, p_root->key);
        }
    }

    if (!p_root)
        return p_root;

    p_root->height = max(getHeight(p_root->p_left), getHeight(p_root->p_right)) + 1;
    int balance = getBalance(p_root);

    //left left
    if (balance > 1 && getBalance(p_root->p_left) >= 0)
        return rightRotation(p_root);
    //right right
    else if (balance < -1 && getBalance(p_root->p_right) <= 0)
        return leftRotation(p_root);
    //left right
    else if (balance > 1 && getBalance(p_root->p_left) < 0)
    {
        p_root->p_left = leftRotation(p_root->p_left);
        return rightRotation(p_root);
    }
    //right left
    else if (balance < -1 && getBalance(p_root->p_right) > 0)
    {
        p_root->p_right = rightRotation(p_root->p_right);
        return leftRotation(p_root);
    }

    return p_root;
}

void Remove(NODE *&p_root, int x)
{
    if (Search(p_root, x))
    {
        p_root = RemoveNode(p_root, x);
        cout << "Removed successfully" << endl;
        return;
    }
    cout << "Node doesn't exist" << endl;
}

void NLR(NODE *p_root) //Pre order traversal
{
    if (p_root)
    {
        cout << p_root->key << "->";
        NLR(p_root->p_left);
        NLR(p_root->p_right);
    }
}

void LNR(NODE *p_root) // In order traversal
{
    if (p_root)
    {
        LNR(p_root->p_left);
        cout << p_root->key << "->";
        LNR(p_root->p_right);
    }
}

void LRN(NODE *p_root) //Post order traversal
{
    if (p_root)
    {
        LRN(p_root->p_left);
        LRN(p_root->p_right);
        cout << p_root->key << "->";
    }
}

void LevelOrder(NODE *p_root)
{
    if (!p_root)
        return;

    queue<NODE *> q;
    q.push(p_root);

    while (q.empty() == false)
    {
        NODE *temp = q.front();
        cout << temp->key << "->";
        q.pop();

        if (temp->p_left)
            q.push(temp->p_left);

        if (temp->p_right)
            q.push(temp->p_right);
    }
}

bool isAVL(NODE *p_root)
{
    static NODE *prev = nullptr;

    if (p_root)
    {
        if (!isAVL(p_root->p_left))
            return false;

        if ((prev && prev->key >= p_root->key) || (abs(getBalance(p_root)) > 1))
            return false;

        prev = p_root;

        return isAVL(p_root->p_right);
    }
    return true;
}

void deleteTree(NODE *&p_root)
{
    if (!!p_root)
        return;
    else
    {
        deleteTree(p_root->p_left);
        deleteTree(p_root->p_right);
        delete p_root;
        p_root = nullptr;
    }
}