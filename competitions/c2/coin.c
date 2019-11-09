#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int greedy(int *coins, int n, int sum) {
    int total = 0;

    for (int i=n-1; i>=0; --i) {
        total += sum / coins[i];
        sum = sum % coins[i];
    }

    return total;
}

int main() {
    int n;

    scanf("%d", &n);

    int coins[n];

    for (int i=0; i<n; ++i) {
        scanf("%d", coins + i);
    }

    int largest = coins[n-1] + coins[n-2];

    int dp[largest+1];
    for (int i=0; i<largest+1; ++i) {
        dp[i] = 0;
    }

    for (int i=0; i<n; ++i) {
        for (int k=0; k<largest-coins[i]+1; ++k) {
            int new = dp[k] + 1;
            if (new < dp[k + coins[i]] || dp[k + coins[i]] == 0) {
                dp[k + coins[i]] = new;
            }
        }
    }
    /*
    for (int i=0; i<largest+1; ++i) {
        printf("%d ", dp[i]);
    }
    printf("\n");
    */

    int canonical = 1;

    for (int i=0; i<largest+1; ++i) {
        if (greedy(coins, n, i) > dp[i]) {
            canonical = 0;
            break;
        }
    }

    if (canonical) {
        printf("canonical\n");
    } else {
        printf("non-canonical\n");
    }

    return 0;
}
