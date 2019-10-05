/* Generate all permutations of array */

#include <stdio.h>
#include <stdlib.h>

/* prints all permutations of a sorted array in lexicographic order
 * modifies the array
 */
void lexicographic(int len, int *arr) {
    while (1) {
        /* print permutation */
        for (int i=0; i<len; ++i) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        /* find next permutation */
        int j = len - 2;
        while (arr[j] >= arr[j+1]) {
            --j;
        }
        if (j == 0) {
            /* all permutations have been exhausted */
            break;
        }
        int l = len - 1;
        while (arr[j] >= arr[l]) {
            --l;
        }
        /* arr[l] is the smallest element greater than a[j] than can follow
         * arr[1], ..., arr[j-1] in a permutation
         */
        int temp = arr[j];
        arr[j] = arr[l];
        arr[l] = temp;
        int k = j + 1;
        l = len - 1;
        while (k < l) {
            temp = arr[k];
            arr[k] = arr[l];
            arr[l] = temp;
            ++k;
            --l;
        }
    }
}

int main() {
    int arr[] = {1, 2, 2, 3};
    lexicographic(4, arr);

    return 0;
}
