/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pm_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:17:30 by tblochet          #+#    #+#             */
/*   Updated: 2024/12/04 01:04:45 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

t_vector	*pm_vector_new(unsigned long start_sz)
{
	t_vector	*vec;

	vec = osgc_malloc(sizeof(t_vector));
	if (!vec)
		return (0);
	vec->len = 1;
	vec->sz = start_sz;
	vec->content = osgc_calloc(vec->sz, sizeof(char));
	if (!vec->content)
		return (0);
	return (vec);
}

int	pm_vector_append(t_vector *vec, char val)
{
	while (vec->sz / 2 < (vec->len + 1))
	{
		vec->content = osgc_realloc(vec->content, vec->sz, vec->sz * 2);
		vec->sz *= 2;
	}
	if (!vec)
		return (0);
	vec->content[vec->len - 1] = val;
	vec->content[vec->len] = 0;
	vec->len++;
	return (1);
}

void	pm_vector_destroy(t_vector **vec)
{
	// (*vec)->content = 0;
	*vec = 0;
}
