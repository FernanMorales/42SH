/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fernan.moralesayuso@gmail>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 00:18:22 by fmorales          #+#    #+#             */
/*   Updated: 2014/03/18 23:20:38 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ftsh.h"

void	print_header(void)
{
	ft_putstr("\n\n");
	/*
	ft_putstr("\t\t\t\t\t     :::   :::   ::::::::::: ::::    ::: ");
	ft_putstr("::::::::::: ");
	ft_putstr("::::::::  :::    ::: :::::::::: :::        :::\n");
	ft_putstr("\t\t\t\t\t   :+:+: :+:+:      :+:     :+:+:   :+:     ");
	ft_putstr(":+:    ");
	ft_putstr(":+:    :+: :+:    :+: :+:        :+:        :+:\n");
	ft_putstr("\t\t\t\t\t +:+ +:+:+ +:+     +:+     :+:+:+  +:+     ");
	ft_putstr("+:+    +:+");
	ft_putstr("\t     +:+    +:+ +:+        +:+        +:+\n");
	ft_putstr("\t\t\t\t        +#+  +:+  +#+     +#+     +#+ +:+ ");
	ft_putstr("+#+     +#+    ");
	ft_putstr("+#++:++#++ +#++:++#++ +#++:++#   +#+        +#+\n");
	ft_putstr("\t\t\t\t       +#+       +#+     +#+     +#+  +#+#+#");
	ft_putstr("	 +#+\t       +#+ ");
	ft_putstr("+#+    +#+ +#+        +#+        +#+\n");
	ft_putstr("\t\t\t\t      #+#       #+#     #+#     #+#   #+#+#");
	ft_putstr("\t#+#    #+#    #+# #+#\t ");
	ft_putstr("#+# #+#        #+#        #+#\n");
	ft_putstr("\t\t\t\t     ###       ### ########### ###");
	ft_putstr("    #### ########### ########  ###\t");
	ft_putendl("### ########## ########## ##########");
	ft_putendl("\n\n\t\t\t\t\t\t\t\t\t               v 2.0\n\n\n");*/
}

void	print_prompt(t_env e)
{
	write(1, "\n", 1);
	ft_putstr(ft_strsub(e.env[e.j], 4, ft_strlen(e.env[e.j])));
	write(1, "\n", 1);
	write(1, " >> ", 4);
}

void	print_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		ft_putendl(env[i]);
		i++;
	}
}

void	print_cmd(t_list *lst)
{
	while (lst != NULL)
	{
		print_env(lst->content);
		lst = lst->next;
	}
}
