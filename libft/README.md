*This project has been created as part of the 42 curriculum by andry-ha.*

# Description
Libft is a project at the 42 school whose goal is to create a personal C library.
This library includes standard libc functions, as well as additional utility functions intended for reuse in future projects.

The project helps strengthen understanding of the C language, memory management, and adherence to the 42 standard.

# Instructions
## 1. Installation
First, clone the project repository
```Shell
git@vogsphere.42antananarivo.mg:vogsphere/intra-uuid-[intra-uuid]-[login]
cd libft
```

## 2. Compilation
To compile the libft library, use the following command:
```shell
make
```
=> This command generates the file <font color="green">**libft.a**</font>.
## 3. Cleanup
To remove object files <font color="green">**(.o)**</font> created during compilation
```shell
make clean
```
To delete the object files and the compiled library:
```shell
make fclean
```
To completely recompile the library:
```shell
make re
```
## 4. Use
To use the library in your project, you must first have the libft.a library available, as well as its corresponding libft.h file.
```css
project/
├── libft.a
├── libft.h
├── main.c
└── Makefile
```

Include the header and link the library during compilation:
```c
#include "libft.h"
```
This is an example of compilation with a <font color="green">**main.c**</font> program:
```shell
gcc -Wextra -Werror -Wall main.c libft.a
```
# Resources
The following resources were used for this project:

- Official documentation (man pages).
- Educational YouTube channels, including **[Algomius](https://www.youtube.com/@algomius), [Neso Academy](https://www.youtube.com/@nesoacademy), and [Codeur Sage](https://www.youtube.com/watch?v=7YGFdkd2-3M)**, to deepen understanding of certain concepts.
- <font color="green">**42 Coding Standard (fr.norm.pdf)**</font>, used to ensure compliance with the project's coding norms.
- ChatGPT, used exclusively as a learning and comprehension tool, not for generating code.

# Library Detailed Description
<details>
<summary>1️⃣ Libc Functions</summary>

| Function     | Description                                                                                            |
| ------------ | ------------------------------------------------------------------------------------------------------ |
| `ft_strlen`  | Returns the length of a string (number of characters before `\0`).                                     |
| `ft_strlcpy` | Copies a string to a destination buffer, ensuring null-termination and not exceeding size.             |
| `ft_strlcat` | Appends a string to the end of a destination buffer, ensuring null-termination and not exceeding size. |
| `ft_strchr`  | Returns a pointer to the first occurrence of a character in a string.                                  |
| `ft_strrchr` | Returns a pointer to the last occurrence of a character in a string.                                   |
| `ft_strncmp` | Compares up to n characters of two strings.                                                            |
| `ft_atoi`    | Converts a string of digits into an integer.                                                           |
| `ft_isalpha` | Checks if a character is an alphabetic letter.                                                         |
| `ft_isdigit` | Checks if a character is a decimal digit.                                                              |
| `ft_isalnum` | Checks if a character is alphanumeric (letter or digit).                                               |
| `ft_isascii` | Checks if a character is an ASCII character (0–127).                                                   |
| `ft_isprint` | Checks if a character is printable, including space.                                                   |
| `ft_toupper` | Converts a lowercase letter to uppercase.                                                              |
| `ft_tolower` | Converts an uppercase letter to lowercase.                                                             |
| `ft_memset`  | Fills a block of memory with a specific byte value.                                                    |
| `ft_bzero`   | Sets a block of memory to zero.                                                                        |
| `ft_memcpy`  | Copies a block of memory from source to destination.                                                   |
| `ft_memmove` | Copies memory safely, even if source and destination overlap.                                          |
| `ft_memchr`  | Searches for a byte in a block of memory.                                                              |
| `ft_memcmp`  | Compares two blocks of memory.                                                                         |
| `ft_calloc`  | Allocates memory for an array of elements and initializes it to zero.                                  |
| `ft_strdup`  | Duplicates a string by allocating new memory for it.                                                   |

</details>

<details>
<summary>2️⃣ Additional Functions</summary>

| Function        | Description                                                              |
| --------------- | ------------------------------------------------------------------------ |
| `ft_substr`     | Returns a substring from a string, given a start index and length.       |
| `ft_strjoin`    | Concatenates two strings into a newly allocated string.                  |
| `ft_strtrim`    | Removes specified characters from the start and end of a string.         |
| `ft_split`      | Splits a string into an array of strings using a delimiter character.    |
| `ft_itoa`       | Converts an integer to a null-terminated string.                         |
| `ft_strmapi`    | Applies a function to each character of a string to create a new string. |
| `ft_putchar_fd` | Writes a character to a given file descriptor.                           |
| `ft_putstr_fd`  | Writes a string to a given file descriptor.                              |
| `ft_putendl_fd` | Writes a string followed by a newline to a file descriptor.              |
| `ft_putnbr_fd`  | Writes an integer as characters to a given file descriptor.              |
</details>

<details>
<summary>3️⃣ Linked List Functions</summary>

| Function          | Description                                                                    |
| ----------------- | ------------------------------------------------------------------------------ |
| `ft_lstnew`       | Creates a new list element with the given content.                             |
| `ft_lstadd_front` | Adds an element at the beginning of the list.                                  |
| `ft_lstsize`      | Returns the number of elements in a list.                                      |
| `ft_lstlast`      | Returns the last element of a list.                                            |
| `ft_lstadd_back`  | Adds an element at the end of a list.                                          |
| `ft_lstdelone`    | Deletes a single element using a provided delete function.                     |
| `ft_lstclear`     | Deletes and frees all elements of a list.                                      |
| `ft_lstiter`      | Applies a function to each element of a list.                                  |
| `ft_lstmap`       | Creates a new list by applying a function to each element of an existing list. |
</details>
