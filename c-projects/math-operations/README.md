# Math Operations

Command-line utilities for mathematical conversions and calculations.

## Contents

- `math-operations.c` — Source code containing all functions
- `reflection.md` — Development notes for the source code

## Compilation

The compilation process is done from the parent directory with CMake. For more detail on the compilation process see the [c-projects README](../README.md/#compilation).

## Running

For CMake compilation, from the `build/` directory:

```bash
./math-operations
```

The program presents a menu in a loop. Follow on-screen prompts to select functions and provide input.

## Functions

### Temperature Converter

Converts temperatures between Celsius, Fahrenheit, and Kelvin. User provides a value and source unit; program outputs all three conversions.

#### Known Limitations

- Number format separators (commas, spaces, periods for thousands/decimals) are not parsed.
- Input must be plain numeric format (e.g., `1000.5`, not `1,000.5` or `1 000,5`).

### Factorial Calculator

Calculates factorial, with overflow detection. User provides a value; program outputs the result. On result overflow it offers to continue with a larger data type. On decimal values, the decimal gets truncated (for example `4.5!` becomes `4!`), and continues the calculations with the truncated value.

#### Known Limitations

- Number format separators (commas, spaces, periods for thousands) are not parsed.
- Decimals truncated (warning at runtime).
- Negatives not accepted (technically not factorial calculation).
- Precision for long double is at least the same as double as per the C standard, which is about 15 to 17 decimal digits for most platforms, but might be environment specific. Numbers outside of that range lose precision or will be rounded.
