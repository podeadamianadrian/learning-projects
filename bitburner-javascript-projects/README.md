# BitBurner JavaScript Projects

Automation scripts written in JavaScript for BitBurner.

## What is BitBurner

BitBurner is a programming game where you write JavaScript to automate in-game systems. I use it as a learning environment for programming—writing scripts that solve challenges, automate tasks, and interact with game mechanics. It's a game, but I treat it as a sandbox for building programming habits and thinking patterns, along with transferable knowledge.

For more information about the game itself, see the [BitBurner repository](https://github.com/bitburner-official/bitburner-src).

## Running Scripts

Scripts run inside the BitBurner game. To run any script from this folder:

1. Access the game through [the browser version](https://bitburner-official.github.io/) or on [Steam](https://store.steampowered.com/app/1812820/Bitburner/)
2. In the game terminal, create a new file: `nano filename.js`
3. Paste the code into the editor and save
4. Run with: `run filename.js`
5. Optional addition of `--tail` to see the automatic log output and/or anything printed in the window that will pop up when running the command: `run filename.js --tail`

## Structure

Scripts are organized by game system. Related scripts that work together or build on each other are kept in the same folder.

Each folder contains:
- Source code (`.js` files)
- A reflection document with notes on the development process

## Game Terms

Some terms that appear in the scripts and documentation:

- **Hacknet** — A system of nodes that passively generate in-game money. Scripts can automate purchasing and upgrading these nodes.
- **Servers** — In-game machines you can hack, grow, or weaken to extract money. Each server has security levels and money thresholds.
- **HGW (Hack/Grow/Weaken)** — The three core operations for extracting money from servers. Hack takes money, Grow increases available money, Weaken reduces security.
- **Nuking** — Gaining root access to a server by opening required ports and running NUKE.exe.
- **RAM** — Memory available to run scripts. Each script costs RAM; managing RAM allocation is part of automation.

For deeper explanations of game mechanics, and coverage of all the terms that appear in the scripts and documentation, see the [BitBurner documentation](https://github.com/bitburner-official/bitburner-src/blob/stable/markdown/bitburner.ns.md).

## Reflection Documents

Each project has a reflection document where I write about what I was trying to do, problems encountered, and how I solved them. For more detail on what these contain, see the [root README](../README.md#reflection-documents).
