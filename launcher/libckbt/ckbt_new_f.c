/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ckbt_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 15:26:48 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/27 16:20:12 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ckbt.h"

t_ckbt		*ckbt_new_f(size_t n)
{
	t_ckbt	*tree;

	tree = (t_ckbt *)malloc(sizeof(t_ckbt));
	if (tree == NULL)
		return (NULL);
	tree->node_size = n;
	tree->root = NULL;
	return (tree);
}
