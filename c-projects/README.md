# C Projects

Standalone C programs, ranging from basic exercises to more involved projects.

## Development Environment

- **Operating System:** Linux
- **Compiler:** GCC
- **C Standard:** C17
- **Editor:** VS Code
- **Version Control:** Git, pushing to GitHub

## Compilation

Projects are compiled using:

```bash
gcc -std=c17 -Wall -Wextra -pedantic -Werror -Wshadow -Wconversion -Wformat=2 -Wswitch-default -Wstrict-prototypes -g -o output.out main.c
```

- `-std=c17` — targets the C17 standard
- `-Wall` — enables common warnings
- `-Wextra` — enables additional warnings beyond -Wall
- `-pedantic` — enforces strict ISO C compliance
- `-Werror` — treats all warnings as errors (must fix to compile)
- `-Wshadow` — warns when variable shadows another in outer scope
- `-Wconversion` — warns on implicit type conversions that may lose data
- `-Wformat=2` — strict checking of printf/scanf format strings
- `-Wswitch-default` — warns when switch lacks default case
- `-Wstrict-prototypes` — requires proper function prototypes
- `-g` — includes debug symbols for GDB/VS Code debugger
- `-o output.out` — names the executable (replace with project name)

This setup catches most beginner mistakes at compile time and enforces habits that transfer to professional C development.

## Structure

Projects are organized by conceptual groups. Related projects that share similar patterns or build on each other are kept together in the same folder, often as functions within the same source file.

For example, temperature conversion and interest calculation might both live in a `math-operations/` folder as functions in the same program, since they're both straightforward input-calculation-output patterns.

Each project folder contains:

- Source code (`.c` files)

- A reflection document with notes on the development process

## Reflection Documents

Each project has a reflection document where I write about what I was trying to do, problems encountered, and how I solved them. For more detail on what these contain, see the [root README](../README.md#reflection-documents).
