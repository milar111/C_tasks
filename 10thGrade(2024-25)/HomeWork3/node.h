#ifndef NODE_H
#define NODE_H

#include "figure.h"

#define MAX 10

typedef struct Node {
    float min_x, max_x, min_y, max_y;
    int is_leaf, f_count;
    Figure *figures[MAX];
    struct Node *children[4];
} Node;

Node *create_node(float min_x, float max_x, float min_y, float max_y);

void split_node(Node *node);
void insert_figure(Node *node, Figure *figure);
void f_arr(Node *node, Figure *all_f[], int *count);
void find_overlaps(Node *root);
void print_quadrants(Node *node);

#endif
