#include <stdio.h>

int main() {
        char char_array[] = "Hello Adam";
        
        //** This is a good approach, but also do note that 'char' is only 1 byte in C (since it usually uses ASCII which fits 1 byte).
        //So you can do the equivalent and get the same result: sizeof(char_array) - 1. If you are dealing with different types of character encodings of different sizes (such as UTF-16), then it's better
        //to divide by the size of the char primitive type i.e: sizeof(char_array)/sizeof(char_array[0]) - 1. **
        
        //size_t length = sizeof(char_array)/sizeof(char)-1; //Calculates the length of the string
        size_t length = sizeof(char_array)/sizeof(char_array[0]) -1;

        char *pointer = char_array + length - 1; // Declare a pointer to char and initialize it to the addr>

        while (pointer >= char_array){
                printf("%c\n", *pointer);
                pointer--;

        }

        return 0;


}
