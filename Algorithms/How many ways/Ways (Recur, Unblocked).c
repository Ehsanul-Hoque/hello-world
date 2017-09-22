#include <stdio.h>

long long waysDP[100][100];

long long ways(int m, int n)
{
    if (m == 0) return 1;
    if (n == 0) return 1;
    if (waysDP[m][n] != -1) return waysDP[m][n];

    waysDP[m][n] = ways(m - 1, n) + ways(m, n - 1);

    return waysDP[m][n];
}

int main()
{
    int m, n, i, j;

    printf("Suppose there's a grid of m columns and n rows. You can only go up and right, but you can't go down or left. Now you need to calculate the number of ways that you can go to (m, n) from (0, 0) [m >= 0, n >= 0].");

    for (i = 0; i < 100; i++) {
        for (j = 0; j < 100; j++) {
            waysDP[i][j] = -1;
        }
    }

    while (1) {
        printf("\n\nPlease enter the value of m and n separated by space or enter : ");
        scanf("%d %d", &m, &n);

        if ((m < 0) || (n < 0)) printf("\n\nm and n should be greater than or equal to 0\n\n");
        else printf("\nTotal ways : %lld\n", ways(m, n));
    }

    return 0;
}
