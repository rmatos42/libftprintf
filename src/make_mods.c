#include <ft_printf.h>

t_mods	*make_mods(const char *format, int loc)
{
	t_mods *result;

	result = (t_mods *)ft_memalloc(sizeof(t_mods));
	result->just = get_just(format, loc);
	result->prec = get_prec(format, loc);
	result->flags = get_flags(format, loc);
	return (result);
}
