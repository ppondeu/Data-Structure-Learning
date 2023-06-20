#include <stdio.h>
#include <stdlib.h>

// recursive function to generate binary sequences
int** generate_binary_sequences(int n, int* count) {
    int i, j;
    int** sequences;

    if (n == 1) {
        // base case: return the two binary sequences {0} and {1}
        sequences = malloc(2 * sizeof(int*));
        sequences[0] = malloc(sizeof(int));
        sequences[1] = malloc(sizeof(int));
        sequences[0][0] = 0;
        sequences[1][0] = 1;
        *count = 2;
        return sequences;
    }

    // recursive case: generate binary sequences of length n-1
    int** sub_sequences = generate_binary_sequences(n-1, count);

    // create new binary sequences by adding a 0 and a 1 to the end of each subsequence
    sequences = malloc(2 * (*count) * sizeof(int*));
    for (i = 0; i < (*count); i++) {
        sequences[2*i] = malloc(n * sizeof(int));
        sequences[2*i+1] = malloc(n * sizeof(int));
        for (j = 0; j < n-1; j++) {
            sequences[2*i][j] = sub_sequences[i][j];
            sequences[2*i+1][j] = sub_sequences[i][j];
        }
        sequences[2*i][n-1] = 0;
        sequences[2*i+1][n-1] = 1;
    }

    // free memory used by sub_sequences
    for (i = 0; i < (*count); i++) {
        free(sub_sequences[i]);
    }
    free(sub_sequences);

    // update count to reflect the new number of sequences
    *count *= 2;

    return sequences;
}

int main() {
    int n = 3;
    int i, j;
    int count = 0;

    int** sequences = generate_binary_sequences(n, &count);

    // print the binary sequences
    for (i = 0; i < count; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", sequences[i][j]);
        }
        printf("\n");
    }

    // free memory used by sequences
    for (i = 0; i < count; i++) {
        free(sequences[i]);
    }
    free(sequences);

    return 0;
}
