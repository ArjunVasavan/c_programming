#include <stdio.h>

int main()
{
    int n;

    printf("Enter the size of the array -> ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements -> ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Unique elements: ");

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        
        // Count occurrences of arr[i]
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        
        // Print only if it appears exactly once and is the first occurrence
        if (count == 1)
        {
            printf("%d ", arr[i]);
        }
    }

    printf("\n");
    return 0;
}
