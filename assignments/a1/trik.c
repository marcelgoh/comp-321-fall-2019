#include <stdio.h>
#include <stdlib.h>

/* returns value of correct cup after a swap of a and b;
 * it is possible cup does not change */
int swap(int cup, int a, int b) {
    if (cup == a) {
        return b;
    } else if (cup == b) {
        return a;
    }
    return cup;
}

int main() {
    char *str = malloc(51*sizeof(char));
    char c;

    scanf("%s", str);

    int cup = 1;
    /* iterate through every character in string and perform swaps */
    while ((c = *(str++)) != '\0') {
        if (c == 'A') {
            cup = swap(cup, 1, 2);
        } else if (c == 'B') {
            cup = swap(cup, 2, 3);
        } else {
            cup = swap(cup, 1, 3);
        }
    }
    /* print final position */
    printf("%d\n", cup);

    return 0;
}

