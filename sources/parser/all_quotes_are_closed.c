/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_quotes_are_closed.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:59:53 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/03 16:00:07 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	all_quotes_are_closed(char *str)
{
	t_bool	is_open;
	size_t	str_len;
	size_t	index;
	char	current_quote;

	is_open = FALSE;
	str_len = ft_strlen(str);
	index = 0;
	while (index < str_len)
	{
		if (str[index] == '\'' || str[index] == '\"')
		{
			is_open = TRUE;
			current_quote = str[index];
			index++;
			while (index < str_len && str[index] != current_quote)
				index++;
			if (str[index] == current_quote)
				is_open = FALSE;
		}
		index++;
	}
	return (!is_open);
}
