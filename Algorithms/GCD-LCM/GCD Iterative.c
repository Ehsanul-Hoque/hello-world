#include <stdio.h>

/*int main()
{
    long long T, a, b, c, gcd;

    while (1) {
        printf("Please enter two numbers : ");

        scanf(" %lld %lld", &a, &b);

        while (b != 0) {
            c = b;
            b = a % b;
            a = c;
        }

        printf("GCD of %lld and %lld is %lld.\n\n", a, b, gcd(a, b));
    }

    return 0;
}*/

int main()
{
    int a, b, c, gcd;

    printf("Please enter two numbers : ");

    scanf(" %d %d", &a, &b);

    while (b != 0) {
        c = b;
        b = a % b;
        a = c;
    }

    printf("GCD is %d.\n\n", a);

    return 0;
}
