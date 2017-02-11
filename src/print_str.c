#include <ft_printf.h>

char 	*print_str(const void *ptr, t_mods *mods)
{
	char *str;

	str = (char *)ptr;
	printf("before: %s\n", str);
	prec_str(&str, mods->prec);
	just_str(&str, ' ', mods->just);
	printf("after: %s\n", str);
	return (str);
}
