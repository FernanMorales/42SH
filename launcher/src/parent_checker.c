/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 18:01:57 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/27 15:02:18 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "ckl.h"
#include "am.h"
#include "sh.h"
#include "ckstd.h"

static size_t	st_check_skipped(const char *src, t_ckl *stack)
{
	if (*src == '\\')
		return (2);
	if (*src != '\'' && stack->last
		&& ckl_data(int, stack->last) == SH_PARENT_CHECK_TYPE_SQ)
		return (1);
	return (0);
}

static size_t	st_do_one(
					const char *src,
					t_ckl *stack,
					t_sh_parent_check_corr corr)
{
	if (ckstd_strlen(src) >= ckstd_strlen(corr.end)
		&& strncmp(src, corr.end, ckstd_strlen(corr.end)) == 0)
	{
		if (stack->last && ckl_data(int, stack->last) == corr.type)
		{
			ckl_withdraw(stack, stack->last);
			return (ckstd_strlen(corr.end));
		}
	}
	if (ckstd_strlen(src) >= ckstd_strlen(corr.start)
		&& strncmp(src, corr.start, ckstd_strlen(corr.start)) == 0)
	{
		ckl_append(stack, &corr.type);
		return (ckstd_strlen(corr.start));
	}
	return (0);
}

int				st_check(const char *src, t_ckl *stack)
{
	int		c;

	c = 0;
	c += st_do_one(src, stack,
		(t_sh_parent_check_corr){ "\"", "\"", SH_PARENT_CHECK_TYPE_DQ });
	c += st_do_one(src, stack,
		(t_sh_parent_check_corr){ "'", "'", SH_PARENT_CHECK_TYPE_SQ });
	c += st_do_one(src, stack,
		(t_sh_parent_check_corr){ "`", "`", SH_PARENT_CHECK_TYPE_BT });
	c += st_do_one(src, stack,
		(t_sh_parent_check_corr){ "$(", ")", SH_PARENT_CHECK_TYPE_CS });
	return (c);
}

int				sh_check_bracketing(const char *src)
{
	size_t		len;
	size_t		i;
	t_ckl		*stack;
	int			c;

	stack = ckl_new(int);
	len = ckstd_strlen(src);
	i = 0;
	while (i < len)
	{
		if ((c = st_check_skipped(src + i, stack)) > 0)
		{
			i += c;
			continue ;
		}
		c = st_check(src + i, stack);
		i += ((c) ? c : 1);
	}
	if (!stack->last)
		return (0);
	return (ckl_data(int, stack->last));
}
