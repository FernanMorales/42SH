/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ckbt.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 01:16:08 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/27 16:39:42 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CKBT_H

# define CKBT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "ckstd.h"

typedef struct			s_ckbt_node
{
	struct s_ckbt_node	*right;
	struct s_ckbt_node	*left;
	void				*data;
}						t_ckbt_node;

typedef struct			s_ckbt
{
	t_ckbt_node			*root;
	size_t				node_size;
}						t_ckbt;

# define ckbt_data(type, node) (*(type *)&(node)->data)
# define ckbt_new(type) ckbt_new_f(sizeof(type))
t_ckbt					*ckbt_new_f(size_t n);
void					ckbt_free(t_ckbt *tree);
void					ckbt_free_node(t_ckbt_node *node);
void					ckbt_debug(t_ckbt *tree,
							void (*f)(t_ckbt *, t_ckbt_node *));
t_ckbt_node				*ckbt_new_node(t_ckbt *tree, void *data);

#endif
