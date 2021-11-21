#include <stdio.h>

#include <stdarg.h>
#include <unistd.h>
#include "libft/libft.h"
#include "write_x.c"

void	write_c(va_list ap, const char *str)
{
	char	arg;

	arg = va_arg(ap, int);
	write(1, &arg, 1);
	str++;
}

void	write_s(va_list ap, const char *str)
{
	char	*arg;
	int		i;

	arg = va_arg(ap, char *);
	i = 0;
	while (arg[i])
		i++;
	write(1, arg, i);
	str += i;
}

void write_p(va_list ap, const char *str)
{
	write(1, "0x", 2);
	write_x(ap, str, 0);
}

void	write_d(va_list ap, const char *str)
{
	char			*arg;
	long long int	num;
	int				len;

	num = va_arg(ap, int);
	if (num < 0)
	{
		write(1, "-", 1);
		str++;
		num *= -1;
	}
	arg = ft_itoa((int)num);
	len = ft_strlen(arg);
	write(1, arg, len);
	str += len;
}

void	write_diu(va_list ap, const char *str, int flag)
{
	char			*arg;
	long long int	num;

	num = va_arg(ap, long long int);
	if (num < 0)
		num *= -1;
	if (flag == 0 || flag == 1)
		arg = ft_itoa((long long int)num);
	else
		arg = ft_itoa((unsigned long long int)num);
	write(1, arg, ft_strlen(arg));
}

int	format(va_list ap, const char **str)
{
	if (**str == 'c')
		write_c(ap, *str);
	if (**str == 's')
		write_s(ap, *str);
	if (**str == 'p')
		write_p(ap, *str);
	if (**str == 'd')
		write_diu(ap, *str, 0);
	if (**str == 'i')
		write_diu(ap, *str, 1);
	if (**str == 'u')
		write_diu(ap, *str, 2);
	if (**str == 'x')
		write_x(ap, *str, 0);
	if (**str == 'X')
		write_x(ap, *str, 1);
	if (**str == '%')
		write(1, "%", 1);
	(*str)++;
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		num_format;
	int		num_result;

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
	char c = 'c';
	ft_printf("c: %c\n", c);
	printf("c: %c\n", c);

	char *s = "string";
	ft_printf("s: %s\n", s);
	printf("s: %s\n", s);

	char *p = "p";
	ft_printf("p: %p\n", &p);
	printf("p: %p\n", &p);

	int d = 42;
	ft_printf("d: %d\n", d);
	printf("d: %d\n", d);

	int i = 42;
	ft_printf("i: %i\n", i);
	printf("i: %i\n", i);

	unsigned int u = 42;
	ft_printf("u: %u\n", u);
	printf("u: %u\n", u);

	int x_low = 42;
	ft_printf("x: %x\n", x_low);
	printf("x: %x\n", x_low);

	int x_Upp = 42;
	ft_printf("X: %X\n", x_Upp);
	printf("X: %X\n", x_Upp);

	ft_printf("%%: %%\n");
	printf("%%: %%\n");
}
