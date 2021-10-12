/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parser_func.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:45:31 by lduplain          #+#    #+#             */
/*   Updated: 2021/10/12 14:58:54 by lduplain         ###   ########.fr       */
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
**	Parse quotes strings.
**	./parser/parse_quotes.c
*/
void	parse_quotes(t_cmd_builder *cmd_builder, char quote);

#endif
