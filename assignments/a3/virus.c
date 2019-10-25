#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *before = malloc(10001*sizeof(char));
    char *after = malloc(10001*sizeof(char));
    scanf("%s", before);
    scanf("%s", after);
    int b_len = strlen(before);
    int a_len = strlen(after);

    if (strcmp(before, after) == 0) {
        printf("%d\n", 0);
    } else {
        int first_diff = 0;
        while (before[first_diff] == after[first_diff]) {
            ++first_diff;
        }
        int last_diff = 0;
        while (before[b_len - last_diff - 1] == after[a_len - last_diff - 1]) {
            ++last_diff;
        }

        printf("%d\n", a_len - first_diff - last_diff);
    }

    return 0;
}
