#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "pathfinder.h"

#define INF -1

typedef struct {
    int x;
    int y;
    double h;
    int v;
} Node;

typedef struct {
    int startN;
    int endN;
    double weight; 
} Edge;

typedef struct {
    int numNodes;
    int numEdges;   
    Node *nodes;
    Edge *edges;
} Graph;

double Weight(Node n1, Node n2, double c) {
    double hDiff = fabs(n1.h - n2.h); //absolute 
    double add = 0;
    if (hDiff > 0) {
        add = 1 - (c / hDiff);
    }
    return c + add;
}

int *findPath(Graph *graph, int start, int end) {
    int n = graph->numNodes;
    double *dist = malloc(n * sizeof(double));
    int *prev = malloc(n * sizeof(int));
    int *visited = calloc(n, sizeof(int));
    int i;
    int j;
    int tempSize = 0;
    int cur = end;
    int *path = malloc((tempSize + 1) * sizeof(int));
    
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

Graph *loadGraph(const char *filename) {

    int n1;
    int n2;
    double weight;
    int N;
    int M;

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error");
    }
    
    fscanf(file, "%d", &N);
    Graph *graph = malloc(sizeof(Graph));
    graph->numNodes = N;
    graph->nodes = malloc(N * sizeof(Node));
    
    for (int i = 0; i < N; i++) {
        fscanf(file, "%d %d %lf %d", &graph->nodes[i].x, &graph->nodes[i].y, &graph->nodes[i].h, &graph->nodes[i].v);
    }
    

    fscanf(file, "%d", &M);
    graph->numEdges = 2 * M;
    graph->edges = malloc(graph->numEdges * sizeof(Edge));
    

    for (int i = 0; i < M; i++) {
        fscanf(file, "%d %d %lf", &n1, &n2, &weight);
        graph->edges[2 * i].startN = n1;
        graph->edges[2 * i].endN = n2;
        graph->edges[2 * i].weight = weight;
        
        graph->edges[2 * i + 1].startN = n2;//drugat aposoka
        graph->edges[2 * i + 1].endN = n1;
        graph->edges[2 * i + 1].weight = weight;
    }
    
    fclose(file);
    return graph;
}

void freeG(Graph *graph) {
    free(graph->nodes);
    free(graph->edges);
    free(graph);
}

int main() {
    Graph *graph = loadGraph("terrain.txt");
    while (1) {  
        int start;
        int end;
        
        printf("start and end\n");
        scanf("%d %d", &start, &end)
        if (start < 0 || start >= graph->numNodes || end < 0 || end >= graph->numNodes) {
            printf("error\n");
            continue;
        }
        
        int *path = findPath(graph, start, end);

        int pathSize = 0;
        int NodesV = 0;
        double EdgeW = 0;
        printf("Path: ");
        for (int i = 0; path[i] != -1; i++) {
            printf(" %d -", path[i]);
            NodesV += graph->nodes[path[i]].v;
            if (i > 0) {
                for (int j = 0; j < graph->numEdges; j++) {
                    if (graph->edges[j].startN == path[i - 1] && graph->edges[j].endN == path[i]) {
                        EdgeW += graph->edges[j].weight;
                        break;
                    }
                }
            }
            pathSize++;
        }
        printf("\n%d %.2lf %d\n", pathSize - 1, EdgeW, NodesV);
    }
    
    freeG(graph);
    return 0;
}
