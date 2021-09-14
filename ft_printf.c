#include <stdio.h>

#include <stdarg.h>
#include <unistd.h>

void write_c(va_list ap, const char *str)
{
    char    arg;

    arg = va_arg(ap, int);
    write(1, &arg, 1);
    str++;
}

void write_s(va_list ap, const char *str)
{
    char    *arg;
    int     i;

    arg = va_arg(ap, char*);
    i = 0;
    while (arg[i])
        i++;
    write(1, arg, i);
    str += i;
}

// void write_p(va_list ap, const char *str)
// {
//     char                *arg;
//     unsigned long int   p;

//     p = va_arg(ap, unsigned long int);

// }

// void write_d(va_list ap, const char *str)
// {
//     char    *arg;
//     int     d;

//     d = va_arg(ap, int);
//     if (d < 0)
//     {
//         write(1, "-", 1);

//     }
// }

void write_percent(const char *str)
{
    write(1, "%", 1);
    str++;
}

int format(va_list ap, const char **str)
{
    if (**str == 'c')
        write_c(ap, *str);
    if (**str == 's')
        write_s(ap, *str);
    if (**str == 'p')
        write(1, "%p", 2);
    if (**str == 'd')
        write(1, "%d", 2);
    if (**str == 'i')
        write(1, "%i", 2);
    if (**str == 'u')
        write(1, "%u", 2);
    if (**str == 'x')
        write(1, "%x", 2);
    if (**str == 'X')
        write(1, "%X", 2);
    if (**str == '%')
        write_percent(*str);
    (*str)++;
    return (1);
}

int ft_printf(const char *str, ...)
{
    va_list ap;
    int     num_format;
    int     num_result;

    if (str == 0)
        return (-1);
    num_result = 0;
    va_start(ap, str);
    while (*str)
    {
        if (*str != '%')
        {
            write(1, str++, 1);
            num_result++;
        }
        //서식지정자가 들어왔을때 처리
        else
        {
            str++;
            num_format = format(ap, &str);
            if (num_format < 0)
                return (-1);
            num_result += num_format;
        }
    }
    va_end(ap);
    return (num_result);
}

int main(void)
{
    ft_printf("Hello, world! %c\n", 'a');
    ft_printf("Hello, world! %s\n", "abcdefg");
    ft_printf("Hello, world! %%\n");
}