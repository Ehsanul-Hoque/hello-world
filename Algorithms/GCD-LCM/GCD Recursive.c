#include <stdio.h>

long long gcd(long long a, long long b)
{
    if (b == 0) return a;
    if (a == 0) return b;

    return gcd(b, (a % b));
}


int main()
{
    long long T, a, b;

    while (1) {
        printf("Please enter two numbers : ");

        scanf(" %lld %lld", &a, &b);

        printf("GCD of %lld and %lld is %lld.\n\n", a, b, gcd(a, b));
    }

    return 0;
}
