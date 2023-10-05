#include <stdio.h>
#include <string.h>

/**
 * Prints out all prime integers less than or equal to 'n' using the Sieve of
 * Erastosthenes algorithm.
 * 
 * @param n The max range for finding a list of prime integers.
*/
void sieve_of_erastosthenes(int n) {
    printf("[");

    printf("]\n");
}

int main() {
    int maxVal;

    printf("Enter an integer to find all primes smaller than or equal to it: ");

    scanf("%d", &maxVal);

    printf("List of all prime integers less than or equal %d:\n", maxVal);

    sieve_of_erastosthenes(maxVal);

    return 0;
}