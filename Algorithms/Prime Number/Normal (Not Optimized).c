#include <stdio.h>

int main()
{
    //freopen("Input.txt", "r", stdin);

    long long T, num, i;
    int isPrime;

    //scanf("%lld", &T);

    //while (T--) {
    scanf(" %lld", &num);

    isPrime = 1;

    for (i = 2; i <= (num / 2); i++) {
        if ((num % i) == 0) {
            isPrime = 0;
        }
    }

    if (isPrime == 1) {
        printf("%lld is a prime number.\n", num);
    } else {
        printf("%lld is not a prime number.\n", num);
    }
    //}

    return 0;
}
