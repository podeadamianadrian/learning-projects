# Math Operations

Command-line utilities for mathematical conversions and calculations.

## Contents

- `main.c` — Source code containing all functions
- `reflection.md` — Development notes for the source code

## Compilation
```bash
gcc -std=c17 -Wall -Wextra -pedantic -Werror -Wshadow -Wconversion -Wformat=2 -Wswitch-default -Wstrict-prototypes -g -o main.out main.c
```

This is the way I compile.

It should work with:
```bash
gcc -std=c11 -o main.out main.c
```

## Running
```bash
./main.out
```

The program runs in a loop. Follow on-screen prompts to select functions and provide input.

The program will not exit cleanly if there is only one function present — it will loop indefinitely. If that is the case, exit with `Ctrl+C`. Proper exit implementation will happen when there are multiple functions present.

## Functions

### Temperature Converter

Converts temperatures between Celsius, Fahrenheit, and Kelvin. User provides a value and source unit; program outputs all three conversions.

## Known Limitations

- Number format separators (commas, spaces, periods for thousands/decimals) are not parsed. Input must be plain numeric format (e.g., `1000.5`, not `1,000.5` or `1 000,5`).
