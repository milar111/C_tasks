#include "tree.h"
#include <stdio.h> //null

Node *build_tree(Figure *figures[]) {
    Node *root = create_node(-13, 13, -13, 13);
    int f_count = 0;

    while (figures[f_count] != NULL) {
        f_count++;
    }

    for (int i = 0; i < f_count; i++) {
        insert_figure(root, figures[i]);
    }

    return root;
}
