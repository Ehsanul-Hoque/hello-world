#include <stdio.h>

long long waysDP[100][100], blocks[100][100];

long long ways(long long m, long long n)
{
    if ((m < 0) || (n < 0)) return 0;
    if ((m == 0) && (n == 0)) return 1;
    if (blocks[m][n] != 0) return 0;
    if (waysDP[m][n] != -1) return waysDP[m][n];

    waysDP[m][n] = ways(m - 1, n) + ways(m, n - 1);

    return waysDP[m][n];
}

int main()
{
    long long m, n, i, j, totalBlocks, a, b;

    printf("Suppose there's a grid of m columns and n rows. You can only go up and right, but you can't go down or left. There are some blocks on the grid that you can't go.");
    printf(" Now you need to calculate the number of ways that you can go to (m, n) from (0, 0) [m >= 0, n >= 0].");

    while (1) {
        for (i = 0; i < 100; i++) {
            for (j = 0; j < 100; j++) {
                waysDP[i][j] = -1;
                blocks[i][j] = 0;
            }
        }

        printf("\n\nPlease enter the value of m and n separated by space or enter : ");
        scanf("%lld %lld", &m, &n);

        if ((m < 0) || (n < 0)) printf("\n\nm and n should be greater than or equal to 0\n\n");
        else {
            printf("\nPlease enter the value of total blocks : ");
            scanf("%lld", &totalBlocks);

            printf("\nPlease enter the (x, y) of the blocks in each line : ");

            while (totalBlocks--) {
                scanf("%lld %lld", &a, &b);
                blocks[a][b] = 1;
            }

            /*for (i = 0; i <= m; i++) {
                for (j = 0; j <= n; j++) {
                     printf("%lld ", blocks[i][j]);
                }

                printf("\n");
            }*/

            /*printf("\n\n");

            for (i = 0; i <= m; i++) {
                for (j = 0; j <= n; j++) {
                     printf("%lld ", waysDP[i][j]);
                }

                printf("\n");
            }*/

            printf("\nTotal ways : %lld\n", ways(m, n));
        }
    }

    return 0;
}
