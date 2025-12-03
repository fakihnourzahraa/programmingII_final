
#include "so_long.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			count += process_format(format, i, args);
			i++;
		}
		else
			count += ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
