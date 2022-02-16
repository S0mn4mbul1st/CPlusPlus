#include<iostream>
#include<list>
 
using namespace std;
 
class Graph
{
    int V;    
    list<int> *adj; 
    void DFSUtil(int v, bool visited[]); 
public:
    Graph(int V);  
    void addEdge(int v, int w); 
    void DFS(int v);  
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); 
}
 
void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    cout << v << " ";
 
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}
 
void Graph::DFS(int v)
{
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    DFSUtil(v, visited);
}
 
int main()
{
    Graph g();
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
 
    cout << "Following is Depth First Traversal \n";
    g.DFS(1);
 
    return 0;
}
