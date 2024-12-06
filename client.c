/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:05:45 by tblochet          #+#    #+#             */
/*   Updated: 2024/12/06 21:25:05 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"


static t_signals	encode(char const *data)
{
	int			i;
	int			j;
	char		byte;
	t_signals	signals;

	signals.n = (ft_strlen(data) + 1) * 8;
	signals.sigs = malloc(signals.n * sizeof(int));
	if (!signals.sigs)
		return ((t_signals){0});
	i = 0;
	j = 0;
	while (data[i])
	{
		byte = data[i];
		while (byte)
		{
			signals.sigs[j] = !!(byte & (1 << (sizeof(char) * 8 - 1)));
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
	server_pid = ft_atoi(argv[1]);
	encoded = encode(argv[2]);
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
