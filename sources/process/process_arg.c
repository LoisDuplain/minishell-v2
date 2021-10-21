/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:43:34 by lduplain          #+#    #+#             */
/*   Updated: 2021/10/21 22:18:25 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_processed_env_var(t_shell *shell, char *arg)
{
	char	*key;
	size_t	index;
	char	*result;

	key = NULL;
	index = 0;
	while (arg[index] && (is_alphanumeric(arg[index]) || arg[index] == '?'))
	{
		key = ft_append_char_to_str(key, arg[index]);
		index++;
	}
	result = get_env_var(shell, key);
	free(key);
	return (result);
}

char	*get_processed_quote(t_shell *shell, char *arg, size_t *i, char quote)
{
	char	*result;
	char	*env_var;

	result = NULL;
	(*i)++;
	while (arg[*i] && arg[*i] != quote)
	{
		if (arg[*i] == '$' && quote == '\"')
		{
			env_var = get_processed_env_var(shell, arg);
			*i += ft_strlen(env_var);
			result = ft_append_strs(result, env_var, TRUE, TRUE);
		}
		else
		{
			result = ft_append_char_to_str(result, arg[*i]);
			(*i)++;
		}
	}
	(*i)++;
	return (result);
}

char	*get_processed_arg(t_shell *shell, char *arg)
{
	char	*processed_arg;
	size_t	arg_len;
	size_t	i;

	exit(EXIT_FAILURE);
	processed_arg = NULL;
	arg_len = ft_strlen(arg);
	i = 0;
	while (i < arg_len)
	{
		if (arg[i] == '\'' || arg[i] == '\"')
			ft_append_strs(processed_arg,
				get_processed_quote(shell, arg, &i, arg[i]), TRUE, FALSE);
		else
		{
			processed_arg = ft_append_char_to_str(processed_arg, arg[i]);
			i++;
		}
	}
	return (processed_arg);
}
