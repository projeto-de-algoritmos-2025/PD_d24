#include <string.h>

int profitableSchemes(int n, int minProfit, int* group, int groupSize, int* profit, int profitSize){
    (void)profitSize; // mesmo tamanho de group
    const int MOD = 1000000007;

    // Limites do problema: n <= 100, minProfit <= 100
    static int dp[101][101];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = 1;

    for (int i = 0; i < groupSize; i++) {
        int g = group[i];
        int prof = profit[i];

        // 0/1 knapsack -> iterar de trás pra frente
        for (int people = n; people >= g; people--) {
            for (int p = minProfit; p >= 0; p--) {
                int new_p = p + prof;
                if (new_p > minProfit) new_p = minProfit;
                dp[people][new_p] = (dp[people][new_p] + dp[people - g][p]) % MOD;
            }
        }
    }

    long long ans = 0;
    for (int people = 0; people <= n; people++) {
        ans = (ans + dp[people][minProfit]) % MOD;
    }

    return (int)ans;
}