// #include <stdio.h>

// #include <stdarg.h>
// #include <unistd.h>
// #include "libft/libft.h"
// #include "write_x.c"
#include "ft_printf.h"

static char	*ft_intmax(void)
{
	char	*result;

	result = (char *)malloc(12);
	if (result == 0)
		return (NULL);
	result[0] = '-';
	result[1] = '2';
	result[2] = '1';
	result[3] = '4';
	result[4] = '7';
	result[5] = '4';
	result[6] = '8';
	result[7] = '3';
	result[8] = '6';
	result[9] = '4';
	result[10] = '8';
	result[11] = 0;
	return (result);
}

static int	ft_intlen(int n)
{
	int	result;

	if (n <= 0)
		result = 1;
	else
		result = 0;
	while (n != 0)
	{
		n /= 10;
		result++;
	}
	return (result);
}

char	*ft_itoa2(long long int n)
{
	int		len;
	char	*result;
	int		i;
	int		n_new;

	printf("n: %lld\n", n);
	if (n == -2147483648)
		return (ft_intmax());
	len = ft_intlen(n);
	result = (char *)malloc(ft_intlen(n) + 1);
	if (!result)
		return (NULL);
	result[len] = 0;
	if (n < 0)
		n_new = -n;
	else
		n_new = n;
	i = len - 1;
	while (i > 0)
	{
		result[i] = n_new % 10 + '0';
		n_new /= 10;
		i--;
	}
	if (n < 0)
		result[0] = '-';
	else
		result[0] = n_new % 10 + '0';
	return (result);
}





int	write_c(char c)
{
	write(1, &c, 1);
	return (1);
}

int	write_s(char *s)
{
	int		result;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	result = 0;
	while (s[result])
		result++;
	write(1, s, result);
	return (result);
}

int write_p(unsigned long long int num)
{
	int result;

	result = 0;
	result += write(1, "0x", 2);
	if (num == 0)
		result += write(1, "0", 1);
	else
		result += write_x(num, 0);
	return result;
}

int	write_diu(long long int	num, int flag)
{
	char			*arg;

	if (num < 0)
		num *= -1;
	if (flag == 0 || flag == 1)
		arg = ft_itoa((long long int)num);
	else
		arg = ft_itoa((unsigned long long int)num);
	write(1, arg, ft_strlen(arg));
	write(1, "whatever", 8);
	return (ft_strlen(arg));
}

int	format(va_list ap, const char **str)
{
	int result;

	result = 0;
	if (**str == 'c')
		result = write_c(va_arg(ap, int));
	if (**str == 's')
		result = write_s(va_arg(ap, char *));
	if (**str == 'p')
		result = write_p(va_arg(ap, unsigned long long int));
	if (**str == 'd')
		result = write_diu(va_arg(ap, long long int), 0);
	if (**str == 'i')
		result = write_diu(va_arg(ap, long long int), 1);
	if (**str == 'u')
		result = write_diu(va_arg(ap, long long int), 2);
	if (**str == 'x')
		result = write_x(va_arg(ap, unsigned long long int), 0);
	if (**str == 'X')
		result = write_x(va_arg(ap, unsigned long long int), 1);
	if (**str == '%')
		result = write(1, "%", 1);
	(*str)++;
	return (result);
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

// int main(void){
// 	printf("%p, %p\n", LONG_MIN, LONG_MAX);
// 	ft_printf("%p, %p\n", LONG_MIN, LONG_MAX);
// 	printf("%p, %p\n", ULONG_MAX, -ULONG_MAX);
// 	ft_printf("%p, %p\n", ULONG_MAX, -ULONG_MAX);
// }

// int main(void)
// {
// 	char c = 'c';
// 	printf("%d, %d\n\n", ft_printf("c: %c\n", c), printf("c: %c\n", c));

// 	char *s = "string";
// 	printf("%d, %d\n\n", ft_printf("s: %s\n", s), printf("s: %s\n", s));

// 	char *p = "p";
// 	printf("%d, %d\n\n", ft_printf("p: %p\n", &p), printf("p: %p\n", &p));

// 	int d = 42;
// 	printf("%d, %d\n\n", ft_printf("d: %d\n", d), printf("d: %d\n", d));

// 	int i = 42;
// 	printf("%d, %d\n\n", ft_printf("i: %i\n", i), printf("i: %i\n", i));

// 	unsigned int u = 42;
// 	printf("%d, %d\n\n", ft_printf("u: %u\n", u), printf("u: %u\n", u));

// 	int x_low = 42;
// 	printf("%d, %d\n\n", ft_printf("x: %x\n", x_low), printf("x: %x\n", x_low));

// 	int x_upp = 42;
// 	printf("%d, %d\n\n", ft_printf("X: %X\n", x_upp), printf("X: %X\n", x_upp));

// 	printf("%d, %d\n\n", ft_printf("%%: %%\n"), printf("%%: %%\n"));

// 	// char *p_new = "p";
// 	// int x_low_new = 42;
// 	// int x_upp_new = 42;
// 	// printf("%d, %d\n\n", ft_printf("%c, %s, %p, %d, %i, %u, %x, %X\n", c, s, p_new, d, i ,u, x_low_new, x_upp_new),
// 	// 	printf("%c, %s, %p, %d, %i, %u, %x, %X\n", c, s, p_new, d, i ,u, x_low_new, x_upp_new));
// 	// ft_printf("%c, %s, %p, %d, %i, %u, %x, %X\n", c, s, p, d, i ,u, test, x_upp);
// 	// printf("%c, %s, %p, %d, %i, %u, %x, %X\n", c, s, p, d, i ,u, test, x_upp);
// }
