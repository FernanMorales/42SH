/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parse_log_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 15:19:16 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/23 15:19:17 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			sh_parse_log_cmd(t_ckl *tokens, t_ckbt *tree, t_ckbt_node **root)
{
	if (tokens->first == NULL)
		return (-1);
	return (sh_parse_actual_log_cmd(tokens, tree, root,
		sh_parse_num_log_ops(tokens)));
}
