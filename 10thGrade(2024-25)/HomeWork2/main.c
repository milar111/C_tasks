#include "header.h"

int main(void) {
    Inventory inventory = {
        .items = malloc(sizeof(Items) * 2),
        .capacity = 2
    };

    inventory.items[0] = (Items){"coins", 2};
    inventory.items[1] = (Items){"sword", 0};

    Node* root = init_node("Welcome to Fantasytown. How can I help you?");
    Node* node1 = init_node("I have some armor.");
    Node* node2 = init_node("Here is your armor.");
    Node* node3 = init_node("I'm the king, what do you want?");
    Node* node4 = init_node("Here is your reward. Anything else?");

    add(root, "I want to buy armor.", node1, NULL);
    add(node1, "Buy light armor.", node2, &(Need){"coins", 5});
    add(node1, "Buy heavy armor.", node2, &(Need){"sword", 1});
    add(root, "Speak with the king.", node3, NULL);
    add(node3, "To matty your daughter.", NULL, NULL);
    add(node3, "To end your tyranny.", NULL, NULL);
    add(root, "I've slain the dragon.", node4, NULL);
    add(node4, "Yes", root, NULL);
    add(node4, "No", NULL, NULL);
    add(root, "Exit.", NULL, NULL);
    add(node1, "Exit.", NULL, NULL);

    play_dialogue(root, &inventory);

    free_node(root);
    free_node(node1);
    free_node(node2);
    free_node(node3);
    free_node(node4);

    free(inventory.items);

    return 0;
}
