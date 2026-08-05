#include <stdio.h>

int main ()
{
    int n = 5;

    for (int i = n ; i >= 1 ; i-- )
    {
        for ( int j = 1 ; j <= n - i ; j++ )
        {
            printf("  "); // what i learned from here is that if i put only one place it will show inverted full traingle but
                          // if i write only one space it will show inverted left half of pyramid
        }
        for ( int k = 1 ; k <= i ; k++ )
        {
            printf("* ");
        }

            printf("\n");
    }
}
