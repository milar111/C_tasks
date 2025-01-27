#ifndef FIGURE_H
#define FIGURE_H

typedef struct {
    char name[10];
    float x, y, a_r;
    int type; // 1- square, 0 - circle
} Figure;

void unique_name(char *buffer, const char *prefix);
Figure *create_figure(int type, float x, float y, float a_r);

int check_overlap(Figure *a, Figure *b);

#endif
