#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Graph
{
    public:
        Graph(int num_vtx) : num_vtx(num_vtx)
        {
            adj.resize(num_vtx);
            visited.resize(num_vtx, false);
        }

        void addEdge(int v, int w)
        {
            adj[v].push_back(w);
        }

        void DFS(int source);

    private:
        int num_vtx;
        vector<list<int>> adj;
        vector<bool> visited;
};

void Graph::DFS(int source)
{
    visited[source] = true;
    cout << source << " ";

    for(auto neighbor : adj[source]){
        if(!visited[neighbor])
        {
            DFS(neighbor);
        }
    }
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.DFS(2);
}