#ifndef GRAPH_H
#define GRAPH_H

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

double Weight(Node n1, Node n2, double c);
Graph *loadGraph(char *filename);
void freeG(Graph *graph);

#endif