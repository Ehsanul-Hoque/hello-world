#include <stdio.h>
#include <math.h>

#define size 200000001

char primeDitector[size];

void sieve(long long range);

int main() {
    int num = 12;

    sieve(100000000);

    printf((primeDitector[num] == '1') ? "%d is a prime." : "%d is not a prime.", num);

    return 0;
}

void sieve(long long range) {
    long long i, j, sqRoot = sqrt(range);

    primeDitector[0] = '0';

    for (i = 1; i <= range; i += 2) {
        primeDitector[i] = '1';
        primeDitector[i + 1] = '0';
    }

    primeDitector[1] = '0';
    primeDitector[2] = '1';

    for (i = 3; i <= sqRoot; i += 2) {
        if (primeDitector[i] == '1') {
            for (j = i; (i * j) <= range; j += 2) {
                primeDitector[i * j] = '0';
            }
        }
    }
}
