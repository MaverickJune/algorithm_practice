#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Graph
{
    public:
        Graph(int num_vtx);
        void addEdge(int v, int w);
        void BFS(int source);

    private:
        int num_vtx;
        vector<list<int>> adj;
};

Graph::Graph(int num_vtx)
{
    this->num_vtx = num_vtx;
    adj.resize(num_vtx);
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::BFS(int source)
{
    vector<bool> visited;
    visited.resize(num_vtx, false);

    list<int> queue;
    visited[source] = true;
    queue.push_back(source);

    while(!queue.empty()){
        int min_vtx = queue.front();
        cout << min_vtx << " ";
        queue.pop_front();

        for(auto adjacent : adj[min_vtx]){
            if(!visited[adjacent])
            {
                visited[adjacent] = true;
                queue.push_back(adjacent);
            }
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

    g.BFS(2);

}