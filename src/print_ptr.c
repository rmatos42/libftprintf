#include <ft_printf.h>

uintmax_t	ft_pow(int base, int i)
{
		if (i == 0)
			return (1);
		return (base * ft_pow(base, i - 1));
}

char	*ft_itoa_ptr(uintmax_t value, int base, int is_upper)
{
	char *alpha_num;
	int size;
	char *nbr;

	alpha_num = (is_upper == 1) ? ft_strdup("0123456789ABCDEF") : ft_strdup("0123456789abcdef");
	size = 1;
	while (ft_pow(base, size) - 1 < value)
		size++;
	nbr = ft_strnew(size);
	while (size-- > 0)
	{
		nbr[size] = alpha_num[value % base];
		value /= base;
	}
	ft_strdel(&alpha_num);
	return (nbr);
}

char	*print_ptr(const void *ptr, t_mods *mods)
{
	uintmax_t address;
	char *str;

	address = (uintmax_t)ptr;
	str = ft_itoa_ptr(address, 16, 0);
	if (mods->flags->zero_flag && mods->just >= 0)
		just_str(&str, '0', mods->just - 2);
	str = ft_strjoin("0x", str);
	if (!mods->flags->zero_flag || mods->just < 0)
		just_str(&str, ' ', mods->just);
	return (str);
}
