#include <stdio.h>
#include <stdbool.h>

#define MAX 100

// function to print one permutation
void printPermutation(int *ds, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", ds[i]);
    }
    printf("\n");
}

// recursive function
void recurPermute(int *nums, int n, int *ds, bool *freq, int level) {

    // base case
    if (level == n) {
        printPermutation(ds, n);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!freq[i]) {

            // pick element
            freq[i] = true;
            ds[level] = nums[i];

            // recurse
            recurPermute(nums, n, ds, freq, level + 1);

            // backtrack
            freq[i] = false;
        }
    }
}

int main() {
    int nums[] = {1, 2, 3};
    int n = 3;

    int ds[MAX];          // current permutation
    bool freq[MAX] = {0}; // used elements

    recurPermute(nums, n, ds, freq, 0);

    return 0;
}
