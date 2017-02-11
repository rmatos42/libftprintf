#include <ft_printf.h>

int 	has_plus_flag(const char *format, int loc)
{
	int i;
	int i_max;

	i = loc;
	i_max = spec_loc(format, loc);
	while (++i < i_max)
		if (format[i] == '+')
			return (1);
	return (0);
}

int 	has_hash_flag(const char *format, int loc)
{
	int i;
	int i_max;

	i = loc;
	i_max = spec_loc(format, loc);
	while (++i < i_max)
		if (format[i] == '#')
			return (1);
	return (0);
}

int 	has_zero_flag(const char *format, int loc)
{
	int i;
	int i_max;

	i = loc;
	i_max = spec_loc(format, loc);
	while (++i < i_max)
	{
		if (ft_atoi(format + i) && format[i] != '0' && format[i] != '+' && format[i] != '-')
			return (0);
		if (format[i] == '0')
			return (1);
	}
	return (0);
}

int 	has_space_flag(const char *format, int loc)
{
	int i;
	int i_max;

	i = loc;
	i_max = spec_loc(format, loc);
	while (++i < i_max)
		if (format[i] == ' ')
			return (1);
	return (0);
}

t_flags *get_flags(const char *format, int loc)
{
	t_flags *result;

	result = (t_flags *)ft_memalloc(sizeof(t_flags));
	result->l_flag = has_l_flag(format, loc);
	result->ll_flag = has_ll_flag(format, loc);
	result->h_flag = has_h_flag(format, loc);
	result->hh_flag = has_hh_flag(format, loc);
	result->j_flag = has_j_flag(format, loc);
	result->z_flag = has_z_flag(format, loc);
	result->hash_flag = has_hash_flag(format, loc);
	result->zero_flag = has_zero_flag(format, loc);
	result->plus_flag = has_plus_flag(format, loc);
	result->space_flag = has_space_flag(format, loc);

	return (result);
}
