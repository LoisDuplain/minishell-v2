/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_processed_quote.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:47:54 by lduplain          #+#    #+#             */
/*   Updated: 2021/10/27 14:10:53 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_processed_quote(t_shell *shell, char *arg,
	size_t arg_len, size_t *i)
{
	char	quote;
	char	*result;

	result = NULL;
	quote = arg[*i];
	(*i)++;
	while (*i < arg_len && arg[*i] != quote)
	{
		if (arg[*i] == '$' && quote == '\"')
			result = append_env_var_to_str(shell, result,
					get_env_var_name(arg, arg_len, i));
		result = ft_append_char_to_str(result, arg[*i]);
		(*i)++;
	}
	(*i)++;
	return (result);
}
