#include "ft_printf.h"

static unsigned int	ft_intlen(unsigned int n)
{
	unsigned int	result;

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

char	*ft_itoa2(unsigned int n)
{
	unsigned int		len;
	char	*result;
	unsigned int		i;
	unsigned int		n_new;

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
		result += write_xp(num, 0, 0);
	return result;
}

int	write_diu(long long int	num, int flag)
{
	char			*arg;
	char			len;

	if (flag == 0 || flag == 1)
		arg = ft_itoa((int)num);
	else
		arg = ft_itoa2((unsigned long long int)num);
	len = ft_strlen(arg);
	write(1, arg, len);
	free(arg);
	return (len);
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
		result = write_xp(va_arg(ap, unsigned long long int), 0, 1);
	if (**str == 'X')
		result = write_xp(va_arg(ap, unsigned long long int), 1, 1);
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
// 	printf("%u\n", -1);
// 	ft_printf("%u\n", -1);
// }