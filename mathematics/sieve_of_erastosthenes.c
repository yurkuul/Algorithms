#include <stdio.h>
#include <string.h>
#include <ctype.h>

const int MAX_INT_VALUE = 50000000;

/**
 * Enumerated types for boolean values where false = 0, true = 1;
*/
typedef enum {
    false,
    true
} BOOLEAN ;

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
    int value;
    BOOLEAN valid_input = false;
    char continue_choice;
    int buffer_value;

    while (!valid_input) {
        printf("Enter an integer to find all primes smaller than or equal to it: ");

        if (scanf("%d", &value) == 1) {
            valid_input = true;
        } else {
            while ((buffer_value = getchar()) != '\n' && buffer_value != EOF);
            printf("Error: Invalid Input.\n");
            printf("\nContinue? Type any key to continue, or Q to quit: ");
            scanf(" %c", &continue_choice);

            if (toupper(continue_choice) == 'Q') {
                return 0;
            }
        }

        while ((buffer_value = getchar()) != '\n' && buffer_value != EOF);

        printf("\n");
    }

    printf("List of all prime integers less than or equal to %d:\n", value);

    sieve_of_erastosthenes(value);

    return 0;
}