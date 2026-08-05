#include <stdio.h>

int pangram(char []);

int main() {
    char str[50];
    printf("Enter the string : ");
    scanf("%[^\n]",str);

    if ( pangram(str) ){
        printf("The entered string is an pangram\n");
    } else {
        printf("The entered string is not an pangram\n");
    }

}

int pangram ( char str[] ) {
    int i = 0;
    int arr[26] = {0};
    while ( str[i] ) {
        if  ( str[i] >='a' && str[i] <= 'z' ) {
            arr[ str[i] - 'a'] = 1;
        }
        else if ( str[i] >= 'A' && str[i] <= 'Z' ){
            arr[str[i] - 'A'] = 1;
        }
        i+=1;
    }
    for ( int j = 0 ; j < 26 ; j++ ) {
        if ( arr[j] == 0 ) {
            return 0;
        }
    }
    return 1;
}
