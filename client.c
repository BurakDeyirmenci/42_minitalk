/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeyirme <rdeyirme@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:29:01 by rdeyirme          #+#    #+#             */
/*   Updated: 2022/02/18 11:33:45 by rdeyirme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	action(int sig)
{
	if (sig == SIGUSR2)
	{
		ft_putstr_fd("Gönderim Tamamlandı", 1);
		exit(0);
	}
}

static void	sender(int pid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_strlen(argv[2]))
		return (1);
	signal(SIGUSR1, action);
	signal(SIGUSR2, action);
	sender(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
