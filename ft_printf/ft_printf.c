/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:01:13 by tblochet          #+#    #+#             */
/*   Updated: 2024/12/06 10:38:25 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *fmt, ...)
{
	va_list		args;
	t_formatter	fmtr;
	int			len;

	if (!fmt)
		return (-1);
	va_start(args, fmt);
	fmtr.err = 0;
	fmtr.flags = 0;
	ft_count_flags(fmt, &fmtr);
	if (fmtr.n < 0)
		return (-1);
	ft_parse_flags(fmt, args, &fmtr);
	len = ft_display_formatted(fmt, fmtr.flags);
	if (fmtr.err)
		len = -1;
	ft_lstclear(&fmtr.flags, free);
	va_end(args);
	return (len);
}
