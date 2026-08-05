/*
--------------------------------------------------------------------------------
  Name : Arjun Vasavan
  Description:

        Pre-requisites:

            • Knowledge about multi-thread process, How to read and understand ‘man pages’.
            • Good knowledge about pthread library functions. 
            • Multiplication of two matrices. 
            • Dynamic allocation for 2D array. 

        Objective: 

            • To understand working and flow of multithread programs. 

        Sample execution: -

            1. ./matrix_mul 

                Enter M1 rows and columns 3  3 
                Enter M2 rows and columns 3  3
                Enter M1 values 1  2  3  1  1  1  2  2  2
                Enter M2 values 1  2  3  1  2  3  1  2  3 
                Result is 
                14 14 14 
                6  6  6 
                12 12 12

--------------------------------------------------------------------------------
*/
#include <stdio.h>          // Header file to include functions like printf, scanf
#include <stdlib.h>         // Header file to include functions like malloc, free
#include <pthread.h>        // Header file to include pthread functions pthread_create, pthread_join

// Structure to pass data to thread
typedef struct {
    short m1_col;           // Number of columns in matrix1 (N)
    short m2_col;           // Number of columns in matrix2 (P)
    int **m1;               // Pointer to matrix1
    int **m2;               // Pointer to matrix2
    int **res;              // Pointer to result matrix
    short cur_row;          // Current row to compute
} Thread_data_t;

int **alloc_matrix(int rows, int cols) {

    int **mat = malloc(rows * sizeof(int *));   // Allocate row pointers
    for (int i = 0; i < rows; i++)
        mat[i] = malloc(cols * sizeof(int));    // Allocate columns
    return mat;

}

void free_matrix(int **mat, int rows) {

    for (int i = 0; i < rows; i++)
        free(mat[i]);                            // Free each row
    free(mat);                                   // Free row pointers
    
}

void *matrix_mul(void *arg) {

    Thread_data_t *data = (Thread_data_t *)arg;  // Typecast argument

    for (int j = 0; j < data->m2_col; j++) {
        data->res[data->cur_row][j] = 0;         // Initialize result cell

        for (int k = 0; k < data->m1_col; k++) {
            data->res[data->cur_row][j] +=
                data->m1[data->cur_row][k] * data->m2[k][j];
        }
    }
    return NULL;                                 // Exit thread
    
}

int main() {

    int M, N, N1, P;                             // Matrix dimensions

    printf("Enter Matrix1 rows and columns: ");
    scanf("%d %d", &M, &N);                      // Read M1 size

    printf("Enter Matrix2 rows and columns: ");
    scanf("%d %d", &N1, &P);                      // Read M2 size

    if(N != N1) {
        printf("Column of matrix 1 must be same for row of matrix 2\n");
        return 1;
    }
    // Allocate matrices dynamically
    int **M1 = alloc_matrix(M, N);               // Matrix 1 (M x N)
    int **M2 = alloc_matrix(N, P);               // Matrix 2 (N x P)
    int **RES = alloc_matrix(M, P);              // Result (M x P)

    // Read Matrix 1 values
    printf("Enter M1 values: ");
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &M1[i][j]);

    // Read Matrix 2 values
    printf("Enter M2 values: ");
    for (int i = 0; i < N; i++)
        for (int j = 0; j < P; j++)
            scanf("%d", &M2[i][j]);


    // Create threads

    pthread_t tid[M];                            // One thread per row
    Thread_data_t tdata[M];                      // Thread data array

    for (int i = 0; i < M; i++) {
        tdata[i].m1_col = N;
        tdata[i].m2_col = P;
        tdata[i].m1 = M1;
        tdata[i].m2 = M2;
        tdata[i].res = RES;
        tdata[i].cur_row = i;

        pthread_create(&tid[i], NULL, matrix_mul, &tdata[i]); // Create threads
    }

    for (int i = 0; i < M; i++) {
        pthread_join(tid[i], NULL); // Join threads
    }


    printf("Result matrix:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            printf("%d ", RES[i][j]); // Print result matrix elements
        }
        printf("\n");
    }

    // Free allocated memory
    free_matrix(M1, M);
    free_matrix(M2, N);
    free_matrix(RES, M);

    return 0;                                    // End of program
}
