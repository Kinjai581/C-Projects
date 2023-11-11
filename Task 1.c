#include <stdio.h>

int main() {
    // Declare a variable
    int num = 10;

    // Declares a pointer and initialize it with the address of the variable
    int *p = &num;

    // Print the initial value of the variable
    printf("Before change: %i\n", num);

    // Changes the value using the pointer
    *p = 20;

    // Prints the value after the change
    printf("After change: %i\n", num);

    return 0;
}
