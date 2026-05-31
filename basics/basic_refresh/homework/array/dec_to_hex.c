#include <stdio.h>

int main()
{
    int n = 1027;

    printf("Enter 'n' value --> :");
    scanf("%d",&n);

    int temp = n;

    int count = 0;

    while (temp != 0)
    {
        count+=1;
        temp/= 16;
    }
    int arr[count];

    for ( int i = 0 ; i < count ; i++ )
    {
        arr[i] = n%16;
        n = n/16;
    }

    printf("Hexadecimal value is -->  ");

    printf("OX");

    for ( int i = count - 1; i >= 0 ; i-- )
    {
        switch(arr[i])
        {
            case 10 : 
                {
                    printf("A");
                    break;
                }
            case 11 : 
                {
                    printf("B");
                    break;
                }
            case 12 : 
                {
                    printf("C");
                    break;
                }
            case 13 : 
                {
                    printf("D");
                    break;
                }
            case 14 : 
                {
                    printf("E");
                    break;
                }
            case 15 :
                {
                    printf("F");
                    break;
                }
            default:
                {
                    printf("%d",arr[i]);
                }
        }
    }

    printf("\n");

}

