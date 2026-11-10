# ft_printf

42 Cursus — Circle 1 project (C / Piscine common core)

## Goal

Recode `printf`, as a library function `ft_printf`, using variadic functions
(`stdarg.h`). The goal isn't to reimplement every flag and option of the
original `printf`, but to understand how a format string is parsed and how a
variable number of arguments of different types is read from it.

## Language & constraints

- **Language:** C
- Norm-compliant (42 Norm)
- Compiled as a static library: `libftprintf.a`
- Handles the following conversions:

| Conversion | Meaning |
|---|---|
| `%c` | single character |
| `%s` | string (prints `(null)` for a `NULL` pointer) |
| `%p` | pointer, in hexadecimal (`0x...`, `(nil)` for `NULL`) |
| `%d` / `%i` | signed decimal integer |
| `%u` | unsigned decimal integer |
| `%x` | hexadecimal, lowercase |
| `%X` | hexadecimal, uppercase |
| `%%` | a literal `%` |

Flags, width and precision (`%-10d`, `%05d`, `%.2f`...) are not implemented —
this version only covers the conversions listed above.

## How it works

`ft_printf` walks the format string character by character with
`ft_printf_searcher`. Each regular character is written as-is with
`ft_putchar`; each `%` is followed by a conversion character which
`ft_printf_sorter` dispatches to the matching helper, pulling the next
argument out of the `va_list` with `va_arg`. Every helper returns the number
of characters it wrote, which are summed up and returned by `ft_printf`, just
like the original `printf`.

| File | Role |
|---|---|
| `ft_printf.c` | Format string parser and conversion dispatcher |
| `ft_usefulfonc.c` | `%s`, `%d`/`%i` (via `ft_itoa`), `%u`, `%x`/`%X` |
| `ft_putptrfunc.c` | `%p`: pointer printed in hexadecimal |
| `libft_functions.c` | Small libft subset used internally (`ft_strlen`, `ft_strdup`, `ft_itoa`) |

## Usage

```c
#include "ft_printf.h"

int main(void)
{
    int written;

    written = ft_printf("%s has %d apples (0x%x)\n", "Maxime", 42, 42);
    ft_printf("written: %d\n", written);
    return (0);
}
```

## Compiling

```sh
make        # builds libftprintf.a
make clean  # removes object files
make fclean # removes object files and the library
make re     # fclean + all
```

Then link it against your own program:

```sh
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o my_program
```

## Author

Maxime Pirt — 42 Cursus
