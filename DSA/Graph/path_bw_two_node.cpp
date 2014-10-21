#include<iostream>
#include <list>
 
using namespace std;
 
// This class represents a directed graph using adjacency list representation
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
public:
    Graph(int V);  // Constructor
    void addEdge(int v, int w); // function to add an edge to graph
    bool isReachable(int s, int d);  // returns true if there is a path from s to d
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

bool Graph::isReachable(int src, int dest){
	
	if(src == dest) return true;
	
	bool* visited = new bool[V];
	for(int i =0; i <V;i++)
	visited[i] = false;
	
	list<int> queue;
	
	visited[src] = true;
	queue.push_back(src);
	
	list<int>::iterator i;
	
	while(!queue.empty())
	{
		src = queue.front();
		queue.pop_front();
		
		for (i = adj[src].begin(); i != adj[src].end(); ++i)
        {
            if (*i == dest)
                return true;
 
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
        
	}
	return false;
	
	
}


int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    int u = 1, v = 3;
    if(g.isReachable(u, v))
        cout<< "\n There is a path from " << u << " to " << v;
    else
        cout<< "\n There is no path from " << u << " to " << v;
 
    u = 3, v = 1;
    if(g.isReachable(u, v))
        cout<< "\n There is a path from " << u << " to " << v;
    else
        cout<< "\n There is no path from " << u << " to " << v;
 
    return 0;
}
