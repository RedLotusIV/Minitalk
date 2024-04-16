/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 22:59:28 by amouhand          #+#    #+#             */
/*   Updated: 2024/04/16 21:13:58 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void sendbits(int pid, char c)
{
	int i;

	i = 0;
	while (i < 8)
	{
		if (c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i++;
	}
	// 'c' = 01100011 | 1 = 00000001
	
	// 'c' = 00000001 = 1, SIGUSR1
	// 'c' = 00000010 = 1, SIGUSR1
	// 'c' = 00000000 = 0, SIGUSR2
	// 'c' = 00000000 = 0, SIGUSR2
	// 'c' = 00000000 = 0, SIGUSR2
	// 'c' = 00100000 = 1, SIGUSR1
	// 'c' = 01000000 = 1, SIGUSR1
	// 'c' = 00000000 = 0, SIGUSR2

	// sleep 100 microseconds to give enough time to send the signal
	// kill is a function that sends a signal to a pid you give
}

int main(int ac, char *av[])
{
	int pid;
	int i;

	if (ac != 3)
	{
		write(1, "Usage: ./client [PID] [Message]\n", 31);
		return (1);
	}
	else
	{
		pid = ft_atoi(av[1]);
		i = 0;
		while (av[2][i])
		{
			sendbits(pid, av[2][i]);
			i++;
		}
		sendbits(pid, '\0');
	}
	return (0);
}