#include <stdio.h>
#include <string.h>

int temperature_converter(void) {
    signed int ch, input, check_char;
    float value, celsius, kelvin, fahrenheit;
    char user_input[100];
    unsigned int i = 0;
    printf("Is your temperature in (K)elvin, (C)elsius or (F)ahrenheit?\n "
           "(Q)uitting the program is possible as well.\n");
    fgets(user_input, sizeof(user_input), stdin);
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
        while (getchar() != '\n') { /* empty */
        }
    }
    switch (ch) {
    case 'q':
        // Fall through
    case 'Q':
        printf("Exit converter.\n");
        return 0;
    case '\n':
        printf("No input detected. Pick 'c' or 'C' for celsius, 'f' or "
               "'F' for fahrenheit, and 'k' or 'K' for kelvin.\n");
        temperature_converter();
        return 0;
    case 'c':
        // Fall through
    case 'C':
        printf("What is the value of the Celsius temperature?\n");
        input = scanf("%f", &value);
        while (input == 0) {
            while (getchar() != '\n') { /* empty */
            }
            printf("Non-numerical value for temperature, please try again.\n "
                   "What is the value "
                   "of the temperature?\n");
            input = scanf("%f", &value);
        }
        if (value < -273.15f) {
            printf("Value defined is not possible.\n");
            break;
        }
        celsius = value;
        kelvin = celsius + 273.15f;
        fahrenheit = (celsius * (9.00f / 5.00f)) + 32.00f;
        printf("Your celsius temperature is: %.3f, kelvin temperature is: "
               "%.3f, and fahrenheit is: %.3f\n",
               celsius, kelvin, fahrenheit);
        break;
    case 'k':
        // Fall through
    case 'K':
        printf("What is the value of the Kelvin temperature?\n");
        input = scanf("%f", &value);
        while (input == 0) {
            while (getchar() != '\n') { /* empty */
            }
            printf("Non-numerical value for temperature, please try again.\n "
                   "What is the value "
                   "of the temperature?\n");
            input = scanf("%f", &value);
        }
        if (value < 0.00f) {
            printf("Value defined is not possible.\n");
            break;
        }
        kelvin = value;
        celsius = kelvin - 273.15f;
        fahrenheit = (kelvin - 273.15f) * (9.00f / 5.00f) + 32.00f;
        printf("Your celsius temperature is: %.3f, kelvin temperature is: "
               "%.3f, and fahrenheit is: %.3f\n",
               celsius, kelvin, fahrenheit);
        break;
    case 'f':
        // Fall through
    case 'F':
        printf("What is the value of the Fahrenheit temperature?\n");
        input = scanf("%f", &value);
        while (input == 0) {
            while (getchar() != '\n') { /* empty */
            }
            printf("Non-numerical value for temperature, please try again.\n "
                   "What is the value "
                   "of the temperature?\n");
            input = scanf("%f", &value);
        }
        if (value < -459.67f) {
            printf("Value defined is not possible.\n");
            break;
        }
        fahrenheit = value;
        celsius = (fahrenheit - 32.00f) * (5.00f / 9.00f);
        kelvin = (fahrenheit - 32.00f) * (5.00f / 9.00f) + 273.15f;
        printf("Your celsius temperature is: %.3f, kelvin temperature is: "
               "%.3f, and fahrenheit is: %.3f\n",
               celsius, kelvin, fahrenheit);
        break;
    default:
        printf("Unexpected character %c. Pick 'c' or 'C' for celsius, 'f' or "
               "'F' for fahrenheit, and 'k' or 'K' for kelvin.\n",
               (char)ch);
        temperature_converter();
        return 0;
    }
    while (getchar() != '\n') { /* empty */
    }
    return 0;
}

int main(void) {
    while (1) {
        temperature_converter();
    }
}
