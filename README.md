*This project has been created as part of the 42 curriculum by zguney.*

## Description

This project is a custom C library (`libft.a`) built as part of the 42 curriculum. The goal is to reimplement a set of libc functions and additional helpers (strings, memory, conversion, file-descriptor output, and linked lists) so they can be reused in later 42 projects.

The library covers:
- libc-style functions (`ft_strlen`, `ft_memcpy`, `ft_atoi`, ...)
- additional helpers (`ft_split`, `ft_itoa`, `ft_strtrim`, ...)
- linked list utilities (`ft_lstnew`, `ft_lstmap`, ...)

## Instructions

Compile the library from the repository root:

```
make
```

This produces `libft.a` with `cc -Wall -Wextra -Werror`.

Useful Makefile rules:
- `make` / `make all` — build `libft.a`
- `make clean` — remove object files
- `make fclean` — remove object files and `libft.a`
- `make re` — rebuild from scratch

To use the library in a program:

```
cc -Wall -Wextra -Werror your_file.c -L. -lft
```

Include the header with `#include "libft.h"`.

## Resources

- man pages for the original libc functions (`man 3 strlen`, `man 3 strlcpy`, ...)
- 42 Libft subject
- 42 The Norm
- [C library documentation](https://man7.org/linux/man-pages/)

**AI usage:** AI was used to better understand certain concepts along the way, such as linked lists and memory management. Once the functions were already implemented, it was also used to double-check the code against the 42 Norm, clarify a few points the subject PDF didn't fully specify, and occasionally help figure out compile errors. AI was not involved in writing any of the function implementations.

## Library overview

`libft.a` groups three parts:

1. **Libc functions** — same prototypes and behavior as the originals, with an `ft_` prefix. Character classifiers return `1` or `0`. `calloc` / `strdup` use `malloc`.
2. **Additional functions** — allocate and return new strings (`ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi`) and write helpers (`ft_put*_fd`).
3. **Linked lists** — `t_list` nodes with `content` and `next`; create, add, size, last, delete, iterate, and map.
