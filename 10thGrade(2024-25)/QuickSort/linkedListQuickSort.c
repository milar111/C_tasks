#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("error\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void addToEnd(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d- ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void swapValues(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

Node* anchorByValues(Node* low, Node* high) {
    int anchor = high->data;
    Node* i = low;
    for (Node* j = low; j != high; j = j->next) {
        if (j->data < anchor) {
            swapValues(&i->data, &j->data);
            i = i->next;
        }
    }
    swapValues(&i->data, &high->data);
    return i;
}

void quickSortValues(Node* low, Node* high) {
    if (low != NULL && high != NULL && low != high && low != high->next) {
        Node* anchor = anchorByValues(low, high);
        if (anchor != low) {
            Node* temp = low;
            while (temp->next != anchor) {
                temp = temp->next;
            }
            quickSortValues(low, temp);
        }
        quickSortValues(anchor->next, high);
    }
}

Node* getLastNode(Node* head) {
    while (head != NULL && head->next != NULL) {
        head = head->next;
    }
    return head;
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* list = NULL;

    addToEnd(&list, 6);
    addToEnd(&list, 8);
    addToEnd(&list, 3);
    addToEnd(&list, 7);
    addToEnd(&list, 2);
    addToEnd(&list, 4);
    addToEnd(&list, 5);
    addToEnd(&list, 1);

    printf("Original:");
    printList(list);

    Node* lastNode = getLastNode(list);
    quickSortValues(list, lastNode);
    printf("Sorted:");
    printList(list);
    freeList(list);

    return 0;
}
