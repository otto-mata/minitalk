/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:05:45 by tblochet          #+#    #+#             */
/*   Updated: 2024/12/04 01:43:43 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

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

t_signals	encode(char const *data)
{
	int			i;
	int			j;
	char		byte;
	t_signals	signals;
	int			sz;

	sz = (1 << (sizeof(char) * 8 - 1));
	signals.n = (strlen(data) + 1) * 8;
	signals.sigs = malloc(signals.n * sizeof(int));
	i = 0;
	j = 0;
	while (data[i])
	{
		byte = data[i];
		while (byte)
		{
			signals.sigs[j] = !!(byte & sz);
			byte = byte << 1;
			j++;
		}
		while ((j) % 8)
			signals.sigs[j++] = 0;
		i++;
	}
	return (signals);
}

int	main(int argc, char const *argv[])
{
	int			server_pid;
	t_signals	encoded;
	size_t		i;
	int			sig;

	if (argc != 3)
		return (1);
	server_pid = atoi(argv[1]);
	encoded = encode(argv[2]);
	printf("Bits to send: %zu\n", encoded.n);
	sig = 0;
	i = 0;
	while (i < encoded.n)
	{
		if (encoded.sigs[i])
			sig = SIGUSR1;
		else
			sig = SIGUSR2;
		kill(server_pid, sig);
		usleep(50);
		i++;
	}
	free(encoded.sigs);
	return (0);
}
