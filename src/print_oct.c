#include <ft_printf.h>

char 	*get_oct(int num)
{
	return (ft_itoa_base(num, 8, 0));
}

char 	*print_oct(const void *ptr, t_mods *mods)
{
	int num;
	char *str;

	num = (int)ptr;
	str = ft_itoa_base(num, 8, 0);
	just_str(&str, '0', mods->prec);
	if (mods->flags->zero_flag && mods->prec == -1 && mods->just >= 0)
		just_str(&str, '0', mods->just);
	else
		just_str(&str, ' ', mods->just);
	return (str);
}
