/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_full_prog.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 15:22:07 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/23 15:22:08 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"

t_cks	sh_full_prog(t_cks prog)
{
	t_cks		full;

	if ((full = cks_dup(prog)) == NULL)
		return (NULL);
	if (full[0] == '/' || (full[0] == '.' && full[1] == '/'))
		return (full);
	return (sh_full_prog_from_path(full));
}
