/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parser_func.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:45:31 by lduplain          #+#    #+#             */
/*   Updated: 2021/09/28 12:48:59 by lduplain         ###   ########.fr       */
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
**	./parser/parse_quotes.c
*/
void	parse(t_shell *shell);

/*
**	Create new shell structure.
**	./parser/parse_quotes.c
*/
size_t	parse_quotes(char *line, size_t index, char quote, char **str);

#endif
