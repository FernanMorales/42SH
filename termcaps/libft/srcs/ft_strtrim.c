/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvarin <pvarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 16:58:20 by pvarin            #+#    #+#             */
/*   Updated: 2013/12/02 18:11:48 by pvarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		len;
	char	*new;

	if (!s)
		return (NULL);
	len = 0;
	while ((*s == ' ' || *s == '\n' || *s == '\t') && *s)
		s++;
	len = ft_strlen(s) - 1;
	while ((s[len] == ' ' || s[len] == '\n' || s[len] == '\t') && len > 0)
		len--;
	new = ft_strnew(len + 1);
	if (new == NULL)
		return (NULL);
	new = ft_strncpy(new, s, len + 1);
	return (new);
}
