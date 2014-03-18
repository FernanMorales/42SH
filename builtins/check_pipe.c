/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fernan.moralesayuso@gmail>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 21:08:26 by fmorales          #+#    #+#             */
/*   Updated: 2014/01/26 21:10:53 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "ftsh.h"

int			count_str(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		;
	return (i);
}

int			check_pipe(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_strcmp("<", str[i]) == 0 || ft_strcmp(">", str[i]) == 0)
			return (2);
		if (ft_strcmp("|", str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

char		**trim2(char **str)
{
	int		i;
	int		j;
	char	**buf;

	i = 0;
	j = 0;
	buf = (char **)malloc(sizeof(char *) * count_str(str));
	while (ft_strcmp(str[i], "|") != 0)
		i++;
	i++;
	while (str[i + j] != NULL)
	{
		buf[j] = str[i + j];
		j++;
	}
	buf[j] = NULL;
	return (buf);
}

char		**trim(char **str)
{
	int		i;
	char	**buf;

	i = 0;
	buf = (char **)malloc(sizeof(char *) * count_str(str));
	while (ft_strcmp(str[i], "|") != 0)
	{
		buf[i] = str[i];
		i++;
	}
	buf[i] = NULL;
	return (buf);
}
