#include "main.h"

/**
 * _printf_char - Print a character.
 * @c: The character to print.
 *
 * Return: The number of characters printed.
 */
int _printf_char(char c)
{
write(1, &c, 1);
return (1);
}

/**
 * _printf_string - Print a string.
 * @s: The string to print.
 *
 * Return: The number of characters printed.
 */
int _printf_string(char *cont)
{
if (cont == NULL)
{
write(1, "(null)", 1);
return (1);
}
else
{
write(1, cont, strlen(cont));
return (strlen(cont));
}
}

/**
 * _printf - Printf function.
 * @format: The format string.
 * @...: Variable arguments.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
int char_printed = 0;
va_list ap;
va_start(ap, format);

while (*format)
{
if (*format != '%')
{
char_printed = char_printed + _printf_char(*format);
}
else
{
format++;

if (*format == '%')
{
char_printed = char_printed + _printf_char('%');
}

else if (*format == 'c')
{
char_printed = char_printed + _printf_char(va_arg(ap, int));
}
else if (*format == 's')
{
char_printed = char_printed + _printf_string(va_arg(ap, char *));
}

}
format++;
}

va_end(ap);
return (char_printed);
}
