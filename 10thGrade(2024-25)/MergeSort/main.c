#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* create_node(int value) {
    Node* newNode = malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void insert_at_head(Node** head, int value) {
    Node* newNode = create_node(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        *head = newNode;
    }
}

void print_linked_list(Node* head) {
    while (head != NULL) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

Node* get_middle_node(Node* head) {
    if (head == NULL) {
        return head;
    }
    Node* slow = head;
    Node* fast = head;

    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node* merge_sorted_linked_list(Node* left, Node* right) {
    if (left == NULL) {
        return right;
    }
    if (right == NULL) {
        return left;
    }

    if (left->value <= right->value) {
        left->next = merge_sorted_linked_list(left->next, right);
        return left;
    } else {
        right->next = merge_sorted_linked_list(left, right->next);
        return right;
    }
}

Node* merge_sort_linked_list(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* middle = get_middle_node(head);
    Node* mid_next = middle->next;

    middle->next = NULL;
    Node* left = merge_sort_linked_list(head);
    Node* right = merge_sort_linked_list(mid_next);
    return merge_sorted_linked_list(left, right);
}

int main() {
    Node* head = NULL;
    insert_at_head(&head, 5);
    insert_at_head(&head, 2);
    insert_at_head(&head, 8);
    insert_at_head(&head, 1);
    insert_at_head(&head, 9);

    head = merge_sort_linked_list(head);
    print_linked_list(head);

    return 0;
}
