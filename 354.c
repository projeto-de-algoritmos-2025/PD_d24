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

// lower_bound: primeiro índice com valor >= target
int lower_bound_int(int *arr, int n, int target) {
    int l = 0, r = n;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] < target) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}

int maxEnvelopes(int** envelopes, int envelopesSize, int* envelopesColSize){
    (void)envelopesColSize;
    if (envelopesSize == 0) return 0;

    qsort(envelopes, envelopesSize, sizeof(int*), cmpEnvelopes);

    int *lis = (int *)malloc(sizeof(int) * envelopesSize);
    int len = 0;

    for (int i = 0; i < envelopesSize; i++) {
        int h = envelopes[i][1];
        int pos = lower_bound_int(lis, len, h);
        if (pos == len) {
            lis[len++] = h;
        } else {
            lis[pos] = h;
        }
    }

    free(lis);
    return len;
}