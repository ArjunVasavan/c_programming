#include <stdio.h>

int main()
{
    int n;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    
    int arr[n];
    printf("Enter elements : ");
    for(int i = 0 ; i <  n ; i++)
    {
        scanf("%d",&arr[i]);
    }
   int flag = 0;
       if (arr[0] > arr[1])
       {
               for (int j = 2 ; j < n-1 ; j+=2)
               {
                   if (arr[j]< arr[j+1] || arr[j] < arr[j-1])
                   {
                       flag = 1;
                       break;
                   }
               }
        }
       
       else if (arr[0] < arr[1])
       {
               for (int j = 1 ; j < n-1 ; j+=2)
               {
                   if (arr[j]< arr[j+1] || arr[j] < arr[j-1])
                   {
                       flag = 1;
                       break;
                   }
               }

           }

   if ( flag == 0 )
   {
       printf ("its an wave form \n");
   }
   else
   {
       
       printf ("its not  an wave form \n");
   }

}

