/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 23:26:39 by thabeck-          #+#    #+#             */
/*   Updated: 2022/04/22 07:31:49 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	chr;
	int				len;

	chr = (unsigned char)c;
	len = ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == chr)
			return ((char *)(&s[len]));
		len--;
	}
	return (NULL);
}
