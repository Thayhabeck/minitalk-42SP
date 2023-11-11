/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 18:06:26 by thabeck-          #+#    #+#             */
/*   Updated: 2022/04/23 19:35:12 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_size(int nbr)
{
	int	exp;

	exp = 1;
	if (nbr < 0)
		exp++;
	while (nbr > 9 || nbr < -9)
	{
		nbr = nbr / 10;
		exp++;
	}
	return (exp);
}

int	ft_count_base(int nbr)
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

char	*ft_fillnbr(char *out, int base, int nbr)
{
	int	i;
	int	n;

	i = 0;
	if (nbr < 0)
	{
		out[i++] = '-';
		n = nbr / base;
		n *= (-1);
		out[i++] = n + '0';
		nbr = nbr % base;
		nbr *= (-1);
		base = base / 10;
	}
	while (base >= 1)
	{
		n = nbr / base;
		out[i++] = n + '0';
		nbr = nbr % base;
		base = base / 10;
	}
	return (out);
}

char	*ft_itoa(int n)
{
	int		nbr;
	int		base;
	char	*out;

	nbr = n;
	base = ft_count_size(nbr);
	out = (char *)ft_calloc((base + 1), sizeof(char));
	if (!out)
		return (NULL);
	base = ft_count_base(nbr);
	out = ft_fillnbr(out, base, nbr);
	return (out);
}
