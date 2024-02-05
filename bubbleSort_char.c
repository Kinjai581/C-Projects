#include <stdio.h>

// ** You successfully completed the task, but make sure you add comments to the code so I can see if you understand
// the implementation and what you have written. Try to explain the difference between the bubbleSort_ascending and 
// bubbleSort_descending methods and what you did differently, as well as how does the bubble sort algorithm sort the array? 
// Try to explain, at most, every line (except for the printing methods) if you can. You can reflect on what we did with the 
// previous task on the last session to help remind you. **

void bubbleSort_ascending(char arr[], int n){ //
        for (int i = 0; i < n - 1; i++){ //The outer for loop for the number of passes.
                for (int j = 0; j < n - i - 1; j++) { //Inner loop for comparisons and swaps
                        if (arr[j] > arr[j + 1]) { //Compare adjacent elements and swap if required for ascending order
                                char temp = arr[j];
                                arr[j] = arr[j + 1];
                                arr[j + 1] = temp;
                        }
                }
        }
}

void bubbleSort_decending(char arr[], int n){
        for (int i = 0; i < n - 1; i++){ //The outer for loop for the number of passes.
                for (int j = 0; j < n - i - 1; j++) { //Inner loop for comparisons and swaps
                        if (arr[j] < arr[j + 1]) { //Compare adjacent elements and swap if required for decending order
                                char temp = arr[j];
                                arr[j] = arr[j + 1];
                                arr[j + 1] = temp;
                        }
                }
        }
}


int main(void) {
    char arr[] = {'j','l','u','c','k','a','t','w'}; //Create the array of character type
    int n = sizeof(arr)/sizeof(arr[0]); //Calculate the number of elements within the array. 

    printf("Original array: ");
    for (int i = 0; i < n; i++)
        printf("%c ", arr[i]); //prints out all the elements of the array in it's original format

    bubbleSort_ascending(arr, n); //Calls the bubbleSort function in ascending order
    printf("\nSorted in ascending order: ");
    for (int i = 0; i < n; i++)
        printf("%c ", arr[i]);

    bubbleSort_decending(arr, n); //Sorts the elements in decending order when called
    printf("\nSorted in decending order: ");
    for (int i = 0; i < n; i++)
        printf("%c ", arr[i]);

    return 0;
}
