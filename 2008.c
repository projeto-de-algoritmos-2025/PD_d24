#include <stdlib.h>

typedef struct {
    int start;
    int end;
    long long profit;
} Interval;

int cmpIntervalByEnd(const void *a, const void *b) {
    const Interval *ia = (const Interval *)a;
    const Interval *ib = (const Interval *)b;
    if (ia->end != ib->end) return ia->end - ib->end;
    return ia->start - ib->start;
}

long long maxTaxiEarnings(int n, int** rides, int ridesSize, int* ridesColSize){
    (void)n;
    (void)ridesColSize;

    if (ridesSize == 0) return 0;

    Interval *intervals = (Interval *)malloc(sizeof(Interval) * ridesSize);
    for (int i = 0; i < ridesSize; i++) {
        int start = rides[i][0];
        int end   = rides[i][1];
        int tip   = rides[i][2];
        long long profit = (long long)(end - start) + (long long)tip;
        intervals[i].start = start;
        intervals[i].end   = end;
        intervals[i].profit = profit;
    }

    // 1) Ordena por end
    qsort(intervals, ridesSize, sizeof(Interval), cmpIntervalByEnd);

    // 2) DP simples: dp[i] = melhor lucro usando corridas até i
    long long *dp = (long long *)malloc(sizeof(long long) * ridesSize);
    dp[0] = intervals[0].profit;

    for (int i = 1; i < ridesSize; i++) {
        long long best = dp[i - 1]; // não pegar i

        long long take = intervals[i].profit;
        for (int j = i - 1; j >= 0; j--) {
            if (intervals[j].end <= intervals[i].start) {
                take += dp[j];
                break;
            }
        }
        if (take > best) best = take;
        dp[i] = best;
    }

    long long ans = dp[ridesSize - 1];

    free(intervals);
    free(dp);

    return ans;
}