#include "header.h"

void MatrixToList(ifstream &fi, string path)
{
    int v, temp;
    string output = "";

    fi.open(path, ios::in);
    if (fi.is_open())
    {
        fi >> v;
        cout << v << endl;
        for (int i = 0; i < v; ++i)
        {
            for (int j = 0; j < v; ++j)
            {
                fi >> temp;
                if (temp == 1)
                    output += to_string(j);
            }

            cout << output.length() << " ";

            for (int k = 0; k < output.length(); ++k)
                cout << output[k] << " ";
            cout << endl;

            output = "";
        }
    }
    else
        cout << "Failed to open the input file" << endl;
    fi.close();
}

void ListToMatrix(ifstream &fi, string path)
{
    int v, vertices, temp, count = 0;

    fi.open(path, ios::in);
    if (fi.is_open())
    {
        fi >> v;
        cout << v << endl;

        for (int i = 0; i < v; ++i)
        {
            fi >> vertices; //Number of edges connects to this vertex

            for (int j = 0; j < vertices; ++j)
            {
                fi >> temp;
                while (count < temp)
                {
                    cout << 0 << " "; //Trailing zeros
                    ++count;
                }
                cout << 1 << " ";
                ++count;
            }

            while (count < v)
            {
                cout << 0 << " "; //Trailing zeros
                ++count;
            }

            cout << endl;
            count = 0;
        }
    }
    else
        cout << "Failed to open the input file" << endl;
    fi.close();
}

void displayMatrix(int **a, int v)
{
    for (int i = 0; i < v; ++i)
    {
        for (int j = 0; j < v; ++j)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

int **createMatrix(int v)
{
    int **temp;
    temp = new int *[v];
    for (int i = 0; i < v; ++i)
        temp[i] = new int[v];
    return temp;
}

int **readMatrix(ifstream &fi, string path, int &v)
{
    int **temp;

    fi.open(path, ios::in);
    if (fi.is_open())
    {
        fi >> v; //Read the size nxn of the matrix

        temp = createMatrix(v);
        for (int i = 0; i < v; ++i)
            for (int j = 0; j < v; ++j)
                fi >> temp[i][j];
    }
    else
    {
        cout << "Failed to open the input file" << endl;
        return nullptr;
    }
    fi.close();

    displayMatrix(temp, v);
    return temp;
}

void deleteMatrix(int **&a, int v)
{
    for (int i = 0; i < v; ++i)
        delete[] a[i];
    delete a;
}

int edges(int **a, int size)
{
    int count = 0;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (a[i][j])
                ++count;
        }
    }
    return (count / 2); //Undirected graph means the matrix is symmetric
}

int vertices(int **a, int size)
{
    return size;
}

bool isolatedVertices(int **a, int v)
{
    bool check = false;
    for (int i = 0; i < v; ++i)
    {
        for (int j = 0; j < v; ++j)
        {
            if (a[i][j])
                break;
            else if ((j - 1) == v) //If the whole row contains no 1 -> isolated vertex
            {
                check = true;
                cout << i << ", ";
            }
        }
    }
    return check;
}

bool leafVertices(int **a, int v)
{
    bool check = false;
    int count = 0;

    for (int i = 0; i < v; ++i)
    {
        for (int j = 0; j < v; ++j)
            if (a[i][j])
                ++count;

        if (count == 1) //Leaf vertex has 1 edge
        {
            cout << i << ", ";
            check = true;
        }
        count = 0;
    }
    return check;
}

bool isCompleteGraph(int **a, int v)
{
    for (int i = 0; i < v; ++i)
        for (int j = 0; j < v; ++j) //A vertex is connected to all other vertices except itself
            if (i != j && !a[i][j])
                return false;
    return true;
}

bool isCircularGraph(int **a, int v, int p_vertex, int cur_vertex, int visited_count, vector<bool> &visited)
{
    int i, j;

    if (visited_count < v) // If all vertices are not visited, continue
    {
        if (!visited[cur_vertex]) // A vertex can't be visited twice
        {
            for (i = 0; i < v; ++i)
            {
                if (i != p_vertex && a[cur_vertex][i] && a[i][cur_vertex]) //Must be bidirectional
                {
                    if (cur_vertex == i) // Self loop is prohibited
                        return false;
                    else
                    {
                        visited[cur_vertex] = true;
                        return isCircularGraph(a, v, cur_vertex, i, visited_count + 1, visited);
                    }
                }
            }
        }
        return false;
    }
    return true;
}

bool isBigraph(int **a, int v, int *color)
{
    queue<int> temp;
    temp.push(0);

    while (!temp.empty())
    {
        int output = temp.front();
        temp.pop();

        if (a[output][output])
            return false;

        for (int i = 0; i < v; ++i)
        {
            if (a[output][i])
            {
                if (color[i] == -1)
                {
                    temp.push(i);
                    color[i] = 1 - color[output];
                }
                else if (color[i] == color[output])
                    return false;
            }
        }
    }

    return true;
}

bool isCompleteBigraph(int **a, int v, int *color)
{
    for (int i = 0; i < v; ++i)
        for (int j = 0; j < v; ++j)
            if (i != j && color[i] != color[j] && !a[i][j])
                return false;
    return true;
}

string graphType(int **a, int v)
{
    if (isCompleteGraph(a, v))
        return "Complete Graph";

    vector<bool> visited(v, false);
    if (isCircularGraph(a, v, -1, 0, 0, visited))
        return "Circular Graph";

    int *color = new int[v];
    for (int i = 0; i < v; ++i)
        color[i] = -1;
    color[0] = 1;

    if (isBigraph(a, v, color))
    {
        if (isCompleteBigraph(a, v, color))
            return "Complete Bigraph";
        else
            return "Bigraph";
    }

    delete color;
    return "Normal graph";
}

void graphInfo(int **a, int v)
{
    int V, e;
    V = vertices(a, v);
    e = edges(a, v);

    cout << "Number of vertices: " << V << endl;
    cout << "Number of edges: " << e << endl;
    cout << "List of isolated vertices: ";
    if (!isolatedVertices(a, v))
        cout << "None";
    cout << endl;
    cout << "List of leaf vertices: ";
    if (!leafVertices(a, v))
        cout << "None";
    cout << endl;
    cout << graphType(a, v) << endl;
}

int traversalUtil(int **a, int v, int root, vector<bool> &visited)
{
    int i, j;

    for (i = root; i < v; ++i)
        for (j = 0; j < v; ++j)
            if (a[i][j])
            {
                visited[i] = true;
                return i;
            }

    if (!visited[i])
        for (i = 0; i < root; ++i)
            for (j = 0; j < v; ++j)
            {
                if (a[i][j])
                {
                    visited[i] = true;
                    return i;
                }
            }

    return -1;
}

void dfs(int **a, int v, int root)
{
    stack<int> temp;
    int output, i, j, src;
    vector<bool> visited(v, false);

    src = traversalUtil(a, v, root, visited);

    if (src >= 0)
        temp.push(src);

    while (!temp.empty())
    {
        output = temp.top();
        temp.pop();
        cout << output << " ";
        for (i = 0; i < v; ++i)
        {
            if (a[output][i] && !visited[i])
            {
                temp.push(i);
                visited[i] = true;
            }
        }
    }

    for (i = 0; i < v; ++i)
        if (!visited[i])
            cout << i << " ";
    cout << endl;
}

void bfs(int **a, int v, int root)
{
    queue<int> temp;
    int output, i, j, src;
    vector<bool> visited(v, false);

    src = traversalUtil(a, v, root, visited);

    if (src >= 0)
        temp.push(src);

    while (!temp.empty())
    {
        output = temp.front();
        temp.pop();
        cout << output << " ";
        for (int i = 0; i < v; ++i)
        {
            if (a[output][i] && !visited[i])
            {
                temp.push(i);
                visited[i] = true;
            }
        }
    }

    for (i = 0; i < v; ++i)
        if (!visited[i])
            cout << i << " ";
    cout << endl;
}

void complementGraph(int **a, int v)
{
    for (int i = 0; i < v; ++i)
    {
        for (int j = 0; j < v; ++j)
        {
            if (a[i][j] || i == j)
                cout << 0 << " ";
            else
                cout << 1 << " ";
        }
        cout << endl;
    }
}

int connectedComponents(int **a, int v, int visited_count, vector<bool> &visited)
{
    if (visited_count >= v)
        return 0;

    stack<int> temp;
    int output, i, j, count = 0;

    for (i = 0; i < v; ++i) //Search for a non isolated vertex to be the root
    {
        if (!visited[i])
        {
            for (j = 0; j < v; ++j)
            {
                if (a[i][j])
                {
                    temp.push(i);
                    visited[i] = true;
                    break;
                }
            }
            if (visited[i])
                break;
            else if (j >= v)
            {
                visited[i] = true;
                return 1 + connectedComponents(a, v, visited_count + 1, visited); //The current vertex is isolated
            }
        }
    }

    while (!temp.empty()) //dfs the whole connnected component
    {
        output = temp.top();
        temp.pop();
        ++count;
        for (i = 0; i < v; ++i)
        {
            if (a[output][i] && !visited[i])
            {
                temp.push(i);
                visited[i] = true;
            }
        }
    }

    return 1 + connectedComponents(a, v, visited_count + count, visited);
}

void cutVertices(int **a, int v, int connected_components)
{
    queue<int> temp;
    vector<bool> visited(v, false);
    vector<bool> visited_comp(v, false);
    vector<bool> cut(v, false);
    int output, i, j, src;
    int **copy = createMatrix(v);
    bool check = true;

    for (i = 0; i < v; ++i)
        for (j = 0; j < v; ++j)
            copy[i][j] = a[i][j];

    src = traversalUtil(a, v, 0, visited);

    if (src >= 0)
        temp.push(src);

    while (!temp.empty())
    {
        output = temp.front();
        temp.pop();

        for (i = 0; i < v; ++i)
        {
            if (a[output][i])
            {
                if (!visited[i])
                {
                    temp.push(i);
                    visited[i] = true;
                }
                copy[output][i] = copy[i][output] = 0;
            }
        }

        j = connectedComponents(copy, v, 0, visited_comp);

        if ((j - 1) > connected_components)
            cut[output] = true;

        fill(visited_comp.begin(), visited_comp.end(), false);

        for (i = 0; i < v; ++i)
            if (a[output][i])
                copy[output][i] = copy[i][output] = 1;
    }

    for (i = 0; i < v; ++i)
    {
        if (cut[i])
        {
            check = false;
            cout << i << " ";
        }
    }

    if (check)
        cout << "None";
    cout << endl;

    deleteMatrix(copy, v);
}

void bridgeEdges(int **a, int v, int connected_components)
{
    int i, j, x;
    int **copy = createMatrix(v);
    int **check = createMatrix(v);
    vector<bool> visited(v, false);
    bool r = true;

    for (i = 0; i < v; ++i)
        for (j = 0; j < v; ++j)
        {
            copy[i][j] = a[i][j];
            check[i][j] = a[i][j];
        }

    for (i = 0; i < v; ++i)
    {
        for (j = 0; j < v; ++j)
        {
            if (a[i][j] && check[i][j] && check[j][i])
            {
                copy[i][j] = copy[j][i] = 0;

                x = connectedComponents(copy, v, 0, visited);
                if (x > connected_components)
                {
                    cout << "[" << i << ", " << j << "]; ";
                    r = false;
                }

                fill(visited.begin(), visited.end(), false);
                copy[i][j] = copy[i][j] = copy[j][i] = 1;
                check[i][j] = check[j][i] = 0;
            }
        }
    }
    if (r)
        cout << "None";
    cout << endl;
    deleteMatrix(copy, v);
    deleteMatrix(check, v);
}
