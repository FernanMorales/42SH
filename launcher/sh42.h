/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh42.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 10:41:19 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/08 11:27:56 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH42_H

# define SH42_H

# include <sys/wait.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdlib.h>
# include "ckl.h"
# include "cks.h"
# include "ckbt.h"
# include "ckstd.h"
# include "sh_parser.h"
/*
# include "ckf.h"
*/

extern char					*const *environ;

typedef struct				s_sh_env
{
	t_cks					base;
	int						last_ret;
	int						tty_fd;
}							t_sh_env;

#endif
