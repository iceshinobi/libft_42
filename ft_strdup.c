/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokuyos <ctokuyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:00:56 by ctokuyos          #+#    #+#             */
/*   Updated: 2024/11/06 16:32:51 by ctokuyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*strcp;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s);
	strcp = (char *)malloc((len + 1) * sizeof(char));
	if (!strcp)
		return (NULL);
	while (s[i] != '\0')
	{
		strcp[i] = s[i];
		i++;
	}
	strcp[i] = '\0';
	return (strcp);
}
