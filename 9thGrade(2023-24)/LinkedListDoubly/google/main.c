#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};


int main(void){

    struct node *head;
    struct node *one = NULL;
    struct node *two = NULL;
    struct node *three = NULL;


    one = malloc(sizeof(struct node));
    two = malloc(sizeof(struct node));
    three = malloc(sizeof(struct node));


    one->data = 1;
    two->data = 2;
    three->data = 3;


    one->next = two;
    one->prev = NULL;

    two->next = three;
    two->prev = one;

    three->next = NULL;
    three->prev = two;

    head = one;
    
}