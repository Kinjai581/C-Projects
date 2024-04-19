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

// Make a remove node function- Remove every child node

void preorderTraversal(node_l* root) {
  if (root == NULL) return;
  printf("%d ->", root->value);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

//Create a initialize_node method that initializes a node_l*
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

void freeTreeNodes(node_l* root){
    if (root == NULL) return;
  printf("%d ->", root->value);
  freeTreeNodes(root->left);
  freeTreeNodes(root->right);
  free(root);
  
}


int main() {
    Tree* s = initialize_tree();
    s->root = initialize_node(5);
    printf("%d\n", s->root->value);
    insertLeft(3, s->root);
    insertRight(8, s->root);
    printf("%d\n", s->root->left->value);
    printf("%d\n", s->root->right->value);
    //preorderTraversal(s->root);
    
    freeTreeNodes(s->root);
    free(s);
    
    return 0;
}
