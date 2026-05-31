#include<stdio.h>
int main(){
    int n;
    printf("Enter an Number : ");
    scanf("%d",&n);

    switch (n)
    {
        case 1:
            printf("You have entered 1");
            break;
        case 2:
            printf("you have entered 2");
            break;
        case 3:{
                   printf("you have entered 3");
               }
        default:
               printf("outside limit");
    }

}
