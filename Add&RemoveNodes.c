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

//**
//Fixed up the issue in the remove nodes function
Node* removeNodes(Node* head, int target) {
    Node* temp = head;
    Node* prev = NULL;

    //Handle head node removal
    while (temp != NULL && temp->data == target) {
        head = temp->next;
        free(temp);
        temp = head;
    }

    //Here we should be removing any other node
    //Think of it as a chain (a link, hence why it is called a linked list)
    while (temp != NULL) {
        //If it is the target
        if (temp->data == target) {
            //Make the previous node's next the current node's next
            prev->next = temp->next;
            free(temp); //Deallocate current (aka removed) node
            //Move the temporary node as the next node of the previous so it removed the current node
            temp = prev->next;
        } else {
            //Otherwise just traverse through list and store the current (temp) and previous (prev) nodes
            prev = temp;
            temp = temp->next;
        }
    }

    return head;
}
//**

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
