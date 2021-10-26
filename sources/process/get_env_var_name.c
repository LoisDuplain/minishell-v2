/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_var_name.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:58:08 by lduplain          #+#    #+#             */
/*   Updated: 2021/10/26 17:35:37 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env_var_name(char *arg, size_t arg_len, size_t *i)
{
	char	*result;

	result = NULL;
	(*i)++;
	while (*i < arg_len && (is_alphanumeric(arg[*i])
			|| arg[*i] == '?' || arg[*i] == '_'))
	{
		result = ft_append_char_to_str(result, arg[*i]);
		(*i)++;
		if (arg[*i - 1] == '?')
			break ;
	}
	return (result);
}
