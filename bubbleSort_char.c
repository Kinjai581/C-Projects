#include <stdio.h>

// ** Bubble sort algorithm **
void bubbleSort_ascending(char arr[], int n){ //takes in the arguments of the character array.
        for (int i = 0; i < n - 1; i++){ //The outer for loop for the number of passes.
                for (int j = 0; j < n - i - 1; j++) { //Inner loop for comparisons and swaps
                        if (arr[j] > arr[j + 1]) { //Compare adjacent elements and swap if required for ascending order
                                char temp = arr[j];//creating a temporary variable and assigns it the value of the element at index j in the array. This is done to prevent data loss.
                                arr[j] = arr[j + 1];// This effectively moves the value from the next position to the current position, overwriting the original value at index j.
                                arr[j + 1] = temp;//This completes the swap by moving the original value of arr[j] to the next position.

                                // The three lines in the if statement swap the variables of arr[j] and arr[j+1].
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
