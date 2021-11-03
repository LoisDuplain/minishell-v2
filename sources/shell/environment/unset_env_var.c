/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_env_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:16:22 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/03 13:06:29 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset_env_var(t_shell *shell, char *key)
{
	ssize_t	env_var_index;
	char	**new_env;
	size_t	line_index;
	size_t	new_index;

	env_var_index = get_env_var_index(shell, key);
	if (env_var_index == -1)
		return ;
	new_env = ft_calloc(get_env_length(shell), sizeof(char *));
	if (new_env == NULL)
		return ;
	new_index = 0;
	line_index = 0;
	while (shell->env[line_index] != NULL)
	{
		if (line_index != (size_t) env_var_index)
		{
			new_env[new_index] = ft_strdup(shell->env[line_index]);
			new_index++;
		}
		line_index++;
	}
	new_env[new_index] = NULL;
	ft_destroy_string_array(&shell->env);
	shell->env = new_env;
}
