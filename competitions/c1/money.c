#include <stdio.h>
#include <stdlib.h>

int main() {
    int num_friends, num_ships;

    scanf("%d %d", &num_friends, &num_ships);

    int *owes = malloc(num_friends*sizeof(int));
    for (int i=0; i<num_friends; ++i) {
        scanf("%d", owes + i);
    }

    int *ships = malloc(num_friends*sizeof(int));

    for (int i=0; i<num_friends; ++i) {
        ships[i] = i;
    }

    for (int i=0; i<num_ships; ++i) {
        int m, n;
        scanf("%d %d", &m, &n);

        int temp = ships[n];
        for (int j=0; j<num_friends; ++j) {
            if (ships[j] == temp) {
                ships[j] = ships[m];
            }
        }
    }

    int possible = 1;
    for (int i=0; i<num_friends; ++i) {
        int sum = 0;
        for (int j=0; j<num_friends; ++j) {
            if (ships[j] == i) {
                sum += owes[j];
            }
        }
        if (sum != 0) {
            possible = 0;
            break;
        }
    }

    if (possible) {
        printf("POSSIBLE\n");
    } else {
        printf("IMPOSSIBLE\n");
    }

    free(owes);
    free(ships);

    return 0;
}
