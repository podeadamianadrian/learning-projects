# Utilities

The folder contains utility functions that are going to be reused across my code.
It is its own folder for my own easy retrieval.

## Contents

- `reflection.md` — Development notes for the source code
- `utils.c` — Source code containing all functions
- `utils.h` — Header file declaring all functions

## Compilation

This code doesn't get compiled standalone, it is compiled along with the source code that calls these functions.
The compilation process is done from the parent directory with CMake. For more detail on the compilation process see the [c-projects README](../README.md/#compilation).

## Usage

These functions are used in different projects for their utility purpose, not to be "used"/ran/compiled standalone.
If compiling with CMake, `#include "utils.h"` in the calling project should be enough for successful compilation.
If compiling manually, `#include "../utilities/utils.h"` in the calling project and `../utilities/utils.c` to the gcc command as a source file are required steps for successful compilation.

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
- array of MenuItem struct (the list of functions, with .name .description and .action for function call)
- array size (number of elements in the array)

The struct itself needs to have .name as a string, .description as a string, and the .action as a void return void parameters function.

#### Known Limitations

- It assumes stdin is always active.
- On EOF it will exit.
- It needs at least one function for proper expected results.
- It cannot automatically detect the list, it is quite hardcoded before passing the parameters to the function.
- It takes only numerical input (no string parsing yet, no fuzzy matching, no "narrow down based on matches").
