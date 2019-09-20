/* Enumerate all subarrays of an array */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 6

int main() {
    char array[] = {'a', 'e', 'i', 'o', 'u', 'y'};
    char *sub;
    /* iterate through all 2^n - 1 possibilities */
    for (int i = 0; i < (1 << SIZE); ++i) {
        sub = (char *) malloc(SIZE*sizeof(char));
        int count = 0;
        for (int j = 0; j < SIZE; ++j) {
            /* check for 1-bit in number */
            if ((1 << j) & i) {
                sub[count++] = array[j];
            }
        }
        /* print subarray */
        for (int j = 0; j < count; ++j) {
            printf("%c ", sub[j]);
        }
        printf("\n");
        free(sub);
    }

    return 0;
}

