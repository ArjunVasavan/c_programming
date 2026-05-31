#include <stdio.h>

int main ()
{
    int n;
    int f;
    int j = 0
        ;
    printf("Enter the array size : ");
    scanf("%d",&n);

    int arr[n];

    printf("Enter the array elements : ");

    for ( int i = 0 ; i < n ; i++ )
    {
        scanf("%d",& arr[i]);
    }

    printf("Enter the Sum You need to find : ");

    scanf("%d",&f);

    for ( int i = 0 ; i < n ; i++ )
    {

        int flag = 0;

        for (  j = i+1 ; j < n ; j++ ) // with this condition (j = i + 1) we dont need extra flags for i == j and it compares before also on sum par
        {
            if  ( arr[i] + arr[j] == f )
            {

                flag = 1;

                store = j;

                break;

            }
        }

        if (flag == 1)
        {
            printf("(%d,%d) \n",arr[i],arr[store]);
        }
    }
}
