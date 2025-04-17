#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pathfinder.h"
#include "graph.h"

int *findPath(Graph *graph, int start, int end) {
    int n = graph->numNodes;
    double *dist = malloc(n * sizeof(double));
    int *prev = malloc(n * sizeof(int));
    int *visited = calloc(n, sizeof(int));
    int i;
    int j;
    int tempSize = 0;
    int cur = end;
    int *path = NULL;
    
    for (i = 0; i < n; i++) {
        dist[i] = INF;
        prev[i] = -1;
    }
    dist[start] = 0;
    for (i = 0; i < n; i++) {
        int u = -1;
        double min = 0; 
        for (j = 0; j < n; j++) {
            if (!visited[j] && dist[j] != INF) {
                if (u == -1 || dist[j] < min) {
                    u = j;
                    min = dist[j];
                }
            }
        }
        if (u == -1) {
            break;  
        }
        visited[u] = 1;
        
        for (j = 0; j < graph->numEdges; j++) {
            if (graph->edges[j].startN == u) {
                int v = graph->edges[j].endN;
                double modCost = Weight(graph->nodes[u], graph->nodes[v], graph->edges[j].weight);
                double newDist = dist[u] + modCost;
                if (dist[v] == INF) {
                    dist[v] = newDist;
                    prev[v] = u;
                } else if (newDist < dist[v]) {
                    dist[v] = newDist;
                    prev[v] = u;
                }
            }
        }
    }
    if (dist[end] == INF) {
        free(dist);
        free(prev);
        free(visited);
        return NULL;
    }

    while (cur != -1) {
        tempSize++;
        cur = prev[cur];
    }

    path = malloc((tempSize + 1) * sizeof(int));
    if (!path) {
        free(dist);
        free(prev);
        free(visited);
        return NULL;
    }
    
    cur = end;
    for (i = tempSize - 1; i >= 0; i--) {
        path[i] = cur;
        cur = prev[cur];
    }
    path[tempSize] = -1;
    
    free(dist);
    free(prev);
    free(visited);
    return path;
} 