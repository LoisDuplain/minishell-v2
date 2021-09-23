/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_env_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain < lduplain@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:16:22 by lduplain          #+#    #+#             */
/*   Updated: 2021/09/23 22:54:26 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset_env_var(t_shell *shell, char *key)
{
	char	**new_env;
	size_t	new_line_index;
	size_t	line_index;

	if (env_var_exists(shell, key))
		return ;
	new_env = ft_calloc(get_env_length(shell), sizeof(char *));
	if (new_env == NULL)
		return ;
	new_line_index = 0;
	line_index = 0;
	while (shell->env[line_index] != NULL)
	{
		if (ft_strncmp(key, shell->env[line_index], ft_strlen(key)))
		{
			new_env[new_line_index] = ft_strdup(shell->env[line_index], FALSE);
			new_line_index++;
		}
		line_index++;
	}
	new_env[line_index] = NULL;
	ft_destroy_string_array(&shell->env);
	shell->env = new_env;
}
