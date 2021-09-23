/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 15:24:15 by lduplain          #+#    #+#             */
/*   Updated: 2021/09/23 16:16:29 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env_value(t_shell *shell, char *key)
{
	char	*new_key;
	size_t	new_key_size;
	size_t	line_index;

	new_key = ft_append_char_to_str(key, '=');
	if (ft_strcmp(new_key, "?=") == 0)
	{
		free(new_key);
		/* TODO: PRINT ERRNO VALUE */
		return (ft_strdup("ERRNO VALUE (TODO)", FALSE));
	}
	new_key_size = ft_strlen(new_key);
	line_index = 0;
	while (shell->env[line_index] != NULL)
	{
		if (ft_strncmp(shell->env[line_index], new_key, new_key_size) == 0)
		{
			free(new_key);
			return (ft_strdup(&shell->env[line_index][new_key_size], FALSE));
		}
		line_index++;
	}
	free(new_key);
	return (NULL);
}
