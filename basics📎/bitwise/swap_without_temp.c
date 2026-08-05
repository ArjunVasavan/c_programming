#include <stdio.h>
int main(int argc, char** argv)
{
    printf("Enter two number a and b: ");
    int a,b;
    scanf("%d %d",&a,&b);


    a ^= b;
    b ^= a;
    a ^= b;

    printf("After Swapping a -> %d and b -> %d \n",a,b);
}
