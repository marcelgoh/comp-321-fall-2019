#include <stdio.h>
#include <stdlib.h>

int main () {
    int h1, m1, s1, h2, m2, s2;

    scanf("%d:%d:%d", &h1, &m1, &s1);
    scanf("%d:%d:%d", &h2, &m2, &s2);

    int h = h2 - h1;
    int m = m2 - m1;
    int s = s2 - s1;

    if (s < 0) {
        s += 60;
        m -= 1;
    }
    if (m < 0) {
        m += 60;
        h -= 1;
    }
    if (h < 0) h += 24;

    if (h == 0 && m == 0 && s == 0) {
        h = 24;
    }

    printf("%02d:%02d:%02d\n", h, m, s);

    return 0;
}
