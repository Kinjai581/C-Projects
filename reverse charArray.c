#include <stdio.h>

int main() {
        char char_array[] = "Hello Adam";

        size_t length = sizeof(char_array)/sizeof(char)-1; //Calculates the length of the string

        char *pointer = char_array + length - 1; // Declare a pointer to char and initialize it to the addr>

        while (pointer >= char_array){
                printf("%c\n", *pointer);
                pointer--;

        }

        return 0;


}
