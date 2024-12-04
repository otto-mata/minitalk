/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:00:55 by tblochet          #+#    #+#             */
/*   Updated: 2024/12/04 01:42:35 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <assert.h>
#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void	signal_handler(int sig)
{
	static char		cbuf = 0;
	static int		recvd = 0;
	static t_vector	*sbuf = 0;

	if (!sbuf)
		sbuf = pm_vector_new(1);
	if (sig == SIGUSR1 || (sig == SIGUSR2))
	{
		cbuf <<= 1;
		cbuf |= (sig == SIGUSR1);
	}
	if (recvd % 8 == 7)
	{
		pm_vector_append(sbuf, cbuf);
		if (cbuf == 0)
		{
			printf("%s\n", sbuf->content);
			pm_vector_destroy(&sbuf);
		}
		cbuf = 0;
	}
	recvd++;
}

int	main(void)
{
	pid_t	server_pid;

	server_pid = getpid();
	printf("Server PID: %d\n", server_pid);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		;
	osgc_clear();
	return (0);
}
