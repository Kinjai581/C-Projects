#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key){
    while (low <= high){
        int middle = low + (high - low) / 2;
        
        if (arr[middle] == key){
            return middle;
        }
        
        if (arr[middle] < key){
            low = middle + 1;
        }
        
        else{
            high = middle - 1;
        }
    }
    return -1;
}
    

int main(){
    int arr[] = {2, 4, 6, 8, 12, 14};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int middle = 12;
    int result = binarySearch(arr, 0, n - 1, middle);
    if (result == -1){
        printf("Element not found");
    }
    
    else{
        printf("Found element at %d", result);
    }
    
    return 0;
    
}
