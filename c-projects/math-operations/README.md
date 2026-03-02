# Math Operations

Mathematical conversions and calculations, presented in a menu "wrapper".

## Running

The program presents a menu in a loop. On-screen prompts show what is available and how to use it. Each option (once selected) has its own interaction flow (listed below).

## Reflection documents

A reflection document is where I write about what I was trying to do, problems encountered, and how I solved them. For more detail on what these contain, see the [root README](/README.md#reflection-documents).

## Features

At the start of the program, a text menu is presented. Interacting with it gives the option to pick one of the following:

### Temperature Converter

Converts temperatures between Celsius, Fahrenheit, and Kelvin.

User provides a value and source unit; program outputs all three conversions.

#### Known Limitations

- Input must be plain numeric format (e.g., `1000.5`, not `1,000.5` or `1 000,5`).

### Factorial Calculator

Calculates factorial, with overflow detection.

User provides a value; program outputs the result. On result overflow it offers to continue with a larger data type.

On decimal values, the program truncates the decimal with a warning (for example `4.5!` becomes `4!`), and continues the calculations with the truncated value.

#### Known Limitations

- Number format separators (commas, spaces, periods for thousands) are not parsed.
- Negatives not accepted (technically not factorial calculation).
- Precision for long double is at least the same as double as per the C standard, which is about 15 to 17 decimal digits for most platforms, but might be environment specific. Numbers outside of that range lose precision or will be rounded.
