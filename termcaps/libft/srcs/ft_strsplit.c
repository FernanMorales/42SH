/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvarin <pvarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 14:31:33 by pvarin            #+#    #+#             */
/*   Updated: 2013/12/02 18:18:48 by pvarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int				ft_count_words(char const *s, char c)
{
	int			i;
	int			words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] == c)
			while (s[i] == c)
				i++;
		else
		{
			while (s[i] != c && s[i])
				i++;
			words++;
		}
	}
	return (words);
}

int				ft_size(char const *s, int i, char c)
{
	int			j;

	j = 0;
	while (s[i] != c && s[i])
	{
		j++;
		i++;
	}
	return (j);
}

static char		*ft_filler(char const *s, int *i, char c)
{
	char		*str;
	int			j;

	j = 0;
	str = ft_strnew(ft_size(s, *i, c));
	while (s[*i] != c && s[*i])
	{
		str[j] = s[*i];
		++*i;
		j++;
	}
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	int			i;
	int			j;
	char		**tab;

	i = 0;
	j = 0;
	if (!s || !c)
		return (NULL);
	tab = (char **)ft_memalloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (tab == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			tab[j] = ft_filler(s, &i, c);
			j++;
		}
	}
	tab[j] = 0;
	return (tab);
}
