#include<stdio.h>

int main()
{
    int row,col;

    printf("Enter row and col\n");
    scanf("%d %d",&row,&col);

    int *arr[row];

    for( int i = 0; i<row; i++ )
    {
        arr[i]=malloc(col * sizeof(int));
    }
}