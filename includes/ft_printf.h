#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft.h"
#include <stdarg.h>
#include <stdio.h>

# define LEFT_PAD 0
# define RIGHT_PAD 1
# define LOW_CASE 0
# define UP_CASE 1
# define SPECS "sSpdDioOuUxXcC"

typedef struct 	s_flags
{
	int 		l_flag;
	int 		ll_flag;
	int 		h_flag;
	int			hh_flag;
	int			j_flag;
	int			z_flag;
	int			hash_flag;
	int			zero_flag;
	int			plus_flag;
	int 		space_flag;
}				t_flags;

typedef struct 	s_mods
{
	int 		just;
	int 		prec;
	t_flags 	*flags;
}				t_mods;


void 	pad_str(char **str, char pad, int pad_len, int pad_side);
void 	just_str(char **str, char pad, int just);
char	*ft_itoa_ptr(uintmax_t value, int base, int is_upper);
char 	*get_hex(int num, int up_low);
char 	*get_oct(int num);
char 	*print_wchar(const void *ptr, t_mods *mods);
char 	*print_char(const void *ptr, t_mods *mods);
char 	*print_hex_down(const void *ptr, t_mods *mods);
char 	*print_hex_up(const void *ptr, t_mods *mods);
char 	*cap_u(const void *ptr, t_mods *mods);
char 	*print_uint(const void *ptr, t_mods *mods);
char 	*cap_o(const void *ptr, t_mods *mods);
char 	*print_oct(const void *ptr, t_mods *mods);
char 	*cap_d(const void *ptr, t_mods *mods);
char 	*print_int(const void *ptr, t_mods *mods);
char 	*print_wstr(const void *ptr, t_mods *mods);
char 	*print_str(const void *ptr, t_mods *mods);
void 	prec_str(char **str, int prec);
t_mods	*make_mods(const char *format, int loc);
int 	get_just(const char *format, int loc);
int 	spec_loc(const char *format, int loc);
int 	spec_index(const char *format, int loc);
int 	has_hh_flag(const char *format, int loc);
int 	has_h_flag(const char *format, int loc);
int 	has_l_flag(const char *format, int loc);
int 	has_ll_flag(const char *format, int loc);
int 	has_j_flag(const char *format, int loc);
int 	has_z_flag(const char *format, int loc);
int 	has_plus_flag(const char *format, int loc);
int 	has_hash_flag(const char *format, int loc);
int 	has_zero_flag(const char *format, int loc);
int 	get_prec(const char *format, int loc);
int 	has_zero_flag(const char *format, int loc);
t_flags *get_flags(const char *format, int loc);
char	*print_ptr(const void *ptr, t_mods *mods);
int 	has_space_flag(const char *format, int loc);
int		ft_printf(const char *format, ...);

static char* (*g_str[])(const void *, t_mods *) = {print_str, print_wstr, print_ptr,
	print_int, cap_d, print_int, print_oct, cap_o, print_uint, cap_u,
	print_hex_down, print_hex_up , print_char, print_wchar};

#endif
