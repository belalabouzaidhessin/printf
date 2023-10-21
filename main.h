#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>



/*Mandatory functions*/
int _printf(const char *format, ...);

/*Other useful functions*/
int count(const char *str);
int _putchar(char c);
void print_number(int n);



#endif
