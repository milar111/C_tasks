#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char firstname[50];
    struct Node* father;
    struct Node* mother;
    struct Node* marriedto;
} Node;

Node* createNode(char firstname[]) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(newNode->firstname, firstname);
    newNode->father = NULL;
    newNode->mother = NULL;
    newNode->marriedto = NULL;
    return newNode;
}

void freeTree(Node* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->father);
    freeTree(root->mother);
    free(root);
}

void printNode(Node* node) {
    if (node == NULL) {
        return;
    }
    printf("Name: %s\n", node->firstname);
    if (node->father) {
        printf("Father: %s\n", node->father->firstname);
    } else {
        printf("Father: Unknown\n");
    }
    if (node->mother) {
        printf("Mother: %s\n", node->mother->firstname);
    } else {
        printf("Mother: Unknown\n");
    }
    if (node->marriedto) {
        printf("Married to: %s\n", node->marriedto->firstname);
    } else {
        printf("Married to: Not Married\n");
    }
    printf("\n");
}

int main() {
    Node* john = createNode("John Smith");
    Node* michael = createNode("Michael Smith");
    Node* sarah = createNode("Sarah Johnson");
    Node* emily = createNode("Emily Brown");
    
    michael->father = createNode("Robert Smith");
    michael->mother = createNode("Mary Wilson");
    
    john->father = michael;
    john->mother = sarah;
    john->marriedto = emily;

    printNode(john);
    printNode(michael);
    
    freeTree(john);
    
    return 0;
}
