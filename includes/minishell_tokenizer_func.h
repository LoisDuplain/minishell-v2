/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_tokenizer_func.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain < lduplain@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:45:31 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/24 14:21:38 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_TOKENIZER_FUNC_H
# define MINISHELL_TOKENIZER_FUNC_H

/*
**	START CUSTOM INCLUDES
*/

# include "minishell.h"

/*
**	END CUSTOM INCLUDES
*/

/*
**	Start line tokenizing.
**	./tokenizer/tokenize.c
*/
t_bool	tokenize(t_cmd_container *cmd_container);

/*
**	Specify tokenizing method by the current_char.
**	./tokenizer/dispatch_tokenizing.c
*/
void	dispatch_tokenizing(t_cmd_container *cmd_container, char current_char);

/*
**	Tokenize quoted strings.
**	./tokenizer/tokenize_quote.c
*/
void	tokenize_quote(t_cmd_container *cmd_container, char quote);

/*
**	Parse redirected command.
**	./tokenizer/tokenize_redirection.c
*/
void	tokenize_redirection(t_cmd_container *cmd_container, char redirect);

/*
**	Parse piped command.
**	./tokenizer/tokenize_pipe.c
*/
void	tokenize_pipe(t_cmd_container *cmd_container);

/*
**	Return TRUE if all quotes are correctly closed in str.
**	./tokenizer/all_quotes_are_closed.c
*/
t_bool	all_quotes_are_closed(char *str);

/*
**	Return TRUE if all cmds are correctly filled.
**	./tokenizer/all_cmds_are_filled.c
*/
t_bool	all_cmds_are_filled(t_cmd_container *cmd_container);

#endif
