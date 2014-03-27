/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ckf_dirname.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 15:14:46 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/18 15:14:48 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "cks.h"
#include "ckstd.h"

t_cks					ckf_dirname(const char *path)
{
	size_t		len;

	len = ckstd_strlen(path);
	if (len > 1 && path[len - 1] == '/')
		len--;
	while (len > 0 && path[len - 1] != '/')
		len--;
	return (cks_new_len(path, len));
}
