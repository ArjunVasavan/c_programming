#include <stdio.h>

int main()
{
    int f = 0;

    int size = 0;

    printf("Enter the size of array --> : ");
    scanf("%d",&size);

    int arr[size];

    printf("Enter the array elements --> : ");
    for ( int i = 0 ; i < size ; i++ )
    {
        scanf("%d",&arr[i]);
    }

    printf("Enter 'n' to find triplets --> : ");
    scanf("%d",&f);

    int flag = 0;

    for ( int i = 0 ; i < size ; i++ )
    {
        for ( int j = i+1 ; j < size ; j++ )
        {
            for ( int k = i+2 ; k < size ; k++ )
            {
                if (arr[i]+arr[j]+arr[k]==f)
                {
                 printf("[%d %d %d]\n",arr[i],arr[j],arr[k]);

                 flag = 1;
                }
            }
        }
    }

    if ( flag == 0 )
    {
        printf("No elements found \n");
    }

}

