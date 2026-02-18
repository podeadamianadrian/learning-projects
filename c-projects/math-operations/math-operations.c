#include <errno.h>
#include <float.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

void TemperatureConverter(void) {
    int ch, input, check_char;
    float value, celsius, kelvin, fahrenheit;
    char user_input[100];
    unsigned int i = 0;
    printf("Is your temperature in (K)elvin, (C)elsius or (F)ahrenheit?\n");
    printf("(Q)uitting the program is possible as well.\n");
    if (fgets(user_input, sizeof(user_input), stdin) == NULL) {
        exit(0);
    }
    while (user_input[i] == ' ') {
        i++;
    }
    ch = user_input[i];
    if (ch == '\0' && !strchr(user_input, '\n')) {
        check_char = getchar();
        while (check_char == ' ') {
            check_char = getchar();
        }
        ch = check_char;
    }
    if (!strchr(user_input, '\n')) {
        ClearInput();
    }
    switch (ch) {
        case 'q':
            // Fall through
        case 'Q':
            printf("Exit converter.\n");
            return;
        case '\n':
            printf("No input detected. Will exit now.\n");
            return;
        case 'c':
            // Fall through
        case 'C':
            printf("What is the value of the Celsius temperature?\n");
            input = scanf("%f", &value);
            while (input == 0) {
                ClearInput();
                printf("Non-numerical value for temperature, please try again.\n What is the value of the temperature?\n");
                input = scanf("%f", &value);
            }
            if (value < -273.15f) {
                printf("Value defined is not possible.\n");
                break;
            }
            celsius = value;
            kelvin = celsius + 273.15f;
            fahrenheit = (celsius * (9.00f / 5.00f)) + 32.00f;
            printf("Your celsius temperature is: %.3f, kelvin temperature is: %.3f, and fahrenheit is: %.3f\n", celsius, kelvin, fahrenheit);
            break;
        case 'k':
            // Fall through
        case 'K':
            printf("What is the value of the Kelvin temperature?\n");
            input = scanf("%f", &value);
            while (input == 0) {
                ClearInput();
                printf("Non-numerical value for temperature, please try again.\n What is the value of the temperature?\n");
                input = scanf("%f", &value);
            }
            if (value < 0.00f) {
                printf("Value defined is not possible.\n");
                break;
            }
            kelvin = value;
            celsius = kelvin - 273.15f;
            fahrenheit = (kelvin - 273.15f) * (9.00f / 5.00f) + 32.00f;
            printf("Your celsius temperature is: %.3f, kelvin temperature is: %.3f, and fahrenheit is: %.3f\n", celsius, kelvin, fahrenheit);
            break;
        case 'f':
            // Fall through
        case 'F':
            printf("What is the value of the Fahrenheit temperature?\n");
            input = scanf("%f", &value);
            while (input == 0) {
                ClearInput();
                printf("Non-numerical value for temperature, please try again.\n What is the value of the temperature?\n");
                input = scanf("%f", &value);
            }
            if (value < -459.67f) {
                printf("Value defined is not possible.\n");
                break;
            }
            fahrenheit = value;
            celsius = (fahrenheit - 32.00f) * (5.00f / 9.00f);
            kelvin = (fahrenheit - 32.00f) * (5.00f / 9.00f) + 273.15f;
            printf("Your celsius temperature is: %.3f, kelvin temperature is: %.3f, and fahrenheit is: %.3f\n", celsius, kelvin, fahrenheit);
            break;
        default:
            printf("Unexpected character %c. Will exit now.\n", ch);
            return;
    }
    ClearInput();
}

void FactorialCalculator(void) {
    // initialization and assignment of different similarly named variables of different types, since I cannot "permanently change" a variable's data type.
    unsigned long long int result_ull = 1;
    long double result_ldouble = 1;
    char user_input[150], *end;
    int choice;
    bool first_overflow = false;
    long input_value, i;

    printf("What is the value for factorial?\n");
    if (fgets(user_input, sizeof(user_input), stdin) == NULL) {
        return;
    }
    if (!strchr(user_input, '\n')) {
        ClearInput();
    }

    errno = 0;
    input_value = strtol(user_input, &end, 10);

    if (end == user_input) {
        printf("No number detected! Will abort now.\n");
        return;
    }
    if (errno == ERANGE) {
        printf("Whatever number that was, it's a bit overboard, don't you think?\n");
        printf("I'll just abort...\n");
        return;
    }
    if (input_value < 0) {
        printf("Negative numbers not accepted for factorial.\n");
        return;
    }
    if (*end == '.') {
        printf("Decimal number detected, factorial is done only with whole numbers!\n");
        printf("Whatever was after the decimal mark is lost.\n");
    } else if (*end != '\n' && *end != '\0') {
        printf("I believe non-numerical characters have been inserted. Whatever it was, it's lost to the void.\n");
    }
    if (input_value == 0) {
        printf("The result of %ld! is: %llu.\n", input_value, result_ull);
        return;
    }

    for (i = 1; i <= input_value; i++) {
        if ((unsigned long long)i > ULLONG_MAX / result_ull) {
            first_overflow = true;
            break;
        }
        result_ull *= (unsigned long long)i; // note to self: equivalent to result_ull = result_ull * i
    }

    if (first_overflow) {
        printf("The result of the value you have requested has overflown.\n");
        printf("Would you like to continue or abort here?\n");
        printf("(Y)es or (n)o:\n");
        choice = getchar();
        ClearInput();

        while (choice != 'n' && choice != 'N' && choice != 'y' && choice != 'Y') {
            printf("Unexpected character.\n");
            printf("Options available are: y/Y for 'yes' and n/N for 'no'.\n");
            choice = getchar();
            ClearInput();
        }

        if (choice == 'n' || choice == 'N') {
            printf("Abort here.\n");
            printf("The value chosen is: %ld!.\n", input_value);
            printf("The value reached is: %ld!.\n", (i - 1));
            printf("The result of %ld! is: %llu.\n", (i - 1), result_ull);
            return;
        }

        for (i = 1; i <= input_value; i++) {
            if (i > LDBL_MAX / result_ldouble) {
                printf("A second overflow happened.\n");
                printf("The value chosen is: %ld!.\n", input_value);
                printf("The value reached is: %ld!.\n", (i - 1));
                printf("The result of %ld! is: %Le.\n", (i - 1), result_ldouble);
                return;
            }
            result_ldouble *= i; // note to self: equivalent to result_ldouble = result_ldouble * i
        }
    }

    if (!first_overflow) {
        printf("The result of %ld! is: %llu.\n", input_value, result_ull);
    } else {
        printf("The result of %ld! is: %Le.\n", input_value, result_ldouble);
    }
}

int main(void) {
    struct MenuItem items[] = {
        {"Temperature Converter", "Convert between Celsius, Fahrenheit and Kelvin", TemperatureConverter},
        {"Factorial Calculator", "Calculates factorial of a given number", FactorialCalculator}};
    while (true) {
        MenuDisplay(items, sizeof(items) / sizeof(items[0]));
    }
}
