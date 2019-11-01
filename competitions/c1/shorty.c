#include <stdio.h>
#include <stdlib.h>

int main() {
    int num_int, num_cor;

    float ans[22];

    int num_cases = 0;

    while (num_cases < 20) {
        scanf("%d %d", &num_int, &num_cor);

        if (num_int == 0 && num_cor == 0) {
            break;
        }

        float a[num_int+1][num_int+1];
        for (int i=0; i<num_int; ++i) {
            for (int j=0; j<num_int; ++j) {
                a[i][j] = -1;
            }
        }

        for (int i=0; i<num_cor; ++i) {
            int k, l;
            float f;
            scanf("%d %d %4f", &k, &l, &f);
            a[k][l] = f;
            a[l][k] = f;
        }

        /*
        for (int i=0; i<num_int; ++i) {
            for (int j=0; j<num_int; ++j) {
                printf("%4f ", a[i][j]);
            }
            printf("\n");
        }
        */

        float arr[num_int+2];
        for (int i=0; i<num_int; ++i) {
            arr[i] = -1;
        }

        arr[0] = 1;

        for (int i=0; i<num_int; ++i) {
            for (int j=0; j<num_int; ++j) {
                if (a[i][j] > 0) {
                    float x = arr[i] * a[i][j];
                    if (x > arr[j]) {
                        arr[j] = x;
                    }
                }
            }
        }

        /*
        for (int i=0; i<num_int; ++i) {
            printf("%4f ", arr[i]);
        }
        printf("\n");
        */

        ans[num_cases++] = arr[num_int - 1];

    }

    for (int i=0; i<num_cases; ++i) {
        printf("%0.4f\n", ans[i]);
    }

    return 0;
}
