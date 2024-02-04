#include <stdio.h>

void bubbleSort_ascending(char arr[], int n){
        for (int i = 0; i < n - 1; i++){
                for (int j = 0; j < n - i - 1; j++) {
                        if (arr[j] > arr[j + 1]) {
                                char temp = arr[j];
                                arr[j] = arr[j + 1];
                                arr[j + 1] = temp;
                        }
                }
        }
}

void bubbleSort_decending(char arr[], int n){
        for (int i = 0; i < n - 1; i++){
                for (int j = 0; j < n - i - 1; j++) {
                        if (arr[j] < arr[j + 1]) {
                                char temp = arr[j];
                                arr[j] = arr[j + 1];
                                arr[j + 1] = temp;
                        }
                }
        }
}


int main(void) {
    char arr[] = {'j','l','u','c','k','a','t','w'};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++)
        printf("%c ", arr[i]);

    bubbleSort_ascending(arr, n);
    printf("\nSorted in ascending order: ");
    for (int i = 0; i < n; i++)
        printf("%c ", arr[i]);

    bubbleSort_decending(arr, n);
    printf("\nSorted in decending order: ");
    for (int i = 0; i < n; i++)
        printf("%c ", arr[i]);

    return 0;
}
