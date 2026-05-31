#include<stdio.h>
#include<stdlib.h>
void read_arr(int row, int col, int **arr)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
}
void print_arr(int row, int col, int **arr)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int row, col;
    printf("Enter the row: ");
    scanf("%d", &row);
    printf("Enter col: ");
    scanf("%d", &col);
  //  int *arr[row];
    int **ptr = malloc(row * sizeof(int *));

    for(int i = 0; i < row; i++)
    {
        ptr[i] = malloc(col * sizeof(int));
    }

    read_arr(row, col, ptr);
    print_arr(row , col, ptr);

}
