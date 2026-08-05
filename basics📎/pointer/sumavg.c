#include <stdio.h>

void function ( int* n1 , int* n2 , int* n3 , int* sum , int* avg )
{
    *sum = *n1 + *n2 + *n3;
    *avg = (*sum)/3;
}

int main()
{
    int n1,n2,n3;

    int sum , avg;
    printf("Enter number1 -->");
    scanf("%d",&n1);
    printf("Enter number2 -->");
    scanf("%d",&n2);
    printf("Enter number3 -->");
    scanf("%d",&n3);

    function(&n1,&n2,&n3,&sum,&avg);

    printf("Sum --> %d , Average --> %d ",sum,avg);
}

