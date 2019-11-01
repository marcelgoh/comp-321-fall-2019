#include <stdio.h>
#include <stdlib.h>

int sum_row(int arr[8][8], int row) {
    int sum = 0;
    for (int i=0; i<8; ++i) {
        sum += arr[row][i];
    }
    return sum;
}

int sum_col(int arr[8][8], int col) {
    int sum = 0;
    for (int i=0; i<8; ++i) {
        sum += arr[i][col];
    }
    return sum;
}

/* idx <= 14 */
int sum_diag(int arr[8][8], int idx) {
    int i, j;

    if (idx < 8) {
        i = 8 - idx - 1;
        j = 0;
    } else {
        i = 0;
        j = idx - 8 + 1;
    }

    int sum = 0;
    while (i < 8 && j < 8) {
        sum += arr[i++][j++];
    }
    return sum;
}

int sum_diag2(int arr[8][8], int idx) {
    int i, j;

    if (idx < 8) {
        i = idx;
        j = 7;
    } else {
        i = 0;
        j = idx - 8;
    }

    int sum = 0;
    while (i < 8 && j >= 0) {
        sum += arr[i++][j--];
    }
    return sum;
}

int main() {
    int arr[8][8];
    char temp;
    char buf[8];

    for (int i=0; i<8; ++i) {
        scanf("%s", buf);

        if (i == 0) {
            temp = buf[0];
        }

        for (int j=0; j<8; ++j) {
            if (buf[j] == '*') {
                arr[i][j] = 1;
            } else {
                arr[i][j] = 0;
            }
        }
    }

    if (temp == '*') {
        arr[0][0] = 1;
    }

    int valid = 1;

    for (int i = 0; i<8; ++i) {
        if (sum_row(arr, i) != 1) {
            valid = 0;
            goto exit;
        }
        if (sum_col(arr, i) != 1) {
            valid = 0;
            goto exit;
        }
    }

    for (int i=0; i<15; ++i) {
        int x = sum_diag(arr,i);
        if (x > 1) {
            valid = 0;
            goto exit;
        }
        int y = sum_diag2(arr, i);
        //printf("%d ", y);
        if (y > 1) {
            valid = 0;
            goto exit;
        }
        //printf("\n");
    }

exit:
    if (valid) {
        printf("valid\n");
    } else {
        printf("invalid\n");
    }

    return 0;
}
