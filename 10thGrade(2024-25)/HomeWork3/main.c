#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    Figure *figures[14];
    figures[0] = create_figure(1, -5.5, -3.5, 3);
    figures[1] = create_figure(1, -3.5, -1.5, 1);
    figures[2] = create_figure(1, -6.5, -4.5, 1);
    figures[3] = create_figure(1, -8, -3, 2);
    figures[4] = create_figure(1, -3.5, -5.5, 2);

    figures[5] = create_figure(0, -2.5, 3.5, 1);
    figures[6] = create_figure(0, -4.5, 2.5, 0.5);
    figures[7] = create_figure(0, -4, 5, 1.5);

    figures[8] = create_figure(1, 2, 2, 4);
    figures[9] = create_figure(0, 5, 5, 1);
    figures[10] = create_figure(0, 5, 5, 2);
    figures[11] = create_figure(0, 3.5, 0.5, 0.3);
    figures[12] = create_figure(0, 4.3, 1, 0.7);
    figures[13] = NULL;

    Node *root = build_tree(figures);

    printf("-------------------\n");
    find_overlaps(root);
    printf("-------------------\n");
    // print_quadrants(root);

    // visualised : https://github.com/milar111/C_tasks/blob/main/UASD.png

    for (int i = 0; i < 13; i++) {
        free(figures[i]);
    }
    free(root);

    return 0;
}
