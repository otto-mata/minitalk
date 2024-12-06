/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pm_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:17:30 by tblochet          #+#    #+#             */
/*   Updated: 2024/12/06 21:33:42 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_string	*pm_string_new(unsigned long start_sz)
{
	t_string	*str;

	str = osgc_malloc(sizeof(t_string));
	if (!str)
		return (0);
	str->len = 1;
	str->sz = start_sz;
	str->content = osgc_calloc(str->sz, sizeof(char));
	if (!str->content)
		return (0);
	return (str);
}

int	pm_string_append(t_string *str, char val)
{
	while (str->sz / 2 < (str->len + 1))
	{
		str->content = osgc_realloc(str->content, str->sz, str->sz * 2);
		str->sz *= 2;
	}
	if (!str)
		return (0);
	str->content[str->len - 1] = val;
	str->content[str->len] = 0;
	str->len++;
	return (1);
}

void	pm_string_destroy(t_string **str)
{
	*str = 0;
}
