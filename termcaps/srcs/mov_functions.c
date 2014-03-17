/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtortera <dtortera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 16:52:34 by dtortera          #+#    #+#             */
/*   Updated: 2014/03/15 22:19:27 by pvarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

void	dont_move(t_lst *l)
{
	(void)l;
}

const t_mov_functions	g_mov_functions[] =
{
	{K_AR_L,		move_left},
	{K_AR_R,		move_right},
	{K_AR_U,		move_up},
	{K_AR_D,		move_down},
	{K_DEL_L,		del_one},
	{K_DEL_R,		del_one},
	{K_RETURN,		save_in_string},
	{NULL,		dont_move}
};
