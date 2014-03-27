/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cks.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 22:50:39 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/18 13:56:51 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CKS_H

# define CKS_H

# include "ckl.h"

/*
** CKS is a standalone library for fast and binary safe string manipulation.
**
** For each function that returns a string, NULL may be returned if any
** of the params are NULL or if a call to malloc failed.
**
** All CKS strings are null terminated and can be used without changes with
** the standard library. You may do this:
**     t_cks str = cks_new("Hello world!");
**     printf("%s\n", str);
**     cks_free(str);
*/
typedef char *		t_cks;

/*
** Includes definitions for size_t.
*/
# include <sys/types.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>
# include "ckstd.h"

/*
** 4 bytes for the allocated memory size
** 4 bytes for the string length
*/
# define CKS_PADDING (sizeof(size_t) + sizeof(size_t))

/*
** Grows the length of a string to about twice its original length
** to avoid constants re-allocations.
*/
size_t				cks_len_grow(size_t len);

/*
** Gets the length of the string.
**
** The length is stored within the string so this takes constant time,
** however long the string is.
*/
size_t				cks_len(const t_cks str);

/*
** Gets the maximum length allowed by the current buffer.
*/
size_t				cks_mem(const t_cks str);

/*
** Frees the string the right way.
*/
void				cks_free(t_cks str);

/*
** Sets the maximum length allowed by the current buffer.
*/
void				cks_set_mem(t_cks str, size_t mem);

/*
** Sets the string length.
*/
void				cks_set_len(t_cks str, size_t len);

/*
** Allocates the appropriate memory size for a given length and
** sets string length to 0, null terminating the string.
*/
t_cks				cks_malloc(size_t len);

/*
** Creates a new cks string from a C string, null terminating the buffer.
*/
t_cks				cks_new(const char *s1);

/*
** Creates a new cks string from a C string and a length, null
** terminating the buffer.
*/
t_cks				cks_new_len(const char *s1, size_t len);

/*
** Creates a new cks string from a C string and a length, null
** terminating the buffer.
*/
t_cks				cks_dup(const t_cks str);

/*
** Inserts s2 in s1 at a given position.
**
** The first parameter, s1, will be freed if its buffer was not big
** enough to hold the result.
**
** Note that the intended usage is this:
**     t_cks str = cks_new("Hello");
**     str = ckscat(str, " World!");
**
** If you cannot afford to modify s1 - because it is referenced elsewhere,
** do this:
**     str = ckscat(cks_dup(str), " World!");
*/
t_cks				cks_insert(t_cks s1, size_t pos, const char *s2);
t_cks				cks_insert_len(t_cks s1, size_t pos, const char *s2,
						size_t len);

/*
** Appends s2 to s1.
**
** The first parameter, s1, will be freed if its buffer was not big
** enough to hold the result.
**
** Note that the intended usage is this:
**     t_cks str = cks_new("Hello");
**     str = ckscat(str, " World!");
**
** If you cannot afford to modify s1 - because it is referenced elsewhere,
** do this:
**     str = ckscat(cks_dup(str), " World!");
*/
t_cks				cks_append(t_cks s1, const char *s2);
t_cks				cks_append_len(t_cks s1, const char *s2, size_t len);

/*
** Prepends s2 to s1.
**
** The first parameter, s1, will be freed if its buffer was not big
** enough to hold the result.
**
** Note that the intended usage is this:
**     t_cks str = cks_new("Hello");
**     str = ckscat(str, " World!");
**
** If you cannot afford to modify s1 - because it is referenced elsewhere,
** do this:
**     str = ckscat(cks_dup(str), " World!");
*/
t_cks				cks_prepend(t_cks s1, const char *s2);
t_cks				cks_prepend_len(t_cks s1, const char *s2, size_t len);

/*
** Take a part of s1, starting at `index` and stopping after `n` chars
*/
t_cks				cks_sub(const t_cks s, size_t start);
t_cks				cks_sub_len(const t_cks s, size_t start, size_t n);

/*
** Compares bytes of both given strings
*/
int					cks_cmp(const t_cks s1, const char *s2);
int					cks_cmp_len(const t_cks s1, const char *s2, size_t len);
t_cks				cks_get_line(int fd);

/*
** Splits a string based on a given delimiter.
*/
t_ckl				*cks_split(const char *s, const char *del,
						int ignore_empty);

#endif
