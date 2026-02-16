#include "utils.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ClearInput(void) {
    int ch;
    while ((ch = getchar()) != '\n') {
        if (ch == EOF) {
            exit(0);
        }
    }
}

void MenuDisplay(struct MenuItem array_name[], int array_size) {
    char user_input[10], *end;
    int i;
    long choice;
    printf("Welcome to the menu of the program!\n");
    printf("Pick what you want to do in this program! The choice needs to be the simple number according to the options displayed.\n");
    printf("The options are: \n");
    printf("0. Exit - exit program.\n");

    for (i = 0; i < array_size; i++) {
        printf("%d. %s - %s.\n", (i + 1), array_name[i].name, array_name[i].description);
    }

    if (fgets(user_input, sizeof(user_input), stdin) == NULL) {
        exit(0);
    }

    if (!strchr(user_input, '\n')) {
        ClearInput();
    }

    errno = 0;
    choice = strtol(user_input, &end, 10);

    if (end == user_input) {
        printf("No digits were found!\n");
        printf("Choice needs to be a digit!\n");
        return;
    }
    if (choice < 0 || choice > array_size) {
        printf("Choice is 'out of bounds'. Pick a choice between 0 and %d.\n", array_size);
        return;
    }
    if (*end != '\0' && *end != '\n') {
        printf("The confirmed choice is: %ld.\n", choice);
    }
    if (choice == 0) {
        exit(0);
    }
    array_name[choice-1].action();
}
