/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 22:57:46 by amouhand          #+#    #+#             */
/*   Updated: 2024/05/08 21:36:08 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <signal.h>
# include <bits/sigaction.h>
# include <unistd.h>
# include "../libft/libft.h"

int	parsing(char **av);
int	atoi_check(char *str);

#endif
