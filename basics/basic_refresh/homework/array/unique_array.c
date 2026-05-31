#include <stdio.h>

int main ()
{
    int n;

    printf("Enter the array size : ");
    scanf("%d",&n);

    int arr[n];

    printf("Enter the array elements : ");

    for ( int i = 0 ; i < n ; i++ )
    {
        scanf("%d",& arr[i]);
    }

    for ( int i = 0 ; i < n ; i ++ )
    {
        int lookbehind = 0;

        int founded = 0;

        for ( int k = 0 ; k < i ; k++ )
        {
            if ( arr[i] == arr[k] )
            {
                lookbehind = 1;

                break;
            }
        }

        if ( lookbehind != 1  )
        {
            for ( int j = i + 1; j < n ; j++ )
            {
                if(arr[i] ==  arr[j])
                {
                    founded = 1;

                    break;
                }
            }
        }

        if ( founded == 0 )
        {
            printf("%d ",arr[i]);
        }
    }
}
