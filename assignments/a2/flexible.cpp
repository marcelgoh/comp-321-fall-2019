#include <stdio.h>
#include <cstdlib>
#include <set>

int main() {
    int w, p;
    scanf("%d %d", &w, &p);

    int *arr = (int*) malloc((p + 2)*sizeof(int));
    /* fill array with {0, ..., w} */
    arr[0] = 0;
    arr[p+1] = w;
    for (int i=1; i<=p; ++i) {
        scanf("%d", arr+i);
    }

    std::set<int> nums;
    /* for all i < j, add arr[j] - arr[i] to set */
    for (int i=0; i<=p+1; ++i) {
        for (int j=i+1; j<=p+1; ++j) {
            nums.insert(arr[j]-arr[i]);
        }
    }

    /* print numbers in set in increasing order */
    for (auto n : nums) {
        printf("%d ", n);
    }
    printf("\n");

    return 0;
}
