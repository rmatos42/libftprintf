#include <ft_printf.h>

int 	spec_index(const char *format, int loc)
{
	int i;
	char spec;

	i = -1;
	if (spec_loc(format, loc) != -1)
		spec = format[spec_loc(format, loc)];
	while (SPECS[++i])
		if (SPECS[i] == spec)
			return (i);
	return (-1);
}
