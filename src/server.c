/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 22:59:58 by amouhand          #+#    #+#             */
/*   Updated: 2024/04/22 05:03:02 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	handler(int signal)
{
	static int	bits;
	static int	i;

	if (signal == SIGUSR1)
		i |= (1 << bits);
	bits++;
	if (bits == 8)
	{
		write(1, &i, 1);
		bits = 0;
		i = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	ft_printf("Waiting for messages...\n");
	while (1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
	}
	return (0);
}
