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
} BOOLEAN;

/**
 * Prints out all prime integers less than or equal to 'n' using the Sieve of
 * Erastosthenes algorithm.
 * 
 * @param n The max range for finding a list of prime integers.
*/
void sieve_of_erastosthenes(int n) {
    BOOLEAN prime_values[n + 1];
    char array_str[10000];
    int pos = 0;
    array_str[pos++] = '[';
    int array_size = sizeof(array_str);

    for (int i = 0; i <= n; i++) {
        prime_values[i] = true;
    }

    for (int p = 2; p * p <= n; p++) {
        if (prime_values[p] == true) {
            for (int i = p * p; i <= n; i += p) {
                prime_values[i] = false;
            }
        }
    }

    if (n >= 2) {
        pos += snprintf(array_str + pos, array_size - pos, "%d", 2);
    }

    for (int i = 3; i <= n; i++) {
        if (prime_values[i] == true) {
            pos += snprintf(array_str + pos, array_size - pos, ", %d", i);
        }
    }

    pos += snprintf(array_str + pos, array_size - pos, "]\n");

    printf("%s", array_str);
}

int main() {
    int value;
    BOOLEAN valid_input = false;
    char continue_choice;
    int buffer_value;

    while (!valid_input) {
        printf("Enter an integer to find all primes smaller than or equal to it: ");

        if (scanf("%d", &value) == true) {
            if (value >= 3) {
                valid_input = true;
            } else {
                printf("Error: Input must be greater than or equal to 3.\n");
            }
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