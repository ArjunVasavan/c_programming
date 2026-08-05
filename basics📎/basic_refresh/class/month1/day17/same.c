#include <stdio.h>

int main ()
{
    int n ,m;
    printf("Enter size of arr 1 : ");

    scanf("%d",&n);

    printf("Enter size of arr 2 : ");
    
    scanf("%d",&m);

    int arr1[n];
    int arr2[m];

    int flag = 0;

    int l;
    
    if ( n == m )
    {

    printf("Enter arr1 elements : ");

    for ( int s = 0 ; s < n ; s++ )
    {
        scanf("%d",& arr1[s]);
    }
    printf("Enter arr2 elements : ");

    for ( int p = 0 ; p < m ; p++)
    {
        scanf("%d",& arr2[p]);
    }   

    for ( l = 0 ; l < n ; l++ )
    {

        flag = 0;

        for ( int j = 0 ; j < n ; j++ )
        {
            if ( arr1[l] == arr2[j] )
            {
                flag = 1;

                break;
            }
        }
        
        if ( flag == 0 )
        {
            break;
        }
    }

    if ( l == n )
    {
        printf("Both array are equal \n");
    }
    else
    {
        printf("Both array is not equal !\n");
    }

}

else
{
    printf("Make both size same \n");
}

}
