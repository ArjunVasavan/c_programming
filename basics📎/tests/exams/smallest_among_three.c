#include <stdio.h>

int smallest ( int n1 , int n2 , int n3 )
{
    int small = n1;

    if ( n2 < small  )
    {
        small = n2;
    }
    if ( n3 < small  )
    {
        small = n3;
    }

    return small;
}

int main()
{
    printf("Enter Num1 Num2 Num3 -->");
    int n1 , n2 , n3;

    scanf("%d %d %d",&n1,&n2,&n3);

    printf("Smallest --> %d \n",smallest(n1,n2,n3));
}

