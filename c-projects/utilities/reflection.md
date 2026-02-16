# Utility functions - Reflection

## ClearInput()

### Purpose

The function will clear all the input that is leftover in stdin, so that it doesn't affect following "taking input" places.

### Origin

This function came to be from the factorial calculator project. I was essentially manually copying (typing) the lines of code over and over, and eventually broke my code by doing that, because it was getting hard to read and figure out where I cleared input and where I didn't, which affected the other input choices in the code. The function is created so that I write one clear function so I can follow where I cleared input and where I didn't, instead of "guessing".

### Specification

**Input:** What does it need?

The function doesn't take any parameters. The expected state is for stdin to be active. It is expected to be used right after an "take input" section that leaves some leftover character, even a `\n`.

**Output:** What does it produce?

It empties the stdin of input.

**Decisions:** What choices does it make?

The function doesn't really make any decisions, just exits on EOF.

**Algorithm:** How does it work?

Function doesn't return anything and doesn't take parameters
    initialization of ch as int
    while ch assigned to getchar() doesn't equal new line
        check if ch equals EOF, if it is EOF then exit

### Dependencies

The function needs `<stdio.h>` for `getchar()` and `EOF`, and `<stdlib.h>` for `exit()`.

### Usage

This function should only be called (preferably immediately) after a function that takes input and leaves "residue" in stdin, otherwise it will wait for input to eat, and if it encounters EOF it will exit.

### Limitations

EOF will result in exit, therefore no "piping input" and no "CTRL+D" whenever the function is used.
It **will** wait for input, if there is no "prior input" for the function to "eat".

---

## Menu system framework

### Requirement

**"Reusable menu system. Deﬁne items, display, get selection, execute. Design for reuse in future projects."**

### Specification (Before Writing Code)

**Input:** What information does this function need?

Array of functions (as structs), the number of items in the array, both as parameters. Inside the function the struct is broken down to name, description and action (function to call) and the user input.

**Output:** What does it create or return?

Display list of functions, display the choice of the user, different messages according to the invalid input inserted, and whatever the other functions that will get called will output.

**Decisions:** What choices does it make?

It decides a number for the function, what function to call according to user input, chooses which messages to display according to the invalid input, whether to exit based on user input.

**Algorithm:** What's the step-by-step logic?

```txt
void FunctionName(array, array size) //still didn't decide what type array size would be
    Define variables: choice, *end, i, user_input
    Print welcome message
    Print "0. Exit - exit program."
    for (i = 0; i < array size; i++) //i starts at 0, because 0 will be the first element of the array
        printf("n. Name of function - description of function" (i+1), array[i].name, array[i].description) // don't remember syntax for printf out of my head, have to look it up
    Take input from the user with fgets
    if EOF exit(0)
    if stdin not empty ClearInput()
    errno = 0
    choice = strtol(input taken with fgets, &end, 10)
    if it's a word refuse input, return
    if it's empty refuse input, return
    if (user input > array size  || user input < 0) refuse input, return
    if it has decimal or words after the initial number warn that it's ignored
    If input equals 0 then exit(0)
    Call function by using array[valid user input - 1].function()
```

---

### Problems Encountered

No problems encountered.

### How I Solved Them

Thorough planning, reusing "essentially the same code" but adapted to my needs at the moment (patterns and pattern recognition I guess?), and understanding the concepts I am about to implement (thoroughly preferably) are very helpful for "no problems during implementation".

---

### Self-Check

1. **Can I trace and predict what happens?**

First I define variables, then print a "welcome message" for the user, and the first option "0. Exit - exit program", then I loop through the array passed in parameters and inside the loop I will just print the options for the user, then I "fgets" the input, inside an if check for null to exit if stdin hit "EOF". Then I check the string passed by the user, to see if fgets caught everything the user inputted, and if it didn't, then I will silently clear the rest of the input. I define errno = 0 (first, because that's recommended to do according to the man page for strtol, second, because there is another place where ERANGE is used, and errno needs to be set to 0), then assign choice to strtol(), then validate the input based on what I want to know (if where "strtol" encountered an issue is at the start of the string passed by the user means no numbered input, then choice needs to fit between 0 and the size of the array, then check for whatever other input might have been passed besides numbers and say that the rest is ignored), and if the choice of the user is 0 then exit the program, at the end having the "calling of the function" just as a simple line, which will happen if the previous if statements don't trigger.

2. **Can I explain why each part exists?**

The printing of the menu is there for "user experience" (it's nicer to see a welcome message than just a list of options without explanations), then I start with "0. Exit" because the "listing of the functions" starts with 1, and if I have 11 functions to pass, it will look weird "1, 2, 3 ... 11, 0", and it makes it easier for me to code if exit is 0, and I don't have to "code a reminder" of where exit should be (plus it would be annoying to type "25" to exit, if it comes to such a length of functions). The for loop prints the options simply because the functions are already "numbered" through the array. The choice for "taking input and validating" through `fgets` + `strtol` is because `fgets` takes input easier than `scanf` for my purposes (in my opinion), and `strtol` validates the input that it's a number, while handling spaces by itself, so I have to worry about "validating input" for fewer cases. Errno is set to 0 because it's recommended, and I have another function that uses errno and ERANGE from strtol, so it's safer to have it there (so that it's set to 0 from the menu, if I ever forget to set it to 0 somewhere else, but hopefully I won't). At the end I have the function call as a standalone line because if the input isn't valid, it will not reach that line, so the line happens only on valid (enough) input, while using the "choice - 1" because the user will input 6 for element 5 of the array.

3. **What pattern did I use? Did I see it before?**

The input validation I have done in factorial calculator as well, and here I just slightly adapted it for what matters in my use case. The "`fgets` + `strtol`" combination is as well a "pattern" I would say (at this point), for "taking numeric input only". And that's all I can quickly notice for now.

4. **What might be general vs C specific?**

The specific calls done to different "C Libraries" functions are specific. The general "print message, let user pick from terminal, validate input, call function according to user choice" is "general menu behavior".

5. **If this broke, how would I find the problem?**

If it did broke, I would look at what happened, try to understand it, and perhaps use "print debugging" just to try and figure out what went wrong where (don't have a visual debugger yet).

---

### Transferable Knowledge

The if-chain to make sure the input is valid (for example not empty string, not "out of bounds") has been something that I have done in Factorial Calculator, and a lot of the logic was reused from there, just adapted or simplified for this project (I don't need to detect '.' now because it is not relevant for a menu).
The "fgets take input - parse it through strtol for validation" is as well a pattern I could extract.
Thorough planning, and proper understanding of concepts before implementation is as well something that can transfer to other projects, but it's less "obvious" than the rest (I think).
The "reusable bits of code" are sharable to other projects, with the biggest issue (for me) being extraction of the bits of code.

---

### Dependencies

The function needs:

- `<stdio.h>` for `fgets()`, `EOF` and `printf()`;
- `<string.h>` for `strchr()`;
- `<stdlib.h>` for `strtol()`, and `exit()`;
- `<errno.h>` for `errno`;
- `"utils.h"` for `struct MenuItem`

### Usage

This function serves the purpose of a menu that the user can pick from.
The place of usage is not "critical", but I usually (and therefore recommend to) put it at the beginning of any program where I could use a menu.
The function needs to be looped, as it doesn't loop by itself (intentional).
I suggest having at least one function in a list of `struct MenuItem array[]` when passing the parameters into the function, for "intended behavior".

### Limitations

Infinite running of the function is not handled by the function itself, needs to be handled by the caller.
It is expected to have at least one item in the array, when passing the parameters to the function. It might have "good" behavior if there are *no* functions, but the intended usage is for "at least one function". (Didn't test it, won't test it, my flags either way stop such a case from happening.)
Stdin is expected to not hit "EOF". If at any point stdin is closed (CTRL+D) the program will exit.

### Notes

While starting to write the function, I have realized that most of what I am writing is essentially copy and paste from the other two "projects" that I have done. The if chain to check if the input is valid is kind of extractable (only for numbers) and the fgets into strtol is as well something that I could extract. Now I will need to figure out at some point how to extract those two in a reliable way that can be reused across different projects.

---
