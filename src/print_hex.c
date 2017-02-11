#include <ft_printf.h>

char 	*print_hex_up(const void *ptr, t_mods *mods)
{
	int num;
	char *str;

	num = (unsigned int)ptr;
	str = ft_itoa_base(num, 16, 1);
	just_str(&str, '0', mods->prec);
	if (mods->flags->zero_flag && mods->prec == -1 && mods->just >= 0)
		just_str(&str, '0', mods->just);
	else
		just_str(&str, ' ', mods->just);
	return (str);
}

char 	*print_hex_down(const void *ptr, t_mods *mods)
{
	int num;
	char *str;

	num = (unsigned int)ptr;
	str = ft_itoa_base(num, 16, 0);
	just_str(&str, '0', mods->prec);
	if (mods->flags->zero_flag && mods->prec == -1 && mods->just >= 0)
		just_str(&str, '0', mods->just);
	else
		just_str(&str, ' ', mods->just);
	return (str);
}
