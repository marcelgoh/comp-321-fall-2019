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

    /* find first non-matching pair of characters pairwise */
    int first_diff = 0;
    while (first_diff < min_len && before[first_diff] == after[first_diff]) {
        ++first_diff;
    }
    /* search from end of strings for the first non-matching pair */
    int last_diff = 1;
    while (last_diff < min_len &&
           before[b_len - last_diff] == after[a_len - last_diff]) {
        ++last_diff;
    }

    /* number of letters that are the same in both */
    int num_same = first_diff + last_diff - 1;
    /* num_same cannot exceed length of either string */
    if (num_same > min_len) {
        num_same = min_len;
    }

    printf("%d\n", a_len - num_same);

    free(before);
    free(after);

    return 0;
}
