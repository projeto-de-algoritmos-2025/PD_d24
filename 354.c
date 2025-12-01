#include <stdlib.h>

int cmpEnvelopes(const void *a, const void *b) {
    const int *ea = *(const int **)a;
    const int *eb = *(const int **)b;

    if (ea[0] != eb[0]) {
        return ea[0] - eb[0];        // largura crescente
    } else {
        return eb[1] - ea[1];        // altura decrescente quando mesma largura
    }
}

int maxEnvelopes(int** envelopes, int envelopesSize, int* envelopesColSize){
    (void)envelopesColSize;
    if (envelopesSize == 0) return 0;

    qsort(envelopes, envelopesSize, sizeof(int*), cmpEnvelopes);

    int *heights = (int *)malloc(sizeof(int) * envelopesSize);
    for (int i = 0; i < envelopesSize; i++) {
        heights[i] = envelopes[i][1];
    }

    // LIS O(n^2)
    int *dp = (int *)malloc(sizeof(int) * envelopesSize);
    int maxLen = 0;

    for (int i = 0; i < envelopesSize; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (heights[j] < heights[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
        if (dp[i] > maxLen) maxLen = dp[i];
    }

    free(heights);
    free(dp);

    return maxLen;
}