#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* left;
    struct node* right;
} node_l;

typedef struct {
    node_l* root;
} Tree;

Tree* initialize_tree(){
    Tree* tree = malloc(sizeof(Tree)); 
    tree->root = NULL;
    return tree;

}

void freeTreeNodes(node_l* root){
    if (root == NULL) return;
  printf("%d ->", root->value);
  freeTreeNodes(root->left);
  freeTreeNodes(root->right);
  free(root);
  
}

// Make a remove node function- Remove every child node

void deleteSubtree(node_l** root, int value) {
    if (*root == NULL) {
        return; // Base case: tree is empty or we've hit a leaf node.
    }
    
    if ((*root)->value == value) {
        // Found the node, now delete this subtree
        freeTreeNodes(*root);
        *root = NULL; // Important to prevent dangling pointer in the parent node
        return;
    }
    
    // Recur down to find the node
    deleteSubtree(&((*root)->left), value);
    deleteSubtree(&((*root)->right), value);
}

void removeNodeWithChildren(Tree* tree, int value) {
    if (tree == NULL) return;
    deleteSubtree(&(tree->root), value);
}

void preorderTraversal(node_l* root) {
  if (root == NULL) return;
  printf("%d ->", root->value);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}


node_l* initialize_node(int value){
    node_l* new_node = malloc(sizeof(node_l));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node_l* insertLeft(int value, node_l* node){
    node->left = initialize_node(value);
    return node->left;
}

node_l* insertRight(int value, node_l* node){
    node->right = initialize_node(value);
    return node->right;
}




int main() {
    Tree* s = initialize_tree();
    s->root = initialize_node(5);
    printf("%d\n", s->root->value);
    insertLeft(3, s->root);
    insertRight(8, s->root);
    insertLeft(7, s->root->left);// Add child node to 3
    printf("%d\n", s->root->left->value);
    printf("%d\n", s->root->right->value);
    
    printf("Preorder before removal: ");
    preorderTraversal(s->root);
    printf("\n");

    removeNodeWithChildren(s, 3);
    
    printf("Preorder after removal: ");
    preorderTraversal(s->root);
    printf("\n");
    
    freeTreeNodes(s->root);
    free(s);
    
    return 0;
}
