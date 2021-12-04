#include "ft_printf.h"

int	write_xp(unsigned long int num, int isUpper, int isX)
{
	const char *str_low = "0123456789abcdef";
	const char *str_upp = "0123456789ABCDEF";
	unsigned long int	tempNum;
	unsigned long int	len;
	unsigned long int	tempLen;
	
	if(isX == 1)
		tempNum = (unsigned int)num;
	else
		tempNum = num;
	if (tempNum == 0)
		return (write(1, "0", 1));
	len = 0;
	while (tempNum > 0){
		tempNum /= 16;
		len++;
	}
	// printf("len:%d\n", len);
	char *result = (char *)malloc(sizeof(char) * (len + 1));
	result[len] = 0;
	tempLen = len;
	while (num > 0){
		if (isUpper == 0)
			result[--tempLen] = str_low[num % 16];
		else
			result[--tempLen] = str_upp[num % 16];
		num /= 16;
	}
	// printf("result:%s\n", result);
	write(1, result, len);
	free(result);
	return (len);
}

