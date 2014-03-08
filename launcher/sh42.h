/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh42.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 10:41:19 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/08 11:09:45 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH42_H

# define SH42_H

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
# include "ckf.h"

typedef struct				s_ftsh_env
{
	t_cks					base;
	int						last_ret;
}							t_ftsh_env;

#endif
