/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokuyos <ctokuyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:57:25 by ctokuyos          #+#    #+#             */
/*   Updated: 2024/11/06 16:38:09 by ctokuyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	word_count(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s != '\0')
	{
		if (*s == c)
			s++;
		else
		{
			while (*s != c && *s != '\0')
				s++;
			count++;
		}
	}
	return (count);
}

static	size_t	word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static	char	*get_word(char const *s, char c)
{
	char	*str;
	size_t	len;
	size_t	i;

	len = word_len(s, c);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = *s;
		s++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

static	void	free_array(char **array, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(array[i]);
		i++;
	}
	free (array);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**array;

	if (!s)
		return (NULL);
	array = (char **)malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			array[i] = get_word(s, c);
			if (!array[i])
				return (free_array(array, i), NULL);
			i++;
		}
		while (*s && *s != c)
			s++;
	}
	array[i] = NULL;
	return (array);
}
