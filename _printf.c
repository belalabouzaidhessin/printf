c#include "main.h"

int _printf_char(char c)
{
write(1, &c, 1);
return (1);
}

int _printf_string(char *cont)
{
if (cont == NULL)
{
write(1, "(null)", 6);
return (6);
}
else
{
write(1, cont, strlen(cont));
return ((int)strlen(cont));
}
}

int _printf(const char *format, ...)
{
int char_printed = 0;
va_list ap;
va_start(ap, format);

while (*format)
{
if (*format != '%')
{
char_printed += _printf_char(*format);
}
else
{
format++;

if (*format == '%')
{
char_printed += _printf_char('%');
}
else if (*format == 'c')
{
char_printed += _printf_char(va_arg(ap, int));
}
else if (*format == 's')
{
char_printed += _printf_string(va_arg(ap, char *));
}
}

format++;
}

va_end(ap);
return (char_printed);
}

