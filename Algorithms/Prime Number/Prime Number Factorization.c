#include <stdio.h>
#include <math.h>


int isPrime(int n)
{
	// 0 mean false, 1 means true

	if (n < 2) return 0;
	if (n == 2) return 1;
	if (n % 2 == 0) return 0;

	int sqroot = sqrt(n), i;

	for (i = 3; i <= sqroot + 1; i += 2) {
		if (n % i == 0) return 0;
	}

	return 1;
}


void primeFactiorization(int n)
{
	int i, totalPrimeFactor, power;

	if (n < 2) {
		printf("No prime factor of %d exists.\n", n);
		return;
	}

	if (isPrime(n) == 1) {
		printf("%d: %d^1\n", n, n);
		return;
	}

	power = 0;
	totalPrimeFactor = 0;

	printf("%d: ", n);

	if (n % 2 == 0)
		totalPrimeFactor++;

	while (n % 2 == 0) {
		n /= 2;
		power++;
	}

	if (power != 0)
		printf("2^%d", power);

	for (i = 3; n > 1; i += 2) {
		if (n % i == 0)
			totalPrimeFactor++;
		else
			continue;

		power = 0;

		while (n % i == 0) {
			n /= i;
			power++;
		}

		if (totalPrimeFactor >= 2)
			printf(" * %d^%d", i, power);
		else
			printf("%d^%d", i, power);
	}

	printf("\n");
}


int main()
{
    int num;

    scanf("%d", &num);

	primeFactiorization(num);


    return 0;
}
