/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fernan.moralesayuso@gmail>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 00:38:45 by fmorales          #+#    #+#             */
/*   Updated: 2013/12/29 01:01:25 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

void	print_cderror(char *var, int i)
{
	if (i == 1)
		ft_putstr("cd:cd:10: not a directory: ");
	if (i == 2)
		ft_putstr("cd:cd:10: permission denied: ");
	if (i == 3)
		ft_putstr("cd:cd:10: string not in pwd: ");
	if (i == 4)
		ft_putstr("cd:cd:10: no such file or directory: ");
	ft_putendl(var);
}
