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

#include "ms.h"
#include "ck.h"

static int32_t	static_easy(int32_t pos, t_ck_str str)
{
	free(environ[pos]);
	environ[pos] = ck_str_to_c_str(str);
	free(str);
	return (1);
}

void			ms_setenv(const char *key, const char *val, int32_t overwrite)
{
	int32_t		pos;
	char		**nenv;
	t_ck_str	str;
	int32_t		len;

	pos = ms_posenv(key);
	str = ck_str_init_from_c_str(key);
	ck_str_append_buf(str, "=", 1);
	ck_str_append_c_str(str, val);
	if (pos != -1 && overwrite && static_easy(pos, str))
		return ;
	len = 0;
	while (environ[len])
		len++;
	nenv = (char **)malloc(sizeof(char *) * (len + 2));
	nenv[len + 1] = NULL;
	len = -1;
	while (environ[++len])
		nenv[len] = environ[len];
	nenv[len] = ck_str_to_c_str(str);
	free(environ);
	free(str);
	environ = nenv;
}
