#include <stdio.h>

int main(){
    int n, sum = 0;
    printf("Enter n value: \n");
    scanf("%d",&n);

    if (n <= 0){
        printf("Error: n must be a positive integer \n");
        return 1; // Exit program with an error code
    }

    for (int i = 1; i <= n; i++){
        sum += i;
    }

    printf("The sum of all values from 1to %d is: %d\n", n, sum);

        return 0;

}
