/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtortera <dtortera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 16:52:34 by dtortera          #+#    #+#             */
/*   Updated: 2014/03/19 19:35:36 by pvarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

void	dont_move(t_lst *l, t_lst_histo *histo)
{
	(void)l;
	(void)histo;
}

const t_mov_functions	g_mov_functions[] =
{
	{K_AR_L,		move_left},
	{K_AR_R,		move_right},
	{K_AR_U,		move_up},
	{K_AR_D,		move_down},
	{K_DEL_L,		del_one},
	{K_DEL_R,		del_one},
	{NULL,		dont_move}
};
