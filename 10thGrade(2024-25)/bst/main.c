#include <stdlib.h>
#include <stdio.h>

struct tree_node_t {
    int value;
    struct tree_node_t* left;
    struct tree_node_t* right;
};
typedef struct tree_node_t tree_node_t;

tree_node_t* init_set_node(int value) {
    tree_node_t* node = malloc(sizeof(tree_node_t));
    node->left = NULL;
    node->right = NULL;
    node->value = value;
    return node;
}

tree_node_t* add(tree_node_t* root, int value) {
    if (root == NULL) {
        return init_set_node(value);
    }

    if (value < root->value) {
        root->left = add(root->left, value);
    } else if (value > root->value) {
        root->right = add(root->right, value);
    }

    return root;
}

void print_tree_bfs(tree_node_t* root) {
    if (root == NULL) {
        return;
    }

    tree_node_t* queue[11];
    int curr = 0;
    int end = 0;

    queue[end++] = root;

    while (curr < end) {
        tree_node_t* current = queue[curr++]; 
        printf("%d ", current->value); 

        if (current->left != NULL) {
            queue[end++] = current->left;
        }
        if (current->right != NULL) {
            queue[end++] = current->right;
        }
    }
    printf("\n");
}

int min_height(tree_node_t* root) {
    if (root == NULL) {
        return 0;
    }

    tree_node_t* queue[11];
    int curr = 0;
    int end = 0;

    queue[end++] = root;
    int height = 0;

    while (curr < end) {
        int size = end - curr; 
        height++;

        int processed = 0; 
        while (processed < size) {
            tree_node_t* current = queue[curr++];
            processed++;

            if (current->left == NULL && current->right == NULL) {
                return height; 
            }
            if (current->left != NULL) {
                queue[end++] = current->left;
            }
            if (current->right != NULL) {
                queue[end++] = current->right;
            }
        }
    }
    return height;
}

// tree_node_t* balance(tree_node_t* root) {
//     if (root == NULL) {
//         return NULL; 
//     }

//     tree_node_t* new_root = root;
//     while (new_root->left != NULL) {
//         new_root = new_root->left; 
//     }

//     if (new_root->right != NULL) {
//         root->left = new_root->right; 
//     }

//     root->value = new_root->value;
//     new_root->left = root;         

//     return new_root;
// }


int main() {
    tree_node_t* my_tree = NULL;
    my_tree = add(my_tree, 10);
    my_tree = add(my_tree, 6);
    my_tree = add(my_tree, 7);
    my_tree = add(my_tree, 3);
    my_tree = add(my_tree, 15);
    my_tree = add(my_tree, 13);
    my_tree = add(my_tree, 20);

    my_tree = add(my_tree, 12);
    my_tree = add(my_tree, 9);
    my_tree = add(my_tree, 8);
    my_tree = add(my_tree, 21);

    printf("Original tree (BFS): ");
    print_tree_bfs(my_tree);

    printf("Height: %d\n", min_height(my_tree));

    // my_tree = balance(my_tree);
    // printf("Heeight2: %d\n", min_height(my_tree));


    return 0;
}
