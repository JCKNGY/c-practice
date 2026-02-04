# C Practice

Small daily C programs to improve my systems programming skills and build real projects.

This repository focuses on **learning by building**, not tutorials.  
Every day I write code, compile manually, and push progress to GitHub.


## Goals

- Practice C fundamentals (pointers, memory, structs, file I/O)
- Build small CLI tools
- Get comfortable with Linux development
- Improve problem-solving skills
- Stay consistent with daily commits
- Reduce reliance on AI


## How to Build & Run

Compile:
gcc file.c -o program

Run:
./program

Example:
gcc todo.c -o todo
./todo list


## Projects

### todo.c
A simple command-line todo app with file persistence.

Features:
- add tasks
- mark tasks complete
- list tasks
- saves data to tasks.txt

Example:
./todo add "Study pointers"
./todo list
./todo done 1


## Folder Structure

c-practice/
  todo.c
  tasks.txt
  README.md


## Daily Workflow

- git add .
- git commit -m "describe changes"
- git push
