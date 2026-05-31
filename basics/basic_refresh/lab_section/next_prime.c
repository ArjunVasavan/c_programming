#include<stdio.h>
int main()
{
    int n;

    int val;

    printf("Enter an Number : ");

    scanf("%d",&n);

    int i,j;

        for( i = 2 ; i <= n ; i++ )

        {

            for (j = 2 ; j*j <= i ; j++)
            {
                if(i%j == 0)

                {
                    break;
                }
            }

            if (j*j > i )
            {
                val = i;
            }


        }

            for (int l = val ; l*l <= val ; l++)
            {
                if(l*l > val)
                {
                    break;
                }

            }
                printf("%d ",val);

}
