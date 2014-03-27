/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvarin <pvarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 17:01:34 by pvarin            #+#    #+#             */
/*   Updated: 2013/11/30 19:06:28 by pvarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tail(int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_filler(int i, int n, int sign)
{
	char	*str;

	str = ft_strnew(i);
	if (str == NULL)
		return (NULL);
	while (i-- > 0)
		{
			str[i] = (n % 10 + '0');
			n /= 10;
		}
		if (sign < 0)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	int		sign;
	int		i;
	char	*str;

	i = 0;
	sign = 1;
	if (n == -2147483648)
	{
		str = ft_strnew(11);
		if (str == NULL)
			return (NULL);
		ft_strcpy(str, "-2147483648");
		return (str);
	}
	if (n < 0)
	{
		sign = -1;
		n *= sign;
		i++;
	}
	i += ft_tail(n);
	str = ft_filler(i, n, sign);
	return (str);
}
