/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_processed_arg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:43:34 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/08 16:28:37 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_processed_arg(t_shell *shell, char *arg)
{
	char	*processed_arg;
	size_t	arg_len;
	size_t	i;

	processed_arg = NULL;
	arg_len = ft_strlen(arg);
	i = 0;
	while (i < arg_len)
	{
		if (arg[i] == '\'' || arg[i] == '\"')
			processed_arg = ft_append_strs(processed_arg,
					get_processed_quote(shell, arg, arg_len, &i),
					TRUE, TRUE);
		else if (arg[i] == '$'
			&& (is_alphanumeric(arg[i + 1]) || arg[i + 1] == '?'))
			processed_arg = append_env_var_to_str(shell,
					processed_arg, get_env_var_name(arg, arg_len, &i));
		else
		{
			processed_arg = ft_append_char_to_str(processed_arg, arg[i]);
			i++;
		}
	}
	return (processed_arg);
}
