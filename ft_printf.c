#include "ft_printf.h"

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
		arg = ft_itoa((unsigned long long int)num);
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
// 	// printf("%d\n", LONG_MAX);
	
// 	// printf("%x\n", LONG_MAX);
// 	// ft_printf("%x\n", LONG_MAX);
// 	// printf("%x\n", LONG_MAX + 1);
// 	// ft_printf("%x\n", LONG_MAX + 1);
// 	// printf("%x\n", UINT_MAX);
// 	// ft_printf("%x\n", (unsigned int)UINT_MAX);
// 	// printf("%x\n", ULONG_MAX);
// 	// ft_printf("%x\n", (unsigned int)ULONG_MAX);
// 	printf("%x\n", LONG_MIN);
// 	ft_printf("%x\n", LONG_MIN);
// }