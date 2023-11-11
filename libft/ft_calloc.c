/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:10:08 by thabeck-          #+#    #+#             */
/*   Updated: 2022/05/04 01:10:58 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	count;

	count = nmemb * size;
	if (count)
	{
		if ((count / nmemb) != size)
			return (NULL);
		ptr = malloc(count);
		if (ptr == NULL)
			return (NULL);
		ft_bzero(ptr, count);
	}
	else
		ptr = malloc(0);
	return (ptr);
}
