// @leet start
#include <stdbool.h>
#include <stdlib.h>

void swap(int* array,int a,int b) {
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

int pivot_index(int* array, int low, int high) {

    /* NOTE: Fix of time exceed in quick_sort
     * organising an better low as pivot
     * and also this is even also exceeding time limit so im using 
     * standard quick_sort from stdlib
     */
    int mid = low + (high - low) / 2;
    if (array[low] > array[mid])   swap(array, low, mid);
    if (array[low] > array[high])  swap(array, low, high);
    if (array[mid] > array[high])  swap(array, mid, high);
    swap(array, low, mid);  // move median to low as pivot

    int pivot = low;
    int i = low;
    int j = high;

    while (i < j) {

        while (array[i] <= array[pivot] && i <= high - 1 ) {
            i++;
        }
        while (array[j] > array[pivot] && j >= low + 1) {
            j--;
        }
        if ( i < j ) {
            swap(array,i,j);
        }
    }
    swap(array, low, j);
    return j;
}

void quick_sort(int* array, int low, int high) {

    if ( low < high ) {
        int pivot = pivot_index(array, low, high);
        quick_sort(array, low, pivot-1);
        quick_sort(array, pivot+1, high);
    }

}

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

bool asteroidsDestroyed(int mass, int* asteroids, int asteroidsSize) {

    qsort(asteroids, asteroidsSize, sizeof(int), cmp);

    unsigned long long accumulate = mass;

    for ( int i = 0 ; i < asteroidsSize; i++ ) {

        if ( accumulate < asteroids[i]) {
            return false;
        } else {
            accumulate+=asteroids[i];
        }

    }
    return true; 
}
// @leet end


