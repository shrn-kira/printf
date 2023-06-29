This is the readme file for the printf project.

REQUIREMENTS

GENERAL

*Allowed editors: vi, vim, emacs
*All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
*All your files should end with a new line
*A README.md file, at the root of the folder of the project is mandatory
*Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
*You are not allowed to use global variables
*No more than 5 functions per file
*In the following examples, the main.c files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own main.c files at compilation. Our main.c files might be different from the one shown in the examples
*The prototypes of all your functions should be included in your header file called main.h
*Don’t forget to push your header file
*All your header files should be include guarded
*Note that we will not provide the _putchar function for this project

question #0
Write a function that produces output according to a format.

question #1
Handle the following conversion specifiers: d , i

question #2
Handle the following custom conversion specifiers:
b: the unsigned int argument is converted to binary

question #3
Handle the following conversion specifiers: u, o. x, X

question #4
Use a local buffer of 1024 chars in order to call write as little as possible.

question #5
Handle the following custom conversion specifier:
S : prints the string.
Non printable characters (0 < ASCII value < 32 or >= 127) are printed this way: \x, followed by the ASCII code value in hexadecimal (upper case - always 2 characters)

question #6
Handle the following conversion specifier: p.

question #7
Handle the following flag characters for non-custom conversion specifiers: +, space, #

question #8
Handle the following length modifiers for non-custom conversion specifiers: l, h
Conversion specifiers to handle: d, i, u, o, x, X

question #9
Handle the field width for non-custom conversion specifiers

question #10
Handle the precision for non-custom conversion specifiers.

question #11
Handle the 0 flag character for non-custom conversion specifiers.

question #12
Handle the - flag character for non-custom conversion specifiers.

question #13
Handle the following custom conversion specifier:
r : prints the reversed string

question #14
Handle the following custom conversion specifier:
R: prints the rot13'ed string

question #15
All the above options work well together.
