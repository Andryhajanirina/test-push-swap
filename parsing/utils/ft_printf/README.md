*This project has been created as part of the 42 curriculum by mamiandr.*

---

# Description
The **ft_printf** project is a fundamental challenge in the 42 curriculum. The goal is to mimic the behavior of the standard C library function `printf`. This project teaches the use of **variadic functions** in C and provides a deeper understanding of how data types are formatted and printed to the standard output.


# Instructions

#### 1. Compilation
The project includes a `Makefile` that compiles the source files into a library named `libftprintf.a`.
```bash
make
```

#### 2. UsageTo use the function in your code, include the header:
```
C
```
```C
#include "ft_printf.h"
```

Then, compile your program with the library:

```
Bash
```
```Bash
cc main.c libftprintf.a
```
#### 3. Clean-up
* `make clean`: Removes object files.
* `make fclean`: Removes object files and the `.a` library.
* `make re`: Recompiles the entire project.

# Resources

* Variadic Arguments: Understanding <stdarg.h> and the macros `va_start`, `va_arg`, `va_copy`, and `va_end`.
* C Type Conversion: Deep dive into hexadecimals, pointers, and unsigned integers.
* Use of IA: An AI (Gemini 3 Flash) was utilized to structure and draft this README file, ensuring clear documentation and a professional layout.


# A detailed explanation

The implementation of `ft_printf` handles the following conversions:

| Format | Description |
| -------|-------------|
| %c | Prints a single character. |
| %s | Prints a string.|
| %p | Prints a void * pointer argument in hexadecimal format. |
| %d / %i | Prints a decimal (base 10) number. |
| %u | Prints an unsigned decimal (base 10) number.
|%x / %X | Prints a number in hexadecimal (base 16) lowercase or uppercase. |
| %% | Prints a percent sign. |

---
The core logic involves parsing the format string and, upon encountering a `%`, calling a dispatcher that identifies the type and processes the `va_list` accordingly. The function returns the total number of characters printed, exactly like the original.
