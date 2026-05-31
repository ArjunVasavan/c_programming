#include <stdio.h>

void fibonacci ( int limit , int first , int second , int fib  )
{
    if ( fib <= limit )
    {
       printf("%d ",fib);

       second = first;
        first = fib;
        fib = first + second ;

        fibonacci( limit , first , second , fib );
    }
}

int main()
{

    int num;

    printf("Enter an number : --> ");
    scanf("%d",&num);
    
    printf("\n");

    fibonacci ( num , 1 , 1 , 0 );

    printf("\n");
}

