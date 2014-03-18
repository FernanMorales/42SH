/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fernan.moralesayuso@gmail>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 05:17:46 by fmorales          #+#    #+#             */
/*   Updated: 2013/12/29 23:32:16 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

void	set_env(t_env *e, char **var)
{
	int	i;

	i = 0;
	var[1] = ft_strjoin(var[1], "=");
	while (ft_strstr(e->env[i], var[1]) == NULL && e->env[i + 1] != NULL)
		i++;
	if (e->env[i + 1] == NULL && ft_strstr(e->env[i], var[1]) == NULL)
		e->env[i + 1] = ft_strjoin(var[1], var[2]);
	else
		e->env[i] = ft_strjoin(var[1], var[2]);
}

void	unset_env(t_env *e, char **var)
{
	int	i;

	i = 0;
	var[1] = ft_strjoin(var[1], "=");
	while (ft_strstr(e->env[i], var[1]) == NULL && e->env[i + 1] != NULL)
		i++;
	if (e->env[i + 1] == NULL && ft_strstr(e->env[i], var[1]) != NULL)
		e->env[i] = NULL;
	if (ft_strstr(e->env[i], var[1]) != NULL && e->env[i + 1] != NULL)
	{
		while (e->env[i + 1] != NULL)
		{
			e->env[i] = ft_strdup(e->env[i + 1]);
			i++;
		}
		e->env[i] = NULL;
	}
}
