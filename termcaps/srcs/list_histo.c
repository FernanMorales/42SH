/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_histo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvarin <pvarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 13:56:10 by pvarin            #+#    #+#             */
/*   Updated: 2014/03/19 18:43:56 by pvarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"
#include "libft.h"
#include <stdlib.h>

/*
t_lst		**rea_histo(t_lst *l, t_lst *new)
{
    int		i;
    int		j;
    t_lst	**realoc;

    i = -1;
    realoc = (t_lst **)malloc(sizeof(t_lst *) * (l->histo->size_lst  + 1));
    while (++i > l->histo->size_lst)
    {
        l->histo[i] = cpy_histo(l, i);
    }
    l->histo[i] = new;
    return (realoc);
}

t_lst		*cpy_histo(t_lst *l, int i)
{
    int		i;
    t_lst	*cpy;

    i = -1;
    t_lst = (t_lst *)malloc(sizeof(t_lst));
    while (i < )
}
*/

void        add_histo(t_lst_histo  *histo, t_lst *l)
{
	t_elem_histo		*new;

	if (histo->first == NULL)
	{
		new = (t_elem_histo *)malloc(sizeof(t_elem_histo));
		new->his = l;
		new->next = NULL;
		new->prev = NULL;
		histo->first = new;
		histo->last = new;
	}
	else
	{
		new = (t_elem_histo *)malloc(sizeof(t_elem_histo));
		new->his = l;
		new->next = NULL;
		new->prev = histo->last;
		histo->last = new;
	}
}
