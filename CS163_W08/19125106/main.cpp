#include "header.h"

int main()
{
    string adjMatrix = "graph1.txt";
    string adjList = "graph2.txt";
    ifstream fi;
    ofstream fo;
    int v, root = 0, c = -1;
    int **graph = readMatrix(fi, adjMatrix, v);
    vector<bool> visited(v, false);

    int choice;

    while (1)
    {
        cout << "1. Adjacency matrix to adjacency list" << endl;
        cout << "2. Adjacency list to adjacency matrix" << endl;
        cout << "3. Graph's information" << endl;
        cout << "4. Complement graph" << endl;
        cout << "5. BFS" << endl;
        cout << "6. DFS" << endl;
        cout << "7. Number of connnected components" << endl;
        cout << "8. Cut vertices" << endl;
        cout << "9. Bridge edges" << endl;
        cout << "Enter the choice or 0 to exit: ";
        cout << "By default, we will use the adjacency matrix to generate information" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Reading from graph1.txt:" << endl;
            MatrixToList(fi, adjMatrix);
            break;
        }
        case 2:
        {
            cout << "Reading from graph2.txt:" << endl;
            ListToMatrix(fi, adjList);
            break;
        }
        case 3:
        {
            graphInfo(graph, v);
            break;
        }
        case 4:
        {
            complementGraph(graph, v);
            break;
        }
        case 5:
        {
            cout << "Enter the root: ";
            cin >> root;
            cout << "BFS: ";
            bfs(graph, v, root);
            break;
        }
        case 6:
        {
            cout << "Enter the root: ";
            cin >> root;
            cout << "DFS: ";
            dfs(graph, v, root);
            break;
        }
        case 7:
        {
            c = connectedComponents(graph, v, 0, visited);
            cout << "Number of connected components: ";
            cout << c << endl;
            fill(visited.begin(), visited.end(), false);
            break;
        }
        case 8:
        {
            cout << "Cut vertices: ";
            if (c == -1)
            {
                c = connectedComponents(graph, v, 0, visited);
                fill(visited.begin(), visited.end(), false);
            }
            cutVertices(graph, v, c);
            break;
        }
        case 9:
        {
            cout << "Bridge edges: ";
            if (c == -1)
            {
                c = connectedComponents(graph, v, 0, visited);
                fill(visited.begin(), visited.end(), false);
            }
            bridgeEdges(graph, v, c);
            break;
        }
        default:
        {
            deleteMatrix(graph, v);
            return 0;
        }
        }
        cout << endl;
    }
}