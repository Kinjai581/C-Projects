#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLES 30
#define INDEX_AMOUNT 30

typedef struct HashNode {
    int ID;
    char title[MAX_TITLES];
} HashNode;

HashNode* hashArray[INDEX_AMOUNT];

void insert_value(int ID, const char* title) {
    if (ID < 0 || ID >= INDEX_AMOUNT) {
        printf("ID %d is out of range. Must be between 0 and %d.\n", ID, INDEX_AMOUNT - 1);
        return;
    }

    HashNode* item = (HashNode*)malloc(sizeof(HashNode));
    item->ID = ID;
    strncpy(item->title, title, MAX_TITLES);
    item->title[MAX_TITLES - 1] = '\0'; // Ensure null termination

    // Directly insert using ID as index
    if (hashArray[ID] != NULL) {
        free(hashArray[ID]); 
    }
    hashArray[ID] = item;
}

HashNode* search_value(int ID) {
    if (ID < 0 || ID >= INDEX_AMOUNT) {
        printf("ID %d is out of range. Must be between 0 and %d.\n", ID, INDEX_AMOUNT - 1);
        return NULL;
    }

    return hashArray[ID];
}

void remove_value(int ID){
    if (ID < 0 || ID >= INDEX_AMOUNT){
        printf("ID %d is out of range. Must be between 0 and %d.\n", ID, INDEX_AMOUNT - 1);
        return;
    }
    
    if (hashArray[ID] != NULL){
        free(hashArray[ID]);
        hashArray[ID] = NULL;
        printf("Book with ID %d has been removed succesfully.\n", ID);
    }
    else{
        printf("No book at ID %d found.\n", ID);
    }
}

void freeHashMap() {
    for (int i = 0; i < INDEX_AMOUNT; i++) {
        if (hashArray[i] != NULL) {
            free(hashArray[i]);
        }
    }
}

int main(){
    for (int i = 0; i < INDEX_AMOUNT; i++) {
        hashArray[i] = NULL;
    }
    
    
    while (1){
        printf("\nMenu:\n");
        printf("1. Insert book\n");
        printf("2. Search book\n");
        printf("3. Remove book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
    
        if (choice == 1){
            int ID_input;
            char title[MAX_TITLES];
            printf("Enter a book ID (0 to %d): ", INDEX_AMOUNT - 1);
            scanf("%d", &ID_input);
        
            printf("Enter book title: ");
            scanf("%s", title);
        
            insert_value(ID_input, title);
        }
    
        else if (choice == 2){
            printf("Enter Book ID Here: \n");
            int ID_input;
            scanf("%d", &ID_input);
            HashNode* item = search_value(ID_input);
        
            if (item != NULL){
                printf("Book ID: %d, Title: %s", item->ID, item->title);
            }
        
        
            else{
                printf("Book not found\n");
            }
        
        }
        
        else if (choice == 3){
            int ID_input;
            printf("Enter Book ID Here: \n");
            scanf("%d", &ID_input);
            remove_value(ID_input);
        }
        
    
    
        else if (choice == 4){
            freeHashMap();
            break;
        }
    
    
    
        else{
            printf("Invalid input. Please enter a number from 1 to 3.\n");
        }
    
    }

    
    
    return 0;
}
    
    
    return 0;
}
