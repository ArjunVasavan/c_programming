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
    for ( int i = 0 ; i <  n ; i++ )
    {
        int present = 0;
        for ( int k = 0 ; k < i ; k++ )
        {
            if ( arr[i] == arr[k] )
            {
                present = 1;

                break;
            }
        }

        int count = 0;

        if(present != 1 )

        {

            for ( int j = i + 1  ; j < n ; j++ )
            {
                    if ( arr[i] == arr[j] )
                    {
                        count = 1;
                        break;
                    }
            }
            if ( count == 1  )
            {
                printf("%d ",arr[i]);

            }




        }

    }
}
