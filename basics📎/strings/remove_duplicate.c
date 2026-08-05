#include <stdio.h>d

char* dup(char* str)
{
    int i = 0;

    while (str[i]) {
        int j = i + 1;
        int dupFound = 0;

        while (str[j]) {
            if (str[i] == str[j]) {
                int k = j;
                while (str[k]) {
                    str[k] = str[k+1];
                    k++;
                }
                dupFound = 1;
            } else {
                j++;
            }
        }

        if (dupFound) {
            int k = i;
            while (str[k]) {
                str[k] = str[k+1];
                k++;
            }
        } else {
            i++;
        }
    }

    return str;
}

int main()
{
    printf("Enter an String->");
    char str[50];

    scanf("%[^\n]",str);

    char* ret = dup(str);

    printf("%s\n",ret);
}

