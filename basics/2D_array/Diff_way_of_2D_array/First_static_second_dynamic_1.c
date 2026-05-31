#include<stdio.h>
#include<stdlib.h>

void scan_arr ( int r , int c , int** ptr )
{
    for ( int i = 0 ; i<r ; i++ )
    {
        for ( int j = 0 ; j<c; j++ )
        {
            scanf("%d",&ptr[i][j]);
        }
    }
}

void print_arr ( int r , int c , int** ptr )
{
    for ( int i = 0 ; i<r ; i++ )
    {
        for ( int j = 0 ; j<c; j++ )
        {
            printf("%d ",ptr[i][j]);
        }
        printf("\n");
    }
}

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

    scan_arr(row,col,arr);
    print_arr(row,col,arr);

    int n_col;

    printf("Enter the new col value\n");
    scanf("%d",&n_col);

    for ( int i = 0 ; i < row ; i++ )
    {
        arr[i] = realloc( arr[i] , n_col * sizeof(int) );
    }

    if ( n_col > col )
    {
        for ( int i = 0 ; i < row ; i++ )
        {
            for ( int j = col ; j < n_col ; j++ )
            {
                scanf ("%d",&arr[i][j]);
            }
        }
    }

    print_arr(row,n_col,arr);

}