#include <stdio.h>
#include <stdlib.h>

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
    while ((c = *(str++)) != '\0') {
        if (c == 'A') {
            cup = swap(cup, 1, 2);
        } else if (c == 'B') {
            cup = swap(cup, 2, 3);
        } else {
            cup = swap(cup, 1, 3);
        }
    }
    printf("%d\n", cup);

    return 0;
}

