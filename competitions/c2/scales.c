#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int int_of_note(char *note) {
    if (strlen(note) == 1) {
        switch (note[0]) {
            case 'A':
                return 0;
            case 'B':
                return 2;
            case 'C':
                return 3;
            case 'D':
                return 5;
            case 'E':
                return 7;
            case 'F':
                return 8;
            case 'G':
                return 10;
            default:
                return -1;
        }
    } else {
        switch (note[0]) {
            case 'A':
                return 1;
            case 'B':
                return -1;
            case 'C':
                return 4;
            case 'D':
                return 6;
            case 'E':
                return -1;
            case 'F':
                return 9;
            case 'G':
                return 11;
            default:
                return -1;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int notes[n];
    char token[3];
    for (int i=0; i<n; ++i) {
        scanf("%s", token);
        notes[i] = int_of_note(token);
        // printf("%d\n", notes[i]);
    }

    int crossed[12];

    for (int i=0; i<12; ++i) {
        crossed[i] = 0;
    }

    int arr[5] = {11, 9, 6, 4, 2};

    for (int i=0; i<n; ++i) {
        for (int j=0; j<5; ++j) {
            int idx = (notes[i] + arr[j]) % 12;
            crossed[idx] = 1;
        }
    }

    int found = 0;
    for (int i=0; i<12; ++i) {
        if (crossed[i] == 0) {
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("none\n");
        goto exit;
    }

    for (int i=0; i<12; ++i) {
        // printf("%d", crossed[i]);
        if (crossed[i] == 0) {
            switch(i) {
                case 0:
                    printf("A");
                    break;
                case 1:
                    printf("A#");
                    break;
                case 2:
                    printf("B");
                    break;
                case 3:
                    printf("C");
                    break;
                case 4:
                    printf("C#");
                    break;
                case 5:
                    printf("D");
                    break;
                case 6:
                    printf("D#");
                    break;
                case 7:
                    printf("E");
                    break;
                case 8:
                    printf("F");
                    break;
                case 9:
                    printf("F#");
                    break;
                case 10:
                    printf("G");
                    break;
                case 11:
                    printf("G#");
                    break;
                default:
                    break;
            }
            printf(" ");
        }
    }
    printf("\n");

exit:
    return 0;
}
