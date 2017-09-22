#include <stdio.h>
#include <math.h>

#define size 200000002

char flag[size];

void sieve(long long range)
{
	/*
	*	0 means non prime
	*	1 means prime
	*/

    long long i, j;

    flag[0] = '0';

    for (i = 1; i <= range; i += 2) {
        flag[i] = '1';
        flag[i + 1] = '0';
    }

    flag[1] = '0';
    flag[2] = '1';

    for (i = 3; i * i <= range; i += 2) {
        if (flag[i] == '1') {
            for (j = i; (i * j) <= range; j += 2) {
                flag[i * j] = '0';
            }
        }
    }
}

int main()
{
	//freopen("output.txt", "w", stdout);
	
    long long num = 1000, i, div, power;

    if (num < 2) {
    	printf("No prime factorization of %lld!\n", num);
    } else if (num == 2) {
    	printf("2! = 2^1\n");
    } else {
    	printf("%lld! = ", num);

	    sieve(num);

	    div = 2;
	    power = 0;

	    while (div <= num) {
	    	power += num / div;
	    	div *= 2;
	    }

	    printf("2^%lld", power);

	    for (i = 3; i <= num; i += 2) {
	    	if (flag[i] == '1') {
		    	div = i;
			    power = 0;

			    while (div <= num) {
			    	power += num / div;
			    	div *= i;
			    }

			    printf(" * %lld^%lld", i, power);
			}
	    }
	    
	    printf("\n");
	}


    return 0;
}