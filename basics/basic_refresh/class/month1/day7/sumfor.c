#include <stdio.h>

int main() {
	int n;
	int sum = 0 ;
	printf("enter n :");
	scanf("%d",&n);

    for ( int i = 0; i <= n; i++)
    {
        sum = sum + i ;
    }
	    printf("%d\n",sum);
    return 0;
}

