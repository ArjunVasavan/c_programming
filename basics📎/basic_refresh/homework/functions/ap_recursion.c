#include <stdio.h>

void ap(int s , int d , int n)
{
    if ( n > 0 )
    {
        printf("%d ",s);
        return ap(s+d,d,n-=1);
    }
    else
    {
        return;
    }
}

int main()
{
    int s = 2, d = 2, n = 5;

    printf("Enter start difference and limit -->");
    scanf("%d %d %d",&s,&d,&n);

    ap(s,d,n);
    printf("\n");

}

