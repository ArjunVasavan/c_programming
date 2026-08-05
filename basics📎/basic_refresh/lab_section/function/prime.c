#include <stdio.h>

int prime(int x)
{
    int i = 0;
    for ( i = 2 ; i*i <= x ; i++ )
    {
        if ( x % i == 0 )
        {
            break;
        }
    }

    if ( i*i >= x )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int n;
    printf("Enter an Number -->");
    scanf("%d",&n);
    
    int check = prime(n);
    check ? printf("Its an Prime Number") : printf("Its not an prime number");

}

