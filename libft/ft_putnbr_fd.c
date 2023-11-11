/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 20:52:59 by thabeck-          #+#    #+#             */
/*   Updated: 2022/04/24 07:32:15 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countbase(int nbr)
{
	int	base;

	base = 1;
	while (nbr > 9 || nbr < -9)
	{
		base = base * 10;
		nbr = nbr / 10;
	}
	return (base);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		nbr;
	int		base;
	char	out_nbr;

	nbr = n;
	base = ft_countbase(nbr);
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = n / base;
		nbr *= (-1);
		out_nbr = nbr + '0';
		ft_putchar_fd(out_nbr, fd);
		n = n % base;
		n *= (-1);
		base = base / 10;
	}
	while (base >= 1)
	{
		nbr = n / base;
		out_nbr = nbr + '0';
		ft_putchar_fd(out_nbr, fd);
		n = n % base;
		base = base / 10;
	}
}
