# 0x16. C - Simple Shell

# Description

Learning Objectives
* Who designed and implemented the original Unix operating system
* Who wrote the first version of the UNIX shell
* Who invented the B programming language (the direct predecessor to the C programming language)
* How does a shell work
* What is a pid and a ppid
* How to manipulate the environment of the current process
* What is the difference between a function and a system call
* How to create processes
* What are the three prototypes of main
* How does the shell use the PATH to find the programs
* How to execute another program with the execve system call
* How to suspend the execution of a process until one of its children terminates
* What is EOF / "end-of-file"?

# Environment

Simple shell was built on Ubuntu LTS 14.04, and compiled with gcc 4.8.

#Installation

Clone or download this repo and run.

```bash
git clone https://github.com/Jdpa357/simple_shell.git
cd simple_shell
gcc -Wall -Werror -pedantic *.c -o hsh
./hsh
```
# About:

The **Shell** is a command interpretor in an operating system such as **Unix** or **GNU/Linux**, it is a program that executes other programs. It provides a computer user an interface to the UNIX/GNU Linux system so that the user can run different commands or utilities/tools with some input data.
The shell is both an interactive command language and a script language, and is used by the operating system to control the execution of the system using shell scripts, It was first conceived by Ken Thompson in 1971.

## Authors
* **Juan Portilla** - [jdpa352](https://github.com/Jdpa357)
* **Jose Saldarriaga** - [asoka904](https://github.com/asoka904)