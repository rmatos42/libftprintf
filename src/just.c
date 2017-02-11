#include <ft_printf.h>

int 	ft_abs(int num)
{
	if (num >= 0)
		return (num);
	else
		return (num * -1);

}

static int get_padlen(char *str, int just)
{
	if ((size_t)ft_abs(just) <= ft_strlen(str))
		return (-1);
	return (ft_abs(ft_strlen(str) - ft_abs(just)));
}

void 	just_str(char **str, char pad, int just)
{
	if(get_padlen(*str, just) == -1)
		return ;
	if (just < 0)
		pad_str(str, pad, get_padlen(*str, just), RIGHT_PAD);
	else
		pad_str(str, pad, get_padlen(*str, just), LEFT_PAD);
}
