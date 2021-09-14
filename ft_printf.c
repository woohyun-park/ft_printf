#include <stdio.h>

#include <stdarg.h>
#include <unistd.h>

int ft_printf(const char *str, ...)
{
    va_list ap;
    int     result;

    result = 0;
    va_start(ap, str);
    while (*str)
    {
        if (*str != '%')
        {
            write(1, str++, 1);
            result++;
        }
        else
            str++;
    }
    va_end(ap);
    return result;
}

int main(void)
{
    ft_printf("Hello, world!");
}