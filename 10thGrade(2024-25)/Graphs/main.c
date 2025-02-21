#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Graph Graph;

typedef struct Node {
    char name[10];
    struct Node* neighbors[100];
    int e_count;
} Node;

typedef struct Graph {
    Node nodes[100];
    int n_count;
} Graph;

void init_graph(Graph* g){
    g->n_count = 0;
}

Node* add(Graph* g, char* name) {
    //prowerka dali syst.-x
	
	Node* newNode = &g->nodes[g->n_count];
    strcpy(newNode->name, name);
    newNode->e_count = 0;
	
    //sysedni
    for (int i = 0; i < 100; i++) {
        newNode->neighbors[i] = NULL;
    }
    g->n_count++;
    return newNode;
}

void conneNodes(Graph* g, Node* a, Node* b) {
    if(a == b) return;
    a->neighbors[a->e_count] = b;
    a->e_count++;
    b->neighbors[b->e_count] = a;
    b->e_count++;
}

Node* fingNode(Graph* g, char* name) {
    for (int i = 0; i < g->n_count; i++) {
        if(strcmp(g->nodes[i].name, name) == 0)
            return &g->nodes[i];
    }
    return NULL;
}

void names(Graph* g, char* name1, char* name2) {
    Node* a = fingNode(g, name1);
    Node* b = fingNode(g, name2);
    if(a == NULL || b == NULL) {
        printf("error\n");
        return;
    }
    conneNodes(g, a, b);
}

int edges(Graph* g, char* name) {
    Node* node = fingNode(g, name);
    if (node == NULL) return -1;
    return node->e_count;
}

int main() {
    Graph g;
    init_graph(&g);
    Node* a = add(&g, "A");
    Node* b = add(&g, "B");
    Node* c = add(&g, "C");
    
    for (int i = 0; i < g.n_count; i++) {
        printf("Node %d: %s\n", i, g.nodes[i].name);
    }
    
    conneNodes(&g, a, b);
    conneNodes(&g, a, c);
    
    names(&g, "B", "C");
    
    printf("Edges B: %d\n", edges(&g, "B"));
    printf("Edges C: %d\n", edges(&g, "C"));
    
    return 0;
}
