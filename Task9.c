#include <stdio.h>

int main(){

        int number;
        int sum = 0;

        printf("Enter a non-negative number:  \n");
        scanf("%d", &number);

        int i = 1;// Start from 1

        while (i< number){
        if (i % 3 == 0 || i % 5 == 0){
                sum += i;

        }
        i++;

        }

        printf("The sum of all multiples of 3 or 5 below %d is: %d\n", number, sum);



        return 0;
}
