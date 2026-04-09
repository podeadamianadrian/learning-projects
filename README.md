# Learning projects

This is a collection of projects as proof of work and the work behind the work. They tackle the programming/development side of things within my currently identified interests and activities.

## About

This repo "displays" my work as a career switcher. The work here is what I can come up with and do at the time of writing each project, representing my progress in the "learning programming" path, sometimes with fast progress and sometimes with slower progress because I am self-teaching with no CS degree, no courses, relying instead on free resources on the internet and whatever I can get my hands on to learn.

The stuff I build in this repo is there to further my learning by teaching me programming foundations that aren't tied to one language and by teaching me git and version control practices.

I do my best when building a project in this repo whether it is a simple input-calculation-output loop or a game or complex clones of well-known tools, and the languages/"technologies" used in the repo are picked in a "this seems like a good starting point" manner.

### Approach

I write code with portability in mind, avoiding platform-specific code as much as I can (since I cannot test yet on all environments), so that the code hopefully works on most contemporary machines. I am aware that portability is important in a lot of industries, and I want to build that habit early.

Right now, all of my code is built and tested on Linux. Lately I have been trying to set up a Windows VM to start testing on other platforms as well (macOS is quite tricky), so cross-platform verification is coming soon.

In a similar vein, I want to become competent at "optimizing" my code, so that I don't bloat systems, I don't waste resources doing a simple thing, and I stay mindful of performance.

## Overview

The repository is organized by language and technology; I am attempting self-descriptive naming. Folders listed here contain either general information about the projects in their subfolders (first level), or projects themselves (second level). Every folder contains a README; every project folder contains an additional reflection file.
The folder structure will grow with me.

- [c-projects/](c-projects/) - standard C projects
    - [math-operations/](c-projects/math-operations/) - a group of projects in the same file doing predetermined calculations
    - [utilities/](c-projects/utilities/) - utility functions extracted or planned for reuse
    - [hangman/](c-projects/games/terminal-based-games/hangman/) - Word guessing game with user profiles, difficulty customization, persistent stats, and adaptive terminal display
- [bitburner-javascript-projects/](bitburner-javascript-projects/) - JavaScript projects written inside BitBurner game environment
    - [servers/](bitburner-javascript-projects/servers/) - game-related automation scripts to handle in-game server interactions

## Motivation

There are multiple sides to why the repo exists; the simplest is: I need something to show for a tech job, since I have no "formal education" for tech.
"I am learning to program" means nothing without proof, so this repo is the proof.

The more complex side is that I want to be able to build things, whatever those things end up being, and if people end up liking them, using them, or even want to help the "development" (of the program or the programmer) then that's even better.

A lot of the projects that I end up creating are not "following a niche", because I don't yet have enough knowledge to go towards a niche, they are instead just things I built. To show how wide my interest actually is, and that I haven't chosen a niche yet, here are some current domains of interest:

- system administration and/or operations, infrastructure, DevOps
- cybersecurity, networking, embedded systems
- game development, graphics programming
- automation, desktop applications

Some of them are similar to each other, others are very different; the point is: I have a wide interest in tech by itself, and that is going to push me further into learning. I am here for the "journey" not just for the "destination".

## Reflection documents

Inside every project there are reflection documents. Their purpose: to make me learn more intentionally by making me focus on more than just the code, and reflect on my learning and what I have done.

They cover: what I was trying to do, problems that I ran into, how I solved them (and if I solved them), what I learned during the project, how I've gone through the project, and much more.

They are not tutorials, polished write-ups, or documents explaining my code in detail — they are thoughts, observations, and ideas that show what I learned and the process I have gone through. I use the term "thoughts" because that's essentially what lies in there: the thinking that I was able to capture while writing the code. **Keep this information in mind when opening any of the documents**.

## Future

Now to answer the question "Where am I headed with this?": I don't know.

I have a long-standing interest in tech, and recently I found the courage to start tackling this domain. To my surprise, it wasn't actually as "scary" as I initially thought.

The near-future goal is for me to work in the tech domain; the far-future goal is not so clear: currently I am trying to learn about the field as a whole, more than a specific language. I want to say "I can make these things", not "I know these languages", and for that I need to set foundations somehow, and if I set them the right way (which I hope I do), I will have an easier time learning other things in the future.

For now I am going for multiple things:
- Programming in C because I have read that it is an "unforgiving" language. It forces the person at the keyboard to be careful, responsible, and intentional during development, because C assumes the developer knows what they are doing; so I thought it's a good language to build foundations on.
- Configuring a rented VPS for remote access through a self-configured WireGuard VPN that connects machines to and from my personal machine, as I have had times when I was away from my machine and I wanted to work on code or other things on my machine. The VPS is undocumented in this repo as I am wary of the possibility of me documenting the wrong things and "self-sabotaging" security somehow.
- I have set up a VM with GPU passthrough, for personal reasons and as a learning exercise. It runs Windows 10, and once I learn more about the Windows environment for development I will start testing programs on Windows for compatibility.

*I have the idea that this is just the beginning as I want to eventually self-host a website (if that is actually possible as I hope it is — I am expecting difficulties with HTTP/S configuration, possible certificates, and the infrastructure of the server itself for the purpose of self-hosting a website), a personal email service, and perhaps many other things.*

The repo is continuously growing, along with knowledge outside of the repo, with whatever knowledge I might gain in the tech field. So this might be a completely different repo in 3 months, or if I find a niche by then, it will just be more focused in a specific direction.
