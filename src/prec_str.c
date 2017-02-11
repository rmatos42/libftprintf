#include <ft_printf.h>

void 	prec_str(char **str, int prec)
{
	printf("prec: %i\n", prec);
	if (prec != -1)
		*str = ft_strsub(*str, 0, prec);
}
