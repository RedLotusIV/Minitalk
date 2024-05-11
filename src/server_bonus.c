/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:33:35 by amouhand          #+#    #+#             */
/*   Updated: 2024/05/09 01:25:25 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

void	handler(int signal, siginfo_t *info, void *context)
{
	static int	bits;
	static int	i;
	static int	pid;

	(void)context;
	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		bits = 0;
		i = 0;
	}
	if (signal == SIGUSR1)
		i |= (1 << bits);
	bits++;
	if (bits == 8)
	{
		if (!i)
			kill(info->si_pid, SIGUSR1);
		write(1, &i, 1);
		bits = 0;
		i = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sig;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	ft_printf("Waiting for messages...\n");
	sig.sa_flags = SA_SIGINFO;
	sigemptyset(&sig.sa_mask);
	sig.sa_sigaction = handler;
	while (1)
	{
		sigaction(SIGUSR1, &sig, NULL);
		sigaction(SIGUSR2, &sig, NULL);
	}
	return (0);
}
