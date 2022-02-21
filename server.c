/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeyirme <rdeyirme@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:26:27 by rdeyirme          #+#    #+#             */
/*   Updated: 2022/02/18 11:31:21 by rdeyirme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	action(int sig, siginfo_t *info, void *context)
{
	static int				i = 0;
	static pid_t			client_pid = 0;
	static unsigned char	c = 0;

	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	c |= (sig == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			kill(client_pid, SIGUSR2);
			client_pid = 0;
			ft_putchar_fd('\n', 1);
			return ;
		}
		ft_putchar_fd(c, 1);
		c = 0;
	}
	else
	{
		c <<= 1;
	}
}

int	main(void)
{
	struct sigaction	client;

	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	client.sa_sigaction = action;
	client.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &client, 0);
	sigaction(SIGUSR2, &client, 0);
	while (1)
		pause();
	return (0);
}
