Project 1: Tokenizer
====================
# Description
This demo code builds tokenizer that takes strings and splits them into
space-seperated tokens.

# Anticipated Learning Outcomes
Using knowledge from previous projects.
- Learning how use declaration & definition of functions and various intger
types.
- Memory management with malloc()
- Importance of compilation and role of include/header files. 

Using new methods and techniques such as:
- Tokenizing a string using space
- Memory allocation for tokens.
- Handling non-space characters.

# Files

- tester.c : Main, tests using set inputs
- tokenizer.h :Header file containing functions of tokenizer.c
- tokenizer.c: Splits given string into tokens
- history.h : Header file contating functions of history.c
- history.c: History of stored tokenized string

You can compile this program using the command:
    $ cc -03 -c tester.c
    $ cc -03 -c tokenizer.c
    $ cc -03 -c history.c
    $ cc -g -03 tokenizer uimain.o tokenizer.o history.o

-You will need to recompile any .c file that has been modified

To compile all files use:
   $ make

The following command runs the program:
    $ ./project1

## Project Structure

- **`src` directory**: Contains the source code.
  - **`tokenizer.h`**: Header file for tokenizer functions.
  - **`history.h`**: Header file for history functions.
  - **`Makefile`**: Builds the project, with a clean target to remove
      generated files.
  - **`README.md`**: This file.

## Learning Outcomes

By completing this lab, you will:
- Use command-line tools for program development (`cp`, `mv`, `rm`, `mkdir`,
  `cd`, `emacs`, `cc`, `make`, `git`).
- Develop and debug C programs involving pointer arithmetic, dynamic memory
  allocation (`malloc`, `calloc`, `free`), multiple source files, and linked
  list data structures.
- Design a small, understandable C program.

## Milestones

### A: Building a Simple UI
- Create a basic user interface (UI) that echoes the input.



### B: Working with Strings & Memory Allocation
Define several functions in `tokenizer.h` to manipulate strings:

1. `int space_char(char c);`
2. `int non_space_char(char c);`
3. `char *token_start(char *s);`
4. `char *token_terminator(char *token);`
5. `int count_tokens(char *s);`
6. `char *copy_str(char *inStr, short len);`

Make sure to read the detailed descriptions in `tokenizer.h`.

### C: Adding Tokens

Define the following functions to tokenize a string:
1. `char **tokenize(char *s);`
2. `void print_tokens(char**);`
3. `void free_tokens(char**);`

The `tokenize` function should return an array of tokens. You must first
calculate how many tokens there are before allocating memory for the array.

### D: Maintaining History

Create a history component using a linked list. Each node should contain:

- An ID (based on its position in the list),
- The user-entered string,
- A pointer to the next node.

Define functions in `history.h` and implement them n `history.c` to manage
the history of user inputs. Users should be able to:
- View the history of commands.
- Recall a command by typing `!<ID>` (e.g., `!3`).

## Conclusion

After completing this project, you will have built a basic tokenizer with
history tracking functionality. Make sure to test the tokenizer, history
features, and overall interface thoroughly.


## Requirements

- All `.c` and `.h` source files.
- A `Makefile` with targets for building and cleaning the project.
- A README documenting any important aspects of your program.



This file is written in the refreshingly simple `markdown` text
formatting language.

To learn about text formatting using markdown, we encourage you to examine 
 - [../README.md](../README.md)
 - the online [Markdown Guide](https://www.markdownguide.org/).
