#include <stdio.h>

int main() {
	int n1,n2;
	int mul = 0;
	printf("enter n 1 and n2:");
	scanf("%d %d",&n1,&n2);

    for ( int i = 1; i <= n2; i++)
    {
        mul = mul + n1 ;
    }
	    printf("%d\n",mul);
    return 0;
}

