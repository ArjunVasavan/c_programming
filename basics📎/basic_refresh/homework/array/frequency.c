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
    
    printf("\n");
    int count = 1;

    for ( int i = 0 ; i < n ; i++ )
    {   
        int present = 0;
        //lookbehind
        for ( int k = 0 ; k < i ; k++ )
        {
            if (arr[i] == arr[k])
            {
                present = 1;

                break;
            }
        }
        count = 1;

        if ( present == 0 )
        {
            for ( int j = 0; j < n ; j ++ )
            {
                if ( i == j )
                {
                    continue;
                }

                if ( arr[i] == arr[j] )
                {
                    count+=1;
                }
            }

            printf("%d Element Frequency is ==> %d \n ",arr[i],count);
        }
    }
}

