/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ckf_access.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 15:14:39 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/18 15:14:40 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "cks.h"
#include "ckf.h"

static int				st_add_home(const char *path_orig, t_cks *path)
{
	const char		*home;

	if (path_orig[0] == '~' && (home = getenv("HOME")) == NULL)
		return (CKF_ERROR_NO_HOME);
	if (path_orig[0] == '~')
		*path = cks_append(cks_new(home), path_orig + 1);
	else
		*path = cks_new(path_orig);
	return (0);
}

static int				st_check_dirs(t_cks path)
{
	t_cks		dirname;
	t_cks		tmp;

	dirname = ckf_dirname(path);
	cks_free(path);
	while (1)
	{
		if (cks_cmp(dirname, "/") == 0 || cks_len(dirname) == 0)
			break ;
		if (access(dirname, F_OK) == 0 && access(dirname, X_OK) == -1)
			return (CKF_ERROR_ACCESS_DENIED);
		tmp = dirname;
		dirname = ckf_dirname(dirname);
		cks_free(tmp);
	}
	cks_free(dirname);
	return (CKF_ERROR_NOT_FOUND);
}

int						ckf_access(const char *path_orig, int amode)
{
	t_cks		path;

	if (st_add_home(path_orig, &path) != 0)
		return (CKF_ERROR_NO_HOME);
	if (access(path, amode) == 0)
	{
		cks_free(path);
		return (0);
	}
	if (access(path, F_OK) == 0)
	{
		cks_free(path);
		return (CKF_ERROR_ACCESS_DENIED);
	}
	return (st_check_dirs(path));
}
