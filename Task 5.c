#include <stdio.h>

int main() {
    int numbers[] = {1, 3, 5, 7, 9};
    
    // Declaring a pointer and assign the address of the first element of the array to it
    int *ptr = &numbers[0];

    // Use the pointer to traverse the array and print its elements
    printf("Elements of the array using pointer:\n");
    for (int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); ++i) {
        printf("%d ", *ptr);
        
        // Move the pointer to the next element in the array
        ptr++;
    }

    return 0;
}

// In terms of memory addresses, when we assign &numbers[0] to the pointer ptr, the pointer now holds the memory address of the first element of the array.
