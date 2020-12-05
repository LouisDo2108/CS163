#ifndef Header_H_
#define Header_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

void MatrixToList(ifstream &fi, string path);
void ListToMatrix(ifstream &fi, string path);
void displayMatrix(int **a, int v);
int **createMatrix(int v);
int **readMatrix(ifstream &fi, string path, int &v);
void deleteMatrix(int **&a, int v);
int edges(int **a, int size);
int vertices(int **a, int size);
bool isolatedVertices(int **a, int v);
bool leafVertices(int **a, int v);
bool isCompleteGraph(int **a, int v);
bool isCircularGraph(int **a, int v, int p_vertex, int cur_vertex, int visited_count, vector<bool> &visited);
bool isBigraph(int **a, int v, int *color);
bool isCompleteBigraph(int **a, int v, int *color);
string graphType(int **a, int v);
void graphInfo(int **a, int v);
int traversalUtil(int **a, int v, int root, vector<bool> &visited);
void dfs(int **a, int v, int root = 0);
void bfs(int **a, int v, int root = 0);
void complementGraph(int **a, int v);
int connectedComponents(int **a, int v, int visited_count, vector<bool> &visited);
void cutVertices(int **a, int v, int connected_components);
void bridgeEdges(int **a, int v, int connected_components);
#endif
