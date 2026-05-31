#include <stdio.h>
int main()
{
    int i,j,n;
    printf("   Enter an 'n' value : ");
    scanf("%d",&n);
    printf("\n");


            printf("|-----------------------------------|\n");
            printf("| i value | j value |i and j value  |\n");
            printf("|-----------------------------------|\n");
    for ( i = 0 ; i <= n ; i++ )
    {
        for(j = 0; j <= i ; j++)
        {
            printf("|  i => %d | j => %d | (i,j) => (%d,%d) |\n",i,j,i,j);
            printf("|         |        |                |\n");
        }
    }
            printf("|-----------------------------------|\n");
            printf("\n");
}
