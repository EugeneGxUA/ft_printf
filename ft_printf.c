/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaragul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 09:29:27 by egaragul          #+#    #+#             */
/*   Updated: 2017/03/05 17:32:04 by egaragul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_print(int len)
{
	int			i;

	i = 0;
	while (i < len)
	{
		ft_putchar_count('%');
		i++;
	}
}

static void		ft_print_perc(char **s)
{
	int			i;
	int			perc;

	i = 0;
	perc = 0;
	while (**s == '%' && **s != '\0')
	{
		(*s)++;
		perc++;
	}
	if (perc > 2)
		ft_print(perc / 2);
	if (perc % 2 != 0)
		(*s)--;
	else if (perc == 2)
		ft_print(1);
}

void			ft_print_format(char **s)
{
	while (**s != '%' && **s != '\0')
	{
		ft_putchar_count(**s);
		(*s)++;
		if (**s == '%' && *(*s + 1) == '%')
			ft_print_perc(s);
	}
}

int				ft_printf(const char *format, ...)
{
	char		*s;
	va_list		arg;
	int			i;

	i = 0;
	va_start(arg, format);
	s = (char*)format;
	g_counter = 0;
	while (*s != '\0')
	{
		if (*s == '%' && *(s + 1) == '%')
			ft_print_perc(&s);
		ft_print_format(&s);
		if (*(s + 1) == '\0' || *s++ == '\0')
			break ;
		ft_init_struct(&s, arg);
		if (*s != '\0')
			s++;
	}
	va_end(arg);
	return (g_counter);
}
