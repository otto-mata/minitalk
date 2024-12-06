/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:21:12 by tblochet          #+#    #+#             */
/*   Updated: 2024/12/06 21:24:49 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H
# include <assert.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <unistd.h>

typedef struct s_signals
{
	int				*sigs;
	size_t			n;
}					t_signals;

typedef struct s_sigpkt
{
	pid_t			src_pid;
	pid_t			dst_pid;
	unsigned char	*payload;
	size_t			payload_size;
}					t_sigpkt;

int					ft_atoi(char const *nptr);
size_t				ft_strlen(char const *s);
#endif