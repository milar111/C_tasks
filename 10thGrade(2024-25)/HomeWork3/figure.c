#include "figure.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static int sq_id = 1;
static int circ_id = 1;

void unique_name(char *name, const char *type) {
    if (strcmp(type, "sq") == 0) {
        snprintf(name, 10, "%s%d", type, sq_id++);
    } else if (strcmp(type, "circ") == 0) {
        snprintf(name, 10, "%s%d", type, circ_id++);
    } else {
        snprintf(name, 10, "%s%d", type, 0);
    }
}

Figure *create_figure(int type, float x, float y, float a_r) {
    Figure *f = malloc(sizeof(Figure));
    if (type == 1) {
        unique_name(f->name, "sq");
    } else {
        unique_name(f->name, "circ");
    }
    f->type = type;
    f->x = x;
    f->y = y;
    f->a_r = a_r;
    return f;
}

int check_overlap(Figure *a, Figure *b) {
    if (a->type == 0 && b->type == 0) { //c-c
        float dx = a->x - b->x;
        float dy = a->y - b->y; 
        float distance = sqrt(dx * dx + dy * dy);
        float r_sum = a->a_r + b->a_r; 
        return r_sum >= distance; 
    } else if (a->type == 1 && b->type == 1) { //s-s
        float dx = fabs(a->x - b->x); //modul
        float dy = fabs(a->y - b->y);
        float half_s1 = a->a_r / 2.0;
        float half_s2 = b->a_r / 2.0;
        int sep_x = dx >= (half_s1 + half_s2);
        int sep_y = dy >= (half_s1 + half_s2);
        return !(sep_x || sep_y);
    } else { //s-c
        Figure *circle;
        Figure *square;
        if (a->type == 0) {
            circle = a;
            square = b;
        } else {
            circle = b;
            square = a;
        }
        float half_a = square->a_r / 2;
        float diagonal_h = (square->a_r * sqrt(2)) / 2;

        float dx = circle->x - square->x;
        float dy = circle->y - square->y;
        float distance_2 = dx * dx + dy * dy;

        if (sqrt(distance_2) <= diagonal_h) {
            return 1;
        }

        float points[8][2] = {
            {square->x - half_a, square->y - half_a},
            {square->x + half_a, square->y - half_a},
            {square->x - half_a, square->y + half_a},
            {square->x + half_a, square->y + half_a},
            {square->x, square->y - half_a},
            {square->x, square->y + half_a},
            {square->x - half_a, square->y},
            {square->x + half_a, square->y}
        };

        for (int i = 0; i < 8; i++) {
            float px = points[i][0] - circle->x;
            float py = points[i][1] - circle->y;
            if (px * px + py * py <= circle->a_r * circle->a_r) {
                return 1;
            }
        }

        return 0;
    }
}
