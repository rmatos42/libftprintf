#include <ft_printf.h>

int 	spec_loc(const char *format, int loc)
{
	int i;

	i = loc;
	if (format[i] != '%')
		return (-1);
	while (format[i++])
		if (ft_strchr(SPECS, format[i]))
			return (i);
	return (-1);
}
