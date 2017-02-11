#include <ft_printf.h>

int 	has_hh_flag(const char *format, int loc)
{
	int i;
	int i_max;

	i = loc;
	i_max = spec_loc(format, loc);
	while (i++ < i_max)
		if (format[i] == 'h' && format[i + 1] == 'h')
			return (1);
	return (0);
}

int 	has_h_flag(const char *format, int loc)
{
	int i;
	int i_max;

	i = loc;
	i_max = spec_loc(format, loc);
	while (i++ < i_max)
		if (format[i] == 'h' && format[i + 1] != 'h' && format[i - 1] != 'h')
			return (1);
	return (0);
}

int 	has_l_flag(const char *format, int loc)
{
	int i;
	int i_max;

	i = loc;
	i_max = spec_loc(format, loc);
	while (i++ < i_max)
		if (format[i] == 'l' && format[i + 1] != 'l' && format[i - 1] != 'l')
			return (1);
	return (0);
}

int 	has_ll_flag(const char *format, int loc)
{
	int i;
	int i_max;

	i = loc;
	i_max = spec_loc(format, loc);
	while (i++ < i_max)
		if (format[i] == 'l' && format[i + 1] != 'l')
			return (1);
	return (0);
}

int 	has_j_flag(const char *format, int loc)
{
	int i;
	int i_max;

	i = loc;
	i_max = spec_loc(format, loc);
	while (i++ < i_max)
		if (format[i] == 'j')
			return (1);
	return (0);
}

int 	has_z_flag(const char *format, int loc)
{
	int i;
	int i_max;

	i = loc;
	i_max = spec_loc(format, loc);
	while (i++ < i_max)
		if (format[i] == 'z')
			return (1);
	return (0);
}
