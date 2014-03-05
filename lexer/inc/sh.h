/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 03:59:39 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/04 18:21:39 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H

# define SH_H

int		lexer_callback_subcommand_dollar(t_am *am);
int		lexer_callback_subcommand_backtick(t_am *am);
int		sh_token_is_string(t_am_token *t);

#endif
