#include <stdio.h>

int main() {
	int n;
	int fact = 1 ;
	printf("enter n :");
	scanf("%d",&n);

    for ( int i = 2; i <= n; i++)
    {
        fact = fact * i ;
    }
	    printf("%d\n",fact);
    return 0;
}

