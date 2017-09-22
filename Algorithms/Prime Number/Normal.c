#include <stdio.h>
#include <math.h>

int isPrime(long long num);

int main()
{
    long long num;

    scanf("%lld", &num);

    printf((isPrime(num) == 1) ? "%lld is a prime." : "%lld is not a prime.", num);

    return 0;
}

int isPrime(long long num)
{
    long long i, sqRoot = sqrt(num);

    if (num < 2) {
        return 0;
    }

    if ((num % 2) == 0) {
        return 0;
    }

    for (i = 3; i <= sqRoot; i += 2) {
        if ((num % i) == 0) {
            return 0;
        }
    }

    return 1;
}
