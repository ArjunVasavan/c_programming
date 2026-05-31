#include <stdio.h>

int main() {
    int n ;

    printf("Enter number of rows: ");
     scanf("%d", &n);

    int start = 1;
    int diff = n;

    for (int i = 0; i < n; i++) {
        int val = start;
        for (int j = 0; j <= i; j++) {
            printf("%d", val);
            if (j < i) printf(" ");
            val -= (n - j);
        }
        printf("\n");
        start += diff;
        diff--;
    }

}

