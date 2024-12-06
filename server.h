/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:30:23 by tblochet          #+#    #+#             */
/*   Updated: 2024/12/06 21:33:30 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
# include "osgc/osgc.h"
# include <stdlib.h>
# include <string.h>

typedef struct s_string	t_string;

struct					s_string
{
	unsigned long		len;
	unsigned long		sz;
	char				*content;
};

void					pm_string_destroy(t_string **vec);
int						pm_string_append(t_string *vec, char val);
t_string				*pm_string_new(unsigned long start_sz);
void					*ft_calloc(size_t nmemb, size_t sz);

#endif