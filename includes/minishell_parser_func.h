/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parser_func.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:45:31 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/09 13:39:28 by lduplain         ###   ########.fr       */
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
**	Start command parsing.
**	./parser/parse.c
*/
void	parse(t_cmd_container *cmd_container);

/*
**	Specify parsing method by the current_char.
**	./parser/dispatch_parsing.c
*/
void	dispatch_parsing(t_cmd_container *cmd_container, char current_char);

/*
**	Parse quoted strings.
**	./parser/parse_quote.c
*/
void	parse_quote(t_cmd_container *cmd_container, char quote);

/*
**	Parse redirected command.
**	./parser/parse_redirection.c
*/
void	parse_redirection(t_cmd_container *cmd_container, char redirect);

/*
**	Parse piped command.
**	./parser/parse_pipe.c
*/
void	parse_pipe(t_cmd_container *cmd_container);

/*
**	Return TRUE if all quotes are correctly closed in str.
**	./parser/all_quotes_are_closed.c
*/
t_bool	all_quotes_are_closed(char *str);

#endif
