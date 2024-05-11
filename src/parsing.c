/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:53:42 by amouhand          #+#    #+#             */
/*   Updated: 2024/05/08 21:42:56 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	atoi_check(char *str)
{
	int			i;
	int			res;

	i = 0;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			return (1);
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		res = res * 10 + (str[i] - '0');
		if (res > 4194304)
			return (1);
		i++;
	}
	return (0);
}

int	parsing(char **av)
{
	if (atoi_check(av[0]))
		return (1);
	return (0);
}
