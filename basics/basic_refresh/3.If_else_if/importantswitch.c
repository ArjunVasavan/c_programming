#include <stdio.h>

int main() {
    char ch;

    printf("Enter the number: ");
    scanf("%c", &ch);

    switch (ch) {
        case 'A' ... 'Z':
            printf(" UPPER CASE CHAR!\n");
            break;
       case 97 ... 122: {
            printf(" lower case \n");
            break;
        }
        case 48 ... 57:
            printf(" digit character!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}



