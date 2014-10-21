#include <iostream>
#include<limits.h>
#include<list>

using namespace std;

class Graph
{
int V; // No. of vertices
list<int> *adj; // Pointer to an array containing adjacency lists
bool isCyclicUtil(int sv, bool* visited, int parent); // used by isCyclic() 
public:
Graph(int V); // Constructor
void addEdge(int v, int w); // to add an edge to graph
bool isCyclic(); // returns true if there is a cycle in this graph };
};

Graph::Graph(int V)
{
this->V = V;
adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
adj[v].push_back(w); // Add w to v’s list.
}


bool Graph:: isCyclicUtil(int s, bool* visited, int parent){ visited[s] = true;

list<int>::iterator it;

for(it= adj[s].begin();it !=adj[s].end();it++){

if(!visited[*it]){
if(isCyclicUtil(*it,visited,s))
return true;
}
else if(*it != parent)
return true;
}

return false;
}


bool Graph:: isCyclic(){
bool* visited = new bool[V];

for(int i =0;i<V;i++)
visited[i] = false;

for(int i =0;i<	V;i++)
if(!visited[i] && isCyclicUtil(i,visited,-1))
return true;

return false;

};



// Driver program to test above functions
int main()
{
Graph g1(5);
g1.addEdge(1, 0);
g1.addEdge(0, 2);
g1.addEdge(2, 0);
g1.addEdge(0, 3);
g1.addEdge(3, 4);
g1.isCyclic()? cout << "Graph contains cycle\n":
cout << "Graph doesn't contain cycle\n";

Graph g2(3);
g2.addEdge(0, 1);
g2.addEdge(1, 2);
g2.isCyclic()? cout << "Graph contains cycle\n":
cout << "Graph doesn't contain cycle\n";

return 0;
}
