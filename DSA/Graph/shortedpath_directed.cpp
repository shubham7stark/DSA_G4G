#include<iostream>
#include <list>
#include <stack>
#include <limits.h>
#define INF INT_MAX
using namespace std;
 
// Graph is represented using adjacency list. Every node of adjacency list 
// contains vertex number of the vertex to which edge connects. It also 
// contains weight of the edge
class AdjListNode
{
    int v;
    int weight;
public:
    AdjListNode(int _v, int _w)  { v = _v;  weight = _w;}
    int getV()       {  return v;  }
    int getWeight()  {  return weight; }
};
 
// Class to represent a graph using adjacency list representation
class Graph
{
    int V;    // No. of vertices'
 
    // Pointer to an array containing adjacency lists
    list<AdjListNode> *adj;
 
    // A function used by shortestPath
    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
public:
    Graph(int V);   // Constructor
 
    // function to add an edge to graph
    void addEdge(int u, int v, int weight);
 
    // Finds shortest paths from given source vertex
    void shortestPath(int s);
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<AdjListNode>[V];
}
 
void Graph::addEdge(int u, int v, int weight)
{
    AdjListNode node(v, weight);
    adj[u].push_back(node); // Add v to u's list
}
 
// A recursive function used by shortestPath. See below link for details
// http://www.geeksforgeeks.org/topological-sorting/
void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack)
{
    // Mark the current node as visited
    visited[v] = true;
 
    // Recur for all the vertices adjacent to this vertex
    list<AdjListNode>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        AdjListNode node = *i;
        if (!visited[node.getV()])
            topologicalSortUtil(node.getV(), visited, Stack);
    }
 
    // Push current vertex to stack which stores topological sort
    Stack.push(v);
}



void Graph::shortestPath(int s){
	
	stack<int> Stack;
	int dist[V];
	
	bool* visited = new bool[V];
	for(int i =0; i < V;i++)
	  visited[V] = 0;
	  
	for(int i = 0; i < V;i++)
	 if(!visited[i])
         topologicalSortUtil(i,visited,Stack);
  	
  	for(int i=0;i<V;i++)
      dist[i] = INF;
      
     dist[s] = 0;
	 
	 while(Stack.empty() == false){
	 	int u = Stack.top();
	 	Stack.pop();
	 	
	 	list<AdjListNode>:: iterator i;
	     if (dist[u] != INF)
        {
          for (i = adj[u].begin(); i != adj[u].end(); ++i)
             if (dist[i->getV()] > dist[u] + i->getWeight())
                dist[i->getV()] = dist[u] + i->getWeight();
        }
     }
	 
	 // Print the calculated shortest distances
    for (int i = 0; i < V; i++)
        (dist[i] == INF)? cout << "INF ": cout << dist[i] << " ";
} 

 
 
 int main()
{
    // Create a graph given in the above diagram.  Here vertex numbers are
    // 0, 1, 2, 3, 4, 5 with following mappings:
    // 0=r, 1=s, 2=t, 3=x, 4=y, 5=z
    Graph g(6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);
 
    int s = 1;
    cout << "Following are shortest distances from source " << s <<" \n";
    g.shortestPath(s);
 
    return 0;
}
