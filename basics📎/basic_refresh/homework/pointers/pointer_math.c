#include <stdio.h>


int main()
{
    int x = 10 , y = 20 , z = 30 ; 

    int* ptr1, * ptr2 , * ptr3;

    ptr1 = &x;
    ptr2 = &y;
    ptr3 = &z;

    *ptr1 = *ptr2 - *ptr3;

    ptr2 = ptr3;

    ptr3 = ptr1;

    ptr1 = ptr2;

    *ptr2 = *ptr1 - *ptr3;

    ptr2 = ptr1;

    ptr1 = ptr3;

    ptr3 = ptr2;

    *ptr3 = *ptr2 - *ptr1;


    printf("%d %d %d %p %p %p %d %d %d \n",x,y,z,ptr1,ptr2,ptr3,*ptr1,*ptr2,*ptr3);
}

