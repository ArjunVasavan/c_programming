#include <stdio.h>

void fandl(char* str)
{
    int i = 0;

    char first = '\0';        /* CHANGED: initialize to avoid garbage */
    char last  = '\0';        /* CHANGED: initialize to avoid garbage */
    int word = 0;
    while (str[i])
    {
        /* detect word start (same logic you had) */
        if ( i == 0 && str[0] != ' ' )
        {
            first = str[0];
            word = 1;
        }
        else if ( str[i] == ' ' && str[i+1] != ' ' && str[i+1] != '\0' )
        {
            first = str[i+1];
            word = 1;
        }

        /* <-- REMOVED printf("%c",first); from here (it caused repeated prints) */ /* MOVED */

        /* detect word end and print once per word (moved/changed logic) */
        if ( word == 1  &&  str[i] != ' ' && (str[i+1] == ' ' || str[i+1] == '\0'))
        {
            last = str[i];
            /* CHANGED: print only when word ends. handle single-letter words */
            if (first == last)
                printf("%c ", first);
            else
                printf("%c%c ", first, last);

            word = 0;
        }

        /* <-- REMOVED printf("%c%c",first,last); from here (it printed before last was set) */ /* MOVED */
        /* printf(" "); removed because printing happens when word ends */

        i+=1;
    }

    printf("\n");
}

int main()
{
    char str[50];

    printf("Enter a String -> ");
    scanf("%[^\n]",str);

    fandl(str);
}

