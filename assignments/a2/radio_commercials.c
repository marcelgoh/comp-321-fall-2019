#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, p;
    scanf("%d %d", &n, &p);

    int *arr = (int *) malloc(n*sizeof(int));

    /* array of best sums so far */
    int *sums = (int *) malloc(n*sizeof(int));

    for (int i=0; i<n; ++i) {
        scanf("%d", &arr[i]);
        arr[i] = arr[i] - p;
    }

    if (n == 0) {
        printf("%d\n", 0);
    } else {
        sums[0] = arr[0];
        for (int i=1; i<n; ++i) {
            /* add previous sum if not negative, otherwise just start a new sum */
            sums[i] = (sums[i-1] > 0) ? sums[i-1] + arr[i] : arr[i];
        }

        int max = sums[0];
        int idx = 0;
        /* find max and print it */
        for (int i=1; i<n; ++i) {
            if (sums[i] > max) {
                max = sums[i];
                idx = i;
            }
        }
        printf("%d\n", max);
    }

    return 0;
}


