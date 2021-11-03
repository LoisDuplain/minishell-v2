/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parser_func.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:45:31 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/03 16:00:49 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_PARSER_FUNC_H
# define MINISHELL_PARSER_FUNC_H

/*
**	START CUSTOM INCLUDES
*/

# include "minishell.h"

/*
**	END CUSTOM INCLUDES
*/

/*
**	Create new shell structure.
**	./parser/parse.c
*/
void	parse(t_shell *shell);

/*
**	Parse quoted strings.
**	./parser/parse_quote.c
*/
void	parse_quote(t_cmd_builder *cmd_builder, char quote);

/*
**	Parse piped command.
**	./parser/parse_pipe.c
*/
void	parse_pipe(t_cmd_builder *cmd_builder);

/*
**	Parse redirected command.
**	./parser/parse_redirection.c
*/
void	parse_redirection(t_cmd_builder *cmd_builder, char redirect);

/*
**	Specify parsing method by the current_char.
**	./parser/dispatch_parsing.c
*/
void	dispatch_parsing(t_cmd_builder *cmd_builder, char current_char);

/*
**	Return TRUE if all quotes are correctly closed in str.
**	./parser/all_quotes_are_closed.c
*/
t_bool	all_quotes_are_closed(char *str);

#endif
