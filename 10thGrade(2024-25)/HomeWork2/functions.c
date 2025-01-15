#include "header.h"

Node* init_node(char* text) {
    Node* node = malloc(sizeof(Node));
    node->next_node = NULL;
    node->choices = NULL;
    node->text = text;
    node->num_choice = 0;
    return node;
}

void print_inventory(Inventory* inventory) {
    printf("------------------------------\n");
    for (int i = 0; i < inventory->capacity; i++) {
        printf("%s: %d\n", inventory->items[i].name, inventory->items[i].num);
    }
    printf("------------------------------\n");
}

void play_dialogue(Node* root, Inventory* inventory) {
    Node* curr = root;
    while (curr) {
        printf("%s\n", curr->text);

        if (curr->num_choice == 0) {
            curr = curr->next_node;
        }

        for (int i = 0; i < curr->num_choice; i++) {
            printf("%d. %s\n", i + 1, curr->choices[i].text);
        }

        int choice;
        printf("Choose: ");
        scanf("%d", &choice);

        if (choice < 1 || choice > curr->num_choice) {
            printf("error.\n");
        }

        Choice* chose = &curr->choices[choice - 1];
        if (chose->needs) {
            int can_afford = 0;
            for (int i = 0; i < inventory->capacity; i++) {
                if (strcmp(inventory->items[i].name, chose->needs->name) == 0 &&
                    inventory->items[i].num >= chose->needs->num) {
                    inventory->items[i].num -= chose->needs->num; 
                    can_afford = 1;
                    break;
                }
            }
            if (!can_afford) {
                printf("You don't have the item.\n");
                continue;
            }
        }

        print_inventory(inventory);
        curr = chose->next_node;
    }
}

void add(Node* node, char* text, Node* next_node, Need* needs) {
    node->choices = realloc(node->choices, sizeof(Choice) * (node->num_choice + 1));
    node->choices[node->num_choice].text = text;
    node->choices[node->num_choice].next_node = next_node;
    node->choices[node->num_choice].needs = needs;
    node->num_choice++;
}

void free_node(Node* node) {
    for (int i = 0; i < node->num_choice; i++) {
        // free(node->choices[i].text);
        free(node->choices[i].needs);
    }
    free(node->choices);
    // free(node->text);
    free(node);
}
