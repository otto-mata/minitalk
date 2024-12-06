/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_formatted.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:11:44 by tblochet          #+#    #+#             */
/*   Updated: 2024/12/02 08:11:08 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_value(char const *s, t_list **f)
{
	int	len;

	if (*(s + 1) == 'c')
	{
		len = 1;
		ft_putchar_fd(*(*f)->val, 1);
	}
	else
	{
		len = ft_strlen((*f)->val);
		ft_putstr_fd((*f)->val, 1);
	}
	*f = (*f)->next;
	return (len);
}

int	ft_display_formatted(char const *fmt, t_list *f)
{
	size_t			i;
	int				len;
	size_t const	sz = ft_strlen(fmt);

	i = 0;
	len = 0;
	while (i < sz)
	{
		if (fmt[i] == '%' && f)
		{
			len += ft_print_value(&fmt[i], &f);
			i += 2;
		}
		else
		{
			ft_putchar_fd(fmt[i], 1);
			len++;
			i++;
		}
	}
	return (len);
}
