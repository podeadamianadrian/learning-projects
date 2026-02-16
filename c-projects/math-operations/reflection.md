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
2. Done a recursive call to the function in the default case, with return immediately after so it exits the converter nicely.
3. `(void)` the functions did the trick.
4. I drop the `getchar()` and instead go for `fgets()` where it reads the whole string, but the important part I am looking for is the "first letter".
5. I decided to clear buffer with a `while (getchar() != '\n')` loop.
6. I decided that the default case will call its function and that it will return right after.

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

*Notice:* After some time, I decided to revisit the function since I have created a menu, and to clean up a bit the recursive calls and the "clear input" lines of code.

---

## Factorial Calculator

### Requirement

**"Calculate factorial of a number. Handle 0! = 1. Warn if number is too large for data type."**

### Specification (Before Writing Code)

**Input:** What information does this function need?

    User's value for factorial math, the <limits.h> header, that "0!" is 1, how to calculate factorial (oh no, I am learning math!).

**Output:** What does it create or return?

    It creates the results as output on the terminal, outputs to the terminal the results with the format "x! = y".

**Decisions:** What choices does it make?

    What values are bigger than what limits, how to handle them, the decision of "0! = 1", whether to display the value directly, or ask the user if they want to see the value even if "it isn't perfectly precise".

**Algorithm:** What's the step-by-step logic?

    Get the value from user as unsigned int
    If value = 0! result = 1
    !Notice!: This will be a factorial helper function above factorial calculator but will be part of this specification because it is useful only for this function.
        For the value defined, do the math required (by a quick google search into "what is factorial math" I guess it will be a for loop with iterations based on the value assigned by user):
            u_int user_value = scanf();
            u_int result = 1;
            for (u_int i = 1; i <= user_value; i++) {
                if (result > INT_MAX / i) {
                    Warn the user and wait for their confirmation/rejection of "I want to see it/I don't want to see it".
                    If user accepts display, show number with explicit cast, else "user aborted" (I will see how I will decide to handle this, wether with return non-zero, or just a simple printf message)}
                u_int result = i * result
            }
    Finish function.

---

### Problems Encountered

1. I got a lot of errors about the formatting I put in the printf, and the values that are actually used.
2. It tells me about statements with no effect/unused-value.
3. Trying to properly convert result to long double by typecasting it warns me (therefore errors on me because of -Werror) about it possibly changing value.
4. I ended up not being able to properly handle the function in function thingie (one function calling another), so that I can do any displaying.
5. After a bit of trying (and a bit of back and forth with AI about my code, I have no person to ask for help as of right now) I figured I have structural issues, as well as some logic issues (I am trying to squeeze into the helper one function that does 3 things, math, display, and checking for overflow, in the same for loop).
6. When compiling it complained about assignment instead of comparison, which made me aware that I mistakenly did assignment in if sentences.
7. Missing address-of `&` in scanf.
8. Forgot to update printf statements to actual valid variables for each "data type" which lead to issues in how the values were displayed.
9. Didn't do assignment on initialization of variables, which for some reason meant it did multiplication by 0. (Undefined behavior, which can get handled differently in different environments)

*The following are done with "code review" done through AI:*

1. Knowledge gap in how typecast works, which lead in poor implementation on the project.
2. Trying to clear input, I ended up overwritting some of the choices of the user.
3. Invalid input like "abc" or "19.99" or "-5" outputting "undefined behavior" (undefined behavior as in behavior that wasn't defined by me for the user to have; well, decimal it silently truncates which is "standard" behavior I feel like, but the other two are behaviors that I didn't "prepare" for, therefore "undefined by me" so to speak)

### How I Solved Them

1. Looking up the proper formatters for displaying values for printf and using the proper ones.
2. I had to reassign the "result" values to "result = (type casting to my choice)result"
3. I decided to do "double scientific_value = result" to get around it. I don't know if there was a better way around it.
4. I will keep it without the function and just have a very long Factorial Calculator.
5. I will go back to the "planning stage" (I guess I will call it), so that I can better do the assignment and fulfill the requests. I will put the "updated code" in the notes as a comparison.
6. Did comparison properly, being sure to do it at all if statements that should have it, compiler said to put parantheses for assignment, so I will keep this in mind whenever I assign then ask for a "value/something" right after in the same condition.
7. Added it to the scanf (I will need to remember to search to find out why the address of is needed and where and whatnot, to figure out how it works)
8. Updated the statements with their respective variables.
9. Assigned values to the value of 1 right after initialization (whichever ones needed that).

*The following are still solved by myself, with minimal/some guidance from AI, no solutions copied and pasted:*

1. After explaining from AI that typecasting doesn't "permanently change the type" and that it is a temporary "change type now and forget it happened", I added multiple variables of appropriate types according to the calculations that I had to make.
2. Removed all lines that "cleared input", created an utility function that I used instead, which allowed me to avoid "overwritting choices".
3. Used strtol with if statements added for different inputs, trying to either "quit" or "warn" for different types of input.

---

### Self-Check

1. **Can I trace and predict what happens?**

    I will take the case of 25! which should be (according to a quick google search) "51,090,942,171,709,440,000".
    The number I pick "25" will be saved in user_value first, which is checked with fgets so that it takes as much of the user input as the array allows, and if it returns EOF it will return.
    Then there will be a quick check if "user_input" holds everything by looking for a "new line", which if it finds, means it got everything I inputed, and if it doesn't, then it will clear the rest of the input.
    Set errno to 0 so that "I start fresh" on the error number between runs.
    input_value is asigned strtol of user_input.
    Now here are a few checks, if end (where the strtol found the first issue in the line) is equal to user_input, that means there was no number detected, perhaps not even inputted, I input "25" so it doesn't happen.
    Then we check if the input_value had over- (or under-) flown, my value shouldn't.
    Then a check for input_value if it's less than 0 for negative numbers, my number is not a negative number.
    Then we check if pointer to end is a dot, in which case it might be a decimal. My number doesn't hold a decimal anywhere. Else if check for pointer to end, if it isn't a new line, or it isn't null, then there might be leftover characters, but not numbers, so there's a warning for that, and that it was lost. My input of "25" doesn't trigger anything yet.
    And then a quick if check for input_value if it equals 0, because 0! is 1, in which case I don't need any math. My value is 25.
    Now we get in the first for loop, where we assign i to 1, so that we start with multiplication, and check if it's less or equal to input_value, incrementing i every loop. Inside the loop there is first an if to check for overflow, which my number will trigger, and assign the value "first_overflow" to true, and break out of the loop. After the if check it will multiply result_ull (the variable it will display as the result) with i being explicitly type casted to unsigned long long. (I don't know the true value of doing the type cast explicit, besides that it makes the compiler happy, for now)
    Then we get to an "if (first_overflow)" where we check if the first overflow has a true value. In my case it does.
    In the if case (where we go in) there will be a prompt, whether I want to continue or not.
    Here my choice gets assigned to getchar() return value, because I am looking just for the first letter, not a whole word, so no matter if someone writes "yeet" or "yes", it will continue after which it will clear the input like it took the whole "yeet" or "yes". Intended to be like this.
    Then there is a "while choice isn't 'n'/'N'/'y'/'Y'" where it will loop in itself looking for the "yes" or "no" with lower or upper letters. If it won't find either of the characters, then it will keep looping.
    After the while, there is an if statement where we check if the choice is n, in which case we print out that we are aborting, that the value chosen was "25" in my case, and that the value reached is "21-1" which is "20" printed on the terminal. The count reached 21 when it realized there will be an overflow, which it broke out of to avoid the overflow at the iteration 21, with value being saved as 21, so we need to show -1 for the actual math that has been done, because we didn't do factorial for 21, just for 20 before breaking. Then it will show the result for that.
    In the case of choice being "y" it will continue to the next for loop, which is the same as the previous one, except with a larger data type of long double, which as well has the same overflow detection, and in the case of overflow, it will just abort there, and display the value chosen, the value reached, and the result of said value, then return, because I don't know how to go for values past long double type. After the if statement, the same math as in the previous loop is done.
    Towards the end I have an if first overflow is false, print result with unsigned long long, else print result with long double. If I wouldn't have triggered the first overflow, then my result would have been in unsigned long long limits, in which case it would print like that, but my result did, so it's printed in exponential with long double. Then return.

2. **Can I explain why each part exists?**

    The "clear_input()" is a function I create to clear input, it's there after every input choice so that the "input buffer" doesn't screw over other input sections and this way I clear it.
    I created two similarly named values, one for unsigned long long, and another for long double, because I cannot do permanent conversion from one data type to another, so I have to have two different data types, so that I can do what I intended to do (continue past overflow, into a higher data type).
    I get input with fgets because it can take a very long string, and that way I take input easier. The fgets is part of an if statement, where if stdin is null, I will return because then it means it's EOF.
    I have a check right after the fgets "if strchr doesn't contain '\n'" because then it means we didn't catch all input, and we need to clear_input().
    Assign errno to 0 so that error from a previous errno assignment doesn't leak through on this function.
    Assign input_value to return value of strtol because I want just the numbers, and anything else goes through different if checks.
    The overflow verification is there, as an if before the math, so that we detect when overflow is about to happen, not when it happens, because if it happens, the value loops back from the lowest value, in which case I will never catch the overflow (because it happened already).
    If (first overflow) is there so that if we don't trigger the first overflow, nothing else happens and we skip through all that without wasting resources.
    The while loop inside the if, is there so it loops for people that don't input what I expect.
    If (choice == 'n' or 'N') there for people that don't want to keep going on higher data type.
    and the if else is there to display the values with two different prints, so that stuff prints out nicely.

3. **What pattern did I use? Did I see it before?**

    I am not aware of any patterns that I might have used, besides the "take input -> clear input" pattern, which I tried to trim down as much as I can as of right now.

4. **What might be general vs C specific?**

    The terminal input clear is general for any language that deals with terminal in a similar way as C, the basic statements don't count, and the overflow check might be general as well for any languages that have some form of overflow that needs to be handled by the "programmer" not handled by the language/compiler. Plenty of the other details might be C specific.

5. **If this broke, how would I find the problem?**

    If something would break I would try the same things as I did for debugging while creating the function: pipe input with the terminal, do manual debugging of specific cases, try to follow the code see where it broke, maybe use printf statements to check where things go sideways.

---

### Transferable Knowledge

    The "code extraction"/"code refactoring" (or whatever it is called) I have done of the "clear input" is transferable knowledge. The terminal input clearing itself for languages that interact with the terminal similar to C. The overflow check for languages that have overflow like C. The general "debugging mentality" ("what if this broke" or "what if the user does this" kind of thinking). The problem solving of possible bugs before they happen and problem solving of bugs I caught at runtime. And I cannot identify anything else besides these.

---

### Notes

    I realised after a bit of moving around that on problem 4, I just didn't put any printing for a normal case where the int doesn't overflow...
    I have revised my approach and now got something more manageable:

**Algorithm:**

    define what I need to define (user input_value, user input_choice, results = 1, first_overflow)
    ask for the value
    if (value 0) {
        display result being 1
        return
    }
    for (i = 1; i <= input_value; i++) {
        if (overflow) {
            update result to what it is now
            first_overflow = true (will need the stdbool.h iirc)
            break
        }
        do the math for the factorial normally
    }
    if (first_overflow = true) {
        warn about overflow
        if (user denies) {
            present maximum value reached
            return
        }
        typecast result to higher type
        for (i = 1; i <= input_value; i++) {
            if (overflow) {
                update result to what it is now
                warn and print max result
            }
            do the math for the factorial normally
        }
    }
    display result (after everything outside of any else/if/while/for or anything)

    Sadly this is the best I can do for now, since I don't know how to separate concerns properly without creating messy code. The attempt to separate concerns in the first place is what created the previous "messy code". I am aware I don't have the tools necessary as of the creation of this function to manage and do "nicer code" in this case.
    The options I am able to see is: helper function that takes different types (but I don't know how to make a function take "variable types" as of right now, besides making 3 different helper functions), and switch case instead of the if sequence that I have created (but I am not sure how I could go about it, the implementation seems confusing for me as of right now).
    I know that I could go about it in many more different ways, much cleaner than I am doing, but the point is for me to make something that works, something that is as thorough as I can get it, therefore, I will do it however I can right now, and if I can ever improve it, I will acknowledge that to myself, maybe in a document, but I will leave the code as is when I am done with it working and thorough, just so that I can look at it without going through the "github versions" to compare my "improvement" or "evolution".

*Note: with the guidance of AI to revise my approach, I ended up going in this current iteration, instead of one that had 7 levels of nesting, and to get out of my mind "going back to the beginning of code" when I "need to redo a loop" for some reason, since that is not something that I can do (I guess).*

    I ended up planning to create some "lib.c" library file for my uses, because of issue 11, where I will properly implement reusable pieces of code like the "clearing input" which I will use a lot, and I will proceed to rewrite the "factorial calculator" once more, but this time following the second "algorithm" I wrote, but a bit more careful so that my code is easily readable, with the new "lib.c" and "lib.h" files I create.

---
