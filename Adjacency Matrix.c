#include <stdio.h>

void initializeMatrix(int matrix[6][6]){
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 6; j++){
            matrix [i][j] = 0;
        }
    }
}

void addEdge(int matrix[6][6], int start, int end){
    matrix[start - 1][end - 1] = 1;
    matrix[end - 1][start - 1] = 1; //For an undirected graph - you can go back and forth
}

void printMatrix(int matrix[6][6]){
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 6; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
}


int main(){
    int matrix[6][6];
    initializeMatrix(matrix);
    
    addEdge(matrix, 1, 2);
    addEdge(matrix, 1, 5);
    addEdge(matrix, 2, 3);
    addEdge(matrix, 3, 4);
    addEdge(matrix, 4, 5);
    addEdge(matrix, 4, 6);
    addEdge(matrix, 5, 2);
    
    
    printMatrix(matrix);
    return 0;
    
}
