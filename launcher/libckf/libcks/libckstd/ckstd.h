/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ckstd.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 21:41:22 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/25 17:33:46 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CKSTD_H

# define CKSTD_H

# include <string.h>
# include <stdlib.h>

size_t			ckstd_strlen(const char *s);
void			*ckstd_memcpy(void *s1, const void *s2, size_t n);
void			*ckstd_memmove(void *s1, const void *s2, size_t n);
int				ckstd_strcmp(const char *s1, const char *s2);
int				ckstd_memcmp(const void *s1, const void *s2, size_t n);
char			*ckstd_strdup(const char *s);
int				ckstd_strncmp(const char *s1, const char *s2, size_t n);
int				ckstd_atoi(const char *s, int *val);
char			*ckstd_strchr(const char *s, int c);

#endif
