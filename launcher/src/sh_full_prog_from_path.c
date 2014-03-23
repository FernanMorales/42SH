/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_full_prog_from_path.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 15:22:01 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/23 15:22:02 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"

t_cks	sh_full_prog_from_path(t_cks full)
{
	const char	*path;
	t_cks		cur;
	t_ckl		*parts;
	t_ckl_item	*item;

	if ((path = getenv("PATH")) == NULL
		|| (parts = cks_split(path, ":", 0)) == NULL)
		return (NULL);
	item = parts->first;
	while (item)
	{
		cur = cks_dup(full);
		cur = cks_prepend(cur, "/");
		cur = cks_prepend(cur, ckl_data(t_cks, item));
		if (ckf_access(cur, X_OK) == 0)
			return (cur);
		cks_free(cur);
		item = item->next;
	}
	return (NULL);
}
