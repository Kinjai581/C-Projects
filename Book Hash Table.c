#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLES 20
#define INDEX_AMOUNT 20

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

    insert_value(1, "Lord of the Flies");
    insert_value(2, "1984");
    insert_value(3, "To Kill a Mockingbird");
    insert_value(4, "Oliver Twist");
    insert_value(5, "Moby Dick");

    HashNode* item = search_value(1);
    if (item != NULL) {
        printf("Book ID: %d, Title: %s\n", item->ID, item->title);
    } else {
        printf("Book not found\n");
    }

    item = search_value(2);
    if (item != NULL) {
        printf("Book ID: %d, Title: %s\n", item->ID, item->title);
    } else {
        printf("Book not found\n");
    }

    // Search for a non-existing book
    item = search_value(10);
    if (item != NULL) {
        printf("Book ID: %d, Title: %s\n", item->ID, item->title);
    } else {
        printf("Book not found\n");
    }

    freeHashMap();
    
    return 0;
}
