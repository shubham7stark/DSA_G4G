#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Edge
{
int src, dest, weight;
};

struct Graph
{
int V, E;
struct Edge* edge;
};

struct Graph* createGraph(int V, int E)
{
struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph) );
graph->V = V;
graph->E = E;

graph->edge = (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );

return graph;
}
struct subset
{
int parent;
int rank;
};


int find(subset s[], int k){
if(s[k].parent != k)
s[k].parent = find(s, s[k].parent);

return s[k].parent;	
}


void Union(subset s[], int x, int y){

int xset = find(s,x);
int yset = find(s,y);

if(s[xset].rank < s[yset].rank){
s[xset].parent = yset;
}else if(s[xset].rank > s[yset].rank){
s[yset].parent = xset;
}else{
s[yset].parent = xset;
s[xset].rank++;
}

}

int myComp(const void* a, const void* b)
{
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->weight > b1->weight;
}

void kruskalMST(Graph* graph){

int V = graph->V;

struct Edge result[V];
int e=0, i=0;

qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);

struct subset* subsets = (struct subset*)malloc(V*sizeof(struct subset));

for(int i = 0; i < V; i++){
subsets[i].parent = i;
subsets[i].rank = 0;
}

while (e < V - 1)
{
struct Edge next_edge = graph->edge[i++];

int x = find(subsets, next_edge.src);
int y = find(subsets, next_edge.dest);

if (x != y)
{
result[e++] = next_edge;
Union(subsets, x, y);
}
}

 printf("Following are the edges in the constructed MST\n");
    for (i = 0; i < e; ++i)
        printf("%d -- %d == %d\n", result[i].src, result[i].dest,
                                                   result[i].weight);
    return;
    
}


int main()
{
/* Let us create following weighted graph
10
0--------1
| \ |
6| 5\ |15
| \ |
2--------3
4 */
int V = 4; // Number of vertices in graph
int E = 5; // Number of edges in graph
struct Graph* graph = createGraph(V, E);


// add edge 0-1
graph->edge[0].src = 0;
graph->edge[0].dest = 1;
graph->edge[0].weight = 10;

// add edge 0-2
graph->edge[1].src = 0;
graph->edge[1].dest = 2;
graph->edge[1].weight = 6;

// add edge 0-3
graph->edge[2].src = 0;
graph->edge[2].dest = 3;
graph->edge[2].weight = 5;

// add edge 1-3
graph->edge[3].src = 1;
graph->edge[3].dest = 3;
graph->edge[3].weight = 15;

// add edge 2-3
graph->edge[4].src = 2;
graph->edge[4].dest = 3;
graph->edge[4].weight = 4;

kruskalMST(graph);

return 0;
}
