#include <stdlib.h>

typedef struct {
    int start;
    int end;
    long long profit;
} Interval;

long long maxTaxiEarnings(int n, int** rides, int ridesSize, int* ridesColSize){
    (void)n;
    (void)ridesColSize;

    // Monta vetor de intervalos com o lucro calculado
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

    // Ainda não fazemos a lógica de ordenação e DP
    // Apenas somamos todos os lucros como teste (obviamente errado, só para ver valores)
    long long total = 0;
    for (int i = 0; i < ridesSize; i++) {
        total += intervals[i].profit;
    }

    free(intervals);
    return total; // placeholder: soma bruta (não é a resposta correta)
}