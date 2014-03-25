/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 19:02:44 by ckleines          #+#    #+#             */
/*   Updated: 2014/01/26 15:17:16 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"

static int32_t	static_easy(int32_t pos, t_cks str)
{
	free(environ[pos]);
	environ[pos] = ckstd_strdup(str);
	cks_free(str);
	return (1);
}

void			ms_setenv(const char *key, const char *val, int32_t overwrite)
{
	int32_t		pos;
	char		**nenv;
	t_cks		str;
	int32_t		len;

	pos = ms_posenv(key);
	str = cks_new(key);
	str = cks_append(str, "=");
	str = cks_append(str, val);
	if (pos != -1 && overwrite && static_easy(pos, str))
		return ;
	len = 0;
	while (environ[len])
		len++;
	nenv = (char **)malloc(sizeof(char *) * (len + 2));
	len = -1;
	while (environ[++len])
		nenv[len] = environ[len];
	nenv[len] = ckstd_strdup(str);
	nenv[len + 1] = NULL;
	ms_environ_free();
	cks_free(str);
	environ = nenv;
}
