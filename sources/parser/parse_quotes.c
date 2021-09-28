/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:26:34 by lduplain          #+#    #+#             */
/*   Updated: 2021/09/28 12:37:50 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	parse_quotes(char *line, size_t index, char quote, char **str)
{
	size_t	line_length;

	line_length = ft_strlen(line);
	while (line[index] != quote && index < line_length)
	{
		*str = ft_append_char_to_str(*str, line[index]);
		index++;
	}
	if (line[index] == quote)
		index++;
	return (index);
}
