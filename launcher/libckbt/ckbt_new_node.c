/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ckbt_new_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 15:27:28 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/27 16:20:23 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ckbt.h"

t_ckbt_node	*ckbt_new_node(t_ckbt *tree, void *data)
{
	t_ckbt_node		*node;

	node = (t_ckbt_node *)malloc(
		sizeof(t_ckbt_node) + tree->node_size - sizeof(void *));
	if (node == NULL)
		return (node);
	ckstd_memcpy(&node->data, data, tree->node_size);
	node->left = NULL;
	node->right = NULL;
	return (node);
}
