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

// upper_bound: primeiro índice com valor > target
int upper_bound(int *arr, int n, int target) {
    int l = 0, r = n;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] <= target) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}

long long maxTaxiEarnings(int n, int** rides, int ridesSize, int* ridesColSize){
    (void)n;
    (void)ridesColSize;

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

    qsort(intervals, ridesSize, sizeof(Interval), cmpIntervalByEnd);

    int *ends = (int *)malloc(sizeof(int) * ridesSize);
    for (int i = 0; i < ridesSize; i++) {
        ends[i] = intervals[i].end;
    }

    long long *dp = (long long *)malloc(sizeof(long long) * (ridesSize + 1));
    dp[0] = 0;

    for (int i = 1; i <= ridesSize; i++) {
        int start_i = intervals[i - 1].start;
        long long profit_i = intervals[i - 1].profit;

        int j = upper_bound(ends, i - 1, start_i);

        long long without = dp[i - 1];
        long long with = profit_i + dp[j];
        dp[i] = (without > with) ? without : with;
    }

    long long ans = dp[ridesSize];

    free(intervals);
    free(ends);
    free(dp);

    return ans;
}