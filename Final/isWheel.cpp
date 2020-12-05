#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node
{
    int key;
    node *left;
    node *right;
};

node *createNode(int k)
{
    node *temp = new node;
    temp->key = k;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void insertNode(node *&root, int k)
{
    if (root == NULL)
        root = createNode(k);
    else if (k < root->key)
        return insertNode(root->left, k);
    else if (k > root->key)
        return insertNode(root->right, k);
}

void NLR(node *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        NLR(root->left);
        NLR(root->right);
    }
}

int sumNode(node *root)
{
    if (root == NULL)
        return 0;

    int s = 0;
    node *temp;
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp && temp->key % 2 == 0)
            s += temp->key;

        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
    }
    return s;
}

void deleteTree(node *&root)
{
    if (root != NULL)
    {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root = NULL;
    }
}

bool isWheel(std::vector<std::vector<bool>> adj)
{
    int n = adj.size(), i, j, root_vertex, count = 0;
    bool check = true;
    vector<bool> visited(n, false);

    //Check for the root vertex
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            if (i == j && adj[i][j]) //Self loop
                return false;
            if (i != j && !adj[i][j]) //Missing edges
                check = false;
        }
        if (j >= n && check)
        {
            visited[i] = true;
            root_vertex = i;
            break;
        }
        check = true;
    }

    if (!check)
        return false;

    for (i = 0; i < root_vertex; ++i)
    {
        if (!visited[i])
        {
            visited[i] = true;
            count = 0;
            for (j = 0; j < n; ++j)
            {
                if ((i == j && adj[i][j]) || count >= 2)
                    return false;
                else if (i != j)
                {
                    if (adj[i][j] && !adj[j][i])
                        return false;
                    if (!adj[i][j] && adj[j][i])
                        return false;
                    if (!adj[i][j])
                        ++count;
                }
            }
        }
        else
            return false;
    }
    // if (visited[i] || !adj[i][root_vertex])
    // 	return false;
    // else
    // 	visited[i] = true;
    // for (j = 0; j < n; ++j)
    // {
    // 	if (i == j && adj[i][j])
    // 		return false;
    // 	else if (i != j)
    // 	{
    // 		if (adj[i][j] && !adj[j][i])
    // 			return false;
    // 		if (!adj[i][j] && adj[j][i])
    // 			return false;
    // 		if (count > 1)
    // 			return false;
    // 		if (!adj[i][j])
    // 			++count;
    // 	}
    // }
    // count = 0;

    for (i = root_vertex + 1; i < n; ++i)
    {
        if (!visited[i])
        {
            visited[i] = true;
            count = 0;
            for (j = 0; j < n; ++j)
            {
                if ((i == j && adj[i][j]) || count >= 2)
                    return false;
                else if (i != j)
                {
                    if (adj[i][j] && !adj[j][i])
                        return false;
                    if (!adj[i][j] && adj[j][i])
                        return false;
                    if (!adj[i][j])
                        ++count;
                }
            }
        }
        else
            return false;
    }
    // 	if (visited[i] || !adj[i][root_vertex])
    // 		return false;
    // 	else
    // 		visited[i] = true;
    // 	for (j = 0; j < n; ++j)
    // 	{
    // 		if (i == j && adj[i][j])
    // 			return false;
    // 		else if (i != j)
    // 		{
    // 			if (adj[i][j] && !adj[j][i])
    // 				return false;
    // 			if (!adj[i][j] && adj[j][i])
    // 				return false;
    // 			if (count > 1)
    // 				return false;
    // 			if (!adj[i][j])
    // 				++count;
    // 		}
    // 		cout << "j : " << j << endl;
    // 	}
    // 	count = 0;
    // }
    return true;
}

int main()
{
    // int choice, key;
    // node *root = NULL;
    // while (1)
    // {
    // 	cout << "1. Insert node bst" << endl;
    // 	cout << "2. NLR" << endl;
    // 	cout << "3. Sum of even node" << endl;
    // 	cout << "Enter a choice or 0 to exit" << endl;

    // 	cin >> choice;

    // 	switch (choice)
    // 	{
    // 	case 1:
    // 	{
    // 		cout << "Enter the key: ";
    // 		cin >> key;
    // 		insertNode(root, key);
    // 		break;
    // 	}
    // 	case 2:
    // 	{
    // 		NLR(root);
    // 		cout << endl;
    // 		break;
    // 	}
    // 	case 3:
    // 	{
    // 		cout << sumNode(root) << endl;
    // 		break;
    // 	}
    // 	default:
    // 	{
    // 		deleteTree(root);
    // 		return 0;
    // 	}
    // 	}
    // }

    vector<vector<bool>> adj;
    vector<bool> adj1 = {0, 1, 1, 1, 1};
    vector<bool> adj2 = {1, 0, 1, 0, 1};
    vector<bool> adj3 = {1, 1, 0, 1, 0};
    vector<bool> adj4 = {1, 0, 1, 0, 1};
    vector<bool> adj5 = {1, 1, 0, 1, 0};
    adj = {adj1, adj2, adj3, adj4, adj5};
    for (int i = 0; i < adj.size(); ++i)
    {
        for (int j = 0; j < adj.size(); ++j)
            cout << adj[i][j] << " ";
        cout << endl;
    }
    if (isWheel(adj))
        cout << "True";
    else
        cout << "False";
    return 0;
}
