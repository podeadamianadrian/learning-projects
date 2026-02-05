# Servers Scanner - Reflection

**Note**: It WILL double as a filter, but I will keep it part of scanning script.

## Scanner

### Requirement

**"Discover all servers in the network. Output list of all server hostnames."**

### Specification (Before Writing Code)

**Input:** What information does this function need?
    The first server to scan from, which is "home".

**Output:** What does it create or return?
    It creates an array full of servers that I will use later, hopefully I will return it properly and use the return value properly in the next function.

**Decisions:** What choices does it make?
    I don't think it makes any decision.

**Algorithm:** What's the step-by-step logic?

    initialize array with only home inside
    for loop of the first array
        for loop of a second array based on the neighbours from the server in the first array
            add server if not on list
    shift the first element of the array

---

### Problems Encountered

1. I had a reference error because I didn't define "server" variable.
2. Reading "ns.scan" (the "scan" specifically), it gives me a type error, that it cannot read properties of undefined.
3. While trying to figure out what I have done wrong that it couldn't read scan, I eneded up crashing the script, because I forgot to add an if statement, to check if the server already exists, creating an infinite loop.

### How I Solved Them

1. I did "let server" in the for loop, I don't know how I didn't realize I forgot to do that.
2. Moving the script inside main fixes the issue, but I want to have it in a separate function. So something with the "/** @param {NS} ns */" that is supposed to exist at the beginning of the functions doesn't work properly to define the functions and whatnot. Lemme figure it out better. For it to actually work, I did pass "ns" as an argument when creating the function (so that ns api is read), but because I wouldn't add the "ns argument" when I am calling it, it wouldn't work. I didn't think it is so needed. So, when creating a function that makes use of the ns api, I need to pass it in the definition and in the call as well.
3. Added an if statement. If the neighbor is not included, add. That handles the case where it is, in which case it continues.

---

### Self-Check

1. **Can I trace and predict what happens?**
    Initialize array, for loop, where I define server variable of server_list array, then another for loop where I define neighbor of ns.scan(server) return value (which is an array), if the neighbor is not included, push it in the array.
2. **Can I explain why each part exists?**
    The first loop is there so that I can loop the array I initialize, the second loop is there so it checks the neighbors of the current server from the array, the if statement is there to add each new neighbor in the first array.
3. **What pattern did I use? Did I see it before?**
    I believe this is called a "breadth first search"? It will be used in many places (since I have heard of it, many people use it for different purposes, which means this is a pattern I will use myself repeatedly).
4. **What might be general vs BitBurner-specific?**
   The ns.scan and ns api is bitburner specific, the "for-of" loop chain I created is something general.
5. **If this broke, how would I find the problem?**
    I think this would break only if the "ns.scan" function gets changed, in which case I would read the docs. Otherwise, if it breaks because of me, I would read the errors to try and figure out what I have done wrong, and if that doesn't guide me enough, I would "print debug".

---

### Transferable Knowledge

    The breadth first search.

---

### Notes

    Nothing noteworthy, I think?

---

## Filter

### Requirement

**"Filter lists and create multiple lists:**
**1. Detailed list of all servers: server name, all hacking-relevant info (max money, min security, hack level required, ports required, root status)."**
**2. List of all "hackable servers": max money > 0.**
**3. List of all "sharable servers": ram > 0.**
**4. List of all "other servers": catch any servers that don't fit the other two categories (might be useful).**

### Specification (Before Writing Code)

**Input:** What information does this function need?
    The return value of the scanner function, which is the array of servers.

**Output:** What does it create or return?
    It creates 4 lists. The first list is detailed list of all servers, second list of just servers I can hack, third of just servers I can share, fourth of the "other ones".

**Decisions:** What choices does it make?
    What servers go in which lists. One server will be able to go into two lists, besides the default one, based on criteria it meets.

**Algorithm:** What's the step-by-step logic?
    initialize empty arrays of detailed servers, hackable servers, sharable servers, and other servers
    for server of list
        get all hacking-relevant details
        if money > 0 add to hacking list
        if ram > 0 add to share list
        if money = 0 and ram = 0 add to other list
    create appropriate file for each list

---

### Problems Encountered

None

### How I Solved Them

---

### Self-Check

1. **Can I trace and predict what happens?**
I initialize values, for element of array I initialize a server variable with multiple properties for later usage, then push into the detailed list (the general with all the servers) and then in the fitting lists, after which I write each list to a file.
2. **Can I explain why each part exists?**
The initialization is there so that I know have the arrays "ready" from the beginning, then the loop is so I can go through it, the pushing into lists with writing is so that I have the details/lists stored. I chose if statements because I want to keep the option of having one server in 3 lists (since the lists will have different purposes). The detailed list exists so I have all the servers condensed into one file.
3. **What pattern did I use? Did I see it before?**
   Simple for element of array loop, and conditional ordering to list.
4. **What might be general vs BitBurner-specific?**
If statements and for loops are general, the api calls are bitburner. I don't know what else I can mention from here.
5. **If this broke, how would I find the problem?**
I am decently sure that it won't break in a way that will kill the script or freeze the game (tested it once), ns.write will create the parent folder if it doesn't exist, most of the error handling is done by the game, and if a server "undefined" gets passed through (because of some mistake I didn't pick up on), it won't kill the script, it will just add "corrupt data" (not really but I'll leave it at that) in the list.

---

### Transferable Knowledge

    Breadth-first-search (I first learned of it from someone else a while ago, with that particular example). Taking "simple string" and making it an "element with properties in an array".

---

### Notes

No notes for now.

---
