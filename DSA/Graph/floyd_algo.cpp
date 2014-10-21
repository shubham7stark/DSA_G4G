#include <stdio.h>
#define INF 99999
#define V 4


void printSolution(int dist[][V])
{
    printf ("Following matrix shows the shortest distances"
            " between every pair of vertices \n");
    int i , j;
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf ("%7d", dist[i][j]);
        }
        printf("\n");
    }
}
 


void floydWarshell(int graph[][V]){
	
	int dist[V][V], i , j ,k;
	
	for(i = 0; i <V;i++){
	for(j =0; j <V; j++){
	  dist[i][j] = graph[i][j];
	}}

	for(i = 0; i <V;i++){
	for(j =0; j <V;j++){
	for(k = 0; k<V;k++){
       
       if(dist[j][i] + dist[i][k] < dist[j][k]){
          dist[j][k] = dist[j][i] + dist[i][k] ;
	}}}}
	
	  printSolution(dist);
}

// driver program to test above function
int main()
{
    /* Let us create the following weighted graph
            10
       (0)------->(3)
        |         /|\
      5 |          |
        |          | 1
       \|/         |
       (1)------->(2)
            3           */
    int graph[V][V] = { {0,   5,  INF, 10},
                        {INF, 0,   3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
                      };
 
    // Print the solution
    floydWarshell(graph);
    return 0;
}
