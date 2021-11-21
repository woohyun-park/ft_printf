void	write_x(va_list ap, const char *str, int flag)
{
	const char *str_low = "0123456789abcdef";
	const char *str_upp = "0123456789ABCDEF";
	long long int   num;
	long long int	tempNum;
	long long int	len;
	long long int	tempLen;

	num = va_arg(ap, unsigned long int);
	tempNum = num;
	len = 0;
	while (tempNum > 0){
		tempNum /= 16;
		len++;
	}
	tempLen = len;
	char *result = malloc(sizeof(char) * (len + 1));
	while (num > 0){
		if (flag == 0)
			result[--len] = str_low[num % 16];
		else
			result[--len] = str_upp[num % 16];
		num /= 16;
	}
	result[tempLen] = 0;
	write(1, result, tempLen);
}