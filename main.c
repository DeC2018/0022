#include <stdio.h>
#include <stdlib.h>

char **generateParenthesis(int n, int* returnSize) {
    char **ans = (char**)malloc(12870 * sizeof(char*));
    *returnSize = 0;
    const int max_i = 1 << (2 * n);
    for (int i = 0; i < max_i; ++i) {
        if (__builtin_popcount(i) != n) continue;
        int j = 0;
        int ii = i;
        for (int k = 0; j >= 0 && k < 2 * n; ++k, ii >>= 1) {
            j += 2 * (ii & 1) - 1; 
        }
        if (j == 0) {
            char *combination = (char *)malloc((2 * n + 1) * sizeof(char));
            ii = i;
            for (int k = 0; k < 2 * n; ++k, ii >>= 1) {
                combination[k] = (ii & 1) ? '(' : ')';
            }
            combination[2 * n] = 0;
            ans[(*returnSize)++] = combination;
        }
    }
    return ans;
}

int main() {
    int n = 3;
    int returnSize;
    char **result = generateParenthesis(n, &returnSize);

    printf("[");
    for (int i = 0; i < returnSize; ++i) {
        printf("\"%s\"", result[i]);
        if (i < returnSize - 1) {
            printf(",");
        }
    }
    printf("]\n");

    // Free memory allocated for each combination
    for (int i = 0; i < returnSize; ++i) {
        free(result[i]);
    }
    // Free memory allocated for the array of combinations
    free(result);

    return 0;
}