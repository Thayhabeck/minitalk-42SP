/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 00:16:37 by thabeck-          #+#    #+#             */
/*   Updated: 2023/02/04 00:07:41 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	client_error_msg(char *str)
{
	if (str)
		free(str);
	ft_putstr_color_fd(COLOR_RED, "[== CLIENT ERROR ==] -> ",
		"Unexpected error\n", 2);
	exit(EXIT_FAILURE);
}

int	send_null_char(int pid, char *str)
{
	static int	i = 0;

	if (i++ != 8)
	{
		if (kill(pid, SIGUSR1) == -1)
			client_error_msg(str);
		return (0);
	}
	return (1);
}

int	send_bit(int pid, char *str)
{
	static char	*msg = 0;
	static int	stat_pid = 0;
	static int	bits = -1;

	if (str != 0)
		msg = ft_strdup(str);
	if (!msg)
		client_error_msg(0);
	if (pid != 0)
		stat_pid = pid;
	if (msg[++bits / 8])
	{
		if (msg[bits / 8] & (0x80 >> (bits % 8)))
		{
			if (kill(stat_pid, SIGUSR2) == -1)
				client_error_msg(msg);
		}
		else if (kill(stat_pid, SIGUSR1) == -1)
			client_error_msg(msg);
		return (0);
	}
	if (!send_null_char(stat_pid, msg))
		return (0);
	free(msg);
	return (1);
}

void	handler_signal_client(int signal)
{
	int	end;

	end = 0;
	if (signal == SIGUSR1)
		end = send_bit(0, 0);
	else if (signal == SIGUSR2)
	{
		ft_putstr_color_fd(COLOR_RED, "[== CLIENT ERROR ==] -> ",
			"Unexpected server error\n", 2);
		exit(EXIT_FAILURE);
	}
	if (end != 0)
	{
		ft_putstr_color_fd(COLOR_GREEN, "[== CLIENT SUCCESS ==] -> ",
			"Server received the message\n", 1);
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_str_isnumeric(argv[1]))
	{
		ft_putstr_color_fd(COLOR_RED, "[== CLIENT ERROR ==] -> ",
			"Invalid Arguments\n", 2);
		ft_putstr_color_fd(COLOR_YELLOW, "[== CLIENT TIP ==] -> ",
			"Try this: [./client <SERVER_PID> <MSG>]\n", 2);
		exit(EXIT_FAILURE);
	}
	if (ft_atoi(argv[1]) <= 0)
	{
		ft_putstr_color_fd(COLOR_RED, "[== CLIENT ERROR ==] -> ",
			"<SERVER_PID> can't be 0\n", 2);
		ft_putstr_color_fd(COLOR_YELLOW, "[== CLIENT TIP ==] -> ",
			"Try this: [./client <SERVER_PID> <MSG>]\n", 2);
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR1, handler_signal_client);
	signal(SIGUSR2, handler_signal_client);
	send_bit(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
}
