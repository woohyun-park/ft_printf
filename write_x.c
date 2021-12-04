#include "ft_printf.h"

int	write_x(unsigned long long int num, int flag)
{
	const char *str_low = "0123456789abcdef";
	const char *str_upp = "0123456789ABCDEF";
	unsigned long long int	tempNum;
	unsigned long long int	len;
	unsigned long long int	tempLen;

	
	tempNum = num;
	len = 0;
	while (tempNum > 0){
		tempNum /= 16;
		len++;
	}
	char *result = (char *)malloc(sizeof(char) * (len + 1));
	result[len] = 0;
	tempLen = len;
	while (num > 0){
		if (flag == 0)
			result[--tempLen] = str_low[num % 16];
		else
			result[--tempLen] = str_upp[num % 16];
		num /= 16;
	}
	write(1, result, len);
	free(result);
	return (len);
}

