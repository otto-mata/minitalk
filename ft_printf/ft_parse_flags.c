/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:10:46 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/28 12:53:40 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_flags(char const *fmt, va_list args, t_formatter *fmtr)
{
	size_t			j;
	t_list			*node;
	size_t const	sz = ft_strlen(fmt);

	j = 0;
	while (j < sz)
	{
		if (fmt[j] == '%')
		{
			node = ft_lstnew(ft_parse_arg(fmt[++j], args));
			if (!node)
				return ;
			ft_lstadd_back(&fmtr->flags, node);
		}
		j++;
	}
}
