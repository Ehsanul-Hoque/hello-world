#include <stdio.h>

long long nPrList[25][25];

long long nPr(int n, int r)
{
    if (r == 0) return 1;
    if (r == 1) return n;
    if (nPrList[n][r] != -1) return nPrList[n][r];

    nPrList[n][r] = nPr(n, r - 1) * (n - r + 1);

    return nPrList[n][r];
}

int main()
{
    int n, r, i, j;

    for (i = 0; i < 25; i++) {
        for (j = 0; j < 25; j++) {
            nPrList[i][j] = -1;
        }
    }

    printf("Please enter the value of n and r separated by space or enter : ");
    scanf("%d %d", &n, &r);

    if (n >= r) printf("\n\nThe value of %dP%d is %lld\n\n", n, r, nPr(n, r));
    else printf("\n\nn should be greater than or equal to r\n\n");

    return 0;
}
