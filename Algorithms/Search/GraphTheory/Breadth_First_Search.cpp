#include <bits/stdc++.h>

using namespace std;

class Graph{

public:
  Graph(int v);
  void addEdge(int v, int w);
  void BFS(int value);


private:

  int V;
  list<int> *adj;

};

  Graph::Graph(int v){
    this->V = v;
    adj = new list<int>[v];
  }

  void Graph::addEdge(int v, int w){
      adj[v].push_back(w);
  }
  
  void Graph::BFS(int st){
      bool *visited = new bool[V];
  
    for(int i = 0; i < V; i ++)
        visited[i] = false;

    list<int> queue;

    visited[st] = true;
    queue.push_back(st);

    list<int>::iterator i;

    while(!queue.empty()){

        st = queue.front();

        cout << st << " ";

        queue.pop_front();


        for(i = adj[st].begin(); i != adj[st].end(); i ++){
            if(!visited[*i]){

                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }


  }
