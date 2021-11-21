#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>

#include <stdarg.h>
#include <unistd.h>
#include "libft/libft.h"

int	write_c(char c);
int	write_s(char *s);
int	write_p(unsigned long long int num);
int	write_diu(long long int num, int flag);
int	write_x(unsigned long long int num, int flag);
int format(va_list ap, const char **str);
int ft_printf(const char *str, ...);

#endif