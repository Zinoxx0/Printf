*This project has been created as part of the 42 curriculum by samercad*

# ft_printf

## Description

ft_printf is a recode of the `printf()` function from the C standard library. It is built as a
static library, `libftprintf.a`, and the goal of the project is to learn how variadic functions
(`va_start`, `va_arg`, `va_end`) work in C.

It handles the following conversions:

| Conversion | Prints |
|---|---|
| `%c` | a single character |
| `%s` | a string (`(null)` for a NULL pointer) |
| `%p` | a pointer in hexadecimal, with `0x` in front (`(nil)` for NULL) |
| `%d` / `%i` | a signed decimal integer |
| `%u` | an unsigned decimal integer |
| `%x` / `%X` | an unsigned integer in lowercase / uppercase hexadecimal |
| `%%` | a percent sign |

Like the original, it returns the number of characters printed (or `-1` if the format is NULL).

## Instructions

Build the library:

```sh
make        # builds libftprintf.a
make clean  # removes the object files
make fclean # removes the object files and the library
make re     # rebuilds everything
```

Use it in a program by including the header and linking the library:

```c
#include "ft_printf.h"

int	main(void)
{
	ft_printf("Hello %s, you are %d years old\n", "world", 42);
	return (0);
}
```

```sh
cc -Wall -Wextra -Werror main.c libftprintf.a -o main
./main
```

## Algorithm and data structure

- **Reading the format:** `ft_printf` walks the format string once, one character at a time, with
  an index. Normal characters are written straight away with `write`. When a `%` is found, the
  next character is sent to `print_check`, which picks the right print function with a chain of
  `if` / `else if`. Adding a new conversion only means adding one more branch and one function.
- **Counting characters:** every print function receives a pointer to the same `int` counter
  (`len`) and adds to it each time it writes, so `ft_printf` just returns that counter at the end.
- **Decimal numbers (`%d`, `%i`, `%u`):** printed recursively: the function calls itself with
  `number / 10` first, then prints `number % 10`, so the digits come out in the right order
  without any buffer. `INT_MIN` is printed as a special case because `-INT_MIN` does not fit in
  an `int`.
- **Hexadecimal (`%x`, `%X`, `%p`):** the number is divided by 16 repeatedly and each digit is
  taken from a base string (`"0123456789abcdef"` or the uppercase one), stored in a small array on
  the stack, then printed backwards.
- **Data structures:** none on the heap. The only data is the `va_list`, the counter and a
  small fixed-size `char` array. There is no `malloc`, so there is nothing to free and no
  possible leak, and there is no output buffer, as the subject asks.

## Resources

- `man 3 printf`: <https://man7.org/linux/man-pages/man3/printf.3.html>
- `man 3 stdarg`: <https://man7.org/linux/man-pages/man3/stdarg.3.html>
- Variadic functions on cppreference: <https://en.cppreference.com/w/c/variadic>

### Use of AI

AI (Claude) was used only after the code was written:

- for some last checks of the finished code against the subject and the real `printf`, as a
  final cleanup effort;
- to help organize my thoughts when writing this README;
- for optimizing the functions after they were written.
