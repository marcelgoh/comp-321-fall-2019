#include <stdio.h>
#include <stdlib.h>

int m, n;

/* deletes an amoeba from the board recursively */
void clear(int grid[m][n], int i, int j) {
    int i_max = (i + 2 < m) ? i + 2 : m;
    int j_max = (j + 2 < n) ? j + 2 : n;
    int i_min = (i - 1 <= 0) ? 0 : i - 1;
    int j_min = (j - 1 <= 0) ? 0 : j - 1;
    /* clear cell (i,j) first before checking all neighbours */
    grid[i][j] = 0;
    for (int a=i_min; a<i_max; ++a) {
        for (int b=j_min; b<j_max; ++b) {
            if (grid[a][b]) {
                /* recurse on first neighbour found */
                return clear(grid, a, b);
            }
        }
    }
    /* if all neighbours clear, base case just exits */
}

int main() {
    scanf("%d %d", &m, &n);
    int grid[m][n];

    char buffer[101];
    for (int i=0; i<m; ++i) {
        scanf("%s", buffer);
        for (int j=0; j<n; ++j) {
            if (buffer[j] == '#') {
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
        }
    }

    int count = 0;
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            if (grid[i][j]) {
                /* increase count on each amoeba found, then clear */
                ++count;
                clear(grid, i, j);
            }
        }
    }

    printf("%d\n", count);

    return 0;
}
