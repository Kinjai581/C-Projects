#include <stdio.h>

int linearSearch(int arr[], int n, int key){
    for (int i = 0; i < n; i++){
        if(arr[i] == key){
            return i;
        }
    }
    return -1;
}


int main(){
    int arr[] = {5, 10, 15, 20, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int key = 15;
    int result = linearSearch(arr, n, key);
    
    if (result != -1){
        printf("Element %d found\n", key);
    }
    else{
        printf("Element not found\n");
    }
    return 0;
}
