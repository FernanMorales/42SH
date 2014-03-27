/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <ckleines@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:38:27 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/27 14:38:28 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"

t_sh_builtin	sh_builtin[] = {
	{ "cd", &sh_builtin_cd },
	{ "echo", &sh_builtin_echo },
	{ "exit", &sh_builtin_exit },
	{ "env", &sh_builtin_env },
	{ "setenv", &sh_builtin_setenv },
	{ "unsetenv", &sh_builtin_unsetenv },
	{ NULL, NULL}
};
