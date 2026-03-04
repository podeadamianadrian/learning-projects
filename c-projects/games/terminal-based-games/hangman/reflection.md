# Hangman - Reflection

I want to make this as a fun game for people to play. I want difficulty (even if hangman doesn't really have difficulty), hints, and perhaps more things. This should be a fleshed out game, not just a programming exercise.

## Word Guessing Game (Hangman) - Program Overview

A program that works as a game. Welcomed by a menu, there's different choices to make between: options, exit, start a game, see leaderboard; with possibility for choosing difficulty, creating custom difficulties, deleting or creating users, having different methods of displaying, and a "scaling" drawing of hangman. The program is my best attempt at something as close to a game as possible. The rest of the concept (guessing a word) is familiar to most people from the actual Hangman game or Wheel of Fortune.

### Requirement

**"Guess a hidden word letter by letter."**

<details>

<summary>

### Design Decisions

</summary>

The format is:
- what was chosen; why chosen; what trade-off was accepted
    - what was rejected; why rejected

- **Storage approach:** load files into memory at the start of a purpose; it has fewer file operations; stale data if the program crashes in the middle of a session
    - Reading and writing in the middle of a session; might be too complex for me and there's a lot of disk operations and hangman doesn't need session saving

- **File format:** labeled text with the format "label: value" stored per line; I will have custom parsing for it, which is good learning and the labels will "align" with struct fields; more complexity and work
    - Positional format; too fragile
    - JSON; external library required
    - JSON-like clone; better fit for standalone project

- **File organization:** one file per user, one master index file; less risk of corrupting data, easier for me to implement; multiple files generated
    - In-place editing of users and user stats; too complex for me as of right now, I risk data corruption
    - Directory listing through functions; learn less about file I/O and data management

- **Username picking handling:** pick by typing username; easier for me to implement; user might be annoyed to have to type/remember username
    - Picking from a list; maybe too complex for me right now

- **Users limit:** 30 usernames maximum limit; not too many files created, but more than 30 usernames might be excessive for hangman; annoying for whoever wants more than 30 users
    - No limit; might break the program on absurd amounts of users

- **Hardcoded defaults:** most presets hardcoded; less files generated, less files expected to exist; code might get bloated
    - File defaults; more files needed for launch, higher chance for game to get "bricked"
    - Generating defaults each time; that means that either way defaults are hardcoded, I get rid of "multiple files generation"

- **File paths:** relative paths from executable location; plenty of bugs avoided; more complex, `#ifdef` per platform
    - Hardcoded relative paths; breaks when user launches game from other location
    - Absolute paths; very easy to break in most cases

- **Dictionary word picking:** load once before game start, filter and randomly pick from array; one file operation, the rest is code; memory usage negligible
    - File based random reads; multiple disk operations could slow down PC performance, random picks can have many "misses" before picking 2 words (maybe even freeze the program for a bit)

- **Hint usage:** reveals all instances of one character, limited to 1/6 of unique characters across all words; perhaps makes guessing more enjoyable; perhaps harder to implement than I assume
    - Limit to be based on word length; I would create an exploit by accident
    - Limit to be higher; makes game too easy

- **Username sensitivity:** convert all characters to lowercase in username on input confirmation (user presses enter => all characters are lowercase; "user" and "uSeR" are the same) with username chosen saved in user's stats; less perceived fragmentation of data; a few more lines of code, a bit more logic to implement
    - Username to not be converted; one person inputs user at game start as "MIke" instead of "Mike" and game considered to be broken/badly made

- **Stats are written on exit:** every exit path from a round will write stats (play count, guesses) before exiting (not applicable if no guess/hint-use made before exit); this prevents "manipulating stats" by quitting before the game ends; more "logistics overhead" for me

- **Multi-word mode:** essentially "wheel of fortune"; more variety; more logic to implement, perhaps trickier

- **Guess types:** full word and single character; more enjoyable game (perhaps?); more logic to implement, perhaps trickier

- **Difficulty customization:** user can create custom difficulties (limit of 5); more "customizable experience" and user can make game harder for themselves; more logic to implement

- **Duplicate guess:** rejected with "already guessed" message, no stat change; less penalizing/less "abusable" system for user; more logic to implement, perhaps trickier

- **Dictionary source:** "The great noun list" (~6000 nouns); no need to create or maintain my own word list; removed category hints, user category choice, category displays, and reduced word filtering to length only
    - Creating own word list; too much time invested for a hangman dictionary, and if I would create it I wouldn't like to be shallow with it
    - Hardcoding a few words in the program; too few choices, half of my plans would be gone

- **Display mode — drawing:** two modes for hangman drawing - primary is "hidden" to reveal (drawing present from start hidden with the background color, body parts revealed by removing the background color on wrong guesses), fallback is progressive stick figure (body parts added one by one); "hidden" to reveal chosen as primary because on bigger drawings it avoids "bleeding" between body parts (head accidentally showing the first line of arms and torso) and progressive addition as fallback for terminals where ANSI behaves unexpectedly (but may have "bleeding"); user can switch from options menu or by passing arguments if primary mode is broken for them, more robust program/game; essentially doubling the drawing implementation work
    - Single mode only; no fallback means broken/buggy display for some users

- **Input collection:** two modes for input - primary is arrow selection with immediate input detection (non-canonical terminal mode), fallback is type-and-enter (canonical); immediate detection chosen as primary because it is closer to a "game feel" with type-and-enter as fallback for terminals where non-canonical might not work as expected; user can switch from options menu or by passing arguments if primary mode is broken for them, more robust program/game; essentially doubling the input collection work
    - Single mode only; no fallback from "non-canonical" means broken input for some users

- **Terminal output method:** ANSI escape codes; more portable for Windows 10 and 11, no external library needed; might behave unexpectedly on some terminals
    - `ncurses`; unreliable portability answers, cannot verify it runs natively without user downloading it
    - `printf` with screen clearing; portable but eliminates cursor positioning and colors, which removes colored feedback from my plans

- **Terminal resize handling:** signal-based detection (SIGWINCH on POSIX) with minimum size of a TTY; no wasted resources when no resize happens; more complex, `#ifdef` per platform
    - Polling for size changes; wastes resources when no resize, and if polling misses a resize the display wraps and looks broken/buggy
    - Forcing terminal to resize on start and lock size; no reliable cross-terminal method found

- **Hangman Drawing:** will have multiple "size" drawings, which the smallest will fit in a minimum terminal, with larger sizes being available to bigger terminals; "adaptive display" for terminal size; more logic (and more complex perhaps) to be implemented, multiple drawings needed to be created (not critical, user can guess without hangman drawing, and user will have visual feedback on guess limit and count)

</details>

### External Dependencies

- "The great noun list" dictionary file (~6000 nouns) — must exist before program launch, program exits if missing. All other files are created with defaults if absent and needed.

### Program Specification (Before Writing Code)

**Input:** What information comes from outside the program?

- Files: difficulties, user, the index, dictionary, options/config, hangman drawing;
- Inside of files: difficulty options, user's stats, list of users in index, words in dictionary file, configurations chosen;
- User input: choices to the options (in menu, or other windows), username (limited, 30 users max, 5 characters longest, 1 character shortest), guess, hint request, arrow buttons, hijack CTRL+D/C
- System input: terminal size and resizing "notices", program arguments passed

**Output:** What does the program produce, display, store, or change externally?

- Files: options/config, user, the index, difficulties;
- Inside of files: difficulty options, user's stats, list of users in index, deleting users and difficulties;
- Pure display: Hangman drawing, menu, options, leaderboard stats shown on screen (hints used, guesses made, win/lose screen, etc),
- Logic based display: the words and hidden parts of the words
- Conditioned display: colored feedback on choices, different messages (like error, feedback messages, confirmation messages and so on)
- System changes: canonical or non canonical, terminal size (still undecided on this one), restoration of terminal to canonical, screen clearing, "terminal function" (arrows don't bring up previous words, they move between "options" on screen), folder structure

**Internal Data:** What data does the program calculate, track, or build for
its own execution?

- Derived: file paths (relative from executable), hangman drawing stage and display type, position of items displayed (perhaps), existing characters in word, hint limit
- Tracked: guesses made, hints used, characters revealed in words, words left to guess, characters to highlight (red green or white), won game, lost game, quit game, played game, "windows" (e.g. game window, menu window, game end window)
- Other: difficulty (and parameters), words chosen, characters to reveal on hint, file data "loading" (e.g. difficulty parameters, configurations in the option file, user's stats,)

**Decisions:** What does the program choose between or validate during
execution?

- Choices of game's state: win, lose, quit, played, limits enforcement (e.g. hints, guesses)
- Choices on user input (and its state mixed in): hints and guesses allowed, difficulty, limits, multi-word mode, guesses made (word and char), hints received and left, current username, start game, "action" (e.g. if arrow move in menu up)
- Other choices: words from dictionary (random from range/list), action on terminal size (e.g. freeze game or change drawing dimension), what "type" of display to use (drawing), if user can be created, if enough words available for start
- Validation of: user input (what characters, valid for game state), terminal size (if it's minimum size needed), guess is valid, file existence, username existence, user's exit (if played or not)
- Choices on program state: menu display, options configuration, difficulty creation, leaderboard sorting, hangman drawing dimension display, whether to choose default values, quit mid game (based on validation, either write or not the stats)
- Display state: hangman drawing stage and type

<details>
<summary>

**Algorithm:**

</summary>

What ordered steps does the program follow from start to finish?

General:

    check for files and their paths relative from executable
    check for dictionary as critical and exit if missing,
    rest create as needed

    switch terminal from canonical,
    check terminal size and wait for resize to minimum if not tty-size,
    wait for signal that it was resized
    hijack ctrl+d and ctrl+c

    ask for confirmation if things work appropriately (input method, display method)
    if not, mark things as not working, and update options/config file,
    if user runs with args store args as flags for options, skip confirmation

    check for input itself if it's valid input for the "window"
    in menu (and sub windows) - arrow keys,
    in username passing window - letters
    in game - letters and words
    in difficulty creation window - up to debate, based on my testing I will see what feels better
    most display-specific things deferred for when I can actually see the "displaying"

Menu window:

    ask for username
    check if already exists in index
    if exists - read file and load to memory
    if doesn't - create file
    display stats (maybe)
    display menu choices (start game, create difficulty, options, exit)
    display leaderboard (maybe or it might be it's own button)
    display "info windows" so the user knows what to expect
    write updates to files when the "manipulation" happens in the window's influence (difficulties created or modified under menu window)

Options:

    if user picks delete users, show nice presented window with username and ask to type username for deletion
    if user picks difficulty creation, show nice presented window with creation picking a default difficulty to start as template
    user can pick here what "defaults" he wants (hangman drawing type, input type)

Round start (as preparation and as window):

    give choices for difficulty selection and creation option
    give choice for multi word option (toggle)
    load dictionary into memory
    filter words from dictionary
    check if enough words exist after
    the program won't let the user start if there aren't enough words
    pick words count based on difficulty settings
    all words should be unique from each other
    choice to start game or exit round start window

Mid round (as presentation and logic):

    if no guesses made and quit - no tracking
    if quit (after user made guess essentially) - track played game and exit
    check if guess matches length for word, or if it is a character
    store guesses made to check against them for further guesses and validity of guess and display guesses made as feedback
    check drawing stage against wrong guesses
    check hint counts and display them (hint used number and hints on the screen)
    word count and if all words are discovered
    check if user won or lost (either guessed all right words, or failed to guess successfully in limit)

Round end (as presentation and logic):

    feedback on the round played (win or loss and message)
    display right words if lost, display the words if won
    display guesses made if lost
    stats that will get updated (and numbers)
    write updates to files (stats or any other updates)
    option to quit game or go to menu

Program end:

    update terminal to normal mode on exits

</details>

### Limitations

- ASCII only — usernames, guesses, and dictionary words do not support characters outside of ASCII
- Primary display mode requires terminal ANSI escape code support
- Ctrl+D and Ctrl+C are (planned to be) hijacked by the program

### Problems Encountered

---

### How I Solved Them

---

### Bug Scenarios Tested

---

### Self-Check

1. **Can I trace and predict what happens?**

---

2. **Can I explain why each part exists?**

---

3. **What pattern did I use? Did I see it before?**

---

4. **What might be general vs C-specific?**

---

5. **If this broke, how would I find the problem?**

---

### Transferable Knowledge

---

### Notes

<details>

<summary>

Implementation

</summary>

Parsing:

- I will have custom parsing for it, check for the label as a string, check for the colon as a character, and then read the value after the colon with what is appropriate (number or alpha)
- Edge cases handled by doing if-checks like: no colon will skip the line and use defaults, no value after colon will use the default, empty file will lead to defaults

File management:

- Index sync: if a file is deleted but still indexed in the master file, then the existence check recreates the file with empty or default values, leaderboard displaying users with 1 game played and higher
- Index sync: file exists but is not indexed — harmless orphan (maybe not visually for the user), will get reindexed when that username is entered
- If the user wants to delete users: they can do that from options
- User limit enforcement: if there are more than 30 usernames, the program will refuse to create a new username until the user deletes an existing username from the options menu

File operation:

- Dictionary is checked at launch, read before round starts
- Stats (inside the user file) are read at menu for display, written on round end to update the stats
- Difficulty is read on selection or creation of one
- Users (the index) are read on program open, written when a new user is added or deleted
- Quit mid-round will count as a total game increment if the user had at least one guess or hint use, it will add guesses registered or hints used, but it will not register a win or a loss
- Quitting from menu won't trigger any stats writing

Gameplay mechanics:

- Multi-word: one guess applies to all words
- Multi-word: all words should be unique from each other
- Multi-word: a guess in this mode will count as one right or wrong guess regardless of the word count and the instances of the letter across words
- Guess types: first type is a single letter/character checked against all words to be guessed
- Guess types: second type is the full word, checked against all words to be guessed
- Each guess type has its own counters and limits

Difficulty system:

- Word length is a range between a min and max value, both limits bounded by the shortest and longest dictionary word, for multi-word mode all words abide by this range
- Word count will be 1/1/2/2/3 across the five default difficulties, customizable up to 10 words
- Wrong letter and wrong word guesses are each limited from 1 and higher, allowed to get to very high values for the limit to be basically "infinite"
- Hinting is customizable as an "on/off" option
- The easiest difficulty intentionally has the wrong guess limits set so high that you cannot lose the game
- Word guessing is customizable "true/false"
- Word selection: zero/not enough matches for the length filter is a flag to the user, suggesting "adjust difficulty", no override

Scope boundaries:

- I thought about complex "abuse" like file tampering, but handling cases of such abuse is similar to an "anti-cheat" from my perspective, which is too much for hangman
- Complex exploitation and abuse of the program is not handled for hangman, common/simple exploitation and abuse of the program will be handled for robustness

</details>

<details>

<summary>

`#ifdef` Research notes

</summary>

1. File paths:
- I have learned that in Visual Studio (not Code) relative filepaths break easily because of how Visual Studio works, so I need to get the current path of the executable so that I can build a relative path from it, which gets rid of any issues with pathing I might have.
- Some time later, after reading this and analyzing it I understood one thing: the segment "I need to get the current path of the executable so that I can build a relative path from it" solves an issue I didn't realize where it came from or how could happen, it essentially solves an issue before I can even encounter it.
If one user runs the file from two different locations, it would generate two sets of files for each run, which is buggy behavior in my opinion, that would make the "get current path of the executable" solve that issue, I just need to figure out the implementation of it.
- I found this "The use of /proc/self/exe is non-portable and unreliable." and on the other side, I found posts talking about avoiding `argv[0]`.
The specifications and the trade-offs and everything are a bit too complex for me to understand as of right now, perhaps later.
For now I will try my luck with "/proc/self/exe" and hope that it's not gonna be one of those "it works on my machine" situations. I will need to "readlink()" the "/proc/self/exe".
- For OS X it seems I need "_NSGetExecutablePath" (I guess that's mac?), and for Windows I need "GetModuleFileName(NULL, buf, bufsize)", apparently.
At least I can try to make it work across all 3 systems? The rest I leave for implementation.

2. Terminal sizing and resizing:
- Apparently there are a lot of ways for me to go about it, depending on what I am using and what I am trying to achieve, all of them different in some considerable way (at least from what I understand) but I found one option with SIGWINCH for resizing, which is POSIX, and the Windows equivalent is ReadConsoleInput for reading the input and looking for "WINDOW_BUFFER_SIZE_EVENT" "for a modern Windows console app to detect when its output console gets resized".
- On the other side: to get terminal size, there is the "ioctl()" POSIX function, with "TIOCGWINSZ" for getting the size, and apparently "TIOCSWINSZ" for setting the size.
- The Windows counterpart apparently has the "GetConsoleScreenBufferInfo", and I need to look at srWindow, in the "CONSOLE_SCREEN_BUFFER_INFO" struct.

3. Arrow keys:
- Apparently arrow keys and other "special" keys return two keycodes for "getch()".
For normal arrow keys it returns 224 first and then the numbers for each key, for numpad apparently it returns first 0 instead of 224, and apparently the function "getch()" isn't even standardized, and it can vary from compiler to compiler and from platform to platform. This is much harder than I thought.
- While looking at the `<termios.h>` I found the following: ICANON is what I need to "set terminal to non-canonical" (therefore I need termios), took me a while to find this.
I found the library being hinted at over the internet for "direct input detection, without enter" and other nice "things" with it, but not really a lot of specific functions.
And through this library's man pages I finally understand why I need to have the "ClearInput" function I created.
- So, for me to use `ICANON` properly for "immediate input detection" I need to make use as well of VTIME and VMIN, but those are going to be things I will look up during implementation, so that I can understand how to use everything appropriately when I get to implementing that.
- For the Windows counterpart, it was a bit quicker for me (wikipedia already had the library listed, and the functions in a nice table somewhere close to the top) because I searched directly for "conio.h" in google, and I found the "_getch" function. If I use "_getche" it echoes the key, which I don't want.


I can use quite some of this knowledge for a snake game (I actually like snake games).

</details>
