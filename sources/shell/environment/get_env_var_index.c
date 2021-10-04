/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_var_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 15:05:09 by lduplain          #+#    #+#             */
/*   Updated: 2021/10/04 16:13:15 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

ssize_t	get_env_var_index(t_shell *shell, char *key)
{
	char	*new_key;
	size_t	new_key_length;
	ssize_t	line_index;

	new_key = ft_append_strs(key, "=", FALSE, FALSE);
	new_key_length = ft_strlen(new_key);
	line_index = -1;
	while (shell->env[++line_index] != NULL)
		if (ft_strncmp(new_key, shell->env[line_index], new_key_length) == 0)
			break ;
	free(new_key);
	if ((size_t) line_index >= get_env_length(shell))
		return (-1);
	return (line_index);
}
