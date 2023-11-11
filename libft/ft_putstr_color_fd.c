/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_color_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 00:20:45 by thabeck-          #+#    #+#             */
/*   Updated: 2022/10/12 21:12:29 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_color_fd(char *color, char *p, char *m, int fd)
{
	ft_putstr_fd(color, fd);
	ft_putstr_fd(p, fd);
	ft_putstr_fd(COLOR_GREY, fd);
	ft_putstr_fd(m, fd);
	ft_putstr_fd(COLOR_RESET, fd);
}
