#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* initialiseNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


Node* appendNode(Node* head, int data) {
    Node* newNode = initialiseNode(data);
    if (head == NULL) {
        return newNode;
    } else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        return head;
    }
}

void printList(Node* head) {
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

/*Node* removeNodes(Node* head, int target){
    Node* temp = head;
    //Node* prev = NULL;
    while (temp != NULL && temp->data == target) {
        head = temp->next;
        free(temp);
        temp = head;
    }
    while (temp != NULL) {
        while (temp != NULL && temp->data != target) {
            //prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) return head;
        //prev->next = temp->next;
        free(temp);
        //temp = prev->next;
    }
    return head;
}*/

Node* removeNodes(Node* head, int target){
    Node* temp = head;
    Node* prev = NULL;
    
    while (temp != NULL) {
        if (temp->data == target){
            prev->next = temp->next;
            free(temp);
        }
        
        //printf("%d -> ", head->data);
        temp = temp->next;
        prev = temp;
    }
}


int main(){
    Node* head = NULL;
    int input;

    // Continuously prompt the user to enter integers
    printf("Enter integers (0 to stop):\n");
    while (1) {
        scanf("%d", &input);
        if (input == 0) break;
        head = appendNode(head, input);// stops program
        if (head == NULL) {
            printf("Error: Unable to allocate memory for the new node\n");
            break;
        }
    }

    // Print the resulting linked list
    printList(head);

    // Prompt the user for deletion requests
    printf("Enter integers to delete (0 to stop):\n");
    while (1) {
        scanf("%d", &input);
        if (input == 0) break;
        head = removeNodes(head, input);
        printList(head);
    }

    // Free memory allocated for the linked list, since we used malloc to dynamically allocate the list
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
