/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaragul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 15:52:44 by egaragul          #+#    #+#             */
/*   Updated: 2017/03/05 22:32:12 by egaragul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <wchar.h>
# include <wctype.h>
# include <stdint.h>

int				g_counter;
typedef struct	s_struct
{
	char		*string;
	char		*modif;
	char		*arg_str;
	char		type;
	int			wid;
	int			prec;
	int			flag_zero;
	int			flag_sharp;
	int			flag_space;
	int			flag_minus;
	int			flag_plus;
}				t_struct;

int				ft_printf(const char *format, ...);
void			ft_init_struct(char **s, va_list arg);
void			ft_begin(t_struct *parts, va_list arg);
void			ft_zero_flag(t_struct *parts);
void			ft_sharp_flag(t_struct *parts);
void			ft_space_flag(t_struct *parts);
void			ft_minus_flag(t_struct *parts);
void			ft_plus_flag(t_struct *parts);
void			ft_fill_prec_wid(t_struct *parts);
void			ft_fill_modificators(t_struct *parts);
void			ft_what_type_print(va_list arg, t_struct *parts);
void			ft_fill_prec_wid(t_struct *parts);
void			ft_print_out(va_list arg, t_struct *parts);
void			ft_print_out_string(t_struct *parts);
char			*ft_itoa(int n);
char			*ft_itoa_base(long long value, int base);
char			*ft_itoa_base_unsigned(unsigned long long value, int base);
void			ft_print_did_digits(t_struct *parts);
void			ft_print_oux_digits(t_struct *parts);
void			ft_for_did_digits_wid(t_struct *parts);
void			ft_for_sharp(t_struct *parts);
void			ft_print_p_type(t_struct *parts, va_list arg);
void			ft_for_nuls_and_spaces(t_struct *parts);
void			ft_print_ub(t_struct *parts);
void			ft_check_for_type(char **s, t_struct *parts);
void			ft_rec_unb_type(t_struct *parts);
void			ft_for_perc_rec_only(char **s, t_struct *parts, int i);
char			*ft_strdup_wint(wint_t *str);
void			ft_putchar_count(char c);
void			ft_putstr_count(char *str);
void			ft_putnbr_unsigned(uintmax_t nb);
char			*ft_tolowstr(char *str);
int				ft_isalpha(int a);
int				ft_isdigit(int a);
size_t			ft_strlen(const char *str);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
int				ft_tolower(int c);
char			*ft_strnew(size_t size);
char			*ft_strchr(const char *s, int c);
int				ft_strcmp(const char *s1, const char *s2);
void			*ft_memset(void *b, int c, size_t len);
char			*ft_strstr(const char *big, const char *small);
char			*ft_strdup(const char *str);
int				ft_atoi(const char *str);
char			*ft_strrchr(const char *s, int c);

#endif
