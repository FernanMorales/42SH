/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 03:59:39 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/07 01:54:59 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H

# define SH_H

# include "sh_parser.h"
# include "am.h"

typedef struct					s_sh_parent_check_corr
{
	const char	*start;
	const char	*end;
	int			type;
}								t_sh_parent_check_corr;

int			lexer_callback_subcommand_dollar(t_am *am);
int			lexer_callback_subcommand_backtick(t_am *am);
int			sh_token_is_string(t_am_token *t);
int			lexer_callback_single_quote_string_content(t_am *am);
t_am		*lexer_automaton_single_quote_string(void);
int			lexer_callback_double_quote_string_content(t_am *am);
t_am		*lexer_automaton_double_quote_string(void);
int			is_not_meaningful(char c);
int			lexer_callback_string(t_am *am);
t_am		*lexer_automaton_string(void);
t_am		*lexer_automaton_command_line_token(void);
int			am_lex(t_am_maker maker, const char *source, t_ckl *tokens);
void		sh_remove_useless_tokens(t_ckl *tokens);
int			sh_type_is_op(int type);
int			sh_token_is_quoted_string(t_am_token *t);
int			sh_token_is_string(t_am_token *t);
void		sh_concat_strings(t_ckl *t);
void		sh_remove_whitespace(t_ckl *tokens);
int			sh_lex(const char *src, t_ckl *tokens);
void		sh_replace_redirections(t_ckl *t, const char *base);
void		sh_print_tokens(t_ckl *tokens);
int			sh_build_tree(t_ckl *tokens, t_ckbt *tree);
void		sh_infile(t_ckl *tokens, t_ckl_item *start, const t_cks file,
				const char *base);
void		sh_heredoc(t_ckl *tokens, t_ckl_item *start, const t_cks boundary,
				const char *base);
void		sh_replace_redirections_in(t_ckl *t, t_ckl_item *start,
				const char *base);
void		sh_outfile(t_ckl *tokens, t_ckl_item *end, const t_cks file,
				const char *base);
void		sh_outfile_append(t_ckl *tokens, t_ckl_item *end,
				const t_cks boundary, const char *base);
void		sh_replace_redirections_out(t_ckl *t, t_ckl_item *start,
				t_ckl_item *end, const char *base);
int			sh_parse(const char *src, t_ckbt *tree, const char *basepath);

int			sh_parse_cmd_line(t_ckl *tokens, t_ckbt *tree, t_ckbt_node **root);
int			sh_parse_seq_cmd(t_ckl *tokens, t_ckbt *tree, t_ckbt_node **root);
int			sh_parse_log_cmd(t_ckl *tokens, t_ckbt *tree, t_ckbt_node **root);
int			sh_parse_pipe_cmd(t_ckl *tokens, t_ckbt *tree, t_ckbt_node **root);
int			sh_parse_cmd(t_ckl *tokens, t_ckbt *tree, t_ckbt_node **root);
t_ckbt_node	*sh_new_node_logic(t_ckbt *tree, t_sh_token_type type);
t_ckbt_node	*sh_new_node_semicolon(t_ckbt *tree);
t_ckbt_node	*sh_new_node_pipe(t_ckbt *tree);
#endif
