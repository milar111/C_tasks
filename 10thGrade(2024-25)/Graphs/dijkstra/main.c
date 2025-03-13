#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INFINITE -1
#define MAX_NODES 100

typedef struct Node {
    char name[10];
    struct Node* neighbors[MAX_NODES];
    int weights[MAX_NODES]; 
    int eCount;
} Node;

typedef struct Graph {
    Node nodes[MAX_NODES];
    int nCount;
} Graph;

void init_graph(Graph* g) {
    g->nCount = 0;
}

Node* add(Graph* g, char* name) {
    Node* newNode = &g->nodes[g->nCount];
    strcpy(newNode->name, name);
    newNode->eCount = 0;
    g->nCount++;
    return newNode;
}

void connectNodes(Graph* g, Node* a, Node* b, int weight) {
    if (a == b) return;
    a->neighbors[a->eCount] = b;
    a->weights[a->eCount] = weight;
    a->eCount++;
    b->neighbors[b->eCount] = a;
    b->weights[b->eCount] = weight;
    b->eCount++;
}

Node* findNode(Graph* g, char* name) {
    for (int i = 0; i < g->nCount; i++) {
        if (strcmp(g->nodes[i].name, name) == 0)
            return &g->nodes[i];
    }
    return NULL;
}

Node* minDistance(Graph* g, int dist[], int visited[]) {
    int min = INFINITE;
    int minI = -1;
    Node* minNode = NULL;
    for (int i = 0; i < g->nCount; i++) {
        if (visited[i]) continue;
        if (dist[i] == INFINITE) continue;
        if (min == INFINITE || dist[i] < min) {
            min = dist[i];       
            minNode = &g->nodes[i]; 
            minI = i;     
        }
    }
    return minNode;
}

int getNodeIndex(Graph* g, Node* node) {
    for (int i = 0; i < g->nCount; i++) {
        if (&g->nodes[i] == node)
            return i;
    }
    return -1;
}

void dijkstra(Graph* g, char* startName, char* endName) {
    int dist[MAX_NODES];
    int visited[MAX_NODES] = {0};
    Node* parent[MAX_NODES] = {NULL};

    for (int i = 0; i < g->nCount; i++)
        dist[i] = INFINITE;

    Node* startNode = findNode(g, startName); 
    Node* endNode = findNode(g, endName); 
    
    int startI = getNodeIndex(g, startNode);
    dist[startI] = 0;

    for (int i = 0; i < g->nCount - 1; i++) {
        Node* u = minDistance(g, dist, visited);
        int uIndex = getNodeIndex(g, u);
        visited[uIndex] = 1;

        for (int j = 0; j < u->eCount; j++) {
            Node* v = u->neighbors[j];
            int vIndex = getNodeIndex(g, v);
            int weight = u->weights[j];

            if (!visited[vIndex] && weight != INFINITE && (dist[uIndex] != INFINITE && (dist[vIndex] == INFINITE || dist[uIndex] + weight < dist[vIndex]))) { //ne e pooseten && systestwuwa tevest && (obraboten li e && (sysed ? inf || nowo < tekusto))
                dist[vIndex] = dist[uIndex] + weight;
                parent[vIndex] = u;
            }
        }
    }

    Node* path[MAX_NODES];
    int pCount = 0;
    
    Node* temp = endNode;
    while (temp) {
        path[pCount++] = temp;
        temp = parent[getNodeIndex(g, temp)];
    }

    for (int i = pCount - 1; i >= 0; i--) {
        printf(" %s -", path[i]->name);
    }
    printf("\n");
}

int main() {
    Graph g;
    init_graph(&g);

    Node* a = add(&g, "A");
    Node* b = add(&g, "B");
    Node* c = add(&g, "C");
    Node* d = add(&g, "D");
    Node* e = add(&g, "E");

    connectNodes(&g, a, b, 1);
    connectNodes(&g, a, e, 10);
    connectNodes(&g, a, c, 3);
    connectNodes(&g, b, c, 5);
    connectNodes(&g, b, d, 5);
    connectNodes(&g, c, d, 2);
    connectNodes(&g, c, e, 1);
    connectNodes(&g, d, e, 1);

    dijkstra(&g, "A", "D");

    return 0;
}



//       (A)
//    /   |   \
//  1/   3|  10\
//  /     |     \
//(B)-5--(C)-1--(E)
//  \     |     /
//   5    2    1
//    \   |   /
//       (D)
