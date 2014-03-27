/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ckf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 15:14:55 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/18 15:15:35 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CKF_H

# define CKF_H

# include "cks.h"
# include "ckl.h"

# define CKF_TYPE_BLOCK (1)
# define CKF_TYPE_CHARACTER (2)
# define CKF_TYPE_DIRECTORY (4)
# define CKF_TYPE_LINK (8)
# define CKF_TYPE_SOCKET (16)
# define CKF_TYPE_FIFO (32)
# define CKF_TYPE_REGULAR (64)

# define CKF_ERROR_NOT_FOUND (-1)
# define CKF_ERROR_ACCESS_DENIED (-2)
# define CKF_ERROR_NO_HOME (-3)

t_cks					ckf_dirname(const char *path);
int						ckf_access(const char *path_orig, int amode);

#endif
