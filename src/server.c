/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 22:59:58 by amouhand          #+#    #+#             */
/*   Updated: 2024/04/16 21:12:45 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
void handler(int signal)
{
	static int bits;
	static int i;

	if (signal == SIGUSR1)
		i = i | (0x01 << bits);
	bits++;
	if (bits == 8)
	{
		ft_printf("%c", i);
		bits = 0;
		i = 0;
	}
	// SIGUSR1, i = 00000000 | 00000001 = 00000001, bits = 0
	// SIGUSR1, i = 00000001 | 00000010 = 00000011, bits = 1
	// SIGUSR2, i = 00000011, bits = 2
	// SIGUSR2, i = 00000011, bits = 3
	// SIGUSR2, i = 00000011, bits = 4
	// SIGUSR1, i = 00000011 | 00100000 = 00100011, bits = 5
	// SIGUSR1, i = 00100011 | 01000000 = 01100011, bits = 6
	// SIGUSR2, i = 01100011, bits = 7
	// bits++;
	// then print the i as character from the built binary, reset the static then continue
}
int main(int ac, char *av[])
{
	int pid;
	
	(void)av;
	if (ac != 1)
	{
		ft_printf("Usage: ./server\n");
		return (1);
	}
	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	ft_printf("Waiting for messages...\n");
	while (ac == 1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		// pause function pauses till a signal arrives
		pause();
	}
	return (0);
}