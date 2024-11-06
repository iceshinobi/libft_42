/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokuyos <ctokuyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:31:11 by ctokuyos          #+#    #+#             */
/*   Updated: 2024/11/06 15:11:41 by ctokuyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*conversion(int len)
{
	char	*temp;

	temp = malloc((len + 1) * sizeof (char));
	if (!temp)
		return (NULL);
	temp[0] = '\0';
	return (temp);
}

static	int	int_len(long nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		count++;
		nbr = -nbr;
	}
	if (nbr == 0)
		count++;
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*res;
	long	nbr;
	int		len;
	int		i;

	nbr = n;
	len = int_len(nbr);
	res = conversion(len);
	if (!res)
		return (NULL);
	if (nbr < 0)
		nbr = -nbr;
	i = len - 1;
	if (nbr == 0)
		res[i--] = '0';
	while (nbr != 0)
	{
		res[i--] = ((nbr % 10) + '0');
		nbr = nbr / 10;
	}
	if (n < 0)
		res[0] = '-';
	res[len] = '\0';
	return (res);
}
