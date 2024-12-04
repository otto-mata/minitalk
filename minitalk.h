/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:30:23 by tblochet          #+#    #+#             */
/*   Updated: 2024/12/02 11:06:52 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <stdlib.h>
# include <string.h>
# include "osgc/osgc.h"

typedef struct s_vector	t_vector;

struct					s_vector
{
	unsigned long		len;
	unsigned long		sz;
	char				*content;
};

void					pm_vector_destroy(t_vector **vec);
int						pm_vector_append(t_vector *vec, char val);
t_vector				*pm_vector_new(unsigned long start_sz);

#endif