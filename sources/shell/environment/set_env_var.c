/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 20:18:51 by lduplain          #+#    #+#             */
/*   Updated: 2021/10/04 16:18:05 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_env_var(t_shell *shell, char *key, char *value, t_bool free_value)
{
	ssize_t	env_var_index;
	char	**new_env;
	size_t	line_index;

	env_var_index = get_env_var_index(shell, key);
	new_env = ft_calloc(get_env_length(shell) + 2, sizeof(char *));
	if (new_env == NULL)
		return ;
	if (env_var_index != -1)
		unset_env_var(shell, key);
	line_index = 0;
	while (shell->env[line_index] != NULL)
	{
		new_env[line_index] = ft_strdup(shell->env[line_index], FALSE);
		line_index++;
	}
	if (value == NULL)
		new_env[line_index] = ft_strdup(key, FALSE);
	else
		new_env[line_index] = ft_append_strs(key,
				ft_append_strs("=", value, FALSE, free_value),
				FALSE, TRUE);
	new_env[line_index + 1] = NULL;
	ft_destroy_string_array(&shell->env);
	shell->env = new_env;
}
