/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokuyos <ctokuyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 08:54:07 by ctokuyos          #+#    #+#             */
/*   Updated: 2024/11/06 16:22:36 by ctokuyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	src;
	unsigned char	*dest;
	size_t			i;

	src = (unsigned char)c;
	dest = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		dest[i] = src;
		i++;
	}
	return (dest);
}
