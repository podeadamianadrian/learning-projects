# Math Operations - Reflection

## Temperature Converter

### Requirement

**"Convert temperatures between Celsius, Fahrenheit, and Kelvin. User inputs value and source unit, program outputs all three."**

### Specification (Before Writing Code)

**Input:** What information does this function need?
    User value, source unit type (C, F, K)

**Output:** What does it create or return?
    Values for Celsius, Fahrenheit and Kelvin from user inputted value and calculations

**Decisions:** What choices does it make?
    Value to display first (ex: Celsius if user input is in Celsius)

**Algorithm:** What's the step-by-step logic?
    ask for source unit type
    switch case for each type and default for unrecognized type
    ask for value and store the value
    in each switch case:
        math the other two source unit values
        print the values with some kind of formatting (will decide formatting when writting code)
    in default switch case:
        print "unrecognized unit type, pick valid" kind of message

---

### Problems Encountered

1. "duplicate case value" essentially, because I was trying to use OR operator in my cases.
2. I realized that indeed, I followed the spec, but I didn't think about the "default case" enough. It prints, but after that it breaks out. I want it to repeat itself, and loop through itself until the thing is set. And maybe add another case for "exit" so the user can exit whenever they want. I think I might actually end up redoing a bit the code according to that idea, then update the spec.
3. I had an error(warning but I make all warnings errors) while compiling about "prototypes", too tired to properly lay out what I read, but the gist of it is, I had to `(void)` at the end of the functions. And that fixed it.
4. Started to check for bugs and unintended behavior and stuff like that, If I write "Kelvin\n" (newline being just me pressing enter), it will pick kelvin in switch because of the k, but then it will read the other characters as well over and over until the last one multiplying my output, and it reads one of the letters in the value section where I want to have just numbers. And there is the no exit that I mentioned at point 2. Should it be just function exit, program exit or both? Because I do intend to make some sort of menu, later when I have multiple functions in here.
5. The script, if it runs continuously from one iteration through the other is a bit iffy. When doing value input it holds the \n and gets read for the next iteration, which gives me the "unexpected character" scenario. Not breaking, but annoying to see "from user's perspective".
6. Adding a while loop to clear the buffer, I created another bug, if unexpected character, then it will wait for input again (after the switch case, the while loop), so that the while loop has what to eat. Great!
*The following are done with "code review" done through AI:*
7. Single vs double quotes in my printf() (character vs string quotes).
8. Integer division, initially I wrote 9/5 which would get truncated to integer resulting 1, which would screw my math.
9. Very long inputs being given (past the 100 elements array)
10. Empty inputs (just enter) printed a bad looking message on default case.
11. Non-numerical values for the temperature defaulting to something I wasn't aware.
12. Scanf() leaves non-numerical values in buffer which created an infinite retry loop.

*The following is again a problem I encountered/realised:*

13. What if the user inputs a space before writing any "actual character"? What if he writes 110 space characters (over my array), because then even if they do write actual characters after the spaces, it will get discarded by the "buffer clearing" part of code.
*The following is a problem pointed out from an outside source:*
14. Temperatures lower than absolute 0.

*Aware of but decided not to "fix":*

15. Separators for thousands/millions/etc and for decimals, different places use different spearators.

### How I Solved Them

1. Fall through the cases as I intend.
2. Done a recursive call to the function in the default case, with return 0 immediately after so it exits the converter nicely.
3. `(void)` the functions did the trick.
4. I drop the `getchar()` and instead go for `fgets()` where it reads the whole string, but the important part I am looking for is the "first letter".
5. I decided to clear buffer with a `while (getchar() != '\n')` loop.
6. I decided that the default case will call its function and that it will return 0 right after.
*The following are still solved by myself, with minimal/some guidance from AI, no solutions copied and pasted:*
7. Changed the printf() to use double quotes (for strings).
8. Changed values to be "9.0f/5.0f" for the result to not be truncated.
9. If statement checking if `strchr()` finds '\n', if it didn't find, it clears buffer.
10. Added case for '\n' specifically where it avoids any bad looking messages.
11. I created an int for the input, to get the return value of scanf, and if it's 0 to clear buffer, and retry for proper input.
12. Clearing buffer inside the retry loop before next attempt.
13. I created a short piece of code where it checks for space characters, if it's a full aray it will stop on '\0', if it's not the full array of spaces then it will proceed normally based on whatever key it finds first. If it is full array, the ch is '\0' (which is needed for the switch case) and there is no '\n' to be found, then it will go through the whole stdin by `getchar()` to find the first character that isn't a space, and it will act according to the first key found, at which point it will stop checking any other keys, and will proceed to clear input buffer.

*The following I again implemented by myself without guidance:*

14. Just a simple "if value < {number here} print "impossible value".

---

### Self-Check

1. **Can I trace and predict what happens?**
    I think I can trace and predict somewhat accurately what happens. I had moments where I tried to predict previous iterations, which didn't math with reality, creating bugs, or making me not see some bugs by myself, but the current state I can somehow trace and predict to (what I believe to be) decent accuracy.
    The code first has the function temperature_converter which is voided because it doesn't take any arguments. Then it creates the signed int (intentional about the signed so that it doesn't become unsigned in other systems/environments) ch and input, and the float value, celsius, kelvin, fahrenheit (this is a difficult word for me to type for some reason) and a char array (which acts as a pointer because of the array) named user_input with 100 elements. The actual "process of the code" starts with the first printf, asking what type of temperature the user brings, after which we do an fgets() which reads the whole array from the stdin (terminal), with the "ch" (which will be for the switch case) defined on the first element of the array, since we are looking for either "c" or "C" (upper and lower case letters) as an example, out of a word like "celsius" because someone might type in "celsius" instead of just the first letter. The explicit conversion for signed int of the first element of the array is intentional so that I don't get warnings (errors with my "gcc wall of arguments"), doesn't error in different environments, and for the code to be "as proper as I can get it". Then a quick check whether the array caught the whole line the user had as input or not. If we didn't, then we clear the buffer. After that a switch case portion. I will stop here because this section gets too long. Hopefully this proves that I can somehow trace and predict/explain the code.
2. **Can I explain why each part exists?**
    I think I have done that previously/just above, as well as with the "problems encountered" section.
3. **What pattern did I use? Did I see it before?**
    I don't know what patterns did I use, and whether I saw them before. For now nothing clear comes through my mind (I won't consider a switch case as a pattern). Maybe the buffer clearing code will be something that I will do again and again. And maybe the intentional fall through of the cases.
4. **What might be general vs C-specific?**
    Besides switch cases, while loops, and if statements, I guess anything that interacts with a terminal and has an "input buffer" will make use of the buffer clearing according to its language. I don't see anything else tho that might be general or c-specific, because I see most stuff as being extremely general for now.
5. **If this broke, how would I find the problem?**
    I would try to understand what happened exactly that it broke, and try to trace through the "possibility of it breaking". Like with the non-numerical values in the scanf looking for numbers. I might use some extra printf's here and there, because I still don't know how to use a debugger in VS Code.

---

### Transferable Knowledge

General switch case, while loop, and if statements, because they work across most languages (I believe), the function being outside of main is another. That's pretty much it for now. I cannot identify too much "transferable knowledge" as of right now.

---

### Notes

After looking in, and losing the file of "NASA's C style guide" I decided to look at the linux kernel one, and decided to create my own which I will follow. Combining ideas from wherever I see, and deciding to write them down somewhere.

I want to have "some edge-case handling": garbage input (default switch case), and repeated output because of "repeated input" (doing something for each character in the whole line, when I want it to do just for the first character of whatever line length there might be).

I think `getchar()` might be the quick option I am looking for. I will try to use that. Checked by using "Beej's C Library Reference" (I know it's not *really* named that, but I want to keep it short.). This should read just one character from the whole line, so there shouldn't be any repeated input, and "forget" the rest. I will first get the code running and then test for it and change accordingly.

I had to look for the binary character table just to be sure, because I am not sure if I will do a proper job if I would typecast. I guess it would be something like `(char) ch; switch (ch) { case "c" || "C": //code}` and so on, but I don't want to risk it so I will use integer values.

I keep reading about typecasting, and trying to figure out how I can convert the character "C" for example to int and back (`getchar()` converts a character to integer by default, and I want to convert it back to character), but I guess I will just int ch then ch = getchar and then for switch I will go something like `case (int)'c' || (int)'C': //code` and hopefully it works. I am now just trying and learning from trial and error. I cannot find what I am looking for (or maybe I don't know to search/look for what I explicitly need/want).

Had to quickly look for the logical operators to make sure that "||" is OR.

While writing the code I encountered the following `case label value has already appeared in this switch at line 11 //C/C++(1578)`. I don't know what or why or how, but I cannot get rid of it by "fixing" whatever error there is. I will try to search it up so I can try and understand.

It is because of the OR operator evaluating it all to 1 because true, and using "case 1" essentially, twice. I will fall through for options then, as suggested on the internet. I will remember from this mistake.

Quite a few of the things I have done and learned I forgot to "document". But I am not going to try and figure out how to phrase them and whatnot. This whole document is supposed to show some part of my learning, and thought process, because I cannot capture it all properly in one document.

While writing whether I can trace the code or not, I realised an edge case, what if the user inputs " celsius" (space at the element 0 of the array). I will test for it and update the rest of the document accordingly if it is a bug.

While writting the document I realised I never gave the possibility for the user to exit the function temperature_converter. Not that it matters for now since the main loops into it, but that's something for when I get 2 or more functions in there.

The final algorithm as well changed, I will update here so that there is a comparison of "before" and "after":

**Algorithm:** What's the step-by-step logic?
    Initiallizing (but not assigning) values needed
    Ask for source unit type and give option to exit
    Get the array of characters written
    Check if any character is a space, proceed to the next if it is.
    Assign ch (for switch) as the first character that is not a space.
    If ch is a '\0' (is it called null?) and strchr cannot find a '\n' (new line) in the array
        check_char calling getchar()
        while check_char is a space
            check again calling getchar()
        ch assigned to check_char
    if strchr doesn't have a new line '\n' in the array
        while getchar() isn't a newline (the block is empty, I just need the while check)
    switch
        q/Q: exit
        '\n': no input detected, recall itself
        c/C: input Celsius value, do math for the rest, break; if less than absolute 0, break;
        k/K: input Kelvin value, do math for the rest, break; if less than absolute 0, break;
        f/F: input Fahrenheit value, do math for the rest, break; if less than absolute 0, break;
        default: character not expected, recall itself
    while getchar() isn't a new line '\n' empty code block because I need just the while

---

## Simple Interest Calculator

(same structure repeats)
