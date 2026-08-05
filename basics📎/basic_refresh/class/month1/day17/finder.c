#include <stdio.h>
int main ()
{
    int n;
    int f;

    int flag = 0;
    printf("Enter element size : ");
    scanf("%d",&n);
        
    printf("Enter an element to find : ");
    scanf("%d",&f);

    int arr[n];

    printf("Enter elements : ");

    for ( int i = 0 ; i < n ; i++ )
    {
        scanf("%d",&arr[i]);
    }




    for ( int i = 0 ; i < n ; i++ )
    {
        if ( f  == arr[i] )
        {
            printf("Element %d is founded at index position %d \n",f,i);
            
            flag = 1;

            break;
        }

    }

    if ( flag == 0 )
    {
        printf("Error Element not found !");
    }
}
