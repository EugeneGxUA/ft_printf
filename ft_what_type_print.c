/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_what_type_print.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaragul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 18:26:30 by egaragul          #+#    #+#             */
/*   Updated: 2017/03/05 21:40:32 by egaragul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*ft_strdup_mod(const char *str)
{
	size_t			i;
	char			*dest;

	if (!str)
	{
		dest = (char*)malloc(sizeof(char) * 6 + 1);
		dest = "(null)";
		return (dest);
	}
	i = 0;
	dest = (char*)malloc(sizeof(*dest) * ((ft_strlen(str)) + 1));
	if (!dest)
		return (NULL);
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void				ft_chr_args(va_list arg, t_struct *parts)
{
	if (parts->modif == NULL)
	{
		if (parts->type == 's')
			parts->arg_str = ft_strdup_mod(va_arg(arg, char*));
	}
	if (parts->type == 's' && parts->modif != NULL)
		parts->type = 'S';
	if (parts->type == 'S')
		parts->arg_str = ft_strdup_wint(va_arg(arg, wint_t*));
	else if (parts->type == 'c')
		parts->arg_str = ft_memset(ft_strnew(1),
								((char)va_arg(arg, int)), 1);
	else if (parts->type == 'C')
		parts->arg_str = ft_memset(ft_strnew(1),
								((unsigned char)va_arg(arg, int)), 1);
}

void				ft_digit_did_args(va_list arg, t_struct *parts)
{
	if (parts->modif == NULL && parts->type != 'D')
		parts->arg_str = ft_itoa_base((long long)va_arg(arg, int), 10);
	else if (ft_strcmp(parts->modif, "hh") == 0)
		parts->arg_str = ft_itoa_base((long long)(char)va_arg(arg, int), 10);
	else if (ft_strchr(parts->modif, 'h') != 0)
		parts->arg_str = ft_itoa_base((long long)(short int)
										va_arg(arg, int), 10);
	else if (ft_strcmp(parts->modif, "ll") == 0)
		parts->arg_str = ft_itoa_base((va_arg(arg, long long int)), 10);
	else if (ft_strchr(parts->modif, 'l') || parts->type == 'D')
		parts->arg_str = ft_itoa_base((long long)va_arg(arg, long int), 10);
	else if (ft_strchr(parts->modif, 'j') != 0)
		parts->arg_str = ft_itoa_base((long long)va_arg(arg, intmax_t), 10);
	else if (ft_strchr(parts->modif, 'z') != 0)
		parts->arg_str = ft_itoa_base((long long)va_arg(arg, size_t), 10);
}

void				ft_write_digit_modificators(va_list arg,
		t_struct *parts, int base)
{
	if (ft_strchr("uUoOxX", parts->type) && parts->modif == NULL)
		parts->arg_str = ft_itoa_base_unsigned((unsigned long long)
				va_arg(arg, unsigned int), base);
	else if (ft_strcmp(parts->modif, "hh") == 0)
		parts->arg_str = ft_itoa_base_unsigned((unsigned long long)
				((unsigned char)va_arg(arg, unsigned int)), base);
	else if (ft_strchr(parts->modif, 'h') != 0)
		parts->arg_str = ft_itoa_base_unsigned((unsigned long long)
				((unsigned short int)va_arg(arg, unsigned int)), base);
	else if (ft_strcmp(parts->modif, "ll") == 0)
		parts->arg_str =
			ft_itoa_base_unsigned(va_arg(arg, unsigned long long int), base);
	else if (ft_strchr(parts->modif, 'l') || ft_strchr("OU", parts->type))
		parts->arg_str = ft_itoa_base_unsigned((unsigned long long)
				va_arg(arg, unsigned long int), base);
	else if (ft_strchr(parts->modif, 'j') != 0)
		parts->arg_str = ft_itoa_base_unsigned((unsigned long long)va_arg(arg,
					uintmax_t), base);
	else if (ft_strchr(parts->modif, 'z') != 0)
		parts->arg_str = ft_itoa_base_unsigned((unsigned long long)
				va_arg(arg, size_t), base);
	if (parts->type == 'x')
		parts->arg_str = ft_tolowstr(parts->arg_str);
}

void				ft_what_type_print(va_list arg, t_struct *parts)
{
	int				base;

	base = 10;
	if (ft_strchr("DdioOuUxX", parts->type))
	{
		if (parts->type == 'd' || parts->type == 'i' || parts->type == 'D')
			ft_digit_did_args(arg, parts);
		else if (ft_strchr("uUoOxX", parts->type))
		{
			if (parts->type == 'u' || parts->type == 'U')
				base = 10;
			else if (parts->type == 'o' || parts->type == 'O')
				base = 8;
			else if (parts->type == 'x' || parts->type == 'X')
				base = 16;
			ft_write_digit_modificators(arg, parts, base);
		}
	}
	else if (ft_strchr("sScC", parts->type))
		ft_chr_args(arg, parts);
}
