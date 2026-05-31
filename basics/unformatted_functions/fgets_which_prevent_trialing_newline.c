#include <stdio.h>
#include <string.h>

int main() {
    char str[50];

    fgets(str, sizeof(str), stdin);

    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    fputs(str, stdout);

    return 0;
}






// #include<stdio.h>
// int main()
// {
//
//   char str[50];
//
//   fgets(str,sizeof(str),stdin);
//
//   int i = 0;
//
//   while ( str[i] )
//   {
//     if ( str[i] == '\n' )
//     {
//       str[i] = '\0';
//     }
//     i+=1;
//   }
//
//   fputs(str,stdout);
// }
