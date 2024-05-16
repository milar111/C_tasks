#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 20   

typedef struct Book {
    char title[LENGTH];
    char author[LENGTH];
    char genre[LENGTH];
    int year;
    char isbn[LENGTH];
} Book;

typedef struct Node {
    Book book;
    struct Node* next;
} Node;

Node* head = NULL;

void addBook() {
    Book book;
    printf("Title: ");
    scanf("%s", book.title);
    printf("Author: ");
    scanf("%s", book.author);
    printf("Genre: ");
    scanf("%s", book.genre);
    printf("Year: ");
    scanf("%d", &book.year);
    printf("ISBN: ");
    scanf("%s", book.isbn);

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->next = head;
    head = newNode;
}

void showList() {
    Node* current = head;
    while (current != NULL) {
        printf("Title: %s, Author: %s, Genre: %s, Year: %d, ISBN: %s\n", current->book.title, current->book.author, current->book.genre, current->book.year, current->book.isbn);
        current = current->next; 
    }
}

void deleteBook() {
    char isbn[LENGTH];
    printf("Enter ISBN: ");
    scanf("%s", isbn);

    Node* current = head;
    Node* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->book.isbn, isbn) == 0) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Error.\n");
}

void saveBooks() {
    FILE *file = fopen("books.txt", "w");
    if (file == NULL) {
        printf("Error.\n");
        return;
    }

    Node* current = head;
    while (current != NULL) {
        fprintf(file, "Title: %s, Author: %s, Genre: %s, Year: %d, ISBN: %s\n", current->book.title, current->book.author, current->book.genre, current->book.year, current->book.isbn);
        current = current->next;
    }
    fclose(file);
}

int main() {
    int choice;
    do {
        printf("\n1. Add Book\n2. Display Books\n3. Delete Book\n4. Save & Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                showList();
                break;
            case 3:
                deleteBook();
                break;
            case 4:
                saveBooks();
                break;
            default:
                printf("Error.\n");
        }
    } while (choice != 4);
}
