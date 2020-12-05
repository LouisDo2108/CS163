#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

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
            fi >> vertices;

            for (int j = 0; j < vertices; ++j)
            {
                fi >> temp;
                while (count <= temp)
                {
                    if (count == temp)
                        cout << 1 << " ";
                    else
                        cout << 0 << " ";
                    ++count;
                }
            }

            while (count < v)
            {
                cout << 0 << " ";
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
        fi >> v;

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

void deleteMatrix(int **&matrix, int v)
{
    for (int i = 0; i < v; ++i)
        delete[] matrix[i];
    delete matrix;
}

int edges(int **matrix, int size)
{
    int count = 0;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (matrix[i][j])
                ++count;
        }
    }
    return (count / 2);
}

int vertices(int **matrix, int size)
{
    return size;
}

bool isolatedVertices(int **matrix, int size)
{
    bool check = false;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (matrix[i][j])
                break;
            else if (j == size - 1)
            {
                check = true;
                cout << i << ", ";
            }
        }
    }
    return check;
}

bool leafVertices(int **matrix, int v)
{
    bool check = false;
    int count = 0;

    for (int i = 0; i < v; ++i)
    {
        for (int j = 0; j < v; ++j)
        {
            if (matrix[i][j])
                ++count;
        }
        if (count == 1)
        {
            cout << i << ", ";
            check = true;
        }
        count = 0;
    }

    return check;
}

bool isCompleteGraph(int **matrix, int size)
{
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            if (i != j && !matrix[i][j])
                return false;
    return true;
}

bool isCircularGraph(int **matrix, int size, int previous_node, int current_node, int visited_count, vector<bool> &visited)
{
    int i, j;

    if (visited_count < size) // If all vertices are not visited, continue
    {
        if (!visited[current_node]) // A vertex can't be visited twice
        {
            for (i = 0; i < size; ++i)
            {
                if (i == previous_node)
                    continue;
                if (matrix[current_node][i] && matrix[i][current_node]) //Must be bidirectional
                {
                    if (current_node == i) // Self loop is prohibited
                        return false;
                    else
                    {
                        visited[current_node] = true;
                        return isCircularGraph(matrix, size, current_node, i, visited_count + 1, visited);
                    }
                }
            }
        }
        return false;
    }
    return true;
}

bool isBigraph(int **matrix, int size, int color[])
{
    queue<int> temp;
    temp.push(0);

    while (!temp.empty())
    {
        int output = temp.front();
        temp.pop();

        if (matrix[output][output])
            return false;

        for (int i = 0; i < size; ++i)
        {
            if (matrix[output][i])
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

bool isCompleteBigraph(int **matrix, int size, int color[])
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (i != j && color[i] != color[j] && !matrix[i][j])
                return false;
        }
    }
    return true;
}

string graphType(int **matrix, int size)
{
    if (isCompleteGraph(matrix, size))
        return "Complete Graph";

    vector<bool> visited(size, false);
    if (isCircularGraph(matrix, size, -1, 0, 0, visited))
        return "Circular Graph";

    int color[size];
    for (int i = 0; i < size; ++i)
        color[i] = -1;

    if (isBigraph(matrix, size, color))
    {
        if (isCompleteBigraph(matrix, size, color))
            return "Complete Bigraph";
        else
            return "Bigraph";
    }
    return "Normal graph";
}

void graphInfo(int **matrix, int size)
{
    int v, e;
    v = vertices(matrix, size);
    e = edges(matrix, size);

    cout << "Number of vertices: " << v << endl;
    cout << "Number of edges: " << e << endl;
    cout << "List of isolated vertices: ";
    if (!isolatedVertices(matrix, size))
        cout << "None";
    cout << endl;
    cout << "List of leaf vertices: ";
    if (!leafVertices(matrix, size))
        cout << "None";
    cout << endl;
    cout << graphType(matrix, size) << endl;
}

int traversalUtil(int **matrix, int v, int root, vector<bool> &visited)
{
    int i, j;

    for (i = root; i < v; ++i)
    {
        for (j = 0; j < v; ++j)
        {
            if (matrix[i][j])
            {
                visited[i] = true;
                return i;
            }
        }
    }

    if (!visited[i])
    {
        for (i = 0; i < root; ++i)
        {
            for (j = 0; j < v; ++j)
            {
                if (matrix[i][j])
                {
                    visited[i] = true;
                    return i;
                }
            }
        }
    }
    return -1;
}

void dfs(int **matrix, vector<bool> &visited, int v, int root = 0)
{
    stack<int> temp;
    int output, i, j, src;

    src = traversalUtil(matrix, v, root, visited);

    if (src >= 0)
        temp.push(src);

    while (!temp.empty())
    {
        output = temp.top();
        temp.pop();
        cout << output << " ";
        for (i = 0; i < v; ++i)
        {
            if (matrix[output][i] && !visited[i])
            {
                temp.push(i);
                visited[i] = true;
            }
        }
    }

    for (i = 0; i < v; ++i)
        if (!visited[i])
            cout << i << " ";
}

void bfs(int **matrix, vector<bool> &visited, int v, int root = 0)
{
    queue<int> temp;
    int output, i, j, src;

    src = traversalUtil(matrix, v, root, visited);

    if (src >= 0)
        temp.push(src);

    while (!temp.empty())
    {
        output = temp.front();
        temp.pop();
        cout << output << " ";
        for (int i = 0; i < v; ++i)
        {
            if (matrix[output][i] && !visited[i])
            {
                temp.push(i);
                visited[i] = true;
            }
        }
    }

    for (i = 0; i < v; ++i)
        if (!visited[i])
            cout << i << " ";
}

void complementGraph(int **matrix, int size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (matrix[i][j] || i == j)
                cout << 0 << " ";
            else
                cout << 1 << " ";
        }
        cout << endl;
    }
}

int connectedComponents(int **matrix, int size, int visited_count, vector<bool> &visited)
{
    if (visited_count >= size)
        return 0;

    stack<int> temp;
    int output, i, j, count = 0;

    for (i = 0; i < size; ++i)
    {
        if (!visited[i])
        {
            for (j = 0; j < size; ++j)
            {
                if (matrix[i][j])
                {
                    temp.push(i);
                    visited[i] = true;
                    break;
                }
            }
            if (visited[i])
                break;
            else if (j >= size)
            {
                visited[i] = true;
                return 1 + connectedComponents(matrix, size, visited_count + 1, visited);
            }
        }
    }

    while (!temp.empty())
    {
        output = temp.top();
        temp.pop();
        ++count;
        for (i = 0; i < size; ++i)
        {
            if (matrix[output][i] && !visited[i])
            {
                temp.push(i);
                visited[i] = true;
            }
        }
    }

    return 1 + connectedComponents(matrix, size, visited_count + count, visited);
}

void cutVertices(int **matrix, int v, int connected_components)
{
    queue<int> temp;
    int output, i, j, src;
    vector<bool> visited(v, false);
    vector<bool> visited_comp(v, false);
    vector<bool> cut(v, false);
    int **copy = createMatrix(v);

    src = traversalUtil(matrix, v, 0, visited);

    if (src >= 0)
        temp.push(src);

    while (!temp.empty())
    {
        for (i = 0; i < v; ++i)
            for (j = 0; j < v; ++j)
                copy[i][j] = matrix[i][j];

        output = temp.front();
        temp.pop();

        for (i = 0; i < v; ++i)
        {
            if (matrix[output][i])
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
            for (j = 0; j < v; ++j)
                copy[i][j] = matrix[i][j];
    }

    for (i = 0; i < v; ++i)
        if (cut[i])
            cout << i << " ";

    deleteMatrix(copy, v);
}

void bridgeEdges(int **matrix, int v, int connected_components)
{
    int i, j, x;
    int **copy = createMatrix(v);
    int **check = createMatrix(v);
    vector<bool> visited(v, false);

    for (i = 0; i < v; ++i)
        for (j = 0; j < v; ++j)
        {
            copy[i][j] = matrix[i][j];
            check[i][j] = matrix[i][j];
        }

    for (i = 0; i < v; ++i)
    {
        for (j = 0; j < v; ++j)
        {
            if (matrix[i][j] && check[i][j] && check[j][i])
            {
                copy[i][j] = copy[j][i] = 0;
                x = connectedComponents(copy, v, 0, visited);
                if (x > connected_components)
                    cout << "[" << i << ", " << j << "]; ";
                fill(visited.begin(), visited.end(), false);
                copy[i][j] = copy[i][j] = copy[j][i] = 1;
                check[i][j] = check[j][i] = 0;
            }
        }
    }
    deleteMatrix(copy, v);
    deleteMatrix(check, v);
}

int main()
{
    string adjMatrix = "E:\\HCMUS-FIT-APCS\\CS163\\CS163_W08\\graph1.txt";
    string adjList = "E:\\HCMUS-FIT-APCS\\CS163\\CS163_W08\\graph2.txt";
    ifstream fi;
    ofstream fo;

    int n, c;
    int **graph = readMatrix(fi, adjMatrix, n);
    graphInfo(graph, n);
    vector<bool> visited(n, false);
    cout << "DFS: ";
    dfs(graph, visited, n, 0);
    cout << endl;
    fill(visited.begin(), visited.end(), false);
    cout << "BFS: ";
    bfs(graph, visited, n, 0);
    cout << endl;
    fill(visited.begin(), visited.end(), false);
    c = connectedComponents(graph, n, 0, visited);
    cout << "Connected Components: ";
    cout << c << endl;
    cout << "Cut vertices: ";
    cutVertices(graph, n, c);
    cout << endl;
    cout << "Bridge edges: ";
    bridgeEdges(graph, n, c);
    deleteMatrix(graph, n);

    return 0;
}