#include <ft_printf.h>

void 	apply_sign(char **str)
{
	if (ft_atoi(*str) >= 0)
		*str = ft_strjoin("+", *str);
	else
		*str = ft_strjoin("-", *str);
}

void 	apply_space(char **str)
{
	*str = ft_strjoin(" ", *str);
}

char 	*print_int(const void *ptr, t_mods *mods)
{
	char *str;
	int num;

	num = (int)ptr;
	str = ft_itoa_base(num, 10, 0);
	if (mods->prec != -1)
		just_str(&str, '0', mods->prec);
	else if (mods->flags->zero_flag && mods->just >= 0)
		just_str(&str, '0', (mods->flags->plus_flag || mods->flags->space_flag ? mods->just - 1 : mods->just));
	if (mods->flags->plus_flag)
		apply_sign(&str);
	else if (mods->flags->space_flag)
		apply_space(&str);
	if (!mods->flags->zero_flag || (mods->flags->zero_flag && mods->just > 0))
		just_str(&str, ' ', mods->just);
	return (str);
}
