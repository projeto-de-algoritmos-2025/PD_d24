#include <stdlib.h>

int cmpEnvelopes(const void *a, const void *b) {
    const int *ea = *(const int **)a;
    const int *eb = *(const int **)b;
    // ordenar apenas por largura crescente (ainda não tratamos empates corretamente)
    return ea[0] - eb[0];
}

int maxEnvelopes(int** envelopes, int envelopesSize, int* envelopesColSize){
    (void)envelopesColSize;

    if (envelopesSize == 0) return 0;

    qsort(envelopes, envelopesSize, sizeof(int*), cmpEnvelopes);

    // Aqui só retornamos envelopesSize como placeholder
    // Ainda não há lógica de LIS.
    return envelopesSize;
}