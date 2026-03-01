# C Style Guide

I decided to create a personal coding style that I will follow, which is built based on multiple sources.
Initially I was thinking of following NASA's C style guide, but later lost the file and I couldn't remember where to find it. Because of that, I started to read the Linux Kernel style guide, and I didn't agree with some parts of it. After that I decided to follow my own style, which I would (hopefully, most likely) be fine with from now on.
I have found the NASA C style guide since then, and there is quite a bit of inspiration from there, but I decided to keep "creating my own", and define "what works for me".

This is my current style, and it might change in the future as I learn more and I run into new situations.

## Naming

| Element | Convention | Example |
|---|---|---|
| Functions | UpperCase | `ClearInput`, `MenuDisplay` |
| Variables | lower_case | `user_input`, `input_value` |
| Structs | lowerUpperCase | `struct menuItem` |
| Struct members | lower_case | `.name`, `.array_size` |
| Constants | ALL_CAPS | `MAX_COUNT` |
| Enum values | ALL_CAPS | `DIFFICULTY_EASY` |
| Files | lower-case | `math-operations.c` |
| Header guards | PATH_FILENAME_H | `HANGMAN_UTILS_H` |

Functions and variables follow NASA's naming directly. Constants and enum values are ALL_CAPS because that is what I see most often in C code.

Structs I decided on lowerUpperCase because the struct is similar to a variable, but not really a variable, and having it named UpperCase makes it look too much like a function for me, and this is what I settled on for visual distinction.

I decided not to use `typedef` for structs, and instead to write `struct menuItem` explicitly because I want to see that it's a struct. I believe that this is similar reasoning to the Linux kernel style.

File names are lower-case because I don't have to press the shift key.

## Formatting

Most formatting is handled by (and therefore visible in) `.clang-format` (included in the repo as a backup copy of my system-wide config). What I want to point out is:

- Opening braces are on the same line with what needs them. This makes it easier for me to read the code.
- I want 4 space indentation, without tab whitespace, and NASA recommends the same, with apparent research backing it up.
- No character limit to wrap on, because I'd rather decide myself when to wrap, not be forced by a limit.
- The pointer is attached to the variable, not to the type (e.g. `int *ptr`), because it's quicker for me to read it, and makes it clear for me that the pointer is for that variable only (`int *a, b` makes it clear for me that `b` isn't a pointer)
- No space after casts makes it easier for me to read.
- Preprocessor indentation after `#` makes it easier for me to read the code and see the "structure".

## Code Patterns

- Currently I am debating with myself between variable declarations at the top of the function's scope and declarations right when I need them. I am leaning towards declarations at the top of function scope because they are "more portable".
- Went for early return for error conditions and edge cases, so that I can focus on "what I want the code to do" after I get "what shouldn't happen" out of the way.
- Block comments (`/* */`) are used for documenting functions and inline comments (`//`) for implementation notes. Easier for me to read when they are visually different.
- Helper functions are above main, with main being at the bottom (enforced by `-Wimplicit-function-declaration`, part of `-Wall`)
- Decided to `const` on parameters in functions that only read for clarity that the value stays the same.
- Decided to use `const` as well for variables instead of `#define` for simple constants, to avoid preprocessor substitution issues (as demonstrated in NASA's guide in section 6.2.4).
- `NULL` for null pointers.
- Explicit `void` in empty parameter lists (the `-Wstrict-prototypes` flag forces me to).
- Fall through comments to show that they are intentional in switch cases.
- Multiple `printf()` calls instead of breaking a single long string. I believe I read about this being easier to grep in the Linux kernel style guide.

## Compiler Flags

The flags and what they do are documented in the [c-projects README](README.md#compilation). The short version is: they are strict on purpose to catch most "beginner mistakes" when compiling, instead of spending hours on debugging easily fixable mistakes, and hopefully this builds the right habits for professional development.
