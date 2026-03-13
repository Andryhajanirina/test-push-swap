*This project has been created as part of the 42 curriculum by mamiandr*

## Description
<hr/>
This project was undertaken with the aim of creating a standard C library from scratch. This library will be converted into a *.a archive file which will be used throughout the course.

It includes basic functions like *ft_strlen*, as well as memory manipulation functions like *ft_calloc* and *ft_strdup*. But that's not all; the library also handles basic string manipulation, and finally, advanced list manipulation.

## Instructions
<hr/>
We have a make file at our disposal which allows us to compile each file automatically in one go.

**compilation** :
> First, to compile, you run the `make` command in the terminal and that's all.

**clean object files** :
> To delete the ***.o** files, nothing could be easier; you simply need to enter the command `make clean`.

**clean all compilation files** :
> And if you feel like doing a deep clean, we also have the `make fclean` command available.


## Resources
<hr/>
The resources used were primarily the Linux manual page, but also the [KooR.fr](https://koor.fr/) website, appreciated for its translation of the manual page into French as well as its suggestions for using various functions that were previously unknown to us.And also [youtube](https://www.youtube.com/) for tutorials.


## A detailed description of the library
<hr/>

#### type of variable
*`ft_isalpha`: This function tests whether a variable of type int is an alphabet character.
*`ft_isdigit`: This function tests whether a variable is a number.
*`ft_isalnum`: Tests whether a variable is an alphabet character or a number.
*`ft_isascii`: If the variable is ASCII, the function returns 1; otherwise, it returns 0.
*`ft_isprint`: tests whether it is a printable character

#### memory function :
*`ft_memset`: function  fills  the  first  n  bytes of the memory area pointed to by s with the constant byte c
*`ft_bzero`: function  erases  the  data  in the n bytes of the memory starting at the location pointed to by s, by writing zeros (bytes  con‐ taining '\0') to that area
*`ft_memcpy`: function  that copies  n bytes from memory area src to memory area dest.  The memory areas must not overlap.  Use memmove(3)  if  the memory areas do overlap.
*`ft_memmove`: copies n bytes from memory area src to memory area dest.  The memory areas may overlap: copying takes place as though the  bytes in src are first copied into a temporary array that does not overlap src or dest, and the bytes are then copied from  the  temporary array to dest.
*`ft_memchr`: scans  the  initial n bytes of the memory area pointed to by s for the first instance of c.  Both c and the  bytes  of the memory area pointed to by s are interpreted as unsigned char.
*`ft_memcmp`: function compares the first n bytes (each interpreted as unsigned char) of the memory areas s1 and s2.
*`ft_calloc`: function allocates size bytes and returns a pointer to the allocated  memory.   The memory is not initialized.  If size is 0, then malloc() returns either NULL, or a unique pointer value that can  later be successfully passed to free().
*`ft_strdup`: function returns a pointer to a new string which is a duplicate of the string s.  Memory for the new string  is  obtained  with malloc(3), and can be freed with free(3).

#### string function :
*`ft_strlen`: The strlen() function calculates the length of the string pointed to by s, excluding the terminating null byte ('\0').
*`ft_strlcpy`: string copying
*`ft_strlcat`: string concatenation
*`ft_toupper`: These functions convert lowercase letters to uppercase, and vice versa.
*`ft_tolower`: These functions convert lowercase letters to uppercase, and vice versa.
*`ft_strchr`: The  strchr() function returns a pointer to the first occurrence of the character c in the string s.
*`ft_strrchr`: function returns a pointer to the last occurrence of  the character c in the string s.
*`ft_strncmp`: This function compares two strings and determines if the first is less than, equal to, or greater than the second. The comparison is performed lexicographically (and therefore takes into account the ASCII values ​​of the characters being compared). However, the comparison will be limited to the first few characters.
*`ft_strnstr`: function locates the first occurrence of the null-terminated string little in the string big, where not more than len characters are searched.  Characters that appear after a ‘\0’ character are not searched.  Since the strnstr() function is a FreeBSD specific API, it should only be used when portability is not a concern.
*`ft_atoi`: The  atoi() function converts the initial portion of the string pointed to by nptr to int.
*`ft_substr`: The SUBSTR function returns a substring of a string.
*`ft_strjoin`: join 2 string
*`ft_strtrim`: The STRTRIM function removes leading and/or trailing blank from the input String.
*`ft_split`: The STRSPLIT function splits its input String argument into separate substrings, according to the specified delimiter or regular expression. By default, an array of the position of the substrings is returned. The EXTRACT keyword can be used to cause STRSPLIT to return an array containing the substrings.
*`ft_itoa`: Converting an integer to a string
*`ft_strmapi`: Apply the function 'f' to each characters in the string 's' to create a new string (with malloc(3)) resulting of the successive applications of 'f'.
*`ft_striteri`: Apply the function 'f' to each characters of the string 's', passing its index as a first parameter. Each character is transmitted by address to 'f' so it can be modified if necessary.

#### print function :
*`ft_putchar_fd`: The ft_putchar_fd() function writes the character c on the file descriptor fd.
*`ft_putstr_fd`: Write the string s on the file descriptor fd.
*`ft_putendl_fd`: ft_putendl_fd() writes the string s, followed by a newline, on the file descriptor
*`ft_putnbr_fd`: ft_putnbr_fd() writes the int n on the file descriptor fd

#### chained list function :
*`ft_lstnew`: create new chained list
*`ft_lstadd_front`: Add the 'new' element at the front of the list
*`ft_lstsize`: return the size of an chained list
*`ft_lstlast`: return the last element of chained list
*`ft_lstadd_back`: Add the 'new' element at the end of the list
*`ft_lstdelone`: Free the memory of the element passed as parameter using the 'del' function then free(3). The memory of 'next' must not be freed.
*`ft_lstclear`: Deletes and free the memory of the element passed as parameter and all the following elements using 'del' and free(3). Finally, the initial pointer must be set to NULL.
*`ft_lstiter`: Iterate over the list 'lst' and apply the function 'f' to the content of all elements.
*`ft_lstmap`: Iterate over the list 'lst' and apply the function 'f' to the content of each elements. Create a new list resulting of the successive applications of 'f'. The function 'del' is used to destroy the content of an element if necessary.

