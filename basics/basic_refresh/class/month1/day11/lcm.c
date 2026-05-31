#include<stdio.h>
int main ()
{
    int n1,n2,mult;
    printf("Enter an number 1 :");
    scanf("%d", &n1);
    printf("Enter an number 2 :");
    scanf("%d", &n2);

    for(int i = 2; i<= (n1*n2) ; i++)
    { mult = n1*i;
        if (mult % n2 == 0)
        {
            break;
        }

    }
    printf("%d \n",mult);

}
