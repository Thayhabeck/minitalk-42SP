/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 23:26:35 by thabeck-          #+#    #+#             */
/*   Updated: 2022/04/25 00:55:04 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*needle;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (((i + j) < len) && (big[i + j] == little[j]))
		{
			if (little[j + 1] == '\0')
			{
				needle = (char *)(&big[i]);
				return (needle);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
