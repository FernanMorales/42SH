/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ckl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 21:53:17 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/27 16:35:51 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CKL_H

# define CKL_H

# include <string.h>
# include <stdlib.h>
# include "ckstd.h"

typedef struct						s_ckl_item
{
	struct s_ckl_item				*prev;
	struct s_ckl_item				*next;
	void							*data;
}									t_ckl_item;

typedef struct						s_ckl
{
	size_t							length;
	size_t							item_size;
	t_ckl_item						*first;
	t_ckl_item						*last;
}									t_ckl;

# define ckl_data(type, item) (*(type *)&(item)->data)
void				ckl_append(t_ckl *list, void *data);
t_ckl_item			*ckl_new_item(t_ckl *list, void *data);
# define ckl_new(type) ckl_new_f(sizeof(type))
t_ckl				*ckl_new_f(size_t item_size);
void				ckl_free_item(t_ckl_item *item);
void				ckl_free_items(t_ckl *list, void (*callback)(void *data));
void				ckl_free(t_ckl *list);
void				ckl_withdraw(t_ckl *list, t_ckl_item *item);
void				ckl_append_item(t_ckl *list, t_ckl_item *prev, void *data);
void				ckl_prepend_item(t_ckl *list, t_ckl_item *prev, void *data);

#endif
