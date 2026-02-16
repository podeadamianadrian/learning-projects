#ifndef UTILS_H
#define UTILS_H

/*
"utils.h" is supposed to be a "shared utilities" file for repeated "lines" that I often do
accross my projects

These are functions that I will use generally, because they go in a lot of places
*/

/*
MenuItem - struct for functions, containing .name, .description and .action (function) to call when selected

Functions passed in this struct need to have void return, no parameters.
*/
struct MenuItem {
    char *name; //name of the function
    char *description; //description of the function
    void (*action)(void); // void return function, no parameters
};

/*
ClearInput - clears any remaining characters from stdin

Reads and discards all characters, including the newline character.
If EOF (end of file) is encountered, it will exit the program as a "panic action"
Note: I just don't know what to do yet when EOF is encountered.

Typically used after functions that take terminal input to remove "leftover input".
*/
void ClearInput(void);

/*
MenuDisplay - Displays a menu.

The parameters:
`array_name[]` needs to be a MenuItem array of structs, with a size equal or bigger than 1,
`array_size` needs to be the size of the array.

It will create a list, starting from 0 with exit which exits the program, and listing the functions in the order given starting from the number 1.
It will call the function chosen by the user.
*/
void MenuDisplay(struct MenuItem array_name[], int array_size);

#endif
