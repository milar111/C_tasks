#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node Node;
typedef struct choice Choice;
typedef struct items Items;
typedef struct need Need;
typedef struct inventory Inventory;

struct node {
    char* text;
    Choice* choices;
    int num_choice;
    Node* next_node;
};

struct choice {
    char* text;
    Node* next_node;
    Items* items;
    // Inventory* inventory;
    Need* needs;
};

Node* init_node(char* text);
void print_inventory(Inventory* inventory);
void play_dialogue(Node* root, Inventory* inventory);
void add(Node* node, char* text, Node* next_node, Need* needs);
void free_node(Node* node);

struct need {
    char* name;
    int num;
};

struct items {
    char* name;
    int num;
};

struct inventory {
    Items* items;
    int capacity;
};


#endif 
