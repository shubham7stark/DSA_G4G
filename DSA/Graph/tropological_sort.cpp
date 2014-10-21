#include<iostream>
#include <list>
#include <stack>
using namespace std;

// Class to represent a graph
class Graph
{
int V; // No. of vertices'

// Pointer to an array containing adjacency listsList
list<int> *adj;

// A function used by topologicalSort
void topologicalSortUtil(int v, bool* visited, stack<int> &Stack); public:
Graph(int V); // Constructor

// function to add an edge to graph
void addEdge(int v, int w);

// prints a Topological Sort of the complete graph
void topologicalSort();
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


void Graph:: topologicalSortUtil(int v, bool* visited, stack<int> &Stack){

visited[v] = true;
list<int>::iterator it;

for(it = adj[v].begin(); it != adj[v].end();++it){
if(!visited[*it])
topologicalSortUtil(*it,visited,Stack);
}

Stack.push(v);

} 

void Graph::topologicalSort(){
stack <int> Stack;
bool* visited = new bool[V];

for(int i =0; i< V;i++)
visited[i] = false;

for(int i =0;i<V;i++){
if(!visited[i]){
topologicalSortUtil(i, visited, Stack);
}
}

while(Stack.empty() == false){
cout<<Stack.top()<<" ";
Stack.pop();
}

}


// Driver program to test above functions
int main()
{
// Create a graph given in the above diagram
Graph g(6);
g.addEdge(5, 2);
g.addEdge(5, 0);
g.addEdge(4, 0);
g.addEdge(4, 1);
g.addEdge(2, 3);
g.addEdge(3, 1);

cout << "Following is a Topological Sort of the given graph \n";
g.topologicalSort();

return 0;
}


