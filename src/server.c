/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 00:15:44 by thabeck-          #+#    #+#             */
/*   Updated: 2022/10/12 22:05:08 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	server_error_msg(int pid, char *str)
{
	if (str)
		free(str);
	ft_putstr_color_fd(COLOR_RED, "\n[== SERVER ERROR ==] -> ",
		"Unexpected error\n", 2);
	kill(pid, SIGUSR2);
	exit(EXIT_FAILURE);
}

char	*print_message(char *msg)
{
	ft_putstr_fd(msg, 1);
	ft_putchar_fd('\n', 1);
	free(msg);
	return (NULL);
}

void	handler_signal_server(int signum, siginfo_t *info, void *context)
{
	static char	c = 0xFF;
	static int	bits = 0;
	static int	pid = 0;
	static char	*message = 0;

	(void)context;
	if (info->si_pid)
		pid = info->si_pid;
	if (signum == SIGUSR1)
		c ^= 0x80 >> bits;
	else if (signum == SIGUSR2)
		c |= 0x80 >> bits;
	if (++bits == 8)
	{
		if (c)
			message = ft_straddchar(message, c);
		else
			message = print_message(message);
		bits = 0;
		c = 0xFF;
	}
	if (kill(pid, SIGUSR1) == -1)
		server_error_msg(pid, message);
}

int	main(void)
{
	struct sigaction	info;
	sigset_t			mask;

	sigemptyset(&mask);
	sigaddset(&mask, SIGUSR1);
	sigaddset(&mask, SIGUSR2);
	info.sa_handler = 0;
	info.sa_flags = SA_SIGINFO;
	info.sa_mask = mask;
	info.sa_sigaction = handler_signal_server;
	sigaction(SIGUSR1, &info, NULL);
	sigaction(SIGUSR2, &info, NULL);
	ft_putstr_color_fd(COLOR_GREEN, "[== SERVER PID ==] -> ",
		ft_itoa(getpid()), 1);
	ft_putchar_fd('\n', 1);
	while (1)
		sleep(1);
}
