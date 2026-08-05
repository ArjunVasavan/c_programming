#include <stdio.h>

int main ()
{
    int n = 5;

    for (int i = n ; i >= 1 ; i-- )
    {
        for ( int j = 1 ; j <= n - i ; j++ )
        {
            printf(" ");  // what i learned from here is that if i exceed the space at "*_" format
                          // and put the white space as only one "_" it will show inverted full triangle
                          //
                          // if i want inverted left half of triangle both the "__" and "*_" star should have equal spacing.
        }
        for ( int k = 1 ; k <= i ; k++ )
        {
            printf("* ");
        }

            printf("\n");
    }
}
