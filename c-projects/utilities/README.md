# Utilities

Utility functions extracted from repeated code or built for reuse. All utilities share a single source file.

## Usage

These utilities handle repetitive tasks that appear across projects so that individual projects don't reimplement them.

With CMake, `#include "utils.h"` in the calling project is enough.
With GCC only, `#include "../utilities/utils.h"` in the calling project and `../utilities/utils.c` added to the gcc command as a source file.

## Reflection documents

A reflection document is where I write about what I was trying to do, problems encountered, and how I solved them. For more detail on what these contain, see the [root README](/README.md#reflection-documents).

## Functions

### ClearInput

It clears input from stdin.
It should be used after "take input" sections of code.
The purpose of that is: no leftover input on the next "take input" section for "appropriate" running.

#### Known Limitations

- It assumes stdin is active.
- On EOF it will exit.
- If there is no input for the function to "consume" it will wait for input.

### MenuDisplay

It displays a list of functions at runtime.
It automatically assigns numbers for the functions present in the menu for the user to pick the wanted function.
The user can exit with `CTRL+D` (EOF will exit the program), `CTRL+C` (general quit/cancel) and according to the function prompt, with 0 which will `exit(0)` from code.

#### Parameters

It takes two parameters:
- array of menuItem struct (the list of functions, with .name .description and .action for function call)
- array size (number of elements in the array)

The struct itself needs to have .name as a string, .description as a string, and the .action as a void return void parameters function.

#### Known Limitations

- It assumes stdin is always active.
- On EOF it will exit.
- It needs at least one function for proper expected results.
- No automatic detection of options list, needs manual building before calling
- It takes only numerical input.
