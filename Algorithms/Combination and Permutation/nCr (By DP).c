#include <stdio.h>

long long nCrList[25][25];

long long nCr(int n, int r)
{
    if (r == 0) return 1;
    if (r == 1) return n;
    if (r == n) return 1;
    if (nCrList[n][r] != -1) return nCrList[n][r];

    nCrList[n][r] = nCr(n - 1, r) + nCr(n - 1, r - 1);
    // or you can use this : nCrList[n][r] = nCr(n, r - 1) * (n - r + 1) / r;
    nCrList[n][n- r] = nCrList[n][r];

    return nCrList[n][r];
}

int main()
{
    int n, r, i, j;

    for (i = 0; i < 25; i++) {
        for (j = 0; j < 25; j++) {
            nCrList[i][j] = -1;
        }
    }

    printf("Please enter the value of n and r separated by space or enter : ");
    scanf("%d %d", &n, &r);

    if (n >= r) printf("\n\nThe value of %dC%d is %lld\n\n", n, r, nCr(n, r));
    else printf("\n\nn should be greater than or equal to r\n\n");

    return 0;
}
