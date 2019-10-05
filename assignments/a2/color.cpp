#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <algorithm>

int diff(int a, int b) {
    return (a > b) ? a - b : b - a;
}

int main() {
    int s, c, k, temp;
    /* get input */
    scanf("%d %d %d", &s, &c, &k);

    std::vector<int> socks;

    /* fill vector with integers */
    for (int i=0; i<s; ++i) {
        scanf("%d", &temp);
        socks.push_back(temp);
    }

    std::sort(socks.begin(), socks.end());

    if (socks.size() == 0) {
        printf("%d\n", 0);
    } else {
        /* contains at least one sock */
        int count = 1;
        int first = socks.at(0);
        int taken = 1;
        for (int i=1; i<socks.size(); ++i) {
            if (taken >= c || diff(first, socks.at(i)) > k) {
                /* start a new machine */
                ++count;
                first = socks.at(i);
                taken = 1;
            } else {
                /* always take a new sock if we can */
                ++taken;
            }
        }
        printf("%d\n", count);
    }

    return 0;
}
