#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *before = malloc(100001*sizeof(char));
    char *after = malloc(100001*sizeof(char));
    scanf("%s", before);
    scanf("%s", after);
    int b_len = strlen(before);
    int a_len = strlen(after);

    int min_len = (b_len < a_len) ? b_len : a_len;

    int first_diff = 0;
    while (first_diff < min_len && before[first_diff] == after[first_diff]) {
        ++first_diff;
    }
    int last_diff = 1;
    while (last_diff < min_len &&
           before[b_len - last_diff] == after[a_len - last_diff]) {
        ++last_diff;
    }

    /* number of letters that are the same in both */
    int num_same = first_diff + last_diff - 1;
    /* num_same cannot exceed length of first string */
    if (num_same > b_len) {
        num_same = b_len;
    }

    /* difference is second length - num_same; if this value
     * is negative, just set to 0
     */
    int difference = (a_len - num_same >= 0) ? a_len - num_same : 0;
    printf("%d\n", difference);

    free(before);
    free(after);

    return 0;
}
