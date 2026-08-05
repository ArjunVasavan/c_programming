#include <stdio.h>
int main(int argc, char** argv) {
    
    printf("Enter an Value: ");
    int n;
    scanf("%d",&n);

    int arr[n];

    printf("Enter array value : ");

    for ( int i = 0 ; i < n  ; i ++){

        scanf("%d",&arr[i]);
    }

    for ( int i = 0 ; i < n ; i++ ){

        printf("%d ",arr[i]);
    }
}
