#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* next;
} node_l;

typedef struct {
    node_l* head;
} List;

//Push method, will add a node to the top of the list
void push(List* list, int value) {
    node_l* temp = malloc(sizeof(node_l));

    temp->value = value;

    //We need the list's head and make that the new nodes 'next' node
    temp->next = list->head;
    list->head = temp;
}

//Create a initialize list method that initializes the List*
List* initialize_list(){
    List* list = malloc(sizeof(List)); 
    list->head = NULL;
    return list;
    //Dynamically allocates  memory for a new list, initializes its head pointer to NULL, and returns a pointer to the newly created list.
}

//Create a initialize_node method that initializes a node_l*
node_l* initialize_node(int value){
    node_l* new_node = malloc(sizeof(node_l));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

//Create a pop() method, removes the node from the head
int pop(List* list){
    
}

//Create a add() method, adds a node to the end of the list
void add(List* list, int value){
    
}

//Create free_list(), deallocates all the memory from the list
void free_list(List* list){
    node_l* current = list->head;
    while (current != NULL) {
        node_l* temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
    // This function iterates through each node in the list, deallocating the memory for each node, and then frees the memory allocated for the list itself.
}

//Try to add your functions if need be

//You can try to clean this main() if you want to and try to utilize your own methods to simplify it.
int main() {
    //Initialize the list and nodes
    List* list    = NULL;
    node_l* one   = NULL;
    node_l* two   = NULL;
    node_l* three = NULL;

    //Allocate memory for the nodes 
    one   = malloc(sizeof(node_l));
    two   = malloc(sizeof(node_l));
    three = malloc(sizeof(node_l));

    //Allocate memory for the list
    list = malloc(sizeof(List));

    //Set each node's value. This is the value/data it stores in the node
    one->value   = 1;
    two->value   = 2;
    three->value = 3;

    //Set each nodes next node. This is to 'link' the list
    one->next   = two;
    two->next   = three;
    three->next = NULL; //It's next value is NULL because its the last value in the list

    //Specify to the list that the 'one' node is the beginning (head) of our list
    list->head = one;

    //Print the current head node's next node value
    printf("%d\n", list->head->next->value);

    //Push a new node to the top of the List (we created a new node with the value 4)
    push(list, 4);
    
    //Print the new head
    printf("%d", list->head->value);

    //Freeing the malloc()s that we made
    free(one);
    free(two);
    free(three);
    free(list->head); //list->head here was malloc()ed from our 'push()' function. 

    free(list);

    return 0;
}
