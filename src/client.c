/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 22:59:28 by amouhand          #+#    #+#             */
/*   Updated: 2024/05/11 19:16:33 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	sendbits(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(450);
		i++;
	}
}

int	main(int ac, char *av[])
{
	int	pid;
	int	i;

	if (ac != 3 || parsing(av + 1) || kill(ft_atoi(av[1]), 0) == -1)
		return (write(2, "Usage: ./client [PID] [Message]\n", 31), 1);
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
