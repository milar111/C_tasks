#include "node.h"
#include <stdlib.h>
#include <stdio.h>

Node *create_node(float min_x, float max_x, float min_y, float max_y) {
    Node *node = malloc(sizeof(Node));
    node->min_x = min_x;
    node->max_x = max_x;
    node->min_y = min_y;
    node->max_y = max_y;
    node->is_leaf = 1;
    node->f_count = 0;
    for (int i = 0; i < 4; i++) {
        node->children[i] = NULL;
    }
    return node;
}

void split_node(Node *node) {
    float mid_x = (node->min_x + node->max_x) / 2;
    float mid_y = (node->min_y + node->max_y) / 2;

    node->children[0] = create_node(mid_x, node->max_x, mid_y, node->max_y);
    node->children[1] = create_node(node->min_x, mid_x, mid_y, node->max_y);
    node->children[2] = create_node(node->min_x, mid_x, node->min_y, mid_y);
    node->children[3] = create_node(mid_x, node->max_x, node->min_y, mid_y);

    node->is_leaf = 0;

    for (int i = 0; i < node->f_count; i++) {
        Figure *f = node->figures[i];
        for (int j = 0; j < 4; j++) {
            Node *child = node->children[j];
            if (f->x >= child->min_x && f->x < child->max_x && f->y >= child->min_y && f->y < child->max_y) {
                child->figures[child->f_count++] = f;
                break;
            }
        }
    }
    node->f_count = 0;
}


void insert_figure(Node *node, Figure *figure) {
    if (node->is_leaf) {
        if (node->f_count < MAX) {
            node->figures[node->f_count++] = figure;
        } else {
            split_node(node);
            insert_figure(node, figure);
        }
    } else {
        for (int i = 0; i < 4; i++) {
            Node *child = node->children[i];
            if (figure->x >= child->min_x && figure->x < child->max_x && figure->y >= child->min_y && figure->y < child->max_y) {
                insert_figure(child, figure);
                break;
            }
        }
    }
}


void f_arr(Node *node, Figure *all_f[], int *count) {
    if (node->is_leaf) {
        for (int i = 0; i < node->f_count; i++) {
            all_f[(*count)++] = node->figures[i];
        }
    } else {
        for (int i = 0; i < 4; i++) {
            if (node->children[i] != NULL) {
                f_arr(node->children[i], all_f, count);
            }
        }
    }
}

void find_overlaps(Node *root) {
    Figure *all_f[1000]; 
    int sum_f = 0;

    f_arr(root, all_f, &sum_f);

    printf("Overlap\n");
    for (int i = 0; i < sum_f; i++) {
        for (int j = i + 1; j < sum_f; j++) {
            if (check_overlap(all_f[i], all_f[j])) {
                printf("%s and %s\n", all_f[i]->name, all_f[j]->name);
            }
        }
    }
}

void print_quadrants(Node *node) {
    if (node == NULL) return;
    printf("Quadrant: [(%.2f;%.2f) - (%.2f;%.2f) - (%.2f;%.2f) - (%.2f;%.2f)]\n", node->min_x, node->max_y, node->max_x, node->max_y, node->min_x, node->min_y, node->max_x, node->min_y);
           //topleft - topright - bottomleft - bottomright
    for (int i = 0; i < 4; i++) {
        if (node->children[i] != NULL) {
            print_quadrants(node->children[i]);
        }
    }
}


