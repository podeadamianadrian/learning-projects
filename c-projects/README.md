# C projects

A collection of standalone, standard C projects ranging from basic exercises to more involved projects. They are built on: strict compilation flags and portability-first "ideals"; while I attempt to build them as optimized as I know how to make them.

The projects here are built in C instead of other languages, so that I can learn fundamentals while building a portfolio.

## Development environment

- **Operating System:** Linux
- **Compiler:** GCC
- **Build system:** CMake
- **C Standard:** C17
- **Editor:** VS Code

## Compilation

Projects are compiled using CMake or GCC.

CMake is the primary compilation method. The command that I use from the `c-projects` directory:

```bash
mkdir build ; cd build ; cmake .. ; make
```

After that:

```bash
cd build ; make
```

*Notice:* Re-run `cmake ..` from the `build/` directory whenever `CMakeLists.txt` has been modified.

GCC is the secondary method of compilation as of right now. The main command is:

```bash
gcc -std=c17 -Wall -Wextra -pedantic -Werror -Wshadow -Wconversion -Wformat=2 -Wswitch-default -Wstrict-prototypes -g -o output.out main.c
```

I went through the [man pages](https://man7.org/linux/man-pages/man1/gcc.1.html#OPTIONS) of GCC so that I can understand the flags better (they are hard to read) and this is my understanding of the flags I use:

- `-std=c17` — compiles for the C17 standard
- `-Wall` — covers most common mistakes
- `-Wextra` — covers "some extra warnings"
- `-pedantic` — enforces as strict ISO C compliance as possible
- `-Werror` — treats all warnings as errors (must fix to compile)
- `-Wshadow` — warns when a variable is named the same as another from outer scope
- `-Wconversion` — warns on "accidental" type conversions (so I don't, for example, truncate floats)
- `-Wformat=2` — strict checking of printf/scanf format strings (%e for doubles, security holes and so on)
- `-Wswitch-default` — warns when switch lacks default case
- `-Wstrict-prototypes` — requires proper function prototypes (I cannot have empty parameters, must void)
- `-g` — includes debug symbols for GDB/VS Code debugger (for when I manage to set it up)
- `-o output.out` — names the executable (replace with project name)
- when compiling manually, add required utility source files (for example `../utilities/utils.c`)

This setup is meant to catch as many mistakes I might make as possible, since I have come to the realization that the compiler is my friend (not my enemy), and that it's easier to "catch bugs" at compile time than later. The list might expand in the future based on what I learn and the way in which I understand the man pages.

For running/"testing" the projects, each project README describes how to run the compiled program.

## Structure

The naming is an attempt at "self-explanatory" names.

Small (function level) projects are organized by conceptual groups. They are related in ways that share similar patterns or build on each other.

Other projects (bigger than just a function or two) are in their own folders, organized under "conceptual folders". The "conceptual folders" put projects that have similar enough connections in a group.

- `CMakeLists.txt` - for the option to compile/build with CMake
- `.clang-format` - a "display" and backup copy of my system-wide formatting configuration
- `STYLE.md` - documenting the coding style I follow and why

### Projects

- [utilities/](./utilities/) - a collection of "personal utility functions", with similarities to the project folders
- [math-operations/](./math-operations/) - input-calculate-output "predetermined calculators" wrapped in a menu
- [hangman/](./games/terminal-based-games/hangman/) - Word guessing game with user profiles, difficulty customization, persistent stats, and adaptive terminal display

Each project folder contains:

- Source code
- README file trying to do a "professional" presentation of the source code
- A reflection document with notes on the development process

## Reflection documents

Each project has a reflection document where I write about what I was trying to do, problems encountered, and how I solved them. For more detail on what these contain, see the [root README](../README.md#reflection-documents).
