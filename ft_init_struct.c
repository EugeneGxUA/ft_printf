/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaragul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 12:12:25 by egaragul          #+#    #+#             */
/*   Updated: 2017/03/05 17:12:15 by egaragul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_check_type(char **s)
{
	int			i;

	i = 0;
	while (ft_strchr("sSpdDioOuUxXcC", (*s)[i]) == NULL && (*s)[i] != '%')
	{
		if (ft_isalpha((*s)[i]))
		{
			if (ft_strchr("sSpdDioOuUxXcC", (*s)[i]) == NULL &&
					ft_strchr("hljz", (*s)[i]) == NULL)
				break ;
		}
		i++;
	}
	if (ft_strchr("sSpdDioOuUxXcC", (*s)[i]) && (*s)[i] != '\0')
		return (1);
	return (0);
}

static int		ft_rec_str(t_struct *parts, char **s)
{
	int			i;
	int			count;
	char		*tmp;

	i = 0;
	count = 0;
	tmp = *s;
	while (ft_strchr("sSpdDioOuUxXcC", **s) == NULL)
	{
		count++;
		(*s)++;
	}
	parts->type = **s;
	parts->string = (char*)malloc(sizeof(char) * (count + 1));
	if (!parts->string)
		parts->string = NULL;
	while (i <= count)
		parts->string[i++] = *tmp++;
	parts->string[i] = '\0';
	return (1);
}

static void		ft_check(t_struct *parts, char **s, int *flag)
{
	while (**s != '\0')
	{
		*flag = 0;
		if (**s == '%')
			(*s)++;
		if (ft_check_type(s))
		{
			if (ft_rec_str(parts, s))
				return ;
		}
		else
		{
			ft_check_for_type(s, parts);
			*flag = 1;
			parts->flag_zero = 0;
			parts->flag_minus = 0;
			parts->wid = -1;
			free(parts->arg_str);
			free(parts->string);
		}
	}
}

static int		ft_check_for_perc_only(char **s, t_struct *parts)
{
	int			i;
	int			flag;
	int			perc;

	flag = 0;
	i = 0;
	perc = 0;
	while ((*s)[i] != '\0')
	{
		if (ft_isalpha((*s)[i]))
			return (flag);
		if ((*s)[i] == '%')
			perc++;
		i++;
	}
	if (perc > 0)
	{
		flag = 2;
		ft_for_perc_rec_only(s, parts, i);
		(*s) -= 2;
	}
	return (flag);
}

void			ft_init_struct(char **s, va_list arg)
{
	t_struct	*parts;
	int			count;
	int			flag;

	flag = 0;
	count = 0;
	parts = (t_struct*)malloc(sizeof(t_struct));
	parts->type = '\0';
	parts->modif = NULL;
	parts->wid = -1;
	parts->prec = -1;
	parts->flag_zero = 0;
	parts->flag_sharp = 0;
	parts->flag_space = 0;
	parts->flag_minus = 0;
	parts->flag_plus = 0;
	if (ft_check_for_perc_only(s, parts))
		return ;
	ft_check(parts, s, &flag);
	if (flag == 1)
		return ;
	ft_begin(parts, arg);
}
