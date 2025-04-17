#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "graph.h"

double Weight(Node n1, Node n2, double c) {
    double hDiff = fabs(n1.h - n2.h); //absolute 
    double add = 0;
    if (hDiff > 0) {
        add = 1 - (c / hDiff);
    }
    return c + add;
}


Graph *loadGraph(char *filename) {
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