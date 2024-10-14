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

void addToStart(Node** head, int value) {
    Node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//?
void bubbleSortValues(Node* head) {
    if (head == NULL) return;

    Node* i;
    Node* j;
    int temp;
    for (i = head; i != NULL; i = i->next) {
        for (j = head; j->next != NULL; j = j->next) {
            if (j->data > j->next->data) {
                temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
            }
        }
    }
}

void bubbleSortNodes(Node** head) {
    if (*head == NULL) return;

    int swapped;
    Node** ptr;
    Node* temp;
    Node* prev;
    Node* end = NULL;

    do {
        swapped = 0;
        ptr = head;

        while ((*ptr)->next != end) {
            if ((*ptr)->data > (*ptr)->next->data) {
                temp = (*ptr)->next;
                (*ptr)->next = temp->next;
                temp->next = *ptr;

                if (ptr == head) {
                    *head = temp;
                } else {
                    prev->next = temp;
                }

                swapped = 1;
            }
            prev = *ptr;
            ptr = &(*ptr)->next;
        }
        end = *ptr;
    } while (swapped);
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

    addToEnd(&list, 5);
    addToEnd(&list, 1);
    addToEnd(&list, 4);
    addToEnd(&list, 3);
    addToEnd(&list, 2);

    printList(list);

    bubbleSortValues(list);
    printList(list);

    addToStart(&list, 10);
    addToStart(&list, 0);
    
    printList(list);

    bubbleSortNodes(&list);
    printList(list);

    freeList(list);
    
    return 0;
}
