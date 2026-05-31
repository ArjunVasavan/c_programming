#include <stdio.h>
int main() {
    int n;
    printf("Enter N value : ");
    scanf("%d", &n);

    for (int i = 1 ; i <= n ; i++) {
        // Print first triangle
        for (int j = 1 ; j <= n ; j++) {
            if (i + j >= n + 1)
                printf("* ");
            else
                printf("  "); 
        }

        if (i != 1) {
            for (int k = 1 ; k <= i - 1 ; k++) {
                printf("* ");
            }
        }

        printf("\n"); 
    }

    return 0;
}

