/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ckbt_debug.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 15:26:59 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/23 15:27:00 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ckbt.h"

static void	ckbt_debug_rec(t_ckbt *tree, t_ckbt_node *node,
				void (*f)(t_ckbt *, t_ckbt_node *), int depth)
{
	int		i;

	if (node != NULL)
	{
		f(tree, node);
		write(2, "\n", 1);
		if (node->left != NULL)
		{
			i = 0;
			while (i++ < depth)
				write(2, "|\t", 2);
			write(2, "L ", 2);
			ckbt_debug_rec(tree, node->left, f, depth + 1);
		}
		if (node->right != NULL)
		{
			i = 0;
			while (i++ < depth)
				write(2, "|\t", 2);
			write(2, "R ", 2);
			ckbt_debug_rec(tree, node->right, f, depth + 1);
		}
	}
}

void		ckbt_debug(t_ckbt *tree, void (*f)(t_ckbt *, t_ckbt_node *))
{
	ckbt_debug_rec(tree, tree->root, f, 1);
}
