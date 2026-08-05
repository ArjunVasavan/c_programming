#include <stdio.h>
int main()
{
    int n;
    int s;
    int ratio;
    int temp;
    int c = 0;

    printf("Enter N :");
    scanf("%d",&n);

    printf("Enter start :");
    scanf("%d",&s);

    printf("Enter common ratio :");
    scanf("%d",&ratio);
    temp = s;
    while ( c < n )
    {
        printf("%d ,",temp);

        temp = temp * ratio;

        c++;
    }
}

