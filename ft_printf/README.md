*This project has been created as part of the 42 curriculum by zguney.*

# ft_printf

## Description
`ft_printf` is a project at 42 where we recode the famous `printf()` function from the standard C library (`libc`).

The main goal is to learn how to use variadic functions in C using `<stdarg.h>` (`va_start`, `va_arg`, `va_end`). The function takes a format string and prints text, numbers, and memory addresses to standard output. It also counts and returns the total number of printed characters.

This version does not use buffer management and handles the following conversions:
- `%c`: Prints a single character.
- `%s`: Prints a string (or `(null)` if the string pointer is NULL).
- `%p`: Prints a memory address (`void *`) in lowercase hexadecimal, starting with `0x` (or `(nil)` if NULL).
- `%d` / `%i`: Prints a signed decimal number (base 10).
- `%u`: Prints an unsigned decimal number (base 10).
- `%x`: Prints an unsigned number in lowercase hexadecimal (base 16).
- `%X`: Prints an unsigned number in uppercase hexadecimal (base 16).
- `%%`: Prints a single percent sign.

---

## Instructions

The project uses a `Makefile` with the required flags (`-Wall -Wextra -Werror`) and the `cc` compiler.

To compile the library, open your terminal and run:
```bash
make

```

This command compiles all `.c` files and creates the library file `libftprintf.a` at the root of the project using the `ar` tool.


* `make` or `make all`: Compiles the source files and builds `libftprintf.a`.
* `make clean`: Deletes all temporary object files (`.o`).
* `make fclean`: Deletes all object files (`.o`) and the library file `libftprintf.a`.
* `make re`: Deletes everything and recompiles from the start.



---

## Algorithm and Data Structure Justification

### Data Structure

This project does not need complex data structures like linked lists or trees. We only use simple C types:

* `va_list`: A special pointer type provided by `<stdarg.h>`. It tracks the position of extra arguments in the function call stack so we can read them one by one.
* `unsigned long`: Used for memory addresses (`%p`) and large numbers. In 64-bit systems, a pointer address has 8 bytes (64 bits). Using `unsigned long` prevents numbers from overflowing or getting cut off.

### Algorithm

1. **String Parsing (Dispatcher):**
The function reads the format string character by character.
* If it sees a normal character, it prints it directly using `write(1, ...)`.
* If it sees a `%`, it reads the next character and calls a helper function (`ft_check`) to decide which type to print (`c`, `s`, `d`, `x`, `p`, etc.).


2. **Recursive Base Conversion:**
For numbers in base 10 (`%d`, `%i`, `%u`) and base 16 (`%x`, `%X`, `%p`), we use recursion. The function divides the number by 10 or 16 until it becomes smaller than the base, and then prints the digits in the correct order using a lookup string (like `"0123456789abcdef"`). This approach is simple, requires very few lines of code, and does not need any heap memory allocation (`malloc`).
3. **Character Counting:**
Every print function returns the number of characters it wrote to the screen. `ft_printf` adds up all these return values and returns the final total, just like the real `printf()`.

---

## Resources

- Manual Pages
- 42 Libft subject
- 42 The Norm

### AI Usage

AI was used as an interactive learning guide to help me understand how variadic functions work under the hood and how va_start, va_arg, and va_end navigate parameters. Through practical examples, we explored how memory addresses are represented and how recursive division converts numbers into decimal and hexadecimal formats. I wrote and adapted the code myself, using AI to discuss the logic, verify that the project strictly follows 42 Norm rules, and help draft this README documentation.