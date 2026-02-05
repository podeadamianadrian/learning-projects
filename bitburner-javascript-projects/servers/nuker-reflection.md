# Servers Nuker - Reflection

## Auto Rooter

### Requirement

**"Continuously attempt to root servers as programs become available and hack level increases."**

### Specification (Before Writing Code)

**Input:** What information does this function need?
    Server list, hacking level, port openers/programs

**Output:** What does it create or return?
    Gives root access to the servers

**Decisions:** What choices does it make?
    Which servers to open ports and root

**Algorithm:** What's the step-by-step logic?

    initialize sleep duration
    initialize file with the file I will read from
    initialize server list from file
    initialize programs list
    While true
    let existing programs
        for loop of programs
            if program.alias exists increment existing programs by 1
        For loop of servers
            if server doesn't have root
                if have programs >= ports requirement and have hacking level >= hacking requirement
                    for loop to open ports with the available programs
                    nuke
        sleep(duration)
---

### Problems Encountered

1. I keep getting a syntax error at the beginning of the string for the JSON.parse, no matter what I name the files it says "it's not valid JSON" even if I made the files be JSON.

### How I Solved Them

1. I first had to read the file, and after that to parse. Doing both of them at the same time would create the syntax error.

---

### Self-Check

1. **Can I trace and predict what happens?**
    Yes, I can trace it, initialize variables, initialize programs array, while true loop to count programs (they can change over time), for programs of programs list increment existing programs variable, for server of servers list if it doesn't have root then check if existing programs is more or equal to servers port requirement and hacking level is more or equal to required hacking level, for loop to run the code of the program, then nuke and sleep a defined duration.
2. **Can I explain why each part exists?**
    I hopefully managed to explain all of the parts that need explaining in the code with comments, along with the reflection writing about them.
3. **What pattern did I use? Did I see it before?**
    I am not sure I can identify any pattern specifically right now, but there might be a couple, I am not counting basic "for of" "while" and "if condition" statements as patterns.
4. **What might be general vs BitBurner-specific?**
    The array I created is general, the file reading is general, the "configurable duration at the top" is general (to avoid magic numbers), and the loops associated with them are general. The ns api calls are specific.
5. **If this broke, how would I find the problem?**
    I am quite certain that it doesn't have a way to "break" right now.

---

### Transferable Knowledge

    The array creation, besides basic "if/for/for-of/while", reading and making use of a file's information. That's all I can identify straight away.

---

### Notes

    Nothing note worthy.

---
