#include <stdio.h>
#include <stdlib.h>

/* sums the digits of an integer, recursively */
int sum_digits(int n) {
    if (n == 0) {
        return 0;
    }

    int q = n / 10;
    int r = n % 10;

    return r + sum_digits(q);
}

int main() {
    int m;

    while(1) {
        scanf("%d", &m);

        if (m == 0) {
            break;
        }

        int n = 11;
        /* does a linear search for the first n that leaves m unaffected */
        for (; n <= 100000; ++n) {
            if (sum_digits(n*m) == sum_digits(m)) {
                break;
            }
        }

        printf("%d\n", n);
    }

    return 0;
}


