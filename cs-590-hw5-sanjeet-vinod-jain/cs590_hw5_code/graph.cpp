#include <iostream>
#include <set>
#include <queue>
#include "graph.h"
using namespace std;
Graph::Graph(int nodes)
{
    this->nodes = nodes;
    this->matrix = new int *[nodes];

    for (int i = 0; i < nodes; i++)
    {
        (this->matrix)[i] = new int[nodes];

        for (int j = 0; j < nodes; j++)
        {
            (this->matrix)[i][j] = 0;
        }
    }
}

Graph::~Graph()
{
    for (int i = 0; i < this->nodes; i++)
    {
        delete[] (this->matrix)[i];
    }
    delete[] this->matrix;
}

Graph::Graph(int **matrix, int nodes)
{
    this->nodes = nodes;
    this->matrix = new int *[nodes];

    for (int i = 0; i < nodes; i++)
    {
        (this->matrix)[i] = new int[nodes];

        for (int j = 0; j < nodes; j++)
        {
            (this->matrix)[i][j] = matrix[i][j];
        }
    }
}

bool Graph::set_edge(int i, int j, int edge)
{
    if (i < this->nodes && j < this->nodes && i >= 0 && j >= 0)
    {
        (this->matrix)[i][j] = edge;
        return true;
    }

    return false;
}

void Graph::dfs()
{
    set<int> *visited = new set<int>;
    int head = 0;
    dfs(head, visited);
    for (int i = 0; i < nodes; i++)
    {
        if (visited->count(i) == 0)
            dfs(i, visited);
    }
    delete visited;
}
void Graph::dfs(int head, set<int> *visited)
{
    cout << "  " << head << " ";
    visited->insert(head);
    for (int i = 0; i < nodes; i++)
    {
        if (matrix[head][i] != 0 && visited->count(i) == 0)
        {
            dfs(i, visited);
        }
    }
}
void Graph::bfs(int head)
{
    set<int> *visited = new set<int>;
    bfs(head, visited);
    delete visited;
}
void Graph::bfs(int head, set<int> *visited)
{
    visited = new set<int>;
    queue<int> queueNodes;
    visited->insert(head);
    queueNodes.push(head);

    while (!queueNodes.empty())
    {
        int queueElement = queueNodes.front();
        cout << queueElement << " ";
        queueNodes.pop();

        for (int i = 0; i < nodes; i++)
        {
            if (matrix[queueElement][i] > 0 && visited->count(i) == 0)
            {
                visited->insert(i);
                queueNodes.push(i);
            }
        }
    }
    delete visited;
}
