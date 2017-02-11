#include <ft_printf.h>

static char *make_pad(char pad, int pad_len)
{
	int i;
	char *padding;

	i = 0;
	padding = (char *)ft_memalloc(sizeof(char) * (pad_len + 1));
	while (i < pad_len)
		padding[i++] = pad;
	padding[i] = '\0';
	return (padding);
}

void 	pad_str(char **str, char pad, int pad_len, int pad_side)
{
	char *padding;

	padding = make_pad(pad, pad_len);
	if (pad_side == LEFT_PAD)
		*str = ft_strjoin(padding, *str);
	if (pad_side == RIGHT_PAD)
		*str = ft_strjoin(*str, padding);
}
