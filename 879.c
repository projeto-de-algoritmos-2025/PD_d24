#include <string.h>

int profitableSchemes(int n, int minProfit, int* group, int groupSize, int* profit, int profitSize){
    (void)group;
    (void)groupSize;
    (void)profit;
    (void)profitSize;

    static int dp[101][101]; // placeholder pelos limites, ainda sem usar crimes
    memset(dp, 0, sizeof(dp));

    dp[0][0] = 1; // um jeito de ter lucro 0 com 0 pessoas (não fazer nada)

    // Ainda não iteramos sobre os crimes
    // Como teste, retornamos dp[0][0] se minProfit == 0
    if (minProfit == 0) return 1;
    return 0;
}