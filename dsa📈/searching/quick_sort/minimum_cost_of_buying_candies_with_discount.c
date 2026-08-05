// @leet start
#include <stdlib.h>

/* NOTE: Descending quick sort is used
 * for interchanging with ascend or descend just change 2 typos only
 */

void swap(int* arr, int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int pivot_index(int* arr, int low, int high) {

    int i = low;
    int j = high;
    int pivot = low;

    /* NOTE: Changing typo
     * int below i commented what are the things to change to interchange 
     * between ascending and Descending
     */

    while ( i < j) {
        /*             ↓ if you make this opposite it becomes ascending */
        while ( arr[i] >= arr[pivot] && i <= high - 1) {
            i++;
        } /*           ↓ if you make this opposite it becomes ascending  */
        while ( arr[j] < arr[pivot] && j >= low + 1 ) {
            j--;
        }

        if ( i < j ) {
            swap(arr, i, j);
        }
    }

    swap(arr, j, low);

    return j;
}

void quick_sort(int* arr, int low, int high) {

    if ( low < high ) {
        int pivot = pivot_index(arr, low, high);
        quick_sort(arr, pivot+1, high);
        quick_sort(arr,low, pivot-1);
    }

}

int minimumCost(int* cost, int costSize) {

    quick_sort(cost, 0, costSize-1);

    int skip = 0;
    int sum = 0;
    for ( int i = 0; i < costSize; i++  ) {
        if ( skip == 2 ) {
            skip = 0;
            continue;
        }
        sum+=cost[i];
        skip+=1;
    }
    return sum;
}
// @leet end

