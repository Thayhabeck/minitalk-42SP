/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 07:25:47 by thabeck-          #+#    #+#             */
/*   Updated: 2022/04/24 19:38:42 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fillcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{
		while (src[i] && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}

char	*ft_makesplit(char const *s, char c, int n)
{
	int		start;
	int		end;
	int		count;
	char	*str;

	count = 0;
	end = 0;
	while (s[end] && count <= n)
	{
		if (s[end] != c && s[end])
		{
			start = end;
			count++;
			while (s[end] != c && s[end])
				end++;
		}
		else
			end++;
	}
	str = (char *)malloc((end - start + 1) * sizeof(char));
	str = ft_fillcpy(str, s + start, (end - start + 1));
	return (str);
}

int	counter(char const *s, char c)
{
	int		count_index;
	int		i;

	i = 0;
	count_index = 0;
	while (s[i])
	{
		if (s[i] != c && s[i])
		{
			count_index++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count_index);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		count_index;
	int		count_str;

	if (!s)
		return (NULL);
	count_index = counter(s, c);
	split = (char **)malloc(++count_index * sizeof(char *));
	if (!split)
		return (NULL);
	count_str = 0;
	while (count_str < count_index - 1)
	{
		split[count_str] = ft_makesplit(s, c, count_str);
		count_str++;
	}
	split[count_str] = NULL;
	return (split);
}
