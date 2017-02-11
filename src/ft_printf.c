#include <ft_printf.h>

int		ft_printf(const char *format, ...)
{
	int 	i;
	char 	*str;
	t_mods 	*mods;
	const void *ptr;
	va_list args;

	i = 0;
	str = "";
	va_start(args, format);
	while (format[i])
	{
		if (spec_loc(format, i) != -1)
		{
			ptr = va_arg(args, const void *);
			mods = make_mods(format, i);
			str = g_str[spec_index(format, i)](ptr, mods);
			ft_putstr(str);
			i = spec_loc(format, i) + 1;
		}
		else
			ft_putchar(format[i++]);
	}
	return (0);
}
